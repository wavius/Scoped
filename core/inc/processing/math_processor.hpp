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
  size_t m_horizontal_scale = 1024;
  size_t m_horizontal_offset = 0;

  // Assume m_math_output is resized already
  // m_math_output = frame1 + frame2 - 128
  void performAdd(const std::vector<float> &frame1,
                  const std::vector<float> &frame2) {
    for (size_t i = 0; i < m_math_output.size(); i++) {
      m_math_output[i] = frame1[i] + frame2[i] - 128.0f;
    }
  }

  // m_math_output = frame1 - frame2 + 128
  void performSubtract(const std::vector<float> &frame1,
                       const std::vector<float> &frame2) {
    for (size_t i = 0; i < m_math_output.size(); i++) {
      m_math_output[i] = frame1[i] - frame2[i] + 128.0f;
    }
  }

  // m_math_output = 256 - frame1
  void performInvert(const std::vector<float> &frame1) {
    for (size_t i = 0; i < m_math_output.size(); i++) {
      m_math_output[i] = 256.0f - frame1[i];
    }
  }

  // m_math_output = frame1 * frame2 (normalized around AC baseline)
  void performMultiply(const std::vector<float> &frame1,
                       const std::vector<float> &frame2) {
    for (size_t i = 0; i < m_math_output.size(); i++) {
      float val1 = (frame1[i] - 128.0f) / 128.0f;
      float val2 = (frame2[i] - 128.0f) / 128.0f;
      m_math_output[i] = (val1 * val2) * 128.0f + 128.0f;
    }
  }

  // m_math_output = integrate(frame1)
  void performIntegrate(const std::vector<float> &frame1) {
    float sum = 0.0f;
    float dt = 0.01f;
    for (size_t i = 0; i < m_math_output.size(); i++) {
      sum += (frame1[i] - 128.0f) * dt;
      m_math_output[i] = sum + 128.0f;
    }
  }

  // m_math_output = diff(frame1)
  void performDifferentiate(const std::vector<float> &frame1) {
    if (m_math_output.empty()) return;
    m_math_output[0] = 128.0f;
    float scale = 5.0f;
    for (size_t i = 1; i < m_math_output.size(); i++) {
      m_math_output[i] = (frame1[i] - frame1[i-1]) * scale + 128.0f;
    }
  }

public:
  // Lifecycle
  explicit MathProcessor(size_t horizontal_scale = 1024)
      : m_horizontal_scale(horizontal_scale) {}

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

    // Check if source channels were resolved
    if (!source1 || (m_operation != MathOperation::INVERT && 
                     m_operation != MathOperation::INTEGRATE && 
                     m_operation != MathOperation::DIFFERENTIATE && 
                     !source2)) {
      return;
    }

    const auto &frame1 = source1->getRawFrame();
    const auto &frame2 = source2 ? source2->getRawFrame() : std::vector<float>();

    if (frame1.empty() || (m_operation != MathOperation::INVERT && 
                           m_operation != MathOperation::INTEGRATE && 
                           m_operation != MathOperation::DIFFERENTIATE && 
                           frame2.empty())) {
      return;
    }

    // Compute size based on raw frame lengths
    size_t size = frame1.size();
    if (m_operation != MathOperation::INVERT && 
        m_operation != MathOperation::INTEGRATE && 
        m_operation != MathOperation::DIFFERENTIATE && 
        frame2.size() < size) {
      size = frame2.size();
    }

    // resize output buffer
    if (m_math_output.size() != size) {
      m_math_output.resize(size);
    }

    switch (m_operation) {
    case (MathOperation::ADD):
      performAdd(frame1, frame2);
      break;
    case (MathOperation::SUBTRACT):
      performSubtract(frame1, frame2);
      break;
    case (MathOperation::MULTIPLY):
      performMultiply(frame1, frame2);
      break;
    case (MathOperation::INVERT):
      performInvert(frame1);
      break;
    case (MathOperation::INTEGRATE):
      performIntegrate(frame1);
      break;
    case (MathOperation::DIFFERENTIATE):
      performDifferentiate(frame1);
      break;
    default:
      break;
    }

    // Extract the visible subset of the math trace using source1's trigger positioning
    size_t trigger_in_frame = source1->getLastTriggerInFrame();
    size_t half_vis = m_horizontal_scale / 2;
    int offset_val = static_cast<int>(m_horizontal_offset); 
    
    long long center_idx = static_cast<long long>(trigger_in_frame) + offset_val;
    long long start_idx = center_idx - half_vis;
    
    size_t time_start = (start_idx < 0) ? 0 : static_cast<size_t>(start_idx);
    if (time_start >= size) time_start = size - 1;
    
    size_t time_width = std::min(m_horizontal_scale, size - time_start);

    Trace math_trace;
    math_trace.name = m_name + " (" + source1->getLabel() + 
                     (m_operation == MathOperation::INVERT ? " Inverted" : 
                      m_operation == MathOperation::INTEGRATE ? " Integrated" :
                      m_operation == MathOperation::DIFFERENTIATE ? " Diff" :
                      " " + std::string(m_operation == MathOperation::ADD ? "+" : 
                                       m_operation == MathOperation::SUBTRACT ? "-" : "*") 
                      + " " + source2->getLabel()) + ")";
    math_trace.domain = Domain::Time;
    math_trace.vertical_scale = m_vertical_scale;
    math_trace.vertical_offset = m_vertical_offset;
    
    math_trace.data.resize(time_width);
    for (size_t i = 0; i < time_width; ++i) {
      math_trace.data[i] = m_math_output[time_start + i];
    }

    traces.push_back(std::move(math_trace));
  }
};

} // namespace Scoped
