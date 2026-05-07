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
  float scale = 1.0f;
  float offset = 0.0f;

  float normalizeToIntensity(float sample) const {
    if (domain == Domain::Time) {
      float centered = sample - 128.0f;
      float scaled = centered * scale + offset + 128.0f;
      return std::clamp(scaled / 256.0f, 0.0f, 1.0f);
    }
    return sample;
  }
};

} // namespace Scoped
