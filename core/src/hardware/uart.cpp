#include <chrono>
#include <iostream>
#include <thread>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <hardware/uart.hpp>

namespace Scoped {

UARTDevice::UARTDevice(const std::string& port, int baudrate)
  : m_port(port), m_baudrate(baudrate) {
}

UARTDevice::~UARTDevice() {
  disconnect();
}

bool UARTDevice::connect() {
  std::cout << "[UART] Attempting connection to " << m_port << " at " << m_baudrate << " baud...\n";

  m_fd = ::open(m_port.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
  if (m_fd < 0) {
    std::cerr << "[UART] Failed to open " << m_port << "\n";
    return false;
  }

  // Configure UART settings
  struct termios options;
  tcgetattr(m_fd, &options);

  // Set baud rate (assuming 115200)
  speed_t speed = B115200;
  cfsetispeed(&options, speed);
  cfsetospeed(&options, speed);

  // 8N1
  options.c_cflag &= ~PARENB;
  options.c_cflag &= ~CSTOPB;
  options.c_cflag &= ~CSIZE;
  options.c_cflag |= CS8;
  
  // No hardware flow control
  options.c_cflag &= ~CRTSCTS;
  options.c_cflag |= CREAD | CLOCAL;  // turn on READ & ignore ctrl lines

  // Disable canonical mode, echo, etc.
  options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
  options.c_iflag &= ~(IXON | IXOFF | IXANY); // turn off s/w flow ctrl
  options.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // disable any special handling of rx bytes
  options.c_oflag &= ~OPOST; // prevent special interpretation of output bytes (e.g. newline chars)

  // Non-blocking read setup
  options.c_cc[VMIN] = 0;
  options.c_cc[VTIME] = 1; // 0.1 seconds timeout

  tcsetattr(m_fd, TCSANOW, &options);
  fcntl(m_fd, F_SETFL, FNDELAY);

  std::cout << "[UART] Successfully connected to " << m_port << ".\n" << std::flush;
  return true;
}

void UARTDevice::disconnect() {
  stopStreaming();
  if (m_fd >= 0) {
    ::close(m_fd);
    m_fd = -1;
  }
}

void UARTDevice::startStreaming(IChannel *channel) {
  if (m_fd < 0 || !channel)
    return;

  if (m_is_streaming) {
    stopStreaming();
  }

  std::cout << "[UART] Starting stream...\n" << std::flush;
  m_is_streaming = true;
  m_stream_thread = std::thread(&UARTDevice::streamLoop, this, channel);
}

void UARTDevice::stopStreaming() {
  m_is_streaming = false;
  if (m_stream_thread.joinable()) {
    if (std::this_thread::get_id() != m_stream_thread.get_id()) {
      m_stream_thread.join();
    } else {
      m_stream_thread.detach();
    }
  }
}

void UARTDevice::streamLoop(IChannel *channel) {
  uint8_t temp[4096];
  size_t total_received = 0;
  auto last_log = std::chrono::steady_clock::now();

  while (m_is_streaming && m_fd >= 0) {
    int bytes_read = ::read(m_fd, temp, sizeof(temp));

    if (bytes_read > 0) {
      channel->pushRawBytes(temp, bytes_read);
      total_received += bytes_read;

      auto now = std::chrono::steady_clock::now();
      auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - last_log);
      if (elapsed.count() >= 1) {
        std::cout << "[UART] Streaming Active! Total Received: " << total_received << " Bytes\n" << std::flush;
        last_log = now;
      }
    } else if (bytes_read == 0) {
      // Nothing read, just sleep a tiny bit to avoid busy-waiting
      std::this_thread::sleep_for(std::chrono::milliseconds(2));
    } else {
      if (errno == EAGAIN || errno == EWOULDBLOCK) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
      } else {
        std::cerr << "[UART] Read error, stopping stream.\n" << std::flush;
        break;
      }
    }
  }

  m_is_streaming = false;
  std::cout << "[UART] Stream exited. Total: " << total_received << " Bytes\n" << std::flush;
}

} // namespace Scoped
