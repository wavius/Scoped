#pragma once

#include <algorithm>
#include <circularbuffer.hpp>
#include <cstdint>
#include <memory>
#include <processor.hpp>
#include <string>
#include <type_traits>
#include <vector>

#include "trace.hpp"

namespace Scoped {

class IChannel {
public:
  virtual ~IChannel() = default;

  virtual const std::string &getLabel() const = 0;
  virtual const std::vector<Trace> &getTraces() const = 0;

  virtual bool hasNewFrame() const = 0;
  virtual void clearNewFrame() = 0;

  virtual float getVerticalScale() const = 0;
  virtual void setVerticalScale(float scale) = 0;
  virtual size_t getVisibleSamples() const = 0;
  virtual void setVisibleSamples(size_t n) = 0;

  // Hardware interaction methods
  virtual float getNormalizedSample(size_t index_offset) const = 0;
  virtual size_t getUnreadSampleCount() const = 0;
  virtual void extractAndProcessFrame(size_t trigger_offset,
                                      size_t frame_width) = 0;
  virtual void consumeBuffer(size_t amount) = 0;

  virtual void pushRawBytes(const uint8_t *data, size_t size) = 0;
  virtual void clearBuffer() = 0;

  virtual bool isHardwareChannel() const = 0;
};

/// Base for processors operating across multiple channels.
class IVirtualProcessor {
public:
  virtual ~IVirtualProcessor() = default;
  virtual void process(const std::vector<IChannel *> &sources,
                       std::vector<Trace> &traces) = 0;
};

/// Encapsulates a channel that pulls data from other channels' traces.
class VirtualChannel : public IChannel {
private:
  std::string m_label;
  std::vector<IChannel *> m_sources;
  std::vector<std::unique_ptr<IVirtualProcessor>> m_processors;
  std::vector<Trace> m_traces;
  bool m_has_new_frame = false;
  float m_vertical_scale = 1.0f;
  size_t m_visible_samples;

public:
  VirtualChannel(const std::string &label, size_t visible)
      : m_label(label), m_visible_samples(visible) {}

  void addSource(IChannel *source) { m_sources.push_back(source); }

  void addProcessor(std::unique_ptr<IVirtualProcessor> proc) {
    m_processors.push_back(std::move(proc));
  }

  // IChannel impl
  const std::string &getLabel() const override { return m_label; }
  const std::vector<Trace> &getTraces() const override { return m_traces; }
  bool hasNewFrame() const override { return m_has_new_frame; }
  void clearNewFrame() override { m_has_new_frame = false; }

  float getVerticalScale() const override { return m_vertical_scale; }
  void setVerticalScale(float scale) override { m_vertical_scale = scale; }
  size_t getVisibleSamples() const override { return m_visible_samples; }
  void setVisibleSamples(size_t n) override { m_visible_samples = n; }

  float getNormalizedSample(size_t /*index_offset*/) const override {
    return 0.0f;
  }
  size_t getUnreadSampleCount() const override { return 0; }
  bool isHardwareChannel() const override { return false; }

  void pushRawBytes(const uint8_t * /*data*/, size_t /*size*/) override {}
  void clearBuffer() override {}

  void extractAndProcessFrame(size_t /*trigger_offset*/,
                              size_t /*frame_width*/) override {
    m_traces.clear();
    for (auto &proc : m_processors) {
      proc->process(m_sources, m_traces);
    }
    m_has_new_frame = true;
  }

