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
  size_t m_last_trigger_offset = 0;
  size_t m_last_frame_width = 1024;
  size_t m_max_capture_width = 16384;

public:
  // Lifecycle
  Oscilloscope() = default;

  // Accessors
  USBDevice &getUSB() { return m_usb; }
  ITrigger *getTrigger() { return m_trigger.get(); }
  const std::vector<std::shared_ptr<IChannel>> &getChannels() const {
    return m_channels;
  }
  std::vector<std::shared_ptr<IChannel>> &getChannels() {
    return m_channels;
  }
  size_t getTriggerSourceIndex() const { return m_trigger_source_idx; }
  size_t getMaxCaptureWidth() const { return m_max_capture_width; }

  // Setters
  void setTrigger(std::unique_ptr<ITrigger> trigger) {
    m_trigger = std::move(trigger);
  }
  void setTriggerSource(size_t channel_index) {
    m_trigger_source_idx = channel_index;
  }
  void setMaxCaptureWidth(size_t width) {
    m_max_capture_width = width;
  }

  // Configuration
  void addChannel(std::shared_ptr<IChannel> channel) {
    m_channels.push_back(std::move(channel));
  }

  // Core
  void forceReprocess() {
    if (m_trigger && m_trigger_source_idx < m_channels.size()) {
      auto &source = m_channels[m_trigger_source_idx];
      size_t new_in_frame_idx = 0;
      if (m_trigger->scanRawBuffer(source->getRawFrame(), new_in_frame_idx)) {
        for (auto &ch : m_channels) {
          ch->updateTriggerPoint(new_in_frame_idx);
        }
      }
    }
    for (auto &ch : m_channels) {
      ch->reprocessLastFrame();
    }
  }

  void update() {
    if (m_channels.empty())
      return;

    if (m_trigger && !m_trigger->isEnabled()) {
      // Re-process last frame using current UI settings
      for (auto &ch : m_channels) {
        ch->reprocessLastFrame();
      }
      return;
    }

    // Always capture the absolute maximum window to allow full resizing while stopped.
    const size_t max_req = m_max_capture_width; 

    if (m_trigger) {
      m_trigger->setFrameWidth(max_req);
    }

    size_t src_idx =
        m_trigger_source_idx < m_channels.size() ? m_trigger_source_idx : 0;
    auto &source_channel = m_channels[src_idx];

    // trigger_offset is the raw crossing index in the buffer
    size_t trigger_idx = 0;
    if (m_trigger &&
        m_trigger->processStream(source_channel.get(), trigger_idx)) {
      m_last_trigger_offset = trigger_idx;

      // Calculate a common consume amount for all hardware channels to stay phase-locked.
      size_t step = 1024; 
      size_t common_consume = trigger_idx + step;

      // Pass 1: Extract hardware frames
      for (auto &ch : m_channels) {
        if (ch->isHardwareChannel()) {
          size_t unread = ch->getUnreadSampleCount();
          
          bool any_proc_enabled = false;
          for (auto* proc : ch->getProcessors()) {
            if (proc->isEnabled()) any_proc_enabled = true;
          }

          if (ch->isEnabled() || any_proc_enabled) {
            ch->extractAndProcessFrame(trigger_idx, max_req);
          } else {
            ch->clearTraces();
          }

          // Apply uniform consumption
          ch->consumeBuffer(std::min(unread, common_consume));
        }
      }

      // Pass 2: Extract virtual frames
      for (auto &ch : m_channels) {
        if (!ch->isHardwareChannel()) {
          bool any_proc_enabled = false;
          for (auto* proc : ch->getProcessors()) {
            if (proc->isEnabled()) any_proc_enabled = true;
          }
          if (ch->isEnabled() || any_proc_enabled) {
            ch->extractAndProcessFrame(trigger_idx, max_req);
          } else {
            ch->clearTraces();
          }
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
