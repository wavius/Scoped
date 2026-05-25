#pragma once

#include <algorithm>
#include <common/channel.hpp>
#include <common/constants.hpp>
#include <processing/iprocessor.hpp>
#include <string>
#include <vector>

namespace Scoped {

class FilterProcessor : public IVirtualProcessor {
private:
  bool m_enabled = false;
  std::string m_name;

  float m_vertical_scale = 1.0f;
  float m_vertical_offset = 0.0f;
  size_t m_horizontal_scale = 1024;
  size_t m_horizontal_offset = 0;
  Color m_color = {1.0f, 1.0f, 1.0f, 1.0f};

public:
  explicit FilterProcessor(const std::string &name,
                           size_t horizontal_scale = 1024)
      : m_name(name), m_horizontal_scale(horizontal_scale) {}

  // Accessors
  std::string getName() const override { return m_name; }
  bool isEnabled() const override { return m_enabled; }
  ProcessorType getType() const override { return ProcessorType::Filter; }
  float getVerticalScale() const override { return m_vertical_scale; }
  float getVerticalOffset() const override { return m_vertical_offset; }
  size_t getHorizontalScale() const override { return m_horizontal_scale; }
  size_t getHorizontalOffset() const override { return m_horizontal_offset; }
  Color getColor() const override { return m_color; }

  // Setters
  void setEnabled(bool enabled) override { m_enabled = enabled; }
  void setVerticalScale(float scale) override { m_vertical_scale = scale; }
  void setVerticalOffset(float offset) override { m_vertical_offset = offset; }
  void setHorizontalScale(size_t scale) override { m_horizontal_scale = scale; }
  void setHorizontalOffset(size_t offset) override {
    m_horizontal_offset = offset;
  }
  void setColor(const Color &color) override { m_color = color; }

  // Pipeline
  void process(const std::vector<IChannel *> &sources,
               std::vector<Trace> &traces, size_t trigger_in_frame) override {
    if (!m_enabled || sources.empty()) {
      return;
    }

    auto *source1 = sources[0];
    if (!source1) {
      return;
    }

    const auto &frame = source1->getBuffer();
    if (frame.empty()) {
      return;
    }

    size_t size = frame.size();
    size_t half_vis = m_horizontal_scale / 2;
    int offset_val = static_cast<int>(m_horizontal_offset);

    long long center_idx =
        static_cast<long long>(trigger_in_frame) + offset_val;
    long long start_idx = center_idx - half_vis;

    size_t time_start = (start_idx < 0) ? 0 : static_cast<size_t>(start_idx);
    if (time_start >= size)
      time_start = size - 1;

    size_t time_width = std::min(m_horizontal_scale, size - time_start);

    Trace filter_trace;
    filter_trace.name = m_name + " (" + source1->getLabel() + ")";
    filter_trace.domain = Domain::Time;
    filter_trace.vertical_scale = m_vertical_scale;
    filter_trace.vertical_offset = m_vertical_offset;
    filter_trace.color = m_color;

    filter_trace.data.resize(time_width);
    for (size_t i = 0; i < time_width; ++i) {
      filter_trace.data[i] = frame[time_start + i];
    }

    traces.push_back(std::move(filter_trace));
  }
};

} // namespace Scoped
