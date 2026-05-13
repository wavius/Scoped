#pragma once

#include <chrono>
#include <common/circularbuffer.hpp>
#include <vector>

#include <common/channel.hpp>
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

// Base class for all trigger strategies.
class ITrigger {
protected:
  using Clock = std::chrono::steady_clock;

  TriggerMode m_mode;
  size_t m_frame_width;
  Clock::time_point m_last_trigger_time;
  static constexpr std::chrono::milliseconds AUTO_TIMEOUT{100};

  virtual bool scanForTrigger(IChannel *channel, size_t &trigger_offset) = 0;
  virtual void onTriggerFired() {}

public:
  // Lifecycle
  explicit ITrigger(size_t width)
      : m_mode(TriggerMode::AUTO), m_frame_width(width),
        m_last_trigger_time(Clock::now()) {}

  virtual ~ITrigger() = default;

  // Accessors
  TriggerMode getMode() const { return m_mode; }
  size_t getFrameWidth() const { return m_frame_width; }

  virtual std::vector<float> getTriggerLevels() const = 0;
  virtual std::vector<TriggerParameter> getUIParameters() = 0;

  // Setters
  void setMode(TriggerMode mode) { m_mode = mode; }
  virtual void setUIParameter(const std::string &name, int val) = 0;
  virtual void clear() = 0;

  // Pipeline
  // Scans the buffer and determines if a trigger has occurred.
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
        out_trigger_offset = 0;
        m_last_trigger_time = Clock::now();
        onTriggerFired();
        return true;
      }
    }

    return false;
  }

  // Checks if stale data should be discarded.
  bool shouldDiscardStale(IChannel *channel, size_t &discard_amount) {
    if (!channel)
      return false;
    size_t unread = channel->getUnreadSampleCount();
    if (unread > m_frame_width) {
      discard_amount = unread - m_frame_width;
      return true;
    }
    return false;
  }
};

// Edge trigger: fires when a sample crosses the threshold with hysteresis.
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
    for (size_t i = 0; i < unread - this->m_frame_width; ++i) {
      float current = channel->getNormalizedSample(i);
      if (checkEdge(current)) {
        trigger_offset = i;
        m_prev_sample = current;
        return true;
      }
      m_prev_sample = current;
    }
    return false;
  }

public:
  // Lifecycle
  explicit EdgeTrigger(size_t width = 1024, float level = 128.0f)
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

    // TODO: fix min_val and max_val hardcoded for 8 bit ADC
    params.push_back(
        {"Level", -128, 128, static_cast<int>(m_threshold) - 128, {}});

    std::vector<std::string> dirs = {"Rising", "Falling"};
    int dir_idx = (m_direction == EdgeDirection::RISING) ? 0 : 1;
    params.push_back({"Edge", 0, 1, dir_idx, dirs});
    return params;
  }

  // Setters
  void setThreshold(float level) { m_threshold = level; }
  void setDirection(EdgeDirection dir) { m_direction = dir; }
  void setUIParameter(const std::string &name, int val) override {
    if (name == "Level") {
      m_threshold =
          static_cast<float>(val + 128); // Internally, trigger ranges from 0 to
                                         // 255 but -128 to 128 in UI
    } else if (name == "Edge") {
      m_direction = (val == 0) ? EdgeDirection::RISING : EdgeDirection::FALLING;
    }
  }
  void clear() override { m_prev_sample = 0; }
};

} // namespace Scoped
