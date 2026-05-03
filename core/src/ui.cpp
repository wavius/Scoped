#include <cmath>
#include <ui.hpp>

namespace Scoped {

void setupChannelColormap(ImVec4 channel_color) {
  static bool mapInitialized = false;
  if (!mapInitialized) {
    // Create a 2-point gradient: Black (0) to Channel Color (1+)
    ImVec4 colors[2] = {ImVec4(0, 0, 0, 1), channel_color};
    ImPlot::AddColormap("ChannelMap", colors, 2);
    mapInitialized = true;
  }
}

void renderIntensityMap(IntensityMap &map) {
  // Make sure to update the texture right before rendering!
  map.updateTexture();

  size_t w = map.getWidth();
  size_t h = map.getHeight();
  ImVec2 plotSize = ImVec2(static_cast<float>(w), static_cast<float>(h));

  ImPlot::PushStyleVar(ImPlotStyleVar_PlotPadding, ImVec2(0.0f, 0.0f));
  ImPlot::PushStyleVar(ImPlotStyleVar_PlotBorderSize, 0.0f);

  ImPlotFlags plotFlags =
      ImPlotFlags_CanvasOnly | ImPlotFlags_NoLegend | ImPlotFlags_NoInputs;

  ImVec2 cursorPos = ImGui::GetCursorScreenPos();
  cursorPos.x = std::floor(cursorPos.x);
  cursorPos.y = std::floor(cursorPos.y);
  ImGui::SetCursorScreenPos(cursorPos);

  if (ImPlot::BeginPlot("##OscilloscopeImage", plotSize, plotFlags)) {
    ImPlot::SetupAxesLimits(0, w, 0, h, ImGuiCond_Always);
    ImPlot::SetupAxis(ImAxis_X1, nullptr, ImPlotAxisFlags_NoDecorations);
    ImPlot::SetupAxis(ImAxis_Y1, nullptr, ImPlotAxisFlags_NoDecorations);

    // Render the GPU texture directly
    ImPlot::PlotImage(
        "OscilloscopeTrace", (ImTextureID)(intptr_t)map.getTextureID(),
        ImPlotPoint(0, 0), // Bottom-Left (Flips the texture right-side up)
        ImPlotPoint(w, h)  // Top-Right
    );

    ImPlot::EndPlot();
  }

  ImPlot::PopStyleVar(2);
}

} // namespace Scoped
