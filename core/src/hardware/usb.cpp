#include <chrono>
#include <iostream>
#include <thread>
#include <hardware/usb.hpp>

namespace Scoped {

// Lifecycle
USBDevice::USBDevice() { libusb_init(&m_context); }

USBDevice::~USBDevice() {
  disconnect();
  libusb_exit(m_context);
}

// Connection
bool USBDevice::connect() {
  std::cout << "[USB] Attempting connection to VID: 0x" << std::hex << VENDOR_ID
            << " PID: 0x" << PRODUCT_ID << std::dec << "...\n";

  m_handle = libusb_open_device_with_vid_pid(m_context, VENDOR_ID, PRODUCT_ID);
  if (!m_handle) {
    std::cerr << "[USB] Failed to open device 0x" << std::hex << VENDOR_ID
              << ":0x" << PRODUCT_ID << std::dec << "\n";
    return false;
  }



  // Set auto-detach if supported
#if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000103
  libusb_set_auto_detach_kernel_driver(m_handle, 1);
#endif



  // Detach kernel drivers if active
  for (int iface : {CTRL_INTERFACE, DATA_INTERFACE}) {
    if (libusb_kernel_driver_active(m_handle, iface) == 1) {
      libusb_detach_kernel_driver(m_handle, iface);
    }
  }

  // Claim Control interface first
  int res_ctrl = libusb_claim_interface(m_handle, CTRL_INTERFACE);
  if (res_ctrl != 0) {
    std::cerr << "[USB] Error claiming CTRL_INTERFACE (" << CTRL_INTERFACE
              << "): " << libusb_error_name(res_ctrl) << "\n";
  }

  // Claim Data interface
  int res_data = libusb_claim_interface(m_handle, DATA_INTERFACE);
  if (res_data != 0) {
    std::cerr << "[USB] Error claiming DATA_INTERFACE (" << DATA_INTERFACE
              << "): " << libusb_error_name(res_data) << "\n";
    libusb_close(m_handle);
    m_handle = nullptr;
    return false;
  }

  // Send CDC Control Line State (DTR=1, RTS=1) & Line Coding (115200 8N1)
  uint8_t line_coding[7] = {0x00, 0xC2, 0x01, 0x00, 0x00, 0x00, 0x08};
  libusb_control_transfer(m_handle, 0x21, 0x20, 0, CTRL_INTERFACE, line_coding, sizeof(line_coding), 500);
  libusb_control_transfer(m_handle, 0x21, 0x22, 0x0003, CTRL_INTERFACE, nullptr, 0, 500);

  std::cout << "[USB] Successfully connected to Scoped.\n" << std::flush;
  return true;
}

void USBDevice::disconnect() {
  stopStreaming();
  if (m_handle) {
    for (int iface : {CTRL_INTERFACE, DATA_INTERFACE}) {
      libusb_release_interface(m_handle, iface);
    }
    libusb_close(m_handle);
    m_handle = nullptr;
  }
}

// Streaming
void USBDevice::startStreaming(IChannel *channel) {
  if (!m_handle || !channel)
    return;

  if (m_is_streaming) {
    stopStreaming();
  }

  std::cout << "[USB] Starting stream on EP 0x" << std::hex
            << static_cast<int>(ENDPOINT_IN) << std::dec << "...\n" << std::flush;
  m_is_streaming = true;
  m_stream_thread = std::thread(&USBDevice::streamLoop, this, channel);
}

void USBDevice::stopStreaming() {
  m_is_streaming = false;
  if (m_stream_thread.joinable()) {
    if (std::this_thread::get_id() != m_stream_thread.get_id()) {
      m_stream_thread.join();
    } else {
      m_stream_thread.detach();
    }
  }
}

void USBDevice::streamLoop(IChannel *channel) {
  uint8_t temp[16384];
  size_t total_received = 0;
  auto last_log = std::chrono::steady_clock::now();

  int consecutive_errors = 0;

  while (m_is_streaming) {
    int transferred = 0;
    int result = libusb_bulk_transfer(m_handle, ENDPOINT_IN, temp, sizeof(temp),
                                      &transferred, 200);

    if (transferred > 0) {
      consecutive_errors = 0;
      channel->pushRawBytes(temp, transferred);
      total_received += transferred;

      auto now = std::chrono::steady_clock::now();
      auto elapsed =
          std::chrono::duration_cast<std::chrono::seconds>(now - last_log);
      if (elapsed.count() >= 1) {
        std::cout << "[USB] Streaming Active! Total Received: " << (total_received / 1024) << " KB\n" << std::flush;
        last_log = now;
      }
    }

    if (result != 0) {
      if (result == LIBUSB_ERROR_TIMEOUT || result == LIBUSB_ERROR_INTERRUPTED) {
        continue;
      } else if (result == LIBUSB_ERROR_PIPE) {
        libusb_clear_halt(m_handle, ENDPOINT_IN);
        consecutive_errors++;
        std::cerr << "[USB] Endpoint stalled (LIBUSB_ERROR_PIPE), cleared halt. Count: "
                  << consecutive_errors << "\n" << std::flush;
      } else if (result == LIBUSB_ERROR_IO || result == LIBUSB_ERROR_OVERFLOW) {
        libusb_clear_halt(m_handle, ENDPOINT_IN);
        consecutive_errors++;
        std::cerr << "[USB] Transfer error (" << libusb_error_name(result)
                  << "). Cleared halt. Count: " << consecutive_errors << "\n" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
      } else {
        consecutive_errors++;
        std::cerr << "[USB] Transfer warning: " << libusb_error_name(result)
                  << " (error count: " << consecutive_errors << ")\n" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
      }

      if (consecutive_errors > 50) {
        std::cerr << "[USB] Too many consecutive transfer errors ("
                  << libusb_error_name(result) << "), stopping stream.\n" << std::flush;
        break;
      }
    }
  }

  m_is_streaming = false;
  std::cout << "[USB] Stream exited. Total: " << (total_received / 1024)
            << " KB\n" << std::flush;
}

} // namespace Scoped
