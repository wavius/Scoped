#include <ui/ui.hpp>
#include <ui/ui_helpers.hpp>
#include <processing/fft_processor.hpp>
#include <imgui.h>
#include <algorithm>

namespace Scoped {

void OscilloscopeUI::drawFFTControls(Oscilloscope &osc) {
  bool found_fft = false;

  for (auto &channel : osc.getHardwareChannels()) {
    ImGui::PushID(channel->getLabel().c_str());

    for (auto &processor : channel->getProcessors()) {
      if (processor->getType() != ProcessorType::FFT) {
        continue;
      }

      auto *fft_proc = dynamic_cast<FFTProcessor *>(processor);
      if (!fft_proc) {
        continue;
      }

      found_fft = true;

      UI::drawComponentHeader(fft_proc, fft_proc->getName(), osc,
                          fft_proc->getWindowSize() / 2);

      drawVerticalControls(fft_proc, osc);

      float sample_rate = Constants::ADC_SAMPLE_RATE_HZ;
      int fft_size = static_cast<int>(fft_proc->getWindowSize());
      int num_bins = fft_size / 2;
      float hz_per_bin = sample_rate / static_cast<float>(fft_size);
      
      int h_scale = static_cast<int>(fft_proc->getHorizontalScale());
      if (h_scale == 0 || h_scale > num_bins)
        h_scale = num_bins;
        
      float freq_scale_hz = h_scale * hz_per_bin;
      if (drawSliderFloatWithInput("Freq Scale", &freq_scale_hz, 2.0f * hz_per_bin, num_bins * hz_per_bin,
                                 "%.2f Hz", false)) {
        fft_proc->setHorizontalScale(static_cast<size_t>(freq_scale_hz / hz_per_bin));
        osc.forceReprocess();
      }

      int h_offset = static_cast<int>(fft_proc->getHorizontalOffset());
      int max_offset = std::max(1, num_bins - h_scale);
      if (h_offset > max_offset) {
        h_offset = max_offset;
        fft_proc->setHorizontalOffset(static_cast<size_t>(h_offset));
      }
      
      float freq_offset_hz = h_offset * hz_per_bin;
      float max_offset_hz = max_offset * hz_per_bin;
      if (drawSliderFloatWithInput("Freq Offset", &freq_offset_hz, 0, max_offset_hz,
                                 "%.2f Hz", true)) {
        fft_proc->setHorizontalOffset(static_cast<size_t>(freq_offset_hz / hz_per_bin));
        osc.forceReprocess();
      }

      int selected_mode = fft_proc->getIsModeLinear() ? 0 : 1;
      const char *modes[] = {"Linear", "Decibel"};
      if (drawCombo("Representation", &selected_mode, modes, 2, true)) {
        fft_proc->setIsModeLinear(selected_mode == 0);
        osc.forceReprocess();
      }

      // Window Type Selection
      const char *window_types[] = {"Rectangular", "Hann", "Hamming",
                                    "Blackman-Harris", "Flat Top"};
      int current_type = 0;
      std::string current_name = fft_proc->getWindowTypeName();
      for (int i = 0; i < 5; i++) {
        if (current_name == window_types[i]) {
          current_type = i;
          break;
        }
      }

      if (drawCombo("Window Function", &current_type, window_types, 5, true)) {
        fft_proc->setWindowType(current_type);
        osc.forceReprocess();
      }

      float smoothing_factor = fft_proc->getSmoothingFactor();
      if (drawSliderFloatWithInput("Smoothing", &smoothing_factor, 0.0f, 1.00f,
                                   "%.2f", true)) {
        fft_proc->setSmoothingFactor(smoothing_factor);
        osc.forceReprocess();
      }

      if (drawSliderIntWithInput("Resolution", &fft_size, 256, 16384,
                                 "%d samples", true)) {
        fft_proc->setWindowSize(static_cast<size_t>(fft_size));
        osc.forceReprocess();
      }

      ImGui::Spacing();
      ImGui::Separator();
      ImGui::Spacing();
    }

    ImGui::PopID();
  }

  if (!found_fft) {
    ImGui::TextDisabled("No FFT processor found.");
  }
}

void OscilloscopeUI::drawFFTWindow(Oscilloscope &osc) {
  ImGui::Begin("FFT");
  ImGui::SetWindowFontScale(1.15f);

  drawFFTControls(osc);

  ImGui::End();
}

} // namespace Scoped
