#include <ui/ui.hpp>
#include <ui/ui_helpers.hpp>
#include <imgui.h>
#include <algorithm>

namespace Scoped {

// Helper to snap a value to the standard 1-2-5 oscilloscope sequence
static float snapTo125Sequence(float value, float threshold_pct = 0.05f) {
  if (value <= 0.0f) return value;
  
  float exp = std::floor(std::log10(value));
  float base = std::pow(10.0f, exp);
  float mantissa = value / base;
  
  float points[] = {1.0f, 2.0f, 5.0f, 10.0f};
  
  for (float p : points) {
      if (std::abs(mantissa - p) / p < threshold_pct) {
          return p * base;
      }
  }
  return value;
}

// Controls how many samples are visible horizontally.
// TODO: Change this to time division instead of samples
void OscilloscopeUI::drawHorizontalControls(IChannel &channel,
                                            Oscilloscope &osc) {
  double sample_rate = channel.getSampleRate();
  float time_span_s = static_cast<float>(channel.getHorizontalScale()) / sample_rate;
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
  
  // Set minimum bound to 10 samples worth of time
  float min_time_s = 10.0f / sample_rate;
  
  if (ImGui::SliderFloat("##TimeScale", &time_span_s, min_time_s, max_time_s, "", ImGuiSliderFlags_Logarithmic)) {
    size_t new_samples = static_cast<size_t>(time_span_s * sample_rate);
    if (new_samples < 10) new_samples = 10;
    channel.setHorizontalScale(new_samples);
    osc.forceReprocess();
  }

  int capture_width = static_cast<int>(osc.getMaxCaptureWidth());
  int visible_width = static_cast<int>(channel.getHorizontalScale());
  float max_offset_ms = std::max(0, (capture_width - visible_width) / 2) / sample_rate * 1000.0f;
  
  float time_offset_ms = static_cast<float>(channel.getHorizontalOffset()) / sample_rate * 1000.0f;

  if (drawSliderFloatWithInput("Time Offset", &time_offset_ms, -max_offset_ms,
                             max_offset_ms, "%.2f ms", true)) {
    channel.setHorizontalOffset(static_cast<int>((time_offset_ms / 1000.0f) * sample_rate));
    osc.forceReprocess();
  }
}

// TODO: Change this to voltage division instead of Scale
void OscilloscopeUI::drawVerticalControls(IChannel &channel,
                                          Oscilloscope &osc) {
  float v_range = Constants::ADC_VMAX - Constants::ADC_VMIN;
  float scale = channel.getVerticalScale();
  if (this->drawSliderFloatWithInput("Voltage Scale", &scale, 0.01f, 5.0f, "%.2fx", false)) {
    channel.setVerticalScale(scale);
    osc.forceReprocess();
  }
  
  float offset_v = channel.getVerticalOffset();
  if (this->drawSliderFloatWithInput("Voltage Offset", &offset_v, -v_range, v_range, "%.2f V", true)) {
    channel.setVerticalOffset(offset_v);
    osc.forceReprocess();
  }
}

// Channel controls window.
void OscilloscopeUI::drawChannelWindow(Oscilloscope &osc) {
  ImGui::Begin("Channels");
  ImGui::SetWindowFontScale(1.15f);

  if (osc.getHardwareChannels().empty()) {
    ImGui::TextDisabled("No channels available.");
    ImGui::End();
    return;
  }

  // Per-Channel Controls
  for (auto &channel : osc.getHardwareChannels()) {
    ImGui::PushID(channel->getLabel().c_str());

    UI::drawComponentHeader(channel.get(), channel->getLabel(), osc);
    drawVerticalControls(*channel, osc);
    drawHorizontalControls(*channel, osc);

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::PopID();
  }

  ImGui::End();
}

} // namespace Scoped
