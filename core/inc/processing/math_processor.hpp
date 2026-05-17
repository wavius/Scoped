#pragma once

#include <cmath>
#include <processing/iprocessor.hpp>
#include <processing/window.hpp>
#include <vector>

namespace Scoped {

class MathProcessor : public IVirtualProcessor {
private:
  bool m_enabled;
  std::string m_name = "FFT";

  std::vector<std::complex<float>> m_fft_output; // FFT output

  // Plotting vars
  size_t m_max_height; // Max plot height (pixels)

  float m_vertical_scale = 0.9f; // Scale factor applied to FFT output
  static constexpr float m_vertical_offset = 0.0f; // Vertical offset
  size_t m_horizontal_scale = 0;                   // 0 means auto/full
  size_t m_horizontal_offset = 0;

public:
  // Lifecycle

  // Accessors
  std::string getName() const override { return m_name; }
  bool isEnabled() const override { return m_enabled; }
  float getVerticalScale() const override { return m_vertical_scale; }
  float getVerticalOffset() const override { return m_vertical_offset; }
  size_t getHorizontalScale() const override { return m_horizontal_scale; }
  size_t getHorizontalOffset() const override { return m_horizontal_offset; }

  // Setters
  void setEnabled(bool enabled) override { m_enabled = enabled; }
  void setVerticalScale(float scale) override { m_vertical_scale = scale; }
  void setVerticalOffset(float offset) override { /* no-op */ }
  void setHorizontalScale(size_t scale) override { m_horizontal_scale = scale; }
  void setHorizontalOffset(size_t offset) override { m_horizontal_offset = offset; }

  // Pipeline
  void process(const std::vector<IChannel *> &sources,
               std::vector<Trace> &traces) override {}
};

} // namespace Scoped
