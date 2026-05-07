#pragma once

#include <channel.hpp>
#include <implot.h> // IWYU pragma: keep
#include <intensitymap.hpp>
#include <memory>
#include <oscilloscope.hpp>
#include <vector>

namespace Scoped {

/// Registers a black-to-color gradient colormap for the display.
void setupChannelColormap(ImVec4 color);

/// Owns the display state and renders the complete oscilloscope UI.
class OscilloscopeUI {
private:
  std::vector<std::unique_ptr<IntensityMap>> m_displays;
  size_t m_display_width;
  size_t m_display_height;
  std::vector<float> m_normalized;
  bool m_show_trigger_line = false;

  void updateDisplay(Oscilloscope &osc);

  void drawGrid(double w, double h);
  void drawTriggerLine(Oscilloscope &osc);
  void renderPlot(Oscilloscope &osc);

  void drawModeCombo(Oscilloscope &osc);
  void drawTimebaseControl(Oscilloscope &osc);
  void renderTopBar(Oscilloscope &osc);

  void drawChannelBlock(IChannel &channel);
  void drawHardwareStatus(Oscilloscope &osc);
  void renderBottomBar(Oscilloscope &osc);

public:
  // ---------------------------------------------------------------------------
  // Lifecycle
  // ---------------------------------------------------------------------------

  OscilloscopeUI(size_t display_width, size_t display_height);

  // ---------------------------------------------------------------------------
  // Rendering
  // ---------------------------------------------------------------------------

  void render(Oscilloscope &osc);
};

} // namespace Scoped
