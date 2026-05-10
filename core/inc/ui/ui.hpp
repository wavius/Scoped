#pragma once

#include <common/channel.hpp>
#include <implot.h> // IWYU pragma: keep
#include <ui/intensitymap.hpp>
#include <memory>
#include <common/oscilloscope.hpp>
#include <vector>

namespace Scoped {

// Registers a black-to-color gradient colormap for the display.
void setupChannelColormap(ImVec4 color);

// Owns the display state and renders the complete oscilloscope UI.
class OscilloscopeUI {
private:
  std::vector<std::unique_ptr<IntensityMap>> m_displays;
  size_t m_display_width;
  size_t m_display_height;
  std::vector<float> m_normalized_time;
  std::vector<float> m_normalized_freq;
  bool m_show_trigger_line = false;

  // Data pipeline — runs once per new frame
  void processNewFrames(Oscilloscope &osc);

  // Plot canvas helpers
  void drawGridLines(double w, double h);
  void drawTriggerLine(Oscilloscope &osc);
  void drawFrequencyTraces(Oscilloscope &osc);
  void drawPlotArea(Oscilloscope &osc);

  // Top bar controls
  void drawModeCombo(Oscilloscope &osc);
  void drawTimebaseControl(Oscilloscope &osc);
  void drawFFTControl(Oscilloscope &osc);
  void drawTopBar(Oscilloscope &osc);

  // Bottom bar controls
  void drawChannelBlock(IChannel &channel);
  void drawHardwareStatus(Oscilloscope &osc);
  void drawBottomBar(Oscilloscope &osc);

public:
  // Lifecycle
  OscilloscopeUI(size_t display_width, size_t display_height);

  // Accessors
  size_t getDisplayHeight() { return m_display_height; }

  // Rendering
  void render(Oscilloscope &osc);
};

} // namespace Scoped
