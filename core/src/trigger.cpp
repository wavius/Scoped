#include <trigger.hpp>

namespace Scoped {

Trigger::Trigger(size_t width, uint8_t level)
    : m_threshold(level), m_type(TriggerType::RISING_EDGE), m_prev_sample(0),
      m_frame_width(width), m_output(width, 0) {}

void Trigger::setThreshold(uint8_t level) { m_threshold = level; }

void Trigger::setType(TriggerType type) { m_type = type; }

const std::vector<uint8_t> &Trigger::getOutput() const { return m_output; }

bool Trigger::checkEdge(uint8_t current) const {
  if (m_type == TriggerType::RISING_EDGE) {
    return m_prev_sample < (m_threshold - HYSTERESIS_MARGIN) &&
           current >= m_threshold;
  }
  return m_prev_sample > (m_threshold + HYSTERESIS_MARGIN) &&
         current <= m_threshold;
}

void Trigger::extractFrame(CircularBuffer &buffer, size_t trigger_offset) {
  size_t buf_capacity = buffer.getCapacity();
  size_t start = (buffer.getReadIdx() + trigger_offset) % buf_capacity;

  if (start + m_frame_width <= buf_capacity) {
    // Contiguous: single copy
    std::copy(buffer.getRawData() + start,
              buffer.getRawData() + start + m_frame_width, m_output.begin());
  } else {
    // Wraps around the end of the ring buffer
    size_t first_len = buf_capacity - start;
    size_t second_len = m_frame_width - first_len;
    std::copy(buffer.getRawData() + start,
              buffer.getRawData() + start + first_len, m_output.begin());
    std::copy(buffer.getRawData(), buffer.getRawData() + second_len,
              m_output.begin() + first_len);
  }

  buffer.advanceReadIdx(trigger_offset + m_frame_width);
  m_prev_sample = m_output.back();
}

bool Trigger::processStream(CircularBuffer &buffer) {
  size_t unread = buffer.getUnreadCount();
  if (unread == 0)
    return false;

  for (size_t i = 0; i < unread; ++i) {
    uint8_t current = buffer.peekAhead(i);

    if (checkEdge(current)) {
      if (unread - i >= m_frame_width) {
        extractFrame(buffer, i);
        return true;
      }
      // Trigger found but frame incomplete — advance past scanned data
      buffer.advanceReadIdx(i);
      return false;
    }

    m_prev_sample = current;
  }

  // No trigger found — discard old data, keep one frame's worth for continuity
  if (unread > m_frame_width) {
    buffer.advanceReadIdx(unread - m_frame_width);
  }

  return false;
}

} // namespace Scoped
