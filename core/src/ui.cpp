#include "implot.h"
#include "intensitymap.hpp"
#include <alloca.h>
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

static bool s_show_trigger_line = false;

void renderIntensityMap(IntensityMap &map, Trigger &trigger) {
  map.updateTexture();

  size_t w = map.getWidth();
  size_t h = map.getHeight();
  ImVec2 plot_size(-1.0f, -1.0f);

  ImPlot::PushStyleVar(ImPlotStyleVar_PlotPadding, ImVec2(0.0f, 0.0f));
  ImPlot::PushStyleVar(ImPlotStyleVar_PlotBorderSize, 0.0f);

  ImPlotFlags flags = ImPlotFlags_CanvasOnly | ImPlotFlags_NoLegend;

  // Snap cursor to pixel boundary to avoid sub-pixel blurring
  ImVec2 cursor = ImGui::GetCursorScreenPos();
  cursor.x = std::floor(cursor.x);
  cursor.y = std::floor(cursor.y);
  ImGui::SetCursorScreenPos(cursor);

  if (ImPlot::BeginPlot("##OscilloscopeImage", plot_size, flags)) {
    ImPlot::SetupAxesLimits(0, w, 0, h, ImGuiCond_Always);
    ImPlot::SetupAxisLimitsConstraints(ImAxis_X1, 0, w);
    ImPlot::SetupAxisLimitsConstraints(ImAxis_Y1, 0, h);

    ImPlot::SetupAxis(ImAxis_X1, nullptr, ImPlotAxisFlags_NoDecorations);
    ImPlot::SetupAxis(ImAxis_Y1, nullptr, ImPlotAxisFlags_NoDecorations);

    ImPlot::PlotImage("OscilloscopeTrace",
                      (ImTextureID)(intptr_t)map.getTextureID(),
                      ImPlotPoint(0, 0), ImPlotPoint(w, h));

    renderGrid(map);

    if (s_show_trigger_line) {
      renderTriggerIndicator(trigger, map);
    }

    ImPlot::EndPlot();
  }

  ImPlot::PopStyleVar(2);
}

/**
 * @brief Renders the hardware connection status and connect/disconnect buttons.
 */
static void renderHardwareSection(USBDevice &usb, CircularBuffer &buffer,
                                  Trigger &trigger) {
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
}

/**
 * @brief Renders controls for trigger level, edge type, and mode (Auto/Normal).
 */
static void renderTriggerControls(Trigger &trigger, IntensityMap &map) {
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
  s_show_trigger_line = ImGui::IsItemActive() || ImGui::IsItemHovered();

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
}

void renderTriggerIndicator(Trigger &trigger, IntensityMap &map) {
  // Scale the trigger level relative to the center (128) just like the waveform
  double threshold = static_cast<double>(trigger.getThreshold());
  double scaled_threshold = (threshold - 128.0) * map.getVerticalScale() + 128.0;

  double y_level = scaled_threshold * map.getHeight() / 256.0;
  double x[] = {0, (double)map.getWidth()};
  double y[] = {y_level, y_level};
  
  // Use ImPlotSpec to set color and weight inline
  ImPlot::PlotLine("##TriggerIndicator", x, y, 2, 
                  {ImPlotProp_LineColor, ImVec4(1, 0, 0, 0.5f), 
                   ImPlotProp_LineWeight, 2.0f});
}

void renderGrid(IntensityMap &map) {
  const double w = static_cast<double>(map.getWidth());
  const double h = static_cast<double>(map.getHeight());
  const ImVec4 grid_color(0.3f, 0.3f, 0.3f, 0.4f);

  // 10 vertical divisions
  for (int i = 0; i <= 10; ++i) {
    double x_pos = (w * i) / 10.0;
    double vx[] = {x_pos, x_pos};
    double vy[] = {0, h};
    float weight = (i == 5) ? 3.0f : 1.0f;
    ImPlot::PlotLine("##vgrid", vx, vy, 2, {ImPlotProp_LineColor, grid_color, ImPlotProp_LineWeight, weight});
  }

  // 8 horizontal divisions
  for (int i = 0; i <= 8; ++i) {
    double y_pos = (h * i) / 8.0;
    double hx[] = {0, w};
    double hy[] = {y_pos, y_pos};
    float weight = (i == 4) ? 3.0f : 1.0f;
    ImPlot::PlotLine("##hgrid", hx, hy, 2, {ImPlotProp_LineColor, grid_color, ImPlotProp_LineWeight, weight});
  }
}

/**
 * @brief Renders Timebase and Vertical Gain zoom controls.
 * @param visible_samples Reference to the number of samples to display from the
 * buffer.
 */
