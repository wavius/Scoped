#pragma once

#include <atomic>
#include <common/channel.hpp>
#include <libusb-1.0/libusb.h>
#include <thread>

namespace Scoped {

// USB CDC bulk-transfer interface for the iCESugar-Pro FPGA.
class USBDevice {
private:
  static constexpr uint16_t VENDOR_ID = 0x1d50;
  static constexpr uint16_t PRODUCT_ID = 0x6149;
  static constexpr uint8_t ENDPOINT_IN = 0x82;
  static constexpr int CTRL_INTERFACE = 0;
  static constexpr int DATA_INTERFACE = 1;

  libusb_context *m_context = nullptr;
  libusb_device_handle *m_handle = nullptr;

  std::thread m_stream_thread;
  std::atomic<bool> m_is_streaming{false};

  void streamLoop(IChannel *channel);

public:
  // Lifecycle
  USBDevice();
  ~USBDevice();

  // Accessors
  bool isConnected() const { return m_handle != nullptr; }
  bool isStreaming() const { return m_is_streaming.load(); }

  // Connection
  bool connect();
  void disconnect();

  // Streaming
  void startStreaming(IChannel *channel);
  void stopStreaming();
};

} // namespace Scoped
