#include <iostream>
#include <usb.hpp>

namespace Scoped {

USBDevice::USBDevice() { libusb_init(&m_context); }

USBDevice::~USBDevice() {
  disconnect();
  libusb_exit(m_context);
}

bool USBDevice::connect() {
  m_handle =
      libusb_open_device_with_vid_pid(m_context, m_vendor_id, m_product_id);
  if (!m_handle)
    return false;

  // Interface 2 is Data, Interface 1 is Control/Management
  int data_iface = 2;
  int ctrl_iface = 1;

  // 1. Detach and Claim interfaces
  for (int i : {ctrl_iface, data_iface}) {
    if (libusb_kernel_driver_active(m_handle, i))
      libusb_detach_kernel_driver(m_handle, i);
    libusb_claim_interface(m_handle, i);
  }

  // 2. Set Baud Rate (115200, 8N1) - Required manual request for CDC
  uint8_t encoding[] = {0x00, 0xC2, 0x01, 0x00, 0x00, 0x00, 0x08};
  libusb_control_transfer(m_handle, 0x21, 0x20, 0, ctrl_iface, encoding, 7, 1000);

  // 3. Set Control Line State (DTR & RTS High) - Starts the FPGA stream
  libusb_control_transfer(m_handle, 0x21, 0x22, 0x03, ctrl_iface, NULL, 0, 1000);

  return true;
}

void USBDevice::disconnect() {
  stopStreaming();
  if (m_handle) {
    for (int i : {1, 2}) {
      libusb_release_interface(m_handle, i);
      libusb_attach_kernel_driver(m_handle, i);
    }
    libusb_close(m_handle);
    m_handle = nullptr;
  }
}

void USBDevice::startStreaming(CircularBuffer &buffer) {
  if (!m_handle || m_is_streaming)
    return;

  std::cout << "[USB] Starting stream thread on EP 0x" << std::hex << m_endpoint
            << std::dec << "...\n";
  m_is_streaming = true;
  m_stream_thread = std::thread(&USBDevice::streamLoop, this, std::ref(buffer));
}

void USBDevice::stopStreaming() {
  if (m_is_streaming) {
    std::cout << "[USB] Stopping stream thread...\n";
    m_is_streaming = false;
    if (m_stream_thread.joinable()) {
      m_stream_thread.join();
      std::cout << "[USB] Stream thread joined.\n";
    }
  }
}

void USBDevice::streamLoop(CircularBuffer &buffer) {
  uint8_t temp_buffer[4096];
  std::cout << "[USB] Stream loop running.\n";

  size_t total_received = 0;
  auto last_log_time = std::chrono::steady_clock::now();

  while (m_is_streaming) {
    int transferred = 0;
    int result = libusb_bulk_transfer(m_handle, m_endpoint, temp_buffer,
                                      sizeof(temp_buffer), &transferred, 100);

    if (result == 0 && transferred > 0) {
      buffer.pushBlock(temp_buffer, transferred);
      total_received += transferred;

      // Log progress every second
      auto now = std::chrono::steady_clock::now();
      if (std::chrono::duration_cast<std::chrono::seconds>(now - last_log_time)
              .count() >= 1) {
        std::cout << "[USB] Receiving data... Total so far: "
                  << (total_received / 1024) << " KB\n";
        last_log_time = now;
      }
    } else if (result == LIBUSB_ERROR_TIMEOUT) {
      continue;
    } else if (result != 0) {
      std::cerr << "[USB] Bulk transfer error: " << libusb_error_name(result)
                << "\n";
      break;
    }
  }

  m_is_streaming = false;
  std::cout << "[USB] Stream loop exited. Total received: "
            << (total_received / 1024) << " KB\n";
}

} // namespace Scoped
