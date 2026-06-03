#pragma once

#include "processing/filter_processor.hpp"
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
  IChannel *m_active_channel = nullptr;
  IProcessorControl *m_active_processor = nullptr;

  // Data pipeline — runs once per new frame
  void processNewFrames(Oscilloscope &osc);

  // Plot canvas helpers
  void drawGridLines(double w, double h);
  void drawTriggerLine(Oscilloscope &osc);
  void drawTriggerMarker(const std::string &label, double h_scale,
                         double h_offset, double w, double h,
                         const ImVec4 &color, float y_offset_rect);
  void drawFrequencyTraces(Oscilloscope &osc);
  void drawVirtualTimeTraces(Oscilloscope &osc);
  void drawPlotArea(Oscilloscope &osc);

  // Control helpers
  void drawModeCombo(Oscilloscope &osc);
  void drawHorizontalControls(IChannel &channel, Oscilloscope &osc);
  void drawVerticalControls(IChannel &channel, Oscilloscope &osc);
  void drawFFTControls(Oscilloscope &osc);
  void drawMathControls(Oscilloscope &osc);
  void drawFilterControls(Oscilloscope &osc);
  void drawFilterPreviewGraph(FilterProcessor* filter_proc);

      // Common UI Control Helpers
      bool drawSliderFloatWithInput(const char *label, float *v, float v_min,
                                    float v_max, const char *format = "%.2f",
                                    bool add_spacing = true);
  bool drawSliderIntWithInput(const char *label, int *v, int v_min, int v_max,
                              const char *format = "%d",
                              bool add_spacing = true);
  bool drawCombo(const char *label, int *current_item,
                 const char *const items[], int items_count,
                 bool add_spacing = true);

  // Dockable v2 layout
  void drawDockSpace();
  void buildDefaultDockLayout(ImGuiID dockspace_id,
                              const ImVec2 &dockspace_size);
  void drawMainMenu();
  void drawScopeWindow(Oscilloscope &osc);
  void drawTriggerWindow(Oscilloscope &osc);
  void drawFFTWindow(Oscilloscope &osc);
  void drawMathWindow(Oscilloscope &osc);
  void drawFilterWindow(Oscilloscope &osc);
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
