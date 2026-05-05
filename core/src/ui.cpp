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
  ImVec2 plot_size(-1.0f, -1.0f);

  ImPlot::PushStyleVar(ImPlotStyleVar_PlotPadding, ImVec2(0.0f, 0.0f));
  ImPlot::PushStyleVar(ImPlotStyleVar_PlotBorderSize, 0.0f);

  ImPlotFlags flags =
      ImPlotFlags_CanvasOnly | ImPlotFlags_NoLegend;

  // Snap cursor to pixel boundary to avoid sub-pixel blurring
  ImVec2 cursor = ImGui::GetCursorScreenPos();
  cursor.x = std::floor(cursor.x);
  cursor.y = std::floor(cursor.y);
  ImGui::SetCursorScreenPos(cursor);

  if (ImPlot::BeginPlot("##OscilloscopeImage", plot_size, flags)) {
    ImPlot::SetupAxesLimits(0, w, 0, h, ImGuiCond_Once);
    ImPlot::SetupAxisLimitsConstraints(ImAxis_X1, 0, w);
    ImPlot::SetupAxisLimitsConstraints(ImAxis_Y1, 0, h);

    ImPlot::SetupAxis(ImAxis_X1, nullptr, ImPlotAxisFlags_NoDecorations);
    ImPlot::SetupAxis(ImAxis_Y1, nullptr, ImPlotAxisFlags_NoDecorations);

    ImPlot::PlotImage("OscilloscopeTrace",
                      (ImTextureID)(intptr_t)map.getTextureID(),
                      ImPlotPoint(0, 0), ImPlotPoint(w, h));

    ImPlot::EndPlot();
  }

  ImPlot::PopStyleVar(2);
}

void renderOscilloscopeUI(Trigger &trigger, IntensityMap &map, USBDevice &usb, CircularBuffer &buffer) {
  const ImGuiViewport *viewport = ImGui::GetMainViewport();
  ImGui::SetNextWindowPos(viewport->WorkPos);
  ImGui::SetNextWindowSize(viewport->WorkSize);
  ImGui::SetNextWindowViewport(viewport->ID);

  ImGuiWindowFlags window_flags =
      ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar |
      ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
      ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus |
      ImGuiWindowFlags_NoNavFocus;

  ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

  ImGui::Begin("OscilloscopeMain", nullptr, window_flags);
  ImGui::PopStyleVar(3);

  if (ImGui::BeginTable("Split", 2, ImGuiTableFlags_BordersInnerV)) {
    ImGui::TableSetupColumn("Plot", ImGuiTableColumnFlags_WidthStretch, 0.8f);
    ImGui::TableSetupColumn("Controls", ImGuiTableColumnFlags_WidthFixed,
                            250.0f);

    ImGui::TableNextRow();
    ImGui::TableSetColumnIndex(0);

    renderIntensityMap(map);

    ImGui::TableSetColumnIndex(1);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(16.0f, 16.0f));
    ImGui::BeginChild("ControlsChild", ImVec2(0, 0),
                      ImGuiChildFlags_AlwaysUseWindowPadding, 0);

    ImGui::TextDisabled("HARDWARE");
    ImGui::Separator();
    ImGui::Spacing();

    if (usb.isConnected()) {
      ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "Status: Connected");
      if (ImGui::Button("Disconnect", ImVec2(-1, 0))) {
        usb.disconnect();
      }
    } else {
      ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Status: Disconnected");
      if (ImGui::Button("Connect USB", ImVec2(-1, 0))) {
        if (usb.connect()) {
          buffer.clear();
          trigger.clear();
          usb.startStreaming(buffer);
        }
      }
    }

    ImGui::Spacing();
    ImGui::Spacing();

    ImGui::TextDisabled("TRIGGER CONTROLS");
    ImGui::Separator();
    ImGui::Spacing();

    static int trigger_level = 128;
    static int edge_selection = 0;
    static int mode_selection = 0;
    const char *edge_options[] = {"Rising Edge", "Falling Edge"};
    const char *mode_options[] = {"Auto", "Normal"};

    ImGui::SetNextItemWidth(-1);
    ImGui::SliderInt("##Level", &trigger_level, 0, 255, "Level: %d");

    ImGui::Spacing();

    ImGui::SetNextItemWidth(-1);
    ImGui::Combo("##Edge", &edge_selection, edge_options, 2);

    ImGui::Spacing();

    ImGui::SetNextItemWidth(-1);
    ImGui::Combo("##Mode", &mode_selection, mode_options, 2);

    trigger.setThreshold(static_cast<uint8_t>(trigger_level));
    trigger.setType(edge_selection == 0 ? Scoped::TriggerType::RISING_EDGE
                                         : Scoped::TriggerType::FALLING_EDGE);
    trigger.setMode(mode_selection == 0 ? Scoped::TriggerMode::AUTO
                                         : Scoped::TriggerMode::NORMAL);

    ImGui::EndChild();
    ImGui::PopStyleVar();

    ImGui::EndTable();
  }

  ImGui::End();
}

} // namespace Scoped
