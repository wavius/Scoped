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

  // Phase accumulator for test signals shared across all instances of this buffer type
  inline static double s_fundamental_phase{0.0};

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
    size_t write_idx = m_write_idx.load(std::memory_order_relaxed);
    for (size_t i = 0; i < length; ++i) {
      m_buffer[write_idx] = data[i];
      write_idx = (write_idx + 1) % m_capacity;
    }
    m_write_idx.store(write_idx, std::memory_order_release);
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
  void fillTestSquareWave(float frequency = 4.0f) {
    size_t count = 1024;
    
    // Scale fundamental phase to local frequency phase
    double phase = s_fundamental_phase * static_cast<double>(frequency);
    double step = (1.0 / 1024.0) * static_cast<double>(frequency);
    size_t write_idx = m_write_idx.load(std::memory_order_relaxed);

    for (size_t i = 0; i < count; i++) {
      T val;
      bool high = (phase - std::floor(phase)) < 0.5;

      if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>) {
        val = high ? static_cast<T>(1.0) : static_cast<T>(-1.0);
      } else {
        val = high ? static_cast<T>(255) : static_cast<T>(0);
      }

      m_buffer[write_idx] = val;
      write_idx = (write_idx + 1) % m_capacity;
      phase += step;
    }

    m_write_idx.store(write_idx, std::memory_order_release);
    
    // Update master clock
    s_fundamental_phase += (1.0 / 1024.0);
    if (s_fundamental_phase >= 1024.0) {
      s_fundamental_phase = std::fmod(s_fundamental_phase, 1024.0);
    }
  }

  void fillTestSineWave(float frequency = 5.00f) {
    constexpr size_t chunk_size = 1024;
    
    // Scale fundamental phase to local frequency phase
    double phase = s_fundamental_phase * static_cast<double>(frequency) * 2.0 * M_PI;
    double step = (2.0 * M_PI / 1024.0) * static_cast<double>(frequency);
    size_t write_idx = m_write_idx.load(std::memory_order_relaxed);

    for (size_t i = 0; i < chunk_size; ++i) {
      float val = std::sinf(static_cast<float>(phase));
      
      T sample;
      if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>) {
        sample = static_cast<T>(val);
      } else {
        sample = static_cast<T>((val * 127.5f) + 127.5f);
      }

      m_buffer[write_idx] = sample;
      write_idx = (write_idx + 1) % m_capacity;
      phase += step;
    }

    m_write_idx.store(write_idx, std::memory_order_release);

    // Update master clock (normalized 0.0 to 1.0)
    s_fundamental_phase += (1.0 / 1024.0);
    if (s_fundamental_phase >= 1024.0) {
      s_fundamental_phase = std::fmod(s_fundamental_phase, 1024.0);
    }
  }
};

} // namespace Scoped
