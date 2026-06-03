#include <ui/ui.hpp>
#include <ui/ui_helpers.hpp>
#include <processing/filter_processor.hpp>
#include <imgui.h>
#include <implot.h>
#include <algorithm>

namespace Scoped {

void OscilloscopeUI::drawFilterControls(Oscilloscope &osc) {
  bool found_filter = false;

  for (auto &channel : osc.getVirtualChannels()) {
    ImGui::PushID(channel->getLabel().c_str());

    for (auto &processor : channel->getProcessors()) {
      if (processor->getType() != ProcessorType::Filter) {
        continue;
      }

      auto *filter_proc = dynamic_cast<FilterProcessor *>(processor);
      if (!filter_proc) {
        continue;
      }

      found_filter = true;

      UI::drawComponentHeader(filter_proc, filter_proc->getName(), osc,
                          Scoped::Constants::DEFAULT_HORIZONTAL_SCALE);

      auto drawSlider = [&](const char *label, float *v, float v_min,
                            float v_max, const char *format, bool add_spacing) {
        return this->drawSliderFloatWithInput(label, v, v_min, v_max, format,
                                              add_spacing);
      };
      UI::drawVerticalControlsT(filter_proc, osc, -500.0f, 500.0f, "%.1f",
                            drawSlider);

      int h_scale = static_cast<int>(filter_proc->getHorizontalScale());
      if (drawSliderIntWithInput("Horizontal Scale", &h_scale, 256, 16384,
                                 "%d samples", false)) {
        filter_proc->setHorizontalScale(static_cast<size_t>(h_scale));
        osc.forceReprocess();
      }

      int h_offset = static_cast<int>(filter_proc->getHorizontalOffset());
      int capture_width = static_cast<int>(osc.getMaxCaptureWidth());
      int visible_width = static_cast<int>(filter_proc->getHorizontalScale());
      int max_offset = std::max(0, (capture_width - visible_width) / 2);
      if (h_offset > max_offset) {
        h_offset = max_offset;
        filter_proc->setHorizontalOffset(static_cast<size_t>(h_offset));
      }
      if (drawSliderIntWithInput("Horizontal Offset", &h_offset, -max_offset,
                                 max_offset, "%d samples", true)) {
        filter_proc->setHorizontalOffset(static_cast<size_t>(h_offset));
        osc.forceReprocess();
      }

      int selected_type = static_cast<int>(filter_proc->getFilterType());
      const char *types[] = {"Lowpass", "Highpass", "Bandpass", "Bandstop"};
      if (drawCombo("Filter Type", &selected_type, types, 4, true)) {
        filter_proc->setFilterType(static_cast<FilterType>(selected_type));
        osc.forceReprocess();
      }

      int selected_resp = static_cast<int>(filter_proc->getFilterResponse());
      const char *resps[] = {"Butterworth", "Chebyshev", "Bessel", "Basic"};
      if (drawCombo("Response", &selected_resp, resps, 4, true)) {
        filter_proc->setFilterResponse(
            static_cast<FilterResponse>(selected_resp));
        osc.forceReprocess();
      }

      std::vector<std::string> channel_labels;
      std::vector<const char *> channel_labels_cstr;
      size_t num_channels = osc.getHardwareChannels().size();
      channel_labels.resize(num_channels);
      channel_labels_cstr.resize(num_channels);
      int src1_idx = 0;
      for (size_t i = 0; i < num_channels; i++) {
        channel_labels[i] = osc.getHardwareChannels()[i]->getLabel();
        channel_labels_cstr[i] = channel_labels[i].c_str();
        if (channel_labels[i] == filter_proc->getSource1Label()) {
          src1_idx = static_cast<int>(i);
        }
      }

      float nyquist = Scoped::Constants::ADC_SAMPLE_RATE_HZ / 2.0f;
      FilterType type = filter_proc->getFilterType();
      
      if (type == FilterType::Bandpass || type == FilterType::Bandstop) {
        float cutoff1 = filter_proc->getCutoff();
        ImGui::Text("Lower Cutoff Frequency");
        ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
        if (ImGui::InputFloat("##Lower Cutoff Frequency", &cutoff1, 0.0f, 0.0f,
                              "%.1f Hz")) {
          cutoff1 = std::clamp(cutoff1, 1.0f, std::min(filter_proc->getCutoff2() - 1.0f, nyquist));
          filter_proc->setCutoff(cutoff1);
          osc.forceReprocess();
        }

        float cutoff2 = filter_proc->getCutoff2();
        ImGui::Text("Upper Cutoff Frequency");
        ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
        if (ImGui::InputFloat("##Upper Cutoff Frequency", &cutoff2, 0.0f, 0.0f,
                              "%.1f Hz")) {
          cutoff2 = std::clamp(cutoff2, std::max(filter_proc->getCutoff() + 1.0f, 1.0f), nyquist);
          filter_proc->setCutoff2(cutoff2);
          osc.forceReprocess();
        }
      } else {
        float cutoff = filter_proc->getCutoff();
        ImGui::Text("Cutoff Frequency");
        ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
        if (ImGui::InputFloat("##Cutoff Frequency", &cutoff, 0.0f, 0.0f,
                              "%.1f Hz")) {
          filter_proc->setCutoff(std::clamp(cutoff, 1.0f, nyquist));
          osc.forceReprocess();
        }
      }

      if (drawCombo("Source", &src1_idx, channel_labels_cstr.data(),
                    static_cast<int>(num_channels), true)) {
        filter_proc->setSource1Label(channel_labels[src1_idx]);
        osc.forceReprocess();
      }

      ImGui::Spacing();

      bool show_preview = filter_proc->getShowPreview();
      if (ImGui::Checkbox("Preview Frequency Response", &show_preview)) {
        filter_proc->setShowPreview(show_preview);
      }

      if (show_preview) {
        ImGui::SetNextWindowSize(ImVec2(600, 400), ImGuiCond_FirstUseEver);
        std::string window_name =
            filter_proc->getName() + std::string(" Frequency Response:");

        if (ImGui::Begin(window_name.c_str(), &show_preview)) {
          ImGui::SetWindowFontScale(1.25f); // Make the graph text 25% larger
          const auto &mag_resp =
              filter_proc->getMagnitudeResponse();
          if (!mag_resp.empty()) {
            if (ImPlot::BeginPlot("Frequency Response", ImVec2(-1, -1),
                                  ImPlotFlags_NoTitle | ImPlotFlags_NoLegend)) {
              ImPlot::SetupAxes("Frequency (Hz)", "Gain (dB)",
                                ImPlotAxisFlags_AutoFit,
                                ImPlotAxisFlags_AutoFit);
              ImPlot::SetupAxisScale(ImAxis_X1, ImPlotScale_Log10);

              float highest_cutoff = filter_proc->getCutoff();
              if (filter_proc->getFilterType() == FilterType::Bandpass || filter_proc->getFilterType() == FilterType::Bandstop) {
                  highest_cutoff = std::max(highest_cutoff, filter_proc->getCutoff2());
              }
              float plot_max_x = std::min(highest_cutoff * 2.5f, nyquist);
              plot_max_x = std::max(plot_max_x, 100.0f);

              // Avoid 0 in log scale
              ImPlot::SetupAxisLimits(ImAxis_X1, 1.0f, plot_max_x,
                                      ImPlotCond_Always);
              ImPlot::SetupAxisLimits(ImAxis_Y1, -60, 10, ImPlotCond_Always);

              ImPlot::PlotLine("##Resp", mag_resp.data(),
                               static_cast<int>(mag_resp.size()),
                               nyquist / mag_resp.size());

              double cutoffs[2] = { static_cast<double>(filter_proc->getCutoff()), 
                                    static_cast<double>(filter_proc->getCutoff2()) };
              
              if (filter_proc->getFilterType() == FilterType::Bandpass || filter_proc->getFilterType() == FilterType::Bandstop) {
                  ImPlot::PlotInfLines("Cutoff Frequencies", cutoffs, 2);
                  ImPlot::TagX(cutoffs[0], ImVec4(0.2f, 0.6f, 1.0f, 1.0f), "w1", cutoffs[0]);
                  ImPlot::TagX(cutoffs[1], ImVec4(0.2f, 0.6f, 1.0f, 1.0f), "w2", cutoffs[1]);
              } else {
                  ImPlot::PlotInfLines("Cutoff Frequency", cutoffs, 1);
                  ImPlot::TagX(cutoffs[0], ImVec4(0.2f, 0.6f, 1.0f, 1.0f), "w", cutoffs[0]);
              }

              ImPlot::EndPlot();
            }
          }
        }
        ImGui::End();

        if (!show_preview) {
          filter_proc->setShowPreview(false);
        }
      }

      ImGui::Separator();
      ImGui::Spacing();
    }

    ImGui::PopID();
  }

  if (!found_filter) {
    ImGui::TextDisabled("No filter processor found.");
  }
}

void OscilloscopeUI::drawFilterWindow(Oscilloscope &osc) {
  ImGui::Begin("Filter");
  ImGui::SetWindowFontScale(1.15f);

  drawFilterControls(osc);

  ImGui::End();
}

} // namespace Scoped
