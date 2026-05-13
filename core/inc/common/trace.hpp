#pragma once

#include <algorithm>
#include <string>
#include <vector>

namespace Scoped {

enum class Domain { Time, Frequency };

struct Trace {
  std::string name;
  Domain domain;
  std::vector<float> data;
  float vertical_scale = 1.0f;
  float vertical_offset = 0.0f;

  // Pipeline
  float normalizeToIntensity(float sample) const {
    if (domain == Domain::Time) {
      float centered = sample - 128.0f;
      float scaled = (centered * vertical_scale) - vertical_offset + 128.0f;
      return std::clamp(scaled / 256.0f, 0.0f, 1.0f);
    } else if (domain == Domain::Frequency) {
      float scaled = (sample * vertical_scale) - vertical_offset;
      return std::clamp(scaled, 0.0f, 1.0f);
    }
    return sample;
  }
};

} // namespace Scoped
