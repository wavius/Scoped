#pragma once

#include <common/constants.hpp>
#include <processing/fft_processor.hpp>
#include <ui/ui.hpp>
#include <ui/colors.hpp>
#include <imgui.h>
#include <string>
#include <type_traits>

namespace Scoped {
namespace UI {

template <typename T>
inline void drawComponentHeader(
    T *component, const std::string &name, Scoped::Oscilloscope &osc,
    size_t default_h_scale = Scoped::Constants::DEFAULT_HORIZONTAL_SCALE) {
  ImVec4 label_color = Scoped::toImVec4(component->getColor());
  bool enabled = component->isEnabled();

  ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(4, 4));
  if (ImGui::Checkbox("##Enabled", &enabled)) {
    component->setEnabled(enabled);
  }
  ImGui::PopStyleVar();
  ImGui::SameLine();

  ImGui::TextColored(label_color, "%s", name.c_str());
  ImGui::SameLine(ImGui::GetWindowWidth() - 70.0f);

  std::string reset_label = "Reset##" + name;
  if (ImGui::Button(reset_label.c_str())) {
    component->setVerticalScale(Scoped::Constants::DEFAULT_VERTICAL_SCALE);
    component->setVerticalOffset(Scoped::Constants::DEFAULT_VERTICAL_OFFSET);
    component->setHorizontalScale(default_h_scale);
    component->setHorizontalOffset(
        Scoped::Constants::DEFAULT_HORIZONTAL_OFFSET);

    if constexpr (std::is_same_v<std::remove_cv_t<T>, Scoped::FFTProcessor>) {
      component->setIsModeLinear(false);
      component->setSmoothingFactor(0.0f);
    }
    osc.forceReprocess();
  }
  ImGui::Spacing();
}

template <typename T, typename DrawSliderFunc>
inline void drawVerticalControlsT(T *target, Scoped::Oscilloscope &osc, float v_min,
                                  float v_max, const char *format_offset,
                                  DrawSliderFunc drawSlider) {
  float scale = target->getVerticalScale();
  if (drawSlider("Vertical Scale", &scale, 0.01f, 10.0f, "%.2f", false)) {
    target->setVerticalScale(scale);
    osc.forceReprocess();
  }

  float offset = target->getVerticalOffset();
  if (drawSlider("Vertical Offset", &offset, v_min, v_max, format_offset,
                 true)) {
    target->setVerticalOffset(offset);
    osc.forceReprocess();
  }
}

} // namespace UI
} // namespace Scoped
