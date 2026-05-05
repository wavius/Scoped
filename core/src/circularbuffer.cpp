#include <circularbuffer.hpp>
#include <cmath>

namespace Scoped {

CircularBuffer::CircularBuffer(size_t capacity) : m_capacity(capacity) {
  m_buffer.resize(m_capacity, 0);
}

void CircularBuffer::pushSample(uint8_t sample) {
  m_buffer[m_write_idx] = sample;
  m_write_idx = (m_write_idx + 1) % m_capacity;
}

void CircularBuffer::pushBlock(const uint8_t *data, size_t length) {
  for (size_t i = 0; i < length; ++i) {
    m_buffer[m_write_idx] = data[i];
    m_write_idx = (m_write_idx + 1) % m_capacity;
  }
}

size_t CircularBuffer::getUnreadCount() const {
  size_t w = m_write_idx.load();
  size_t r = m_read_idx.load();
  return (w >= r) ? (w - r) : (m_capacity - r + w);
}

uint8_t CircularBuffer::peekAhead(size_t offset) const {
  return m_buffer[(m_read_idx.load() + offset) % m_capacity];
}

void CircularBuffer::advanceReadIdx(size_t amount) {
  m_read_idx = (m_read_idx.load() + amount) % m_capacity;
}

void CircularBuffer::fillTestSquareWave() {
  for (size_t i = 0; i < m_capacity; i++) {
    m_buffer[i] = ((i % 8) < 4) ? 255 : 0;
  }
}

void CircularBuffer::fillTestSineWave() {
  static float phase = 0.0f;

  constexpr float frequency = 5.23f;
  constexpr size_t chunk_size = 1024;
  constexpr float phase_step = (2.0f * M_PI * frequency) / chunk_size;

  for (size_t i = 0; i < chunk_size; ++i) {
    float val = std::sin(phase);
    uint8_t sample = static_cast<uint8_t>((val * 127.5f) + 127.5f);
    pushSample(sample);
    phase += phase_step;
  }

  // Wrap phase periodically to prevent floating-point precision loss
  if (phase > 2.0f * M_PI * 100.0f) {
    phase = std::fmod(phase, 2.0f * M_PI);
  }
}

} // namespace Scoped
