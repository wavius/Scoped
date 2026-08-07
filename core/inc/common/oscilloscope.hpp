#pragma once

#include <common/channel.hpp>
#include <hardware/usb.hpp>
#include <hardware/uart.hpp>
#include <processing/trigger.hpp>

namespace Scoped {

enum class InputSource { USB, UART };

// Owns all channels, hardware links, and global trigger engine
class Oscilloscope {
private:
  std::vector<std::shared_ptr<IChannel>> m_hardware_channels;
  std::vector<std::shared_ptr<VirtualChannel>> m_virtual_channels;
  USBDevice m_usb;
  UARTDevice m_uart;
  InputSource m_input_source = InputSource::USB;
  std::unique_ptr<ITrigger> m_trigger;
  size_t m_trigger_source_idx = 0;
  size_t m_last_trigger_offset = 0;
  size_t m_last_frame_width = 1024;
  size_t m_max_capture_width = 8192;

public:
  // Lifecycle
  Oscilloscope() = default;

  // Accessors
  USBDevice &getUSB() { return m_usb; }
  UARTDevice &getUART() { return m_uart; }
  InputSource getInputSource() const { return m_input_source; }
  
  void setInputSource(InputSource source) {
    if (m_input_source != source) {
      if (m_usb.isStreaming()) m_usb.stopStreaming();
      if (m_uart.isStreaming()) m_uart.stopStreaming();
      m_input_source = source;
    }
  }

  ITrigger *getTrigger() { return m_trigger.get(); }
  const std::vector<std::shared_ptr<IChannel>> &getHardwareChannels() const {
    return m_hardware_channels;
  }
  std::vector<std::shared_ptr<IChannel>> &getHardwareChannels() {
    return m_hardware_channels;
  }
  const std::vector<std::shared_ptr<VirtualChannel>> &
  getVirtualChannels() const {
    return m_virtual_channels;
  }
  std::vector<std::shared_ptr<VirtualChannel>> &getVirtualChannels() {
    return m_virtual_channels;
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
  void setMaxCaptureWidth(size_t width) { m_max_capture_width = width; }

  // Configuration
  void addHardwareChannel(std::shared_ptr<IChannel> channel) {
    m_hardware_channels.push_back(std::move(channel));
  }
  void addVirtualChannel(std::shared_ptr<VirtualChannel> channel) {
    m_virtual_channels.push_back(std::move(channel));
  }

  // Core
  void forceReprocess() {
    for (auto &ch : m_hardware_channels) {
      ch->reprocessLastFrame();
    }
    for (auto &ch : m_virtual_channels) {
      ch->reprocessLastFrame();
    }
  }

  void update() {
    if (m_hardware_channels.empty())
      return;

    if (m_trigger && !m_trigger->isEnabled()) {
      for (auto &ch : m_hardware_channels) {
        ch->reprocessLastFrame();
      }
      for (auto &ch : m_virtual_channels) {
        ch->reprocessLastFrame();
      }
      return;
    }

    const size_t max_req = m_max_capture_width;

    if (m_trigger) {
      m_trigger->setFrameWidth(max_req);
    }

    size_t src_idx = m_trigger_source_idx < m_hardware_channels.size()
                         ? m_trigger_source_idx
                         : 0;
    auto &source_channel = m_hardware_channels[src_idx];
    if (!source_channel)
      return;

    size_t unread = source_channel->getUnreadSampleCount();
    if (unread < max_req)
      return;

    // Keep only the most recent buffer window to prevent backlog accumulation and buffer wrap-around
    if (unread > max_req * 2) {
      size_t discard = unread - (max_req * 2);
      for (auto &ch : m_hardware_channels) {
        size_t ch_unread = ch->getUnreadSampleCount();
        ch->consumeBuffer(std::min(ch_unread, discard));
      }
    }

    size_t trigger_idx = 0;
    float trigger_subsample_offset = 0.0f;
    bool triggered = m_trigger &&
                     m_trigger->processStream(source_channel.get(), trigger_idx, trigger_subsample_offset);

    if (triggered) {
      m_last_trigger_offset = trigger_idx;

      for (auto &ch : m_hardware_channels) {
        bool any_proc_enabled = false;
        for (auto *proc : ch->getProcessors()) {
          if (proc->isEnabled())
            any_proc_enabled = true;
        }

        if (ch->isEnabled() || any_proc_enabled) {
          ch->extractAndProcessFrame(trigger_idx, max_req, trigger_subsample_offset);
        } else {
          ch->clearTraces();
        }

        // Consume up to the trigger point minus half the max capture width.
        // This retains 'max_req / 2' pre-trigger samples for the next frame,
        // while ensuring the next scan starts exactly after this trigger to maintain phase.
        size_t half_req = max_req / 2;
        size_t consume_amount = 0;
        if (trigger_idx >= half_req) {
          consume_amount = std::min(trigger_idx - half_req + 1, ch->getUnreadSampleCount());
        }
        ch->consumeBuffer(consume_amount);
      }

      for (auto &ch : m_virtual_channels) {
        bool any_proc_enabled = false;
        for (auto *proc : ch->getProcessors()) {
          if (proc->isEnabled())
            any_proc_enabled = true;
        }
        if (ch->isEnabled() || any_proc_enabled) {
          ch->extractAndProcessFrame(trigger_idx, max_req, trigger_subsample_offset);
        } else {
          ch->clearTraces();
        }
      }
    } else {
      // Drain unread samples when untriggered to prevent buffer backlog & USB stream timeout
      for (auto &ch : m_hardware_channels) {
        size_t ch_unread = ch->getUnreadSampleCount();
        if (ch_unread > max_req) {
          ch->consumeBuffer(ch_unread - max_req);
        }
      }
    }
  }
};

} // namespace Scoped
