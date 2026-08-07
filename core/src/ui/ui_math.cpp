#include <ui/ui.hpp>
#include <ui/ui_helpers.hpp>
#include <processing/math_processor.hpp>
#include <imgui.h>
#include <algorithm>

namespace Scoped {

void OscilloscopeUI::drawMathControls(Oscilloscope &osc) {
  bool found_math = false;

  for (auto &channel : osc.getVirtualChannels()) {
    ImGui::PushID(channel->getLabel().c_str());

    for (auto &processor : channel->getProcessors()) {
      if (processor->getType() != ProcessorType::Math) {
        continue;
      }

      found_math = true;

      UI::drawComponentHeader(processor, processor->getName(), osc);

      drawVerticalControls(processor, osc);

      drawHorizontalControls(processor, osc);

      auto *math_proc = dynamic_cast<MathProcessor *>(processor);
      if (math_proc) {
        // Operation Selection
        const char *op_names[] = {"Add",    "Subtract",  "Multiply",
                                  "Invert", "Integrate", "Differentiate"};
        int current_op = static_cast<int>(math_proc->getOperation());
        if (drawCombo("Operation", &current_op, op_names, 6, true)) {
          math_proc->setOperation(static_cast<MathOperation>(current_op));
          osc.forceReprocess();
        }

        // Channels vector for dropdowns (Hardware channels only)
        std::vector<std::string> channel_labels;
        std::vector<const char *> channel_labels_cstr;
        size_t num_channels = osc.getHardwareChannels().size();
        channel_labels.resize(num_channels);
        channel_labels_cstr.resize(num_channels);
        int src1_idx = 0;
        int src2_idx = 0;
        bool found_src1 = false;
        bool found_src2 = false;
        for (size_t i = 0; i < num_channels; i++) {
          channel_labels[i] = osc.getHardwareChannels()[i]->getLabel();
          channel_labels_cstr[i] = channel_labels[i].c_str();
          if (channel_labels[i] == math_proc->getSource1Label()) {
            src1_idx = static_cast<int>(i);
            found_src1 = true;
          }
          if (channel_labels[i] == math_proc->getSource2Label()) {
            src2_idx = static_cast<int>(i);
            found_src2 = true;
          }
        }

        // Fix UI desync: if the processor holds a label that doesn't exist, sync it to what the combo box will default to
        if (!found_src1 && num_channels > 0) {
          math_proc->setSource1Label(channel_labels[0]);
          osc.forceReprocess();
        }
        if (!found_src2 && num_channels > 0) {
          math_proc->setSource2Label(channel_labels[0]);
          osc.forceReprocess();
        }

        if (drawCombo("Source 1", &src1_idx, channel_labels_cstr.data(),
                      static_cast<int>(num_channels), true)) {
          math_proc->setSource1Label(channel_labels[src1_idx]);
          osc.forceReprocess();
        }

        // Source 2 Selection (hidden for single-source operations)
        if (math_proc->getOperation() != MathOperation::INVERT &&
            math_proc->getOperation() != MathOperation::INTEGRATE &&
            math_proc->getOperation() != MathOperation::DIFFERENTIATE) {
          if (drawCombo("Source 2", &src2_idx, channel_labels_cstr.data(),
                        static_cast<int>(num_channels), true)) {
            math_proc->setSource2Label(channel_labels[src2_idx]);
            osc.forceReprocess();
          }
        }

        // Smoothing control for differentiation
        if (math_proc->getOperation() == MathOperation::DIFFERENTIATE) {
          int radius = static_cast<int>(math_proc->getDiffSmoothRadius());
          if (drawSliderIntWithInput("Smoothing Radius", &radius, 0, 128,
                                     "%d samples", true)) {
            math_proc->setDiffSmoothRadius(static_cast<size_t>(radius));
            osc.forceReprocess();
          }
        }
      }

      ImGui::Spacing();
      ImGui::Separator();
      ImGui::Spacing();
    }

    ImGui::PopID();
  }

  if (!found_math) {
    ImGui::TextDisabled("No Math processor found.");
  }
}

void OscilloscopeUI::drawMathWindow(Oscilloscope &osc) {
  ImGui::Begin("Math");
  ImGui::SetWindowFontScale(1.15f);

  drawMathControls(osc);

  ImGui::End();
}

} // namespace Scoped
