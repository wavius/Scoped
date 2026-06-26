#pragma once

#include <imgui.h>
#include <processing/iprocessor.hpp> // for Scoped::Color

namespace Scoped {

namespace Colors {
// Traces
const ImVec4 CH1 = ImVec4(1, 1, 0, 1);                   // Yellow
const ImVec4 CH2 = ImVec4(0, 1, 0, 1);                   // Green
const ImVec4 FFT1 = ImVec4(0.78f, 0.64f, 0.94f, 1.0f);   // Lilac
const ImVec4 FFT2 = ImVec4(0.0f, 1.0f, 1.0f, 1.0f);      // Cyan
const ImVec4 MATH1 = ImVec4(1.0f, 0.4f, 0.7f, 1.0f);     // Pink/Magenta
const ImVec4 MATH2 = ImVec4(1.0f, 0.55f, 0.0f, 1.0f);    // Neon Orange/Amber
const ImVec4 FILTER1 = ImVec4(0.1f, 0.6f, 1.0f, 1.0f);   // Bright Sky Blue
const ImVec4 FILTER2 = ImVec4(0.0f, 0.85f, 0.45f, 1.0f); // Mint Green / Emerald
const ImVec4 MEAS1 = ImVec4(1.0f, 0.3f, 0.3f, 1.0f);     // Bright Coral
const ImVec4 MEAS2 = ImVec4(0.3f, 1.0f, 0.6f, 1.0f);     // Spring Green
const ImVec4 FFTLine = ImVec4(0.7f, 0.5f, 1.0f, 1.0f);   // Light Purple

// UI Elements
const ImVec4 Black = ImVec4(0, 0, 0, 1);            // Black
const ImVec4 Grid = ImVec4(0.3f, 0.3f, 0.3f, 0.4f); // Dark Gray
const ImVec4 Trigger = ImVec4(1, 0, 0, 0.5f);       // Red (semi-transparent)
const ImVec4 StatusOk = ImVec4(0, 1, 0, 1);         // Green
const ImVec4 StatusError = ImVec4(1, 0, 0, 1);      // Red
const ImVec4 TopBarBg = ImVec4(0.11f, 0.14f, 0.18f, 1.0f);    // Dark Blue-Gray
const ImVec4 ChannelBlockBg = ImVec4(1.0f, 0.8f, 0.0f, 1.0f); // Amber/Gold
const ImVec4 BottomBarBg = ImVec4(0.08f, 0.1f, 0.12f, 1.0f);  // Dark Navy
} // namespace Colors

// Converts a Scoped::Color (std::array<float,4>) to ImVec4 for rendering.
inline ImVec4 toImVec4(const Color &c) {
  return ImVec4(c[0], c[1], c[2], c[3]);
}

} // namespace Scoped
