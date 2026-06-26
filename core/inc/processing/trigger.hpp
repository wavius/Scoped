#pragma once

#include <chrono>
#include <common/circularbuffer.hpp>
#include <vector>

#include <common/channel.hpp>
#include <common/constants.hpp>
#include <string>

namespace Scoped {

struct TriggerParameter {
  std::string name;
  int min_val;
  int max_val;
  int current_val;
  std::vector<std::string> combo_items;
};

enum class TriggerMode { AUTO, NORMAL };

// Base trigger class
class ITrigger {
protected:
  using Clock = std::chrono::steady_clock;

  TriggerMode m_mode;
  bool m_enabled;
  size_t m_frame_width;
  Clock::time_point m_last_trigger_time;
  static constexpr std::chrono::milliseconds AUTO_TIMEOUT{100};

  virtual bool scanForTrigger(IChannel *channel, size_t &trigger_offset) = 0;
  virtual void onTriggerFired() {}

public:
  ITrigger(size_t width = 1024)
      : m_mode(TriggerMode::AUTO), m_enabled(true), m_frame_width(width),
        m_last_trigger_time(Clock::now()) {}

  virtual ~ITrigger() = default;

  // Accessors
  TriggerMode getMode() const { return m_mode; }
  bool isEnabled() const { return m_enabled; }
  size_t getFrameWidth() const { return m_frame_width; }

  virtual std::vector<float> getTriggerLevels() const = 0;
  virtual std::vector<TriggerParameter> getUIParameters() = 0;

  // Setters
  void setMode(TriggerMode mode) { m_mode = mode; }
  void setEnabled(bool enabled) { m_enabled = enabled; }
  void setFrameWidth(size_t width) { m_frame_width = width; }
  virtual void setUIParameter(const std::string &name, int val) = 0;
  virtual void clear() = 0;

  // Pipeline
  // Scans the buffer and determines if a trigger has occurred
  bool processStream(IChannel *channel, size_t &out_trigger_offset) {
    if (!channel)
      return false;
    size_t unread = channel->getUnreadSampleCount();
    if (unread < m_frame_width)
      return false;

    if (scanForTrigger(channel, out_trigger_offset)) {
      m_last_trigger_time = Clock::now();
      onTriggerFired();
      return true;
    }

    if (m_mode == TriggerMode::AUTO) {
      auto elapsed = Clock::now() - m_last_trigger_time;
      if (elapsed > AUTO_TIMEOUT) {
        // Place the crossing in the middle of available data
        out_trigger_offset = unread / 2;
        m_last_trigger_time = Clock::now();
        onTriggerFired();
        return true;
      }
    }

    return false;
  }

  // Scans a raw float buffer for a trigger crossing
  virtual bool scanRawBuffer(const std::vector<float> &buffer,
                             size_t &out_offset) = 0;

  // Checks if stale data should be discarded
  bool shouldDiscardStale(IChannel *channel, size_t &discard_amount) {
    if (!channel)
      return false;
    size_t unread = channel->getUnreadSampleCount();
    // Keep enough data for pre-trigger centering
    size_t keep = m_frame_width * 2;
    if (unread > keep) {
      discard_amount = unread - keep;
      return true;
    }
    return false;
  }
};

// Edge trigger
class EdgeTrigger : public ITrigger {
public:
  enum class EdgeDirection { RISING, FALLING };

private:
  float m_threshold;
  EdgeDirection m_direction;
  float m_prev_sample;
  float m_hysteresis_margin;

  bool checkEdge(float current) const {
    if (m_direction == EdgeDirection::RISING) {
      return m_prev_sample < (m_threshold - m_hysteresis_margin) &&
             current >= m_threshold;
    }
    return m_prev_sample > (m_threshold + m_hysteresis_margin) &&
           current <= m_threshold;
  }

protected:
  bool scanForTrigger(IChannel *channel, size_t &trigger_offset) override {
    size_t unread = channel->getUnreadSampleCount();
    size_t half = m_frame_width / 2;

    // We need at least m_frame_width samples to guarantee we can extract
    // a centered frame of that size.
    if (unread < m_frame_width)
      return false;

    // Initialize edge detector from the first sample of the safe search range
    m_prev_sample = channel->getNormalizedSample(0);

    // To ensure the crossing is centered and we have enough data to fill the
    // frame without distortion, we only search in a range that allows for
    // 'half' samples of padding on both sides.
    size_t search_start = 1;
    size_t search_end = (unread > half) ? unread - half : 0;

    if (search_start >= search_end)
      return false;

    for (size_t i = search_start; i < search_end; ++i) {
      float current = channel->getNormalizedSample(i);
      if (checkEdge(current)) {
        trigger_offset = i; // Raw crossing index
        m_prev_sample = current;
        return true;
      }
      m_prev_sample = current;
    }
    return false;
  }

  bool scanRawBuffer(const std::vector<float> &buffer,
                     size_t &out_offset) override {
    if (buffer.size() < 2)
      return false;

    float prev = buffer[0];
    for (size_t i = 1; i < buffer.size(); ++i) {
      float current = buffer[i];
      bool fired = false;
      if (m_direction == EdgeDirection::RISING) {
        fired = prev < (m_threshold - m_hysteresis_margin) &&
                current >= m_threshold;
      } else {
        fired = prev > (m_threshold + m_hysteresis_margin) &&
                current <= m_threshold;
      }

      if (fired) {
        out_offset = i;
        return true;
      }
      prev = current;
    }
    return false;
  }

public:
  // Lifecycle
  explicit EdgeTrigger(size_t width = 1024,
                       float level = Constants::ADC_MIDPOINT)
      : ITrigger(width), m_threshold(level), m_direction(EdgeDirection::RISING),
        m_prev_sample(0) {
    m_hysteresis_margin = 2.0f;
  }

  // Accessors
  float getThreshold() const { return m_threshold; }
  EdgeDirection getDirection() const { return m_direction; }
  std::vector<float> getTriggerLevels() const override { return {m_threshold}; }
  std::vector<TriggerParameter> getUIParameters() override {
    std::vector<TriggerParameter> params;

    params.push_back({"Level",
                      -static_cast<int>(Constants::ADC_MIDPOINT),
                      static_cast<int>(Constants::ADC_MIDPOINT),
                      static_cast<int>(m_threshold - Constants::ADC_MIDPOINT),
                      {}});

    std::vector<std::string> dirs = {"Rising", "Falling"};
    int dir_idx = (m_direction == EdgeDirection::RISING) ? 0 : 1;
    params.push_back({"Edge", 0, 1, dir_idx, dirs});

    params.push_back(
        {"Hysteresis", 0, 50, static_cast<int>(m_hysteresis_margin), {}});
    return params;
  }

  // Setters
  void setThreshold(float level) { m_threshold = level; }
  void setDirection(EdgeDirection dir) { m_direction = dir; }
  void setUIParameter(const std::string &name, int val) override {
    if (name == "Level") {
      m_threshold = static_cast<float>(val) + Constants::ADC_MIDPOINT;
    } else if (name == "Edge") {
      m_direction = (val == 0) ? EdgeDirection::RISING : EdgeDirection::FALLING;
    } else if (name == "Hysteresis") {
      m_hysteresis_margin = static_cast<float>(val);
    }
  }
  void clear() override { m_prev_sample = 0; }
};

} // namespace Scoped