static void renderDivisionControls(IntensityMap &map, size_t &visible_samples) {
  ImGui::TextDisabled("DIVISION CONTROLS");
  ImGui::Separator();
  ImGui::Spacing();

  // Horizontal (Timebase)
  int samples = static_cast<int>(visible_samples);
  ImGui::SetNextItemWidth(-1);
  if (ImGui::SliderInt("##Timebase", &samples, 256, 16384,
                       "Time: %d samples")) {
    visible_samples = static_cast<size_t>(samples);
  }

  ImGui::Spacing();

  // Vertical (Gain)
  static float gain = 1.0f;
  ImGui::SetNextItemWidth(-1);
  if (ImGui::SliderFloat("##Gain", &gain, 0.1f, 10.0f, "Gain: %.1fx")) {
    map.setVerticalScale(gain);
  }
}

/**
 * @brief Renders the status bar with full Trigger and Horizontal controls.
 */
static void renderStatusBar(Trigger &trigger, size_t &visible_samples) {
  ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.11f, 0.14f, 0.18f, 1.0f));
  ImGui::BeginChild("StatusBar", ImVec2(0, 45), false);

  // Trigger Section
  ImGui::SetCursorPos(ImVec2(10, 12));
  ImGui::TextDisabled("TRG:");
  ImGui::SameLine();
  
  ImGui::SetNextItemWidth(100);
  int level = trigger.getThreshold();
  if (ImGui::SliderInt("##Level", &level, 0, 255, "L: %d")) {
    trigger.setThreshold(level);
  } 
  // Show trigger line when slider is being interacted with
  // Used in renderIntensityMap
  s_show_trigger_line = ImGui::IsItemActive() || ImGui::IsItemHovered();

  ImGui::SameLine();
  const char* edges[] = {"Rising", "Falling"};
  int edge = (trigger.getType() == TriggerType::RISING_EDGE ? 0 : 1);
  ImGui::SetNextItemWidth(90);
  if (ImGui::Combo("##Edge", &edge, edges, 2)) {
    trigger.setType(edge == 0 ? TriggerType::RISING_EDGE : TriggerType::FALLING_EDGE);
  }

  ImGui::SameLine();
  const char* modes[] = {"Auto", "Norm"};
  int mode = (trigger.getMode() == TriggerMode::AUTO ? 0 : 1);
  ImGui::SetNextItemWidth(70);
  if (ImGui::Combo("##Mode", &mode, modes, 2)) {
    trigger.setMode(mode == 0 ? TriggerMode::AUTO : TriggerMode::NORMAL);
  }

  // Horizontal Section
  ImGui::SameLine(ImGui::GetWindowWidth() - 250);
  ImGui::TextDisabled("HORIZ:");
  ImGui::SameLine();
  int samples = static_cast<int>(visible_samples);
  ImGui::SetNextItemWidth(150);
  if (ImGui::SliderInt("##Time", &samples, 256, 16384, "%d smp")) {
    visible_samples = samples;
  }

  ImGui::EndChild();
  ImGui::PopStyleColor();
}

/**
 * @brief Renders the bottom channel and hardware bar.
 */
static void renderChannelBar(IntensityMap &map, USBDevice &usb, CircularBuffer &buffer, Trigger &trigger) {
  ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.08f, 0.1f, 0.12f, 1.0f));
  ImGui::BeginChild("ChannelBar", ImVec2(0, 50), false);

  // Channel 1 Block
  ImGui::SetCursorPos(ImVec2(10, 7));
  ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(1.0f, 0.8f, 0.0f, 1.0f));
  ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0, 0, 0, 1));
  ImGui::BeginChild("C1", ImVec2(180, 36), true);
  ImGui::Text("C1");
  ImGui::SameLine(40);
  float gain = map.getVerticalScale();
  ImGui::SetNextItemWidth(120);
  if (ImGui::SliderFloat("##Gain", &gain, 0.1f, 10.0f, "G: %.1fx")) {
    map.setVerticalScale(gain);
  }
  ImGui::EndChild();
  ImGui::PopStyleColor(2);

  // Hardware Section
  ImGui::SameLine(ImGui::GetWindowWidth() - 320);
  ImGui::SetCursorPosY(12);
  if (usb.isConnected()) {
    ImGui::TextColored(ImVec4(0, 1, 0, 1), "CONNECTED");
    ImGui::SameLine();
    if (ImGui::Button("Disconnect")) {
      usb.stopStreaming();
      usb.disconnect();
    }
  } else {
    ImGui::TextColored(ImVec4(1, 0, 0, 1), "OFFLINE");
    ImGui::SameLine();
    if (ImGui::Button("Connect")) {
      if (usb.connect()) {
        buffer.clear();
        trigger.clear();
        usb.startStreaming(buffer);
      }
    }
  }

  ImGui::EndChild();
  ImGui::PopStyleColor();
}

void renderOscilloscopeUI(Trigger &trigger, IntensityMap &map, USBDevice &usb,
                          CircularBuffer &buffer, size_t &visible_samples) {
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

  // Layout Stack
  renderStatusBar(trigger, visible_samples);

  // Main Plot Area
  float available_height = ImGui::GetContentRegionAvail().y - 50; 
  ImGui::BeginChild("PlotContainer", ImVec2(0, available_height), false);
  renderIntensityMap(map, trigger);
  ImGui::EndChild();

  renderChannelBar(map, usb, buffer, trigger);

  ImGui::End();
}


} // namespace Scoped
