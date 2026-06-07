#include "imgui.h"
#include <common/oscilloscope.hpp>
#include <processing/measurement_processor.hpp>
#include <ui/ui.hpp>

namespace Scoped {

void OscilloscopeUI::drawMeasurementWindow(Oscilloscope &osc) {
  ImGui::Begin("Measurements");
  ImGui::SetWindowFontScale(1.15f);

  std::vector<std::string> source_labels;
  for (const auto &ch : osc.getHardwareChannels()) {
    source_labels.push_back(ch->getLabel());
  }
  for (const auto &vc : osc.getVirtualChannels()) {
    source_labels.push_back(vc->getLabel());
    for (const auto &proc : vc->getProcessors()) {
      if (proc->getType() != ProcessorType::Measurement) {
        source_labels.push_back(proc->getName());
      }
    }
  }

  std::vector<const char *> source_cstr;
  for (const auto &label : source_labels) {
    source_cstr.push_back(label.c_str());
  }

  int proc_idx = 0;
  for (const auto &vc : osc.getVirtualChannels()) {
    for (const auto &proc : vc->getProcessors()) {
      auto *meas_proc = dynamic_cast<MeasurementProcessor *>(proc);
      if (!meas_proc)
        continue;

      ImGui::PushID(proc_idx++);

      bool enabled = meas_proc->isEnabled();
      if (ImGui::Checkbox(meas_proc->getName().c_str(), &enabled)) {
        meas_proc->setEnabled(enabled);
        osc.forceReprocess();
      }

      if (enabled) {
        ImGui::Indent();

        int current_source = 0;
        for (size_t i = 0; i < source_labels.size(); ++i) {
          if (source_labels[i] == meas_proc->getSourceLabel()) {
            current_source = static_cast<int>(i);
            break;
          }
        }

        ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x * 0.5f);
        if (ImGui::Combo("Source", &current_source, source_cstr.data(),
                         static_cast<int>(source_cstr.size()))) {
          meas_proc->setSourceLabel(source_labels[current_source]);
          osc.forceReprocess();
        }

        ImGui::Spacing();
        // Convert ADC levels to voltage (assuming 8-bit ADC ranges -128 to 127 = approx -10V to 10V or similar)
        // Since we don't have true analog scale yet, we just print the raw values or scaled by a factor
        // The user just said "display all the measurements". Let's assume standard formatting.
        ImGui::Text("Vpp:  %.2f", meas_proc->getVpp());
        ImGui::Text("Vrms: %.2f", meas_proc->getVrms());
        ImGui::Text("Vavg: %.2f", meas_proc->getVavg());
        ImGui::Text("Vmin: %.2f", meas_proc->getVmin());
        ImGui::Text("Vmax: %.2f", meas_proc->getVmax());
        ImGui::Spacing();
        ImGui::Text("Frequency: %.2f Hz", meas_proc->getFreq());
        if (meas_proc->getFreq() > 0.0f) {
            ImGui::Text("Period:    %.4f ms", meas_proc->getPeriod() * 1000.0f);
        } else {
            ImGui::Text("Period:    -- ms");
        }

        ImGui::Unindent();
      }

      ImGui::Separator();
      ImGui::Spacing();

      ImGui::PopID();
    }
  }

  if (proc_idx == 0) {
    ImGui::TextDisabled("No measurement processors.");
  }

  ImGui::End();
}

} // namespace Scoped
