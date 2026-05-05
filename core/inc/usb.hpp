#pragma once

#include <atomic>
#include <circularbuffer.hpp>
#include <libusb-1.0/libusb.h>
#include <thread>

// iCESugar-Pro v1.3
#define VENDOR_ID 0x1d50
#define PRODUCT_ID 0x602b
#define ENDPOINT_IN 0x84
#define DATA_INTERFACE 2

namespace Scoped {

class USBDevice {
private:
  uint16_t m_vendor_id = VENDOR_ID;
  uint16_t m_product_id = PRODUCT_ID;

  uint16_t m_endpoint = ENDPOINT_IN;
  uint16_t m_data_interface = DATA_INTERFACE;

  libusb_context *m_context = nullptr;
  libusb_device_handle *m_handle = nullptr;

  std::thread m_stream_thread;
  std::atomic<bool> m_is_streaming{false};

  void streamLoop(CircularBuffer &buffer);

public:
  USBDevice();
  ~USBDevice();

  bool connect();
  void disconnect();
  bool isConnected() const { return m_handle != nullptr; }

  void startStreaming(CircularBuffer &buffer);
  void stopStreaming();
};

} // namespace Scoped
