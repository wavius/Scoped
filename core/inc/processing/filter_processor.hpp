#pragma once

#include <cmath>
#include <common/channel.hpp>
#include <common/constants.hpp>
#include <complex>
#include <processing/iprocessor.hpp>
#include <string>
#include <vector>

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
  void setCenterFrequency(float center_freq) {
    m_center_frequency = center_freq;
  }
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

  // Pipeline
  float processSample(float current_input) {
    float new_output = (m_a0 * current_input) + (m_a1 * m_x1) + (m_a2 * m_x2) -
                       (m_b1 * m_y1) - (m_b2 * m_y2);

    m_x2 = m_x1;
    m_x1 = current_input;

    m_y2 = m_y1;
    m_y1 = new_output;

    return new_output;
  }

  void reset() {
    m_x1 = 0.0f;
    m_x2 = 0.0f;
    m_y1 = 0.0f;
    m_y2 = 0.0f;
  }

  void calculateCoefficients(FilterType type) {
    if (m_sample_rate <= 0.0f)
      return;

    // Convert frequency to radians
    float w0 = 2.0f * M_PI * m_cutoff / m_sample_rate;
    float cos_w0 = std::cos(w0);
    float sin_w0 = std::sin(w0);

    // Alpha determines the resonance (Q)
    float alpha = sin_w0 / (2.0f * m_quality_factor);

    float b0, b1, b2, a0, a1, a2;

    switch (type) {
    case FilterType::Lowpass:
      b0 = (1.0f - cos_w0) / 2.0f;
      b1 = 1.0f - cos_w0;
      b2 = (1.0f - cos_w0) / 2.0f;
      a0 = 1.0f + alpha;
      a1 = -2.0f * cos_w0;
      a2 = 1.0f - alpha;
      break;

    case FilterType::Highpass:
      b0 = (1.0f + cos_w0) / 2.0f;
      b1 = -(1.0f + cos_w0);
      b2 = (1.0f + cos_w0) / 2.0f;
      a0 = 1.0f + alpha;
      a1 = -2.0f * cos_w0;
      a2 = 1.0f - alpha;
      break;

    case FilterType::Bandpass:
      // Bandpass (constant 0 dB peak gain)
      b0 = alpha;
      b1 = 0.0f;
      b2 = -alpha;
      a0 = 1.0f + alpha;
      a1 = -2.0f * cos_w0;
      a2 = 1.0f - alpha;
      break;

    case FilterType::Bandstop:
      b0 = 1.0f;
      b1 = -2.0f * cos_w0;
      b2 = 1.0f;
      a0 = 1.0f + alpha;
      a1 = -2.0f * cos_w0;
      a2 = 1.0f - alpha;
      break;
    }

    // Normalize all coefficients so a0 is always 1.0
    float a0_inv = 1.0f / a0;

    m_a0 = b0 * a0_inv;
    m_a1 = b1 * a0_inv;
    m_a2 = b2 * a0_inv;

    m_b1 = a1 * a0_inv;
    m_b2 = a2 * a0_inv;
  }

  std::complex<float> getResponse(float w) const {
    std::complex<float> z_inv(std::cos(w), -std::sin(w));
    std::complex<float> z_inv2 = z_inv * z_inv;
    std::complex<float> num = m_a0 + m_a1 * z_inv + m_a2 * z_inv2;
    std::complex<float> den = 1.0f + m_b1 * z_inv + m_b2 * z_inv2;
    std::complex<float> eps(1e-8f, 0.0f);
    return num / (den + eps);
  }
};

class FilterProcessor : public IVirtualProcessor {
private:
  bool m_enabled = false;
  bool m_show_preview = false;
  std::string m_name;
  std::string m_source1_label = "CH1";

  FilterType m_filter_type = FilterType::Lowpass;
  FilterResponse m_response = FilterResponse::Basic;

  float m_cutoff = 0.0f;
  float m_cutoff2 = 0.0f;

  bool m_dirty = true;

