#include <ui/ui.hpp>
#include <ui/ui_helpers.hpp>
#include <imgui.h>
#include <algorithm>

namespace Scoped {

// Controls how many samples are visible horizontally.
// TODO: Change this to time division instead of samples
void OscilloscopeUI::drawHorizontalControls(IChannel &channel,
                                            Oscilloscope &osc) {
  int samples = static_cast<int>(channel.getHorizontalScale());
  if (drawSliderIntWithInput("Horizontal Scale", &samples, 256, 16384,
                             "%d samples", false)) {
    channel.setHorizontalScale(static_cast<size_t>(samples));
    osc.forceReprocess();
  }

  int h_offset = channel.getHorizontalOffset();
  int capture_width = static_cast<int>(osc.getMaxCaptureWidth());
  int visible_width = static_cast<int>(channel.getHorizontalScale());
  int max_offset = std::max(0, (capture_width - visible_width) / 2);

  if (drawSliderIntWithInput("Horizontal Offset", &h_offset, -max_offset,
                             max_offset, "%d samples", true)) {
    channel.setHorizontalOffset(h_offset);
    osc.forceReprocess();
  }
}

// TODO: Change this to voltage division instead of Scale
void OscilloscopeUI::drawVerticalControls(IChannel &channel,
                                          Oscilloscope &osc) {
  auto drawSlider = [&](const char *label, float *v, float v_min, float v_max,
                        const char *format, bool add_spacing) {
    return this->drawSliderFloatWithInput(label, v, v_min, v_max, format,
                                          add_spacing);
  };
  UI::drawVerticalControlsT(&channel, osc, -255.0f, 255.0f, "%.1f", drawSlider);
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
