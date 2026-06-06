#pragma once

#include <cmath>
#include <common/channel.hpp>
#include <common/constants.hpp>
#include <processing/iprocessor.hpp>
#include <string>
#include <vector>

namespace Scoped {

class MeasurementProcessor : public IVirtualProcessor {
private:
  bool m_enabled = false;
  std::string m_name;
  std::string m_source_label = "CH1";

  float m_vertical_scale = Constants::DEFAULT_VERTICAL_SCALE;
  float m_vertical_offset = Constants::DEFAULT_VERTICAL_OFFSET;
  size_t m_horizontal_scale = Constants::DEFAULT_HORIZONTAL_SCALE;
  size_t m_horizontal_offset = Constants::DEFAULT_HORIZONTAL_OFFSET;
  Color m_color = {1.0f, 1.0f, 1.0f, 1.0f};

  // Measured values
  float m_v_pp = 0.0f;
  float m_v_rms = 0.0f;
  float m_v_avg = 0.0f;
  float m_v_min = 0.0f;
  float m_v_max = 0.0f;
  float m_freq = 0.0f;
  float m_period = 0.0f;

public:
  explicit MeasurementProcessor(const std::string &name)
      : m_name(name) {}

  // Accessors
  std::string getName() const override { return m_name; }
  bool isEnabled() const override { return m_enabled; }
  ProcessorType getType() const override { return ProcessorType::Measurement; }
  float getVerticalScale() const override { return m_vertical_scale; }
  float getVerticalOffset() const override { return m_vertical_offset; }
  size_t getHorizontalScale() const override { return m_horizontal_scale; }
  size_t getHorizontalOffset() const override { return m_horizontal_offset; }
  Color getColor() const override { return m_color; }

  std::string getSourceLabel() const { return m_source_label; }

  // Setters
  void setEnabled(bool enabled) override { m_enabled = enabled; }
  void setVerticalScale(float scale) override { m_vertical_scale = scale; }
  void setVerticalOffset(float offset) override { m_vertical_offset = offset; }
  void setHorizontalScale(size_t scale) override { m_horizontal_scale = scale; }
  void setHorizontalOffset(size_t offset) override { m_horizontal_offset = offset; }
  void setColor(const Color &color) override { m_color = color; }

  void setSourceLabel(const std::string &label) { m_source_label = label; }

  // Accessors for measured values
  float getVpp() const { return m_v_pp; }
  float getVrms() const { return m_v_rms; }
  float getVavg() const { return m_v_avg; }
  float getVmin() const { return m_v_min; }
  float getVmax() const { return m_v_max; }
  float getFreq() const { return m_freq; }
  float getPeriod() const { return m_period; }

  // Pipeline
  void process(const std::vector<IChannel *> &sources,
               std::vector<Trace> &traces, size_t trigger_in_frame) override {
    if (!m_enabled || sources.empty())
      return;

    const std::vector<float> *raw_frame_ptr = nullptr;
    for (auto *ch : sources) {
      if (ch->getLabel() == m_source_label) {
        raw_frame_ptr = &ch->getRawFrame();
        break;
      }
    }

    if (!raw_frame_ptr || raw_frame_ptr->empty())
      return;

    const auto &raw_frame = *raw_frame_ptr;

    // TODO: Implement measurement logic here (Vpp, Vrms, etc.)
  }

  void calculateVpp(const std::vector<float> &frame) {
    if (frame.empty()) {
      m_v_pp = 0.0f;
      return;
    }

    float min_val = frame[0];
    float max_val = frame[0];

    for (size_t i = 1; i < frame.size(); ++i) {
      if (frame[i] < min_val)
        min_val = frame[i];
      if (frame[i] > max_val)
        max_val = frame[i];
    }

    m_v_pp = max_val - min_val;
  }

  void calculateVRMS(const std::vector<float> &frame) {
    if (frame.empty()) {
      m_v_rms = 0.0f;
      return;
    }

    float sum_sq = 0.0f;
    for (size_t i = 0; i < frame.size(); ++i) {
      sum_sq += frame[i] * frame[i];
    }

    m_v_rms = std::sqrt(sum_sq / frame.size());
  }

  void calculateVavg(const std::vector<float> &frame) {
    if (frame.empty()) {
      m_v_avg = 0.0f;
      return;
    }

    float sum = 0.0f;
    for (size_t i = 0; i < frame.size(); ++i) {
      sum += frame[i];
    }

    m_v_avg = sum / frame.size();
  }

  void calculateVmin(const std::vector<float> &frame) {
    if (frame.empty()) {
      m_v_min = 0.0f;
      return;
    }

    float min_val = frame[0];
    for (size_t i = 1; i < frame.size(); ++i) {
      if (frame[i] < min_val)
        min_val = frame[i];
    }

    m_v_min = min_val;
  }

  void calculateVmax(const std::vector<float> &frame) {
    if (frame.empty()) {
      m_v_max = 0.0f;
      return;
    }

    float max_val = frame[0];
    for (size_t i = 1; i < frame.size(); ++i) {
      if (frame[i] > max_val)
        max_val = frame[i];
    }

    m_v_max = max_val;
  }

  // TODO: FFT implementation
  void calculateFreqAndPeriod(const std::vector<float> &frame) {
    if (frame.empty()) {
      m_freq = 0.0f;
      m_period = 0.0f;
      return;
    }

  }
};

} // namespace Scoped
