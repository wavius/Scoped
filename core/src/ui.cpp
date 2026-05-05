#include <cmath>
#include <ui.hpp>

namespace Scoped {

void setupChannelColormap(ImVec4 color) {
  static bool initialized = false;
  if (initialized)
    return;

  ImVec4 gradient[2] = {ImVec4(0, 0, 0, 1), color};
  ImPlot::AddColormap("ChannelMap", gradient, 2);
  initialized = true;
}

void renderIntensityMap(IntensityMap &map) {
  map.updateTexture();

  size_t w = map.getWidth();
  size_t h = map.getHeight();
  ImVec2 plot_size(static_cast<float>(w), static_cast<float>(h));

  ImPlot::PushStyleVar(ImPlotStyleVar_PlotPadding, ImVec2(0.0f, 0.0f));
  ImPlot::PushStyleVar(ImPlotStyleVar_PlotBorderSize, 0.0f);

  ImPlotFlags flags =
      ImPlotFlags_CanvasOnly | ImPlotFlags_NoLegend | ImPlotFlags_NoInputs;

  // Snap cursor to pixel boundary to avoid sub-pixel blurring
  ImVec2 cursor = ImGui::GetCursorScreenPos();
  cursor.x = std::floor(cursor.x);
  cursor.y = std::floor(cursor.y);
  ImGui::SetCursorScreenPos(cursor);

  if (ImPlot::BeginPlot("##OscilloscopeImage", plot_size, flags)) {
    ImPlot::SetupAxesLimits(0, w, 0, h, ImGuiCond_Always);
    ImPlot::SetupAxis(ImAxis_X1, nullptr, ImPlotAxisFlags_NoDecorations);
    ImPlot::SetupAxis(ImAxis_Y1, nullptr, ImPlotAxisFlags_NoDecorations);

    ImPlot::PlotImage("OscilloscopeTrace",
                      (ImTextureID)(intptr_t)map.getTextureID(),
                      ImPlotPoint(0, 0), ImPlotPoint(w, h));

    ImPlot::EndPlot();
  }

  ImPlot::PopStyleVar(2);
}

} // namespace Scoped
