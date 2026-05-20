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

    // Check if source channels were resolved
    if (!source1 || (m_operation != MathOperation::INVERT && 
                     m_operation != MathOperation::INTEGRATE && 
                     m_operation != MathOperation::DIFFERENTIATE && 
                     !source2)) {
      return;
    }

    // Find the time domain trace of source1
    const Trace *trace1 = nullptr;
    for (const auto &t : source1->getTraces()) {
      if (t.domain == Domain::Time) {
        trace1 = &t;
        break;
      }
    }

    // Find the time domain trace of source2 (if required)
    const Trace *trace2 = nullptr;
    if (m_operation != MathOperation::INVERT && 
        m_operation != MathOperation::INTEGRATE && 
        m_operation != MathOperation::DIFFERENTIATE && 
        source2) {
      for (const auto &t : source2->getTraces()) {
        if (t.domain == Domain::Time) {
          trace2 = &t;
          break;
        }
      }
    }

    if (!trace1 || (m_operation != MathOperation::INVERT && 
                    m_operation != MathOperation::INTEGRATE && 
                    m_operation != MathOperation::DIFFERENTIATE && 
                    !trace2)) {
      return;
    }

    // Compute size based on source trace lengths
    size_t size = trace1->data.size();
    if (trace2 && trace2->data.size() < size) {
      size = trace2->data.size();
    }

    // resize output buffer
    if (m_math_output.size() != size) {
      m_math_output.resize(size);
    }

    switch (m_operation) {
    case (MathOperation::ADD):
      performAdd(trace1->data, trace2->data);
      break;
    case (MathOperation::SUBTRACT):
      performSubtract(trace1->data, trace2->data);
      break;
    case (MathOperation::MULTIPLY):
      performMultiply(trace1->data, trace2->data);
      break;
    case (MathOperation::INVERT):
      performInvert(trace1->data);
      break;
    case (MathOperation::INTEGRATE):
      performIntegrate(trace1->data);
      break;
    case (MathOperation::DIFFERENTIATE):
      performDifferentiate(trace1->data);
      break;
    default:
      break;
    }

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
    math_trace.data = m_math_output; // Copy data!

    traces.push_back(std::move(math_trace));
  }
};

} // namespace Scoped