  Biquad m_biquad1;
  Biquad m_biquad2;
  std::vector<float> m_magnitude_array;

  float m_vertical_scale = Constants::DEFAULT_VERTICAL_SCALE;
  float m_vertical_offset = Constants::DEFAULT_VERTICAL_OFFSET;
  size_t m_horizontal_scale = Constants::DEFAULT_HORIZONTAL_SCALE;
  size_t m_horizontal_offset = Constants::DEFAULT_HORIZONTAL_OFFSET;
  Color m_color = {1.0f, 1.0f, 1.0f, 1.0f};

  void calculateMagnitudeResponse(size_t points = 512) {
    m_magnitude_array.resize(points);
    for (size_t i = 0; i < points; i++) {
      float f = (Constants::ADC_SAMPLE_RATE_HZ / 2.0f) *
                (static_cast<float>(i) / static_cast<float>(points - 1));
      float w = 2.0f * M_PI * f / Constants::ADC_SAMPLE_RATE_HZ;

      std::complex<float> h1 = m_biquad1.getResponse(w);
      float mag = 0.0f;
      if (m_filter_type == FilterType::Bandpass) {
        std::complex<float> h2 = m_biquad2.getResponse(w);
        mag = std::abs(h1 * h2);
      } else if (m_filter_type == FilterType::Bandstop) {
        std::complex<float> h2 = m_biquad2.getResponse(w);
        mag = std::abs(h1 + h2);
      } else {
        mag = std::abs(h1);
      }

      float mag_db = 20.0f * std::log10(std::max(mag, 1e-5f));
      m_magnitude_array[i] = mag_db;
    }
  }

  void updateCoefficients() {
    if (!m_dirty)
      return;

    float max_cutoff = Constants::ADC_SAMPLE_RATE_HZ / 2.0f;
    m_cutoff = std::clamp(m_cutoff, 1.0f, max_cutoff - 0.1f);
    m_cutoff2 = std::clamp(m_cutoff2, 1.0f, max_cutoff - 0.1f);

    if (m_filter_type == FilterType::Bandpass || m_filter_type == FilterType::Bandstop) {
      if (m_cutoff >= m_cutoff2) {
        m_cutoff = m_cutoff2 - 1.0f;
        if (m_cutoff < 1.0f) {
          m_cutoff = 1.0f;
          m_cutoff2 = 2.0f;
        }
      }
    }

    if (m_filter_type == FilterType::Bandpass) {
      m_biquad1.setCutoff(m_cutoff);
      m_biquad1.calculateCoefficients(FilterType::Highpass);
      m_biquad2.setCutoff(m_cutoff2);
      m_biquad2.calculateCoefficients(FilterType::Lowpass);
    } else if (m_filter_type == FilterType::Bandstop) {
      m_biquad1.setCutoff(m_cutoff);
      m_biquad1.calculateCoefficients(FilterType::Lowpass);
      m_biquad2.setCutoff(m_cutoff2);
      m_biquad2.calculateCoefficients(FilterType::Highpass);
    } else {
      m_biquad1.setCutoff(m_cutoff);
      m_biquad1.calculateCoefficients(m_filter_type);
    }

    calculateMagnitudeResponse();

    m_dirty = false;
  }

public:
  explicit FilterProcessor(
      const std::string &name,
      size_t horizontal_scale = Constants::DEFAULT_HORIZONTAL_SCALE)
      : m_name(name), m_horizontal_scale(horizontal_scale) {
    updateCoefficients();
  }

  // Accessors
  std::string getName() const override { return m_name; }
  bool isEnabled() const override { return m_enabled; }
  ProcessorType getType() const override { return ProcessorType::Filter; }
  float getVerticalScale() const override { return m_vertical_scale; }
  float getVerticalOffset() const override { return m_vertical_offset; }
  size_t getHorizontalScale() const override { return m_horizontal_scale; }
  size_t getHorizontalOffset() const override { return m_horizontal_offset; }
  bool getShowPreview() const { return m_show_preview; }
  Color getColor() const override { return m_color; }

