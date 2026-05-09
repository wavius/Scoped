#pragma once

#include <atomic>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <vector>

namespace Scoped {

// Lock-free single-producer single-consumer circular buffer.
template <typename T> class CircularBuffer {
private:
  std::vector<T> m_buffer;
  size_t m_capacity;
  std::atomic<size_t> m_read_idx{0};
  std::atomic<size_t> m_write_idx{0};
  float m_test_phase = 0.0f;

public:
  // Lifecycle
  explicit CircularBuffer(size_t capacity = 8192) : m_capacity(capacity) {
    m_buffer.resize(m_capacity, T());
  }

  // Write Operations
  void pushSample(T sample) {
    m_buffer[m_write_idx] = sample;
    m_write_idx = (m_write_idx + 1) % m_capacity;
  }

  void pushBlock(const T *data, size_t length) {
    for (size_t i = 0; i < length; ++i) {
      m_buffer[m_write_idx] = data[i];
      m_write_idx = (m_write_idx + 1) % m_capacity;
    }
  }

  // Read Operations
  size_t getUnreadCount() const {
    size_t w = m_write_idx.load();
    size_t r = m_read_idx.load();
    return (w >= r) ? (w - r) : (m_capacity - r + w);
  }

  T peekAhead(size_t offset) const {
    return m_buffer[(m_read_idx.load() + offset) % m_capacity];
  }

  void advanceReadIdx(size_t amount) {
    m_read_idx = (m_read_idx.load() + amount) % m_capacity;
  }

  // Accessors
  const T *getRawData() const { return m_buffer.data(); }
  size_t getCapacity() const { return m_capacity; }
  size_t getReadIdx() const { return m_read_idx.load(); }

  // Setters
  void clear() {
    m_read_idx.store(0);
    m_write_idx.store(0);
  }

  // Test Signal Generators
  void fillTestSquareWave() {
    size_t count = 1024;
    constexpr size_t frequency = 6;
    size_t x = std::pow(2, frequency);
    for (size_t i = 0; i < count; i++) {
      T val;
      if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>) {
        val = (i % (x * 2)) < x ? static_cast<T>(1.0) : static_cast<T>(-1.0);
      } else {
        val = (i % (x * 2)) < x ? static_cast<T>(255) : static_cast<T>(0);
      }
      pushSample(val);
      pushSample(val);
    }
  }

  void fillTestSineWave() {
    constexpr float frequency = 5.00f;
    constexpr size_t chunk_size = 1024;
    constexpr float phase_step = (2.0f * M_PI * frequency) / chunk_size;

    for (size_t i = 0; i < chunk_size; ++i) {
      float val = std::sin(m_test_phase);
      if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>) {
        pushSample(static_cast<T>(val));
      } else {
        pushSample(static_cast<T>((val * 127.5f) + 127.5f));
      }
      m_test_phase += phase_step;
    }

    if (m_test_phase > 2.0f * M_PI * 100.0f) {
      m_test_phase = std::fmod(m_test_phase, 2.0f * M_PI);
    }
  }
};

} // namespace Scoped
