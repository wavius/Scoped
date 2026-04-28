#include "test.hpp"

namespace Test {

void RenderUI() {

  float bar_data[] = {11.0f};
  float x_data[] = {1.0f};
  float y_data[] = {1.0f};

  ImGui::Begin("Test1");
  if (ImPlot::BeginPlot("My Plot")) {
    ImPlot::PlotBars("My Bar Plot", bar_data, 11);
    ImPlot::PlotLine("My Line Plot", x_data, y_data, 1000);
    ImPlot::EndPlot();
  }
  ImGui::End();
}
} // namespace Test
