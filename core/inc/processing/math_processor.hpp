#pragma once

#include <algorithm>
#include <common/channel.hpp>
#include <common/constants.hpp>
#include <limits>
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
  float m_vertical_scale = 1.0f;
  float m_vertical_offset = 0.0f;
  size_t m_horizontal_scale = 1024;
  size_t m_horizontal_offset = 0;
  Color m_color = {1.0f, 1.0f, 1.0f, 1.0f};

  // Differentiate pre-smoothing: half-width of the box filter (samples)
  size_t m_diff_smooth_radius = 16;

  // Assume m_math_output is resized already
  // m_math_output = frame1 + frame2 - Constants::ADC_MIDPOINT
  void performAdd(const std::vector<float> &frame1,
                  const std::vector<float> &frame2) {
    for (size_t i = 0; i < m_math_output.size(); i++) {
      m_math_output[i] = frame1[i] + frame2[i] - Constants::ADC_MIDPOINT;
    }
  }

  // m_math_output = frame1 - frame2 + Constants::ADC_MIDPOINT
  void performSubtract(const std::vector<float> &frame1,
                       const std::vector<float> &frame2) {
    for (size_t i = 0; i < m_math_output.size(); i++) {
      m_math_output[i] = frame1[i] - frame2[i] + Constants::ADC_MIDPOINT;
    }
  }

  // m_math_output = Constants::ADC_LEVELS - frame1
  void performInvert(const std::vector<float> &frame1) {
    for (size_t i = 0; i < m_math_output.size(); i++) {
      m_math_output[i] = Constants::ADC_LEVELS - frame1[i];
    }
  }

  // m_math_output = frame1 * frame2 (normalized around AC baseline)
  void performMultiply(const std::vector<float> &frame1,
                       const std::vector<float> &frame2) {
    for (size_t i = 0; i < m_math_output.size(); i++) {
      float val1 = (frame1[i] - Constants::ADC_MIDPOINT) / Constants::ADC_MIDPOINT;
      float val2 = (frame2[i] - Constants::ADC_MIDPOINT) / Constants::ADC_MIDPOINT;
      m_math_output[i] = (val1 * val2) * Constants::ADC_MIDPOINT + Constants::ADC_MIDPOINT;
    }
  }

  // Trapezoidal integration on DC-removed signal, auto-scaled to [0, Constants::ADC_MAX_VAL]
  // Amplitude is normalized per frame
  void performIntegrate(const std::vector<float> &frame1) {
    size_t n = m_math_output.size();

    float mean = 0.0f;
    for (size_t i = 0; i < n; i++)
      mean += frame1[i];
    mean /= static_cast<float>(n);

    float sum = 0.0f;
    float min_val = 0.0f, max_val = 0.0f;
    m_math_output[0] = 0.0f;
    for (size_t i = 1; i < n; i++) {
      sum += (frame1[i - 1] - mean + frame1[i] - mean) * 0.5f;
      m_math_output[i] = sum;
      if (sum < min_val)
        min_val = sum;
      if (sum > max_val)
        max_val = sum;
    }

    float range = max_val - min_val;
    if (range < 1e-6f) {
      std::fill(m_math_output.begin(), m_math_output.end(), Constants::ADC_MIDPOINT);
      return;
    }
    for (size_t i = 0; i < n; i++)
      m_math_output[i] = ((m_math_output[i] - min_val) / range) * Constants::ADC_MAX_VAL;
  }

  // Box-filter pre-smooth + central difference, centered at Constants::ADC_MIDPOINT
  // Pre-smoothing with radius m_diff_smooth_radius reduces quantization noise
  // before differentiating
  void performDifferentiate(const std::vector<float> &frame1) {
    size_t n = m_math_output.size();
    if (n < 3)
      return;

    size_t r = m_diff_smooth_radius;

    // Prefix sum for O(n) sliding window average
    std::vector<float> prefix(n + 1, 0.0f);
    for (size_t i = 0; i < n; i++)
      prefix[i + 1] = prefix[i] + frame1[i];

    std::vector<float> smoothed(n);
    for (size_t i = 0; i < n; i++) {
      size_t lo = (i >= r) ? i - r : 0;
      size_t hi = std::min(n - 1, i + r);
      smoothed[i] =
          (prefix[hi + 1] - prefix[lo]) / static_cast<float>(hi - lo + 1);
    }

    for (size_t i = 1; i < n - 1; i++)
      m_math_output[i] = (smoothed[i + 1] - smoothed[i - 1]) * 0.5f + Constants::ADC_MIDPOINT;

    m_math_output[0] = m_math_output[1];
    m_math_output[n - 1] = m_math_output[n - 2];
  }

