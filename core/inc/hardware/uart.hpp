#pragma once

#include <atomic>
#include <common/channel.hpp>
#include <common/constants.hpp>
#include <termios.h>
#include <thread>
#include <string>

namespace Scoped {

// UART serial device for the iCELink debugger connection
class UARTDevice {
private:
  int m_fd = -1;
  std::thread m_stream_thread;
  std::atomic<bool> m_is_streaming{false};
  std::string m_port;
  speed_t m_baudrate;

  void streamLoop(IChannel *channel);

public:
  // Lifecycle
  UARTDevice(const std::string& port = "/dev/ttyACM0", speed_t baudrate = Constants::UART_BAUD_RATE);
  ~UARTDevice();

  // Accessors
  bool isConnected() const { return m_fd >= 0; }
  bool isStreaming() const { return m_is_streaming.load(); }

  // Connection
  bool connect();
  void disconnect();

  // Streaming
  void startStreaming(IChannel *channel);
  void stopStreaming();
};

} // namespace Scoped
