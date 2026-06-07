#include "imgui.h"
#include <common/oscilloscope.hpp>
#include <processing/measurement_processor.hpp>
#include <ui/ui.hpp>

namespace Scoped {

void OscilloscopeUI::drawMeasurementWindow(Oscilloscope &osc) {
  ImGui::Begin("Measurements");
  ImGui::SetWindowFontScale(1.15f);



  int proc_idx = 0;
  for (const auto &vc : osc.getVirtualChannels()) {
    for (const auto &proc : vc->getProcessors()) {
      auto *meas_proc = dynamic_cast<MeasurementProcessor *>(proc);
      if (!meas_proc)
        continue;

      ImGui::PushID(proc_idx++);

      if (!meas_proc->isEnabled()) {
        meas_proc->setEnabled(true);
        osc.forceReprocess();
      }

      ImVec4 color = toImVec4(meas_proc->getColor());
      ImGui::TextColored(color, "%s", meas_proc->getName().c_str());
      ImGui::SameLine();
      bool popout = meas_proc->getShowInPopup();
      if (ImGui::Checkbox("Popout", &popout)) {
        meas_proc->setShowInPopup(popout);
      }
      ImGui::Spacing();

      std::string meas_name = meas_proc->getName();
      bool is_meas1 = meas_name.find("1") != std::string::npos;
      bool is_meas2 = meas_name.find("2") != std::string::npos;

      std::vector<std::string> valid_sources;
      for (const auto &ch : osc.getHardwareChannels()) {
        std::string ch_name = ch->getLabel();
        if ((is_meas1 && ch_name.find("1") != std::string::npos) ||
            (is_meas2 && ch_name.find("2") != std::string::npos) ||
            (!is_meas1 && !is_meas2)) {
          valid_sources.push_back(ch_name);
        }
      }
      for (const auto &p : vc->getProcessors()) {
        if (p == proc) break;
        if (p->getType() != ProcessorType::Measurement) {
          std::string p_name = p->getName();
          if ((is_meas1 && p_name.find("1") != std::string::npos) ||
              (is_meas2 && p_name.find("2") != std::string::npos) ||
              (!is_meas1 && !is_meas2)) {
            valid_sources.push_back(p_name);
          }
        }
      }

      std::vector<const char *> source_cstr;
      for (const auto &label : valid_sources) {
        source_cstr.push_back(label.c_str());
      }

      int current_source = 0;
      for (size_t i = 0; i < valid_sources.size(); ++i) {
        if (valid_sources[i] == meas_proc->getSourceLabel()) {
          current_source = static_cast<int>(i);
          break;
        }
      }

      ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x * 0.5f);
      if (ImGui::Combo("Source", &current_source, source_cstr.data(),
                       static_cast<int>(source_cstr.size()))) {
        meas_proc->setSourceLabel(valid_sources[current_source]);
          osc.forceReprocess();
        }

        ImGui::Spacing();
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

      if (popout) {
        bool open = true;
        std::string window_name = meas_proc->getName() + " Info";
        if (ImGui::Begin(window_name.c_str(), &open, ImGuiWindowFlags_AlwaysAutoResize)) {
          ImGui::TextColored(color, "%s", meas_proc->getName().c_str());
          ImGui::Separator();
          ImGui::Text("Source: %s", meas_proc->getSourceLabel().c_str());
          ImGui::Spacing();
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
        }
        ImGui::End();
        if (!open) {
          meas_proc->setShowInPopup(false);
        }
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
