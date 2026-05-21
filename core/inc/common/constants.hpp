#pragma once

#include <cstddef>

namespace Scoped {
namespace Constants {

// Global ADC configuration
constexpr size_t ADC_BITS = 8;

// Derived constants
constexpr float ADC_LEVELS = static_cast<float>(1 << ADC_BITS);   // 256.0f for 8-bit
constexpr float ADC_MAX_VAL = ADC_LEVELS - 1.0f;                  // 255.0f for 8-bit
constexpr float ADC_MIDPOINT = ADC_LEVELS / 2.0f;                 // 128.0f for 8-bit

} // namespace Constants
} // namespace Scoped
