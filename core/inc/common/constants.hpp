#pragma once

#include <cstddef>

namespace Scoped {
namespace Constants {

// Global ADC configuration
constexpr size_t ADC_BITS = 8;

// Derived constants
constexpr float ADC_LEVELS =
    static_cast<float>(1 << ADC_BITS);            // 256.0f for 8-bit
constexpr float ADC_MAX_VAL = ADC_LEVELS - 1.0f;  // 255.0f for 8-bit
constexpr float ADC_MIDPOINT = ADC_LEVELS / 2.0f; // 128.0f for 8-bit
constexpr float ADC_SAMPLE_RATE_HZ = 1024.0f;     // Default mock sample rate

// Default Plot Settings
constexpr float DEFAULT_VERTICAL_SCALE = 1.0f;
constexpr float DEFAULT_VERTICAL_OFFSET = 0.0f;
constexpr size_t DEFAULT_HORIZONTAL_SCALE = 2048;
constexpr int DEFAULT_HORIZONTAL_OFFSET = 0;

// Processing Settings
constexpr size_t BUFFER_SIZE = 16384 * 4;

} // namespace Constants
} // namespace Scoped