  void consumeBuffer(size_t /*amount*/) override {}
};

/// Encapsulates the acquisition and processing pipeline for a single hardware
/// channel.
template <typename HardwareT> class Channel : public IChannel {
private:
  std::string m_label;
  CircularBuffer<HardwareT> m_buffer;
  std::vector<std::unique_ptr<IProcessor<HardwareT>>> m_processors;

  float m_vertical_scale = 1.0f;
  float m_vertical_offset = 0.0f;
  size_t m_visible_samples;

  std::vector<HardwareT> m_raw_frame;
  std::vector<Trace> m_traces;
  bool m_has_new_frame = false;

public:
  // ---------------------------------------------------------------------------
  // Lifecycle
  // ---------------------------------------------------------------------------

  Channel(const std::string &label, size_t buffer_size, size_t visible)
      : m_label(label), m_buffer(buffer_size), m_visible_samples(visible) {}

  // ---------------------------------------------------------------------------
  // Pipeline
  // ---------------------------------------------------------------------------

  void extractAndProcessFrame(size_t trigger_offset,
                              size_t frame_width) override {
    m_raw_frame.resize(frame_width);
    size_t capacity = m_buffer.getCapacity();
    size_t start = (m_buffer.getReadIdx() + trigger_offset) % capacity;

    if (start + frame_width <= capacity) {
      std::copy(m_buffer.getRawData() + start,
                m_buffer.getRawData() + start + frame_width,
                m_raw_frame.begin());
    } else {
      size_t first_len = capacity - start;
      size_t second_len = frame_width - first_len;
      std::copy(m_buffer.getRawData() + start,
                m_buffer.getRawData() + start + first_len, m_raw_frame.begin());
      std::copy(m_buffer.getRawData(), m_buffer.getRawData() + second_len,
                m_raw_frame.begin() + first_len);
    }

    m_traces.clear();
    Trace base_trace;
    base_trace.name = m_label + " Time";
    base_trace.domain = Domain::Time;
    base_trace.scale = m_vertical_scale;
    base_trace.offset = m_vertical_offset;
    base_trace.data.resize(frame_width);

    for (size_t i = 0; i < frame_width; ++i) {
      base_trace.data[i] = static_cast<float>(m_raw_frame[i]);
    }

    m_traces.push_back(std::move(base_trace));

    for (auto &proc : m_processors) {
      proc->process(m_raw_frame, m_traces);
    }

    m_has_new_frame = true;
  }

  void consumeBuffer(size_t amount) override {
    m_buffer.advanceReadIdx(amount);
  }

  // ---------------------------------------------------------------------------
  // Getters & Setters
  // ---------------------------------------------------------------------------

  bool hasNewFrame() const override { return m_has_new_frame; }
  void clearNewFrame() override { m_has_new_frame = false; }

  void addProcessor(std::unique_ptr<IProcessor<HardwareT>> proc) {
    m_processors.push_back(std::move(proc));
  }
  void clearProcessors() { m_processors.clear(); }

  const std::string &getLabel() const override { return m_label; }

  CircularBuffer<HardwareT> &getBuffer() { return m_buffer; }

  float getNormalizedSample(size_t index_offset) const override {
    if (index_offset >= m_buffer.getUnreadCount())
      return 0.0f;
    return static_cast<float>(m_buffer.peekAhead(index_offset));
  }

  size_t getUnreadSampleCount() const override {
    return m_buffer.getUnreadCount();
  }

  bool isHardwareChannel() const override { return true; }

  void pushRawBytes(const uint8_t *data, size_t size) override {
    // Very simplistic casting. In a real scenario, handle endianness and types.
    if constexpr (std::is_same_v<HardwareT, uint8_t>) {
      m_buffer.pushBlock(data, size);
    } else {
      // Hardware conversion logic
      for (size_t i = 0; i < size; ++i) {
        m_buffer.pushSample(static_cast<HardwareT>(data[i]));
      }
    }
  }

  void clearBuffer() override { m_buffer.clear(); }

  float getVerticalScale() const override { return m_vertical_scale; }
  void setVerticalScale(float scale) override { m_vertical_scale = scale; }
  size_t getVisibleSamples() const override { return m_visible_samples; }
  void setVisibleSamples(size_t n) override { m_visible_samples = n; }

  const std::vector<Trace> &getTraces() const override { return m_traces; }
  const std::vector<HardwareT> &getRawFrame() const { return m_raw_frame; }
};

} // namespace Scoped
