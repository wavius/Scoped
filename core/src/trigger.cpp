#include <SDL.h>
#include <trigger.hpp>

namespace Scoped {

Trigger::Trigger(size_t width, uint8_t level)
    : m_threshold(level), m_type(TriggerType::RISING_EDGE),
      m_mode(TriggerMode::AUTO), m_prev_sample(0), m_frame_width(width),
      m_output(width, 0), m_last_trigger_time(0) {}

void Trigger::setThreshold(uint8_t level) { m_threshold = level; }

void Trigger::setType(TriggerType type) { m_type = type; }

TriggerType Trigger::getType() const { return m_type; }

void Trigger::setMode(TriggerMode mode) { m_mode = mode; }

const std::vector<uint8_t> &Trigger::getOutput() const { return m_output; }

TriggerMode Trigger::getMode() const { return m_mode; }

size_t Trigger::getFrameWidth() const { return m_frame_width; }

uint8_t Trigger::getThreshold() const { return m_threshold; }

void Trigger::clear() { m_prev_sample = 0; }

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
    std::copy(buffer.getRawData() + start,
              buffer.getRawData() + start + m_frame_width, m_output.begin());
  } else {
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
  if (unread < m_frame_width)
    return false;

  for (size_t i = 0; i < unread - m_frame_width; ++i) {
    uint8_t current = buffer.peekAhead(i);

    if (checkEdge(current)) {
      extractFrame(buffer, i);
      m_last_trigger_time = SDL_GetTicks();
      return true;
    }
    m_prev_sample = current;
  }

  if (m_mode == TriggerMode::AUTO) {
    uint32_t now = SDL_GetTicks();
    if (now - m_last_trigger_time > AUTO_TIMEOUT_MS) {
      extractFrame(buffer, 0);
      m_last_trigger_time = now;
      return true;
    }
  }

  if (unread > m_frame_width) {
    buffer.advanceReadIdx(unread - m_frame_width);
  }

  return false;
}

} // namespace Scoped
