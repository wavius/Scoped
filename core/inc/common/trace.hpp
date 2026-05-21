#pragma once

#include <algorithm>
#include <array>
#include <common/constants.hpp>
#include <string>
#include <vector>

namespace Scoped {

using Color = std::array<float, 4>;

enum class Domain { Time, Frequency };

struct Trace {
  std::string name;
  Domain domain;
  std::vector<float> data;
  float vertical_scale = 1.0f;
  float vertical_offset = 0.0f;
  Color color = {1.0f, 1.0f, 1.0f, 1.0f};

  // Pipeline
  float normalizeToIntensity(float sample) const {
    if (domain == Domain::Time) {
      float centered = sample - Constants::ADC_MIDPOINT;
      float scaled = (centered * vertical_scale) + vertical_offset + Constants::ADC_MIDPOINT;
      return std::clamp(scaled / Constants::ADC_LEVELS, 0.0f, 1.0f);
    } else if (domain == Domain::Frequency) {
      // Frequency domain auto-scaling logic assumes subtraction
      float scaled = (sample * vertical_scale) - vertical_offset;
      return std::clamp(scaled, 0.0f, 1.0f);
    }
    return sample;
  }
};

} // namespace Scoped
