#pragma once

#include <../../extern/pocketfft/pocketfft_hdronly.h>
#include <cmath>
#include <common/constants.hpp>
#include <complex>
#include <limits>
#include <processing/iprocessor.hpp>
#include <processing/window.hpp>
#include <vector>

namespace Scoped {

// Class to apply FFT to channel
class FFTProcessor : public IProcessor {
private:
  bool m_enabled = false;
  std::string m_name = "FFT";

  std::vector<std::complex<float>> m_fft_output; // FFT output

  // Windowing
  Scoped::Window m_window;

  // Constants
  static constexpr std::complex<float> I_COMPLEX{0.0f, 1.0f};
  static constexpr float PI = 3.141592653589f;
  static constexpr float EPSILON = 1e-8f;

  // Plotting vars
  bool m_isLinearMode = false; // Linear = true, dB = false
  size_t m_max_height;         // Max plot height (pixels)

  float m_smoothing_factor =
      0.0f; // Smoothing factor for exponential smoothing (EMA)
  std::vector<float> m_smoothed_data; // Smooothed FFT data
  size_t m_fft_size;                  // Window size for FFT

  float m_vertical_scale = Constants::DEFAULT_VERTICAL_SCALE;
  float m_vertical_offset = Constants::DEFAULT_VERTICAL_OFFSET;
  size_t m_horizontal_scale = 0; // 0 = auto/full
  size_t m_horizontal_offset = Constants::DEFAULT_HORIZONTAL_OFFSET;
  Color m_color = {1.0f, 1.0f, 1.0f, 1.0f};

public:
  // Lifecycle
  FFTProcessor(const std::string &name, size_t display_height,
               size_t initial_fft_size = Constants::BUFFER_SIZE / 4)
      : m_name(name), m_window(initial_fft_size, WindowType::HANN),
        m_fft_size(initial_fft_size) {
    m_max_height = display_height;
  }

  // Accessors
  std::string getName() const override { return m_name; }
  bool isEnabled() const override { return m_enabled; }
  ProcessorType getType() const override { return ProcessorType::FFT; }
  float getVerticalScale() const override { return m_vertical_scale; }
  float getVerticalOffset() const override { return m_vertical_offset; }
  bool getIsModeLinear() const { return m_isLinearMode; }
  float getSmoothingFactor() const { return m_smoothing_factor; }
  WindowType getWindowType() const { return m_window.getType(); }
  std::string getWindowTypeName() const { return m_window.getTypeName(); }
  size_t getWindowSize() const { return m_fft_size; }
  size_t getHorizontalScale() const override { return m_horizontal_scale; }
  size_t getHorizontalOffset() const override { return m_horizontal_offset; }
  Color getColor() const override { return m_color; }

  // Setters
  void setEnabled(bool enabled) override { m_enabled = enabled; }
  void setVerticalScale(float scale) override { m_vertical_scale = scale; }
  void setVerticalOffset(float offset) override { m_vertical_offset = offset; }
  void setIsModeLinear(bool mode) { m_isLinearMode = mode; }
  void setSmoothingFactor(float factor) { m_smoothing_factor = factor; }
  void setWindowType(int type) {
    m_window.setType(static_cast<WindowType>(type));
  }
  void setWindowSize(size_t size) { m_fft_size = size; }
  void setHorizontalScale(size_t scale) override { m_horizontal_scale = scale; }
  void setHorizontalOffset(size_t offset) override {
    m_horizontal_offset = offset;
  }
  void setColor(const Color &color) override { m_color = color; }

  // Pipeline
  void process(const std::vector<float> &raw_frame,
               std::vector<Trace> &traces) override {

    size_t frame_size = std::min(m_fft_size, raw_frame.size());
    m_fft_output.resize(frame_size);

    // Update window size (Window class only regenerates if size actually
    // changes)
    m_window.setSize(frame_size);
    const auto &window_func = m_window.getFunction();

    // Remove DC offset and apply windowing function
    std::vector<float> centered_frame;
    centered_frame.resize(frame_size);
    float mean = calculateMean(raw_frame);
    for (size_t i = 0; i < frame_size; i++) {
      centered_frame[i] = (raw_frame[i] - mean) * window_func[i];
    }

    // Real to complex Fourier Transform
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
    fft_trace.color = m_color;

    size_t num_bins = frame_size / 2;
    size_t scale = (m_horizontal_scale == 0 || m_horizontal_scale > num_bins)
                       ? num_bins
                       : m_horizontal_scale;
    size_t offset = std::min(m_horizontal_offset, num_bins - scale);

    fft_trace.data.resize(scale);
    m_smoothed_data.resize(num_bins);

    // Find magnitude and normalize
    float max = std::numeric_limits<float>::lowest();
    float min = std::numeric_limits<float>::max();
    for (size_t i = 0; i < num_bins; i++) {
      float mag = std::abs(m_fft_output[i]);
      float val;
      if (m_isLinearMode) {
        val = mag;
      } else {
        val = 20.0f * std::log10(mag + EPSILON);
      }

      // Smooth data
      m_smoothed_data[i] = ((1.0f - m_smoothing_factor) * val) +
                           (m_smoothed_data[i] * m_smoothing_factor);

      val = m_smoothed_data[i];

      // Calculate min/max over the entire FFT
      max = val > max ? val : max;
      min = val < min ? val : min;

      if (i >= offset && i < offset + scale) {
        fft_trace.data[i - offset] = val;
      }
    }

    // Scale + offset
    float range =
        (max - min) > 0.001f ? max - min : 1.0f; // Prevent division by 0
    fft_trace.vertical_scale = (1.0f / range) * m_vertical_scale;

    fft_trace.vertical_offset =
        (min * fft_trace.vertical_scale) - (m_vertical_offset / 256.0f);

    fft_trace.horizontal_scale = m_horizontal_scale;
    fft_trace.horizontal_offset = static_cast<int>(m_horizontal_offset);

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

  float calculateMean(const std::vector<float> &frame) {
    double sum = 0;
    for (auto i : frame) {
      sum += i;
    }
    return static_cast<float>(sum / frame.size());
  }
};

} // namespace Scoped
