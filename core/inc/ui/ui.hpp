#pragma once

#include <common/channel.hpp>
#include <common/oscilloscope.hpp>
#include <implot.h> // IWYU pragma: keep
#include <memory>
#include <ui/colors.hpp>
#include <ui/intensitymap.hpp>
#include <vector>

namespace Scoped {

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
