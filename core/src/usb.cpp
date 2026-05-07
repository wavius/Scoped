#include <chrono>
#include <iostream>
#include <thread>
#include <usb.hpp>

namespace Scoped {

USBDevice::USBDevice() { libusb_init(&m_context); }

USBDevice::~USBDevice() {
  disconnect();
  libusb_exit(m_context);
}

// ---------------------------------------------------------------------------
// Connection
// ---------------------------------------------------------------------------

bool USBDevice::connect() {
  m_handle = libusb_open_device_with_vid_pid(m_context, VENDOR_ID, PRODUCT_ID);
  if (!m_handle)
    return false;

  for (int iface : {CTRL_INTERFACE, DATA_INTERFACE}) {
    if (libusb_kernel_driver_active(m_handle, iface))
      libusb_detach_kernel_driver(m_handle, iface);
    libusb_claim_interface(m_handle, iface);
  }

  // CDC line encoding: 115200 baud, 8N1
  uint8_t encoding[] = {0x00, 0xC2, 0x01, 0x00, 0x00, 0x00, 0x08};
  libusb_control_transfer(m_handle, 0x21, 0x20, 0, CTRL_INTERFACE, encoding,
                          sizeof(encoding), 1000);
  libusb_control_transfer(m_handle, 0x21, 0x22, 0x03, CTRL_INTERFACE, nullptr,
                          0, 1000);

  return true;
}

void USBDevice::disconnect() {
  stopStreaming();
  if (m_handle) {
    for (int iface : {CTRL_INTERFACE, DATA_INTERFACE}) {
      libusb_release_interface(m_handle, iface);
      libusb_attach_kernel_driver(m_handle, iface);
    }
    libusb_close(m_handle);
    m_handle = nullptr;
  }
}

// ---------------------------------------------------------------------------
// Streaming
// ---------------------------------------------------------------------------

void USBDevice::startStreaming(IChannel *channel) {
  if (!m_handle || m_is_streaming || !channel)
    return;

  std::cout << "[USB] Starting stream on EP 0x" << std::hex
            << static_cast<int>(ENDPOINT_IN) << std::dec << "...\n";
  m_is_streaming = true;
  m_stream_thread = std::thread(&USBDevice::streamLoop, this, channel);
}

void USBDevice::stopStreaming() {
  if (m_is_streaming) {
    m_is_streaming = false;
    if (m_stream_thread.joinable()) {
      m_stream_thread.join();
    }
  }
}

void USBDevice::streamLoop(IChannel *channel) {
  uint8_t temp[4096];
  size_t total_received = 0;
  auto last_log = std::chrono::steady_clock::now();

  while (m_is_streaming) {
    int transferred = 0;
    int result = libusb_bulk_transfer(m_handle, ENDPOINT_IN, temp, sizeof(temp),
                                      &transferred, 100);

    if (result == 0 && transferred > 0) {
      channel->pushRawBytes(temp, transferred);
      total_received += transferred;

      auto now = std::chrono::steady_clock::now();
      auto elapsed =
          std::chrono::duration_cast<std::chrono::seconds>(now - last_log);
      if (elapsed.count() >= 1) {
        std::cout << "[USB] Received: " << (total_received / 1024) << " KB\n";
        last_log = now;
      }
    } else if (result == LIBUSB_ERROR_TIMEOUT) {
      continue;
    } else if (result != 0) {
      std::cerr << "[USB] Transfer error: " << libusb_error_name(result)
                << "\n";
      break;
    }
  }

  m_is_streaming = false;
  std::cout << "[USB] Stream exited. Total: " << (total_received / 1024)
            << " KB\n";
}

} // namespace Scoped
