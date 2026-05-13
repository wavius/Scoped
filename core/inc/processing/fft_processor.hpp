#pragma once

#include <../../extern/pocketfft/pocketfft_hdronly.h>
#include <cmath>
#include <complex>
#include <limits>
#include <processing/iprocessor.hpp>
#include <vector>

namespace Scoped {

// Class to apply FFT to channel
template <typename HardwareT>
class FFTProcessor : public IProcessor<HardwareT> {
private:
  bool m_enabled;
  std::string m_name = "FFT";

  std::vector<std::complex<float>> m_fft_output; // FFT output
  std::vector<float> m_window_lut;               // LUT for windowing function

  // Constants
  static constexpr std::complex<float> I_COMPLEX{0.0f, 1.0f};
  static constexpr float PI = 3.141592653589f;
  static constexpr float EPSILON = 1e-8f;

  // Plotting vars
  bool m_isLinearMode = false; // Linear = true, dB = false
  size_t m_max_height;         // Max plot height (pixels)

  float m_smoothing_factor =
      0.8f; // Smoothing factor for exponential smoothing (EMA)
  std::vector<float> m_smoothed_data; // Smooothed FFT data

  float m_scale = 0.9f;                   // Scale factor applied to FFT output
  static constexpr float m_offset = 0.0f; // Vertical offset

public:
  // Lifecycle
  FFTProcessor(size_t display_height) { m_max_height = display_height; }

  // Accessors
  std::string getName() const override { return m_name; }
  bool isEnabled() const override { return m_enabled; }
  float getScale() const override { return m_scale; }
  bool getIsModeLinear() const override { return m_isLinearMode; }
  float getSmoothingFactor() const override { return m_smoothing_factor; }

  // Setters
  void setEnabled(bool enabled) override { m_enabled = enabled; }
  void setScale(float scale) override { m_scale = scale; }
  void setIsModeLinear(bool mode) override { m_isLinearMode = mode; }
  void setSmoothingFactor(float factor) override {
    m_smoothing_factor = factor;
  }

  // Pipeline
  void process(const std::vector<HardwareT> &raw_frame,
               std::vector<Trace> &traces) override {

    size_t frame_size = raw_frame.size();
    m_fft_output.resize(frame_size);

    // Remove DC offset and apply windowing function (Gaussian distribution)
    std::vector<float> centered_frame;
    centered_frame.resize(frame_size);
    prepareWindow(frame_size);
    float mean = calculateMean(raw_frame);
    for (size_t i = 0; i < frame_size; i++) {
      centered_frame[i] =
          (static_cast<float>(raw_frame[i]) - mean) * m_window_lut[i];
    }

    // Old FFT function
    // calculateFFTRecursive(centered_frame, m_fft_output);

    // Real to complex Fourier Transform
    /*
    template<typename T> void r2c(const shape_t &shape_in,
      const stride_t &stride_in, const stride_t &stride_out, size_t axis,
      bool forward, const T *data_in, complex<T> *data_out, T fct,
      size_t nthreads=1)
    */
    pocketfft::shape_t shape{frame_size};

    pocketfft::stride_t stride_in(1);
    stride_in[0] = sizeof(float);

    pocketfft::stride_t stride_out(1);
    stride_out[0] = sizeof(std::complex<float>);

    pocketfft::shape_t axes;
    axes.push_back(0);

    pocketfft::r2c(shape, stride_in, stride_out, axes, pocketfft::FORWARD,
                   centered_frame.data(), m_fft_output.data(),
                   2.0f / static_cast<float>(frame_size));

    Trace fft_trace;
    fft_trace.name = this->m_name; // TODO: Add channel to name
    fft_trace.domain = Domain::Frequency;

    fft_trace.data.resize(frame_size / 2);

    m_smoothed_data.resize(frame_size / 2);

    // Find magnitude and normalize
    float max = std::numeric_limits<float>::lowest();
    float min = std::numeric_limits<float>::max();
    for (size_t i = 0; i < frame_size / 2; i++) {
      float mag = std::abs(m_fft_output[i]);
      if (m_isLinearMode) {
        fft_trace.data[i] = mag;
      } else {
        fft_trace.data[i] = 20.0f * std::log10(mag + EPSILON);
      }

      // Smooth data
      m_smoothed_data[i] = ((1.0f - m_smoothing_factor) * fft_trace.data[i]) +
                           (m_smoothed_data[i] * m_smoothing_factor);

      fft_trace.data[i] = m_smoothed_data[i];

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
  [[deprecated("Recursive implementation is slow, use PocketFFT.")]]
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