  FilterType getFilterType() const { return m_filter_type; }
  FilterResponse getFilterResponse() const { return m_response; }
  float getCutoff() const { return m_cutoff; }
  float getCutoff2() const { return m_cutoff2; }
  std::string getSource1Label() const { return m_source1_label; }

  // Setters
  void setSource1Label(const std::string &label) {
    m_source1_label = label;
    m_dirty = true;
  }
  void setEnabled(bool enabled) override { m_enabled = enabled; }
  void setShowPreview(bool show) { m_show_preview = show; }

  void setVerticalScale(float scale) override { m_vertical_scale = scale; }
  void setVerticalOffset(float offset) override { m_vertical_offset = offset; }
  void setHorizontalScale(size_t scale) override { m_horizontal_scale = scale; }
  void setHorizontalOffset(size_t offset) override {
    m_horizontal_offset = offset;
  }
  void setColor(const Color &color) override { m_color = color; }

  void setFilterType(FilterType type) {
    m_filter_type = type;
    m_dirty = true;
  }

  void setFilterResponse(FilterResponse resp) {
    m_response = resp;

    float q = 0.707f; // Butterworth
    if (m_response == FilterResponse::Bessel)
      q = 0.577f;
    else if (m_response == FilterResponse::Basic)
      q = 0.5f;
    else if (m_response == FilterResponse::Chebyshev)
      q = 1.0f;

    m_biquad1.setQualityFactor(q);
    m_biquad2.setQualityFactor(q);

    m_dirty = true;
  }
  void setCutoff(float cutoff) {
    m_cutoff = cutoff;
    m_dirty = true;
  }
  void setCutoff2(float cutoff) {
    m_cutoff2 = cutoff;
    m_dirty = true;
  }

  const std::vector<float>& getMagnitudeResponse() { 
    updateCoefficients();
    return m_magnitude_array; 
  }

  // Pipeline
  void process(const std::vector<IChannel *> &sources,
               std::vector<Trace> &traces, size_t trigger_in_frame) override {
    if (!m_enabled || sources.empty())
      return;

    const std::vector<float> *raw_frame_ptr = nullptr;
    for (auto *ch : sources) {
      if (ch->getLabel() == m_source1_label) {
        raw_frame_ptr = &ch->getRawFrame();
        break;
      }
    }

    if (!raw_frame_ptr || raw_frame_ptr->empty())
      return;
    const auto &raw_frame = *raw_frame_ptr;

    updateCoefficients();

    // Reset the biquad's internal state memory so frame discontinuities don't
    // explode the math
    m_biquad1.reset();
    m_biquad2.reset();

    std::vector<float> filtered_frame;
    filtered_frame.reserve(raw_frame.size());

    for (float sample : raw_frame) {
      if (m_filter_type == FilterType::Bandpass) {
        float temp = m_biquad1.processSample(sample);
        filtered_frame.push_back(m_biquad2.processSample(temp));
      } else if (m_filter_type == FilterType::Bandstop) {
        float temp1 = m_biquad1.processSample(sample);
        float temp2 = m_biquad2.processSample(sample);
        filtered_frame.push_back(temp1 + temp2);
      } else {
        filtered_frame.push_back(m_biquad1.processSample(sample));
      }
    }

    Trace filter_trace;
    filter_trace.name = this->m_name;
    filter_trace.domain = Domain::Time;
    filter_trace.color = m_color;

    filter_trace.data.resize(filtered_frame.size());
    for (size_t i = 0; i < filtered_frame.size(); i++) {
      filter_trace.data[i] = filtered_frame[i];
    }

    // Scale + offset
    filter_trace.vertical_scale = m_vertical_scale;
    filter_trace.vertical_offset = m_vertical_offset;
    filter_trace.horizontal_scale = m_horizontal_scale;
    filter_trace.horizontal_offset = static_cast<int>(m_horizontal_offset);

    traces.push_back(std::move(filter_trace));
  }
};

} // namespace Scoped
