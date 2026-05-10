#pragma once

#include "trace.hpp"
#include <cmath>
#include <complex>
#include <cstdint>
#include <limits>
#include <vector>

namespace Scoped {

class IChannel;

class IProcessorControl {
public:
  // Lifecycle
  virtual ~IProcessorControl() = default;

  // Accessors
  virtual std::string getName() const = 0;
  virtual bool isEnabled() const = 0;
  virtual float getScale() const = 0;
  virtual bool getIsModeLinear() const = 0;

  // Setters
  virtual void setEnabled(bool enabled) = 0;
  virtual void setScale(float scale) = 0;
  virtual void setIsModeLinear(bool mode) = 0;
};

// Base for processors operating across multiple channels.
class IVirtualProcessor : public IProcessorControl {
public:
  // Lifecycle
  virtual ~IVirtualProcessor() = default;

  // Pipeline
  virtual void process(const std::vector<IChannel *> &sources,
                       std::vector<Trace> &traces) = 0;
};

// Base class for signal processing stages.
//
// Processors transform a triggered frame in-place and are chained
// between the trigger output and the display engine.
template <typename HardwareT> class IProcessor : public IProcessorControl {
public:
  // Lifecycle
  virtual ~IProcessor() = default;

  // Pipeline
  // Applies the processing operation and generates/mutates traces.
  virtual void process(const std::vector<HardwareT> &raw_frame,
                       std::vector<Trace> &traces) = 0;
};

// Class to apply FFT to channel
template <typename HardwareT>
class FFTProcessor : public IProcessor<HardwareT> {
private:
  bool m_enabled;
  std::string m_name = "FFT";
  std::vector<std::complex<float>> m_fft_output;
  std::vector<float> m_window_lut;

  static constexpr std::complex<float> I_COMPLEX{0.0f, 1.0f};
  static constexpr float PI = 3.141592653589f;

  // Plotting vars
  bool m_isLinearMode = false; // Linear = true, dB = false
  float m_scale = 0.9f;
  size_t m_max_height;
  static constexpr float m_offset = 0.0f;
  static constexpr float EPSILON = 1e-8f;

public:
  // Lifecycle
  FFTProcessor(size_t display_height) { m_max_height = display_height; }

  // Accessors
  std::string getName() const override { return m_name; }
  bool isEnabled() const override { return m_enabled; }
  float getScale() const override { return m_scale; }
  bool getIsModeLinear() const override { return m_isLinearMode; }

  // Setters
  void setEnabled(bool enabled) override { m_enabled = enabled; }
  void setScale(float scale) override { m_scale = scale; }
  void setIsModeLinear(bool mode) override { m_isLinearMode = mode; }

  // Pipeline
  void process(const std::vector<HardwareT> &raw_frame,
               std::vector<Trace> &traces) override {

    size_t frame_size = raw_frame.size();
    m_fft_output.resize(frame_size);

    std::vector<float> centered_frame;
    centered_frame.resize(frame_size);
    prepareWindow(frame_size);
    float mean = calculateMean(raw_frame);
    for (size_t i = 0; i < frame_size; i++) {
      centered_frame[i] =
          (static_cast<float>(raw_frame[i]) - mean) * m_window_lut[i];
    }

    calculateFFTRecursive(centered_frame, m_fft_output);

    Trace fft_trace;
    fft_trace.name = this->m_name; // TODO: Add channel to name
    fft_trace.domain = Domain::Frequency;

    fft_trace.data.resize(frame_size / 2);

    // Find magnitude and normalize
    float max = std::numeric_limits<float>::lowest();
    float min = std::numeric_limits<float>::max();
    for (size_t i = 0; i < frame_size / 2; i++) {
      float mag = std::abs(m_fft_output[i]) / frame_size * 2.0f;
      if (m_isLinearMode) {
        fft_trace.data[i] = mag;
      } else {
        fft_trace.data[i] = 20.0f * std::log10(mag + EPSILON);
      }
      max = fft_trace.data[i] > max ? fft_trace.data[i] : max;
      min = fft_trace.data[i] < min ? fft_trace.data[i] : min;
    }

    // Scale + offset
    float range =
        (max - min) > 0.001f ? max - min : 1.0f; // Prevent division by 0
    fft_trace.scale = (static_cast<float>(m_max_height) / range) * m_scale;
    fft_trace.offset = -min * fft_trace.scale;

    traces.push_back(std::move(fft_trace));
  }

  // Logic
  [[deprecated("Recursive implementation is slow, use iterative FFT.")]]
  void calculateFFTRecursive(const std::vector<float> &frame,
                             std::vector<std::complex<float>> &fft_frame) {
    size_t n = frame.size();
    if (n == 1) {
      fft_frame[0] = static_cast<std::complex<float>>(frame[0]);
      return;
    }
    auto w = std::exp(-I_COMPLEX * (2.0f * PI / static_cast<float>(n)));

    std::vector<float> even_frame;
    std::vector<float> odd_frame;
    even_frame.resize(n / 2);
    odd_frame.resize(n / 2);
    size_t e_idx = 0;
    size_t o_idx = 0;
    for (size_t i = 0; i < n; i++) {
      if (i % 2) {
        odd_frame[o_idx] = frame[i];
        o_idx++;
      } else {
        even_frame[e_idx] = frame[i];
        e_idx++;
      }
    }

    std::vector<std::complex<float>> even_fft_frame;
    std::vector<std::complex<float>> odd_fft_frame;
    even_fft_frame.resize(n / 2);
    odd_fft_frame.resize(n / 2);

    calculateFFTRecursive(even_frame, even_fft_frame);
    calculateFFTRecursive(odd_frame, odd_fft_frame);

    std::complex<float> twiddle(1.0f, 0.0f);

    for (int j = 0; j < (n / 2); j++) {
      fft_frame[j] = even_fft_frame[j] + twiddle * odd_fft_frame[j];
      fft_frame[j + (n / 2)] = even_fft_frame[j] - twiddle * odd_fft_frame[j];

      twiddle *= w;
    }
  }

  float calculateMean(const std::vector<HardwareT> &frame) {
    double sum = 0;
    for (auto i : frame) {
      sum += i;
    }
    return static_cast<float>(sum / frame.size());
  }

  void prepareWindow(size_t size) {
    if (m_window_lut.size() == size)
      return;

    m_window_lut.resize(size);
    for (size_t i = 0; i < size; i++) {
      m_window_lut[i] =
          0.5f *
          (1.0f - std::cos(2.0f * PI * i / (static_cast<float>(size) - 1.0f)));
    }
  }
};

} // namespace Scoped
