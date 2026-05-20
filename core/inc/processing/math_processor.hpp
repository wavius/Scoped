#pragma once

#include <common/channel.hpp>
#include <processing/iprocessor.hpp>
#include <processing/window.hpp>
#include <vector>

namespace Scoped {

enum class MathOperation {
  ADD,
  SUBTRACT,
  MULTIPLY,
  INVERT,
  INTEGRATE,
  DIFFERENTIATE
};

class MathProcessor : public IVirtualProcessor {
private:
  bool m_enabled = false;
  std::string m_name = "Math";
  MathOperation m_operation = MathOperation::ADD;

  std::vector<float> m_math_output;
  std::string m_source1_label = "CH1";
  std::string m_source2_label = "CH2";

  // Plotting vars
  float m_vertical_scale = 0.9f;
  float m_vertical_offset = 0.0f;
  size_t m_horizontal_scale = 0;
  size_t m_horizontal_offset = 0;

  // Assume m_math_output is resized already
  // m_math_output = frame1 + frame2
  void performAdd(const std::vector<float> &frame1,
                  const std::vector<float> &frame2) {
    for (size_t i = 0; i < m_math_output.size(); i++) {
      m_math_output[i] = frame1[i] + frame2[i];
    }
  }

  // m_math_output = frame1 - frame2
  void performSubtract(const std::vector<float> &frame1,
                       const std::vector<float> &frame2) {
    for (size_t i = 0; i < m_math_output.size(); i++) {
      m_math_output[i] = frame1[i] - frame2[i];
    }
  }

  // m_math_output = -frame1
  void performInvert(const std::vector<float> &frame1) {
    for (size_t i = 0; i < m_math_output.size(); i++) {
      m_math_output[i] = -frame1[i];
    }
  }

public:
  // Lifecycle
  MathProcessor() = default;

  // Accessors
  std::string getName() const override { return m_name; }
  bool isEnabled() const override { return m_enabled; }
  float getVerticalScale() const override { return m_vertical_scale; }
  float getVerticalOffset() const override { return m_vertical_offset; }
  size_t getHorizontalScale() const override { return m_horizontal_scale; }
  size_t getHorizontalOffset() const override { return m_horizontal_offset; }

  MathOperation getOperation() const { return m_operation; }
  const std::string &getSource1Label() const { return m_source1_label; }
  const std::string &getSource2Label() const { return m_source2_label; }

  // Setters
  void setEnabled(bool enabled) override { m_enabled = enabled; }
  void setVerticalScale(float scale) override { m_vertical_scale = scale; }
  void setVerticalOffset(float offset) override { m_vertical_offset = offset; }
  void setHorizontalScale(size_t scale) override { m_horizontal_scale = scale; }
  void setHorizontalOffset(size_t offset) override {
    m_horizontal_offset = offset;
  }

  void setOperation(MathOperation op) { m_operation = op; }
  void setSource1Label(const std::string &label) { m_source1_label = label; }
  void setSource2Label(const std::string &label) { m_source2_label = label; }

  // Pipeline
  void process(const std::vector<IChannel *> &sources,
               std::vector<Trace> &traces) override {

    IChannel *source1 = nullptr;
    IChannel *source2 = nullptr;

    for (size_t i = 0; i < sources.size(); i++) {
      if (sources[i]->getLabel() == m_source1_label) {
        source1 = sources[i];
      } else if (sources[i]->getLabel() == m_source2_label) {
        source2 = sources[i];
      }
    }

    // if labels don't match
    if (!source1 || (m_operation != MathOperation::INVERT && !source2)) {
      return;
    }

    const auto &frame1 = source1->getRawFrame();
    const auto &frame2 = source2->getRawFrame();

    // should never happen but just in case
    if (frame1.size() != frame2.size())
      return;

    // resize output buffer
    if (m_math_output.size() != frame1.size()) {
      m_math_output.resize(frame1.size());
    }

    switch (m_operation) {
    case (MathOperation::ADD):
      performAdd(frame1, frame2);
      break;
    case (MathOperation::SUBTRACT):
      performSubtract(frame1, frame2);
      break;
    case (MathOperation::INVERT):
      performInvert(frame1);
    // TODO: add remaining cases
    default:
      break;
    }

    Trace math_trace;
    math_trace.name = this->m_name; // TODO: Add channel to name
    math_trace.domain = Domain::Time;

    math_trace.data.resize(m_math_output.size());

    // Find magnitude and normalize

    // Scale + offset
    math_trace.vertical_scale = m_vertical_scale;
    math_trace.vertical_offset = m_vertical_offset;

    traces.push_back(std::move(math_trace));
  }
};

} // namespace Scoped
