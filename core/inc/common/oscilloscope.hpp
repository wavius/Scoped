#pragma once

#include <common/channel.hpp>
#include <processing/trigger.hpp>
#include <hardware/usb.hpp>

namespace Scoped {

// The central hub of the application. Owns all channels, hardware links, and
// the global trigger engine.
class Oscilloscope {
private:
  std::vector<std::shared_ptr<IChannel>> m_channels;
  USBDevice m_usb;
  std::unique_ptr<ITrigger> m_trigger;
  size_t m_trigger_source_idx = 0;

public:
  // Lifecycle
  Oscilloscope() = default;

  // Configuration
  void addChannel(std::shared_ptr<IChannel> channel) {
    m_channels.push_back(std::move(channel));
  }
  void setTrigger(std::unique_ptr<ITrigger> trigger) {
    m_trigger = std::move(trigger);
  }
  void setTriggerSource(size_t channel_index) {
    m_trigger_source_idx = channel_index;
  }

  // Accessors
  USBDevice &getUSB() { return m_usb; }
  ITrigger *getTrigger() { return m_trigger.get(); }
  const std::vector<std::shared_ptr<IChannel>> &getChannels() const {
    return m_channels;
  }

  // Core
  void update() {
    if (m_channels.empty() || (m_trigger && !m_trigger->isEnabled()))
      return;

    size_t src_idx =
        m_trigger_source_idx < m_channels.size() ? m_trigger_source_idx : 0;
    auto &source_channel = m_channels[src_idx];

    size_t trigger_offset = 0;
    if (m_trigger &&
        m_trigger->processStream(source_channel.get(), trigger_offset)) {
      size_t frame_width = m_trigger->getFrameWidth();

      // Pass 1: Extract hardware frames
      for (auto &ch : m_channels) {
        if (ch->isHardwareChannel()) {
          if (ch->getUnreadSampleCount() >= frame_width) {
            if (ch->isEnabled()) {
              ch->extractAndProcessFrame(trigger_offset, frame_width);
            }
            ch->consumeBuffer(trigger_offset + frame_width);
          }
        }
      }

      // Pass 2: Extract virtual frames
      for (auto &ch : m_channels) {
        if (!ch->isHardwareChannel() && ch->isEnabled()) {
          ch->extractAndProcessFrame(trigger_offset, frame_width);
        }
      }
    } else if (m_trigger) {
      size_t discard_amount = 0;
      if (m_trigger->shouldDiscardStale(source_channel.get(), discard_amount)) {
        for (auto &ch : m_channels) {
          if (ch->isHardwareChannel()) {
            ch->consumeBuffer(discard_amount);
          }
        }
      }
    }
  }
};

} // namespace Scoped
