#pragma once

#include <common/channel.hpp>
#include <common/oscilloscope.hpp>
#include <implot.h> // IWYU pragma: keep
#include <memory>
#include <ui/intensitymap.hpp>
#include <vector>

namespace Scoped {

namespace Colors {
const ImVec4 Black = ImVec4(0, 0, 0, 1);            // Black
const ImVec4 Grid = ImVec4(0.3f, 0.3f, 0.3f, 0.4f); // Dark Gray
const ImVec4 Trigger = ImVec4(1, 0, 0, 0.5f);       // Red (Semi-transparent)
const ImVec4 TriggerMarker =
    ImVec4(1.0f, 0.55f, 0.0f, 1.0f);                       // Neon Orange/Amber
const ImVec4 FFTLine = ImVec4(0.7f, 0.5f, 1.0f, 1.0f);     // Light purple
const ImVec4 StatusOk = ImVec4(0, 1, 0, 1);                // Green
const ImVec4 StatusError = ImVec4(1, 0, 0, 1);             // Red
const ImVec4 CH1 = ImVec4(1, 1, 0, 1);                     // Yellow
const ImVec4 CH2 = ImVec4(0, 1, 0, 1);                     // Green
const ImVec4 FFT1 = ImVec4(0.78f, 0.64f, 0.94f, 1.0f);     // Lilac
const ImVec4 FFT2 = ImVec4(0.0f, 1.0f, 1.0f, 1.0f);        // Cyan
const ImVec4 Math = ImVec4(1.0f, 0.4f, 0.7f, 1.0f);        // Pink/Magenta
const ImVec4 TopBarBg = ImVec4(0.11f, 0.14f, 0.18f, 1.0f); // Dark Blue-Gray
const ImVec4 ChannelBlockBg = ImVec4(1.0f, .8f, 0.0f, 1.0f); // Amber/Gold
const ImVec4 BottomBarBg = ImVec4(0.08f, 0.1f, 0.12f, 1.0f); // Dark Navy
} // namespace Colors

// Registers a black-to-color gradient colormap for the display.
void setupChannelColormap(ImVec4 color);

// Owns the display state and renders the complete oscilloscope UI.
class OscilloscopeUI {
private:
  std::unique_ptr<IntensityMap> m_display;
  size_t m_display_width;
  size_t m_display_height;
  std::vector<float> m_normalized_time;
  std::vector<float> m_normalized_freq;
  bool m_show_trigger_line = false;
  bool m_reset_dock_layout = true;

  // Data pipeline — runs once per new frame
  void processNewFrames(Oscilloscope &osc);

  // Plot canvas helpers
  void drawGridLines(double w, double h);
  void drawTriggerLine(Oscilloscope &osc);
  void drawTriggerMarker(const std::string &label, double h_scale, double h_offset,
                         double w, double h, const ImVec4 &color, float y_offset_rect);
  void drawFrequencyTraces(Oscilloscope &osc);
  void drawPlotArea(Oscilloscope &osc);

  // Control helpers
  void drawModeCombo(Oscilloscope &osc);
  void drawHorizontalControls(IChannel &channel, Oscilloscope &osc);
  void drawVerticalControls(IChannel &channel, Oscilloscope &osc);
  void drawFFTControls(Oscilloscope &osc);
  void drawMathControls(Oscilloscope &osc);

  // Dockable v2 layout
  void drawDockSpace();
  void buildDefaultDockLayout(ImGuiID dockspace_id,
                              const ImVec2 &dockspace_size);
  void drawMainMenu();
  void drawScopeWindow(Oscilloscope &osc);
  void drawTriggerWindow(Oscilloscope &osc);
  void drawFFTWindow(Oscilloscope &osc);
  void drawMathWindow(Oscilloscope &osc);
  void drawChannelWindow(Oscilloscope &osc);
  void drawHardwareWindow(Oscilloscope &osc);
  void drawDebugWindow(Oscilloscope &osc);

public:
  // Lifecycle
  OscilloscopeUI(size_t display_width, size_t display_height);

  // Accessors
  size_t getDisplayHeight() { return m_display_height; }

  // Rendering
  void render(Oscilloscope &osc);
};

} // namespace Scoped