public:
  // Lifecycle
  explicit MathProcessor(const std::string &name,
                         size_t horizontal_scale = 1024)
      : m_name(name), m_horizontal_scale(horizontal_scale) {}

  // Accessors
  std::string getName() const override { return m_name; }
  bool isEnabled() const override { return m_enabled; }
  ProcessorType getType() const override { return ProcessorType::Math; }
  float getVerticalScale() const override { return m_vertical_scale; }
  float getVerticalOffset() const override { return m_vertical_offset; }
  size_t getHorizontalScale() const override { return m_horizontal_scale; }
  size_t getHorizontalOffset() const override { return m_horizontal_offset; }
  Color getColor() const override { return m_color; }

  MathOperation getOperation() const { return m_operation; }
  const std::string &getSource1Label() const { return m_source1_label; }
  const std::string &getSource2Label() const { return m_source2_label; }
  size_t getDiffSmoothRadius() const { return m_diff_smooth_radius; }

  // Setters
  void setEnabled(bool enabled) override { m_enabled = enabled; }
  void setVerticalScale(float scale) override { m_vertical_scale = scale; }
  void setVerticalOffset(float offset) override { m_vertical_offset = offset; }
  void setHorizontalScale(size_t scale) override { m_horizontal_scale = scale; }
  void setHorizontalOffset(size_t offset) override {
    m_horizontal_offset = offset;
  }
  void setColor(const Color &color) override { m_color = color; }

  void setOperation(MathOperation op) { m_operation = op; }
  void setSource1Label(const std::string &label) { m_source1_label = label; }
  void setSource2Label(const std::string &label) { m_source2_label = label; }
  void setDiffSmoothRadius(size_t r) { m_diff_smooth_radius = r; }

  // Pipeline
  void process(const std::vector<IChannel *> &sources,
               std::vector<Trace> &traces, size_t trigger_in_frame) override {

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
                     m_operation != MathOperation::DIFFERENTIATE && !source2)) {
      return;
    }

    const auto &frame1 = source1->getRawFrame();
    const auto &frame2 =
        source2 ? source2->getRawFrame() : std::vector<float>();

    if (frame1.empty() ||
        (m_operation != MathOperation::INVERT &&
         m_operation != MathOperation::INTEGRATE &&
         m_operation != MathOperation::DIFFERENTIATE && frame2.empty())) {
      return;
    }

    // Compute size based on raw frame lengths
    size_t size = frame1.size();
    if (m_operation != MathOperation::INVERT &&
        m_operation != MathOperation::INTEGRATE &&
        m_operation != MathOperation::DIFFERENTIATE && frame2.size() < size) {
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

    size_t half_vis = m_horizontal_scale / 2;
    int offset_val = static_cast<int>(m_horizontal_offset);

    long long center_idx =
        static_cast<long long>(trigger_in_frame) + offset_val;
    long long start_idx = center_idx - half_vis;

    size_t time_start = (start_idx < 0) ? 0 : static_cast<size_t>(start_idx);
    if (time_start >= size)
      time_start = size - 1;

    size_t time_width = std::min(m_horizontal_scale, size - time_start);

    Trace math_trace;
    math_trace.name =
        m_name + " (" + source1->getLabel() +
        (m_operation == MathOperation::INVERT      ? " Inverted"
         : m_operation == MathOperation::INTEGRATE ? " Integrated"
         : m_operation == MathOperation::DIFFERENTIATE
             ? " Diff"
             : " " +
                   std::string(m_operation == MathOperation::ADD        ? "+"
                               : m_operation == MathOperation::SUBTRACT ? "-"
                                                                        : "*") +
                   " " + source2->getLabel()) +
        ")";
    math_trace.domain = Domain::Time;
    math_trace.vertical_scale = m_vertical_scale;
    math_trace.vertical_offset = m_vertical_offset;
    math_trace.color = m_color;

    math_trace.data.resize(time_width);
    for (size_t i = 0; i < time_width; ++i) {
      math_trace.data[i] = m_math_output[time_start + i];
    }

    traces.push_back(std::move(math_trace));
  }
};

} // namespace Scoped
