#pragma once

#include "trace.hpp"
#include <cmath>
#include <complex>
#include <cstdint>
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

  // Setters
  virtual void setEnabled(bool enabled) = 0;
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

  static constexpr std::complex<float> I_COMPLEX{0.0f, 1.0f};
  static constexpr float PI = 3.141592653589f;

  // Plotting constants
  static constexpr float m_scale = 2.0;
  static constexpr float m_offset = 0;

public:
  // Lifecycle
  FFTProcessor() = default;

  // Accessors
  std::string getName() const override { return m_name; }
  bool isEnabled() const override { return m_enabled; }

  // Setters
  void setEnabled(bool enabled) override { m_enabled = enabled; }

  // Pipeline
  void process(const std::vector<HardwareT> &raw_frame,
               std::vector<Trace> &traces) override {

    m_fft_output.resize(raw_frame.size());

    calculateFFT(raw_frame, m_fft_output);

    Trace fft_trace;
    fft_trace.name = this->m_name; // TODO: Add channel to name
    fft_trace.domain = Domain::Frequency;
    fft_trace.scale = m_scale;
    fft_trace.offset = m_offset;
    fft_trace.data.resize(m_fft_output.size());

    for (size_t i = 0; i < m_fft_output.size(); i++) {
      fft_trace.data[i] = std::abs(m_fft_output[i]);
    }

    traces.push_back(std::move(fft_trace));
  }

  // Logic
  void calculateFFT(const std::vector<HardwareT> &frame,
                    std::vector<std::complex<float>> &fft_frame) {
    size_t n = frame.size();
    if (n == 1) {
      fft_frame[0] = static_cast<std::complex<float>>(frame[0]);
      return;
    }
    auto w = std::exp(-I_COMPLEX * (2.0f * PI / static_cast<float>(n)));

    std::vector<HardwareT> even_frame;
    std::vector<HardwareT> odd_frame;
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

    calculateFFT(even_frame, even_fft_frame);
    calculateFFT(odd_frame, odd_fft_frame);

    std::complex<float> twiddle(1.0f, 0.0f);

    for (int j = 0; j < (n / 2); j++) {
      fft_frame[j] = even_fft_frame[j] + twiddle * odd_fft_frame[j];
      fft_frame[j + (n / 2)] = even_fft_frame[j] - twiddle * odd_fft_frame[j];

      twiddle *= w;
    }
  }
};

} // namespace Scoped
