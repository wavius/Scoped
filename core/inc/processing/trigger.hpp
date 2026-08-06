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
  float min_val;
  float max_val;
  float current_val;
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
  static constexpr std::chrono::milliseconds AUTO_TIMEOUT{50};

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
  virtual void setUIParameter(const std::string &name, float val) = 0;
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
  mutable bool m_armed = false;

  bool checkEdge(float current) const {
    if (m_direction == EdgeDirection::RISING) {
      if (current < (m_threshold - m_hysteresis_margin)) {
        m_armed = true;
      } else if (m_armed && current >= m_threshold) {
        m_armed = false;
        return true;
      }
    } else {
      if (current > (m_threshold + m_hysteresis_margin)) {
        m_armed = true;
      } else if (m_armed && current <= m_threshold) {
        m_armed = false;
        return true;
      }
    }
    return false;
  }

protected:
  bool scanForTrigger(IChannel *channel, size_t &trigger_offset) override {
    size_t unread = channel->getUnreadSampleCount();
    size_t half = m_frame_width / 2;
    if (unread < m_frame_width)
      return false;

    m_armed = false;
    float raw_prev = channel->getNormalizedSample(half > 0 ? half - 1 : 0);
    m_prev_sample = Constants::ADC_VMIN + (raw_prev / Constants::ADC_LEVELS) * (Constants::ADC_VMAX - Constants::ADC_VMIN);

    size_t search_end = (unread > half) ? unread - half : 0;
    for (size_t i = half; i < search_end; ++i) {
      float raw_curr = channel->getNormalizedSample(i);
      float current = Constants::ADC_VMIN + (raw_curr / Constants::ADC_LEVELS) * (Constants::ADC_VMAX - Constants::ADC_VMIN);
      if (checkEdge(current)) {
        trigger_offset = i;
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

    m_armed = false;
    m_prev_sample = buffer[0];
    for (size_t i = 1; i < buffer.size(); ++i) {
      float current = buffer[i];
      if (checkEdge(current)) {
        out_offset = i;
        return true;
      }
      m_prev_sample = current;
    }
    return false;
  }

public:
  // Lifecycle
  explicit EdgeTrigger(size_t width = 1024,
                       float level = Constants::ADC_MIDPOINT_V) // default 0.0 V
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

    params.push_back({"Voltage Level",
                      Constants::ADC_VMIN,
                      Constants::ADC_VMAX,
                      m_threshold,
                      {}});

    std::vector<std::string> dirs = {"Rising", "Falling"};
    float dir_idx = (m_direction == EdgeDirection::RISING) ? 0.0f : 1.0f;
    params.push_back({"Edge", 0.0f, 1.0f, dir_idx, dirs});

    params.push_back(
        {"Hysteresis", 0.0f, 50.0f, m_hysteresis_margin, {}});
    return params;
  }

  // Setters
  void setThreshold(float level) { m_threshold = level; }
  void setDirection(EdgeDirection dir) { m_direction = dir; }
  void setUIParameter(const std::string &name, float val) override {
    if (name == "Voltage Level") {
      m_threshold = val;
    } else if (name == "Edge") {
      m_direction = (static_cast<int>(val) == 0) ? EdgeDirection::RISING : EdgeDirection::FALLING;
    } else if (name == "Hysteresis") {
      m_hysteresis_margin = val;
    }
  }
  void clear() override { m_prev_sample = 0; }
};

} // namespace Scoped
