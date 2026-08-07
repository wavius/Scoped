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
  
  template <typename T>
  void drawHorizontalControls(T *target, Oscilloscope &osc) {
    double sample_rate = Constants::ADC_SAMPLE_RATE_HZ;
    if constexpr (std::is_base_of_v<IChannel, T>) {
      sample_rate = target->getSampleRate();
    }
    if (sample_rate <= 0.0) sample_rate = Constants::ADC_SAMPLE_RATE_HZ;
    
    float time_span_s = static_cast<float>(target->getHorizontalScale()) / sample_rate;
    float max_time_s = static_cast<float>(osc.getMaxCaptureWidth()) / sample_rate;

    ImGui::Spacing();
    if (time_span_s < 1e-6f) {
        ImGui::Text("Time Scale: %.2f ns", time_span_s * 1e9f);
    } else if (time_span_s < 1e-3f) {
        ImGui::Text("Time Scale: %.2f us", time_span_s * 1e6f);
    } else if (time_span_s < 1.0f) {
        ImGui::Text("Time Scale: %.2f ms", time_span_s * 1e3f);
    } else {
        ImGui::Text("Time Scale: %.2f s", time_span_s);
    }

    ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
    
    // allow zooming deep into the buffer (e.g. 2 samples)
    float min_time_s = 2.0f / sample_rate;
    
    if (ImGui::SliderFloat("##TimeScale", &time_span_s, min_time_s, max_time_s, "", ImGuiSliderFlags_Logarithmic)) {
      size_t new_samples = static_cast<size_t>(time_span_s * sample_rate);
      if (new_samples < 2) new_samples = 2;
      target->setHorizontalScale(new_samples);
      osc.forceReprocess();
    }

    int visible_width = static_cast<int>(target->getHorizontalScale());
    int capture_width = static_cast<int>(osc.getMaxCaptureWidth());
    float max_offset_ms = std::max(0, (capture_width - visible_width) / 2) / sample_rate * 1000.0f;
    
    float time_offset_ms = static_cast<float>(target->getHorizontalOffset()) / sample_rate * 1000.0f;

    if (drawSliderFloatWithInput("Time Offset", &time_offset_ms, -max_offset_ms,
                               max_offset_ms, "%.2f ms", true)) {
      target->setHorizontalOffset(static_cast<int>((time_offset_ms / 1000.0f) * sample_rate));
      osc.forceReprocess();
    }
  }

  template <typename T>
  void drawVerticalControls(T *target, Oscilloscope &osc) {
    float v_range = Constants::ADC_VMAX - Constants::ADC_VMIN;
    float scale = target->getVerticalScale();
    if (drawSliderFloatWithInput("Voltage Scale", &scale, 0.01f, 5.0f, "%.2fx", false)) {
      target->setVerticalScale(scale);
      osc.forceReprocess();
    }
    
    float offset_v = target->getVerticalOffset();
    if (drawSliderFloatWithInput("Voltage Offset", &offset_v, -v_range, v_range, "%.2f V", true)) {
      target->setVerticalOffset(offset_v);
      osc.forceReprocess();
    }
  }

  void drawFFTControls(Oscilloscope &osc);
  void drawMathControls(Oscilloscope &osc);
  void drawFilterControls(Oscilloscope &osc);
  void drawFilterPreviewGraph(FilterProcessor *filter_proc);

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
  void drawMeasurementWindow(Oscilloscope &osc);
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
