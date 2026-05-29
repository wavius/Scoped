#pragma once

#include <algorithm>
#include <common/channel.hpp>
#include <common/constants.hpp>
#include <processing/iprocessor.hpp>
#include <string>
#include <vector>
#include <common/constants.hpp>

namespace Scoped {

enum class FilterType { Lowpass, Highpass, Bandpass, Bandstop };
enum class FilterResponse { Butterworth, Chebyshev, Bessel, Basic };

class Biquad {
private:
  // Coefficients
  float m_a0 = 0.0f, m_a1 = 0.0f, m_a2 = 0.0f;
  float m_b1 = 0.0f, m_b2 = 0.0f;

  // Filter state
  float m_x1 = 0.0f, m_x2 = 0.0f;
  float m_y1 = 0.0f, m_y2 = 0.0f;

  // Config
  float m_cutoff = 0.0f;
  float m_center_frequency = 0.0f;
  float m_quality_factor = 0.707f;
  float m_gain = 1.0f;
  float m_order = 1.0f;
  float m_sample_rate = Constants::ADC_SAMPLE_RATE_HZ;

public:
  Biquad() = default;

  // Setters
  void setCutoff(float cutoff) { m_cutoff = cutoff; }
  void setCenterFrequency(float center_freq) { m_center_frequency = center_freq; }
  void setQualityFactor(float q) { m_quality_factor = q; }
  void setGain(float gain) { m_gain = gain; }
  void setOrder(float order) { m_order = order; }
  void setSampleRate(float sample_rate) { m_sample_rate = sample_rate; }

  // Accessors
  float getCutoff() const { return m_cutoff; }
  float getCenterFrequency() const { return m_center_frequency; }
  float getQualityFactor() const { return m_quality_factor; }
  float getGain() const { return m_gain; }
  float getOrder() const { return m_order; }
  float getSampleRate() const { return m_sample_rate; }
};

class FilterProcessor : public IProcessor {
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
  void process(const std::vector<float> &raw_frame,
               std::vector<Trace> &traces) override {}
};

} // namespace Scoped
