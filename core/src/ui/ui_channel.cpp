#include <ui/ui.hpp>
#include <ui/ui_helpers.hpp>
#include <imgui.h>
#include <algorithm>
#include <fstream>
#include <iostream>

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
    
    // Check if it's a hardware channel, and add a dump button
    if (auto hw_channel = dynamic_cast<Scoped::Channel<uint8_t>*>(channel.get())) {
        if (ImGui::Button("Dump to JSON")) {
            std::string filename = "dump_" + channel->getLabel() + ".json";
            std::ofstream out(filename);
            if (out.is_open()) {
                out << "{\n";
                out << "  \"label\": \"" << channel->getLabel() << "\",\n";
                
                const auto& raw_bytes = hw_channel->getHardwareFrame();
                const auto& float_volts = hw_channel->getRawFrame(); // This holds m_float_frame
                
                out << "  \"samples\": [\n";
                size_t len = std::min(raw_bytes.size(), float_volts.size());
                for (size_t i = 0; i < len; ++i) {
                    out << "    { \"raw\": " << static_cast<int>(raw_bytes[i]) 
                        << ", \"volts\": " << float_volts[i] << " }";
                    if (i < len - 1) out << ",";
                    out << "\n";
                }
                out << "  ]\n";
                out << "}\n";
                out.close();
                std::cout << "Dumped " << len << " samples to " << filename << std::endl;
            }
        }
    }

    drawVerticalControls(channel.get(), osc);
    drawHorizontalControls(channel.get(), osc);

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::PopID();
  }

  ImGui::End();
}

} // namespace Scoped
