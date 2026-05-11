#include "imgui.h"
#include "imgui_internal.h"
#include "implot.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include <ui/ui.hpp>

namespace Scoped {

// colors 
namespace Colors {
const ImVec4 Black = ImVec4(0, 0, 0, 1);
const ImVec4 Grid = ImVec4(0.3f, 0.3f, 0.3f, 0.4f);
const ImVec4 Trigger = ImVec4(1, 0, 0, 0.5f);
const ImVec4 FFTLine = ImVec4(1.0f, 1.0f, 0.0f, 1.0f);
const ImVec4 StatusOk = ImVec4(0, 1, 0, 1);
const ImVec4 StatusError = ImVec4(1, 0, 0, 1);
} // namespace Colors


static void plotLineSegment(const char *label, double x0, double y0, double x1,
                            double y1, ImVec4 color, float weight) {
  double xs[] = {x0, x1};
  double ys[] = {y0, y1};

  ImPlot::PlotLine(label, xs, ys, 2,
                   {ImPlotProp_LineColor, color, ImPlotProp_LineWeight,
                    weight});
}


// Colour gradient for the oscilloscope trace image
void setupChannelColormap(ImVec4 color) {
  static bool initialized = false;

  if (initialized) {
    return;
  }

  ImVec4 gradient[2] = {Colors::Black, color};
  ImPlot::AddColormap("ChannelMap", gradient, 2);

  initialized = true;
}


OscilloscopeUI::OscilloscopeUI(size_t display_width, size_t display_height)
    : m_display_width(display_width), m_display_height(display_height) {}


void OscilloscopeUI::processNewFrames(Oscilloscope &osc) {
  const auto &channels = osc.getChannels();

  while (m_displays.size() < channels.size()) {
    m_displays.push_back(
        std::make_unique<IntensityMap>(m_display_width, m_display_height));
  }

  for (size_t i = 0; i < channels.size(); ++i) {
    auto &channel = *channels[i];

    if (!channel.hasNewFrame()) {
      continue;
    }

    const auto &traces = channel.getTraces();

    for (const auto &trace : traces) {
      if (trace.domain == Domain::Time) {
        size_t visible =
            std::min(channel.getVisibleSamples(), trace.data.size());

        m_normalized_time.resize(visible);

        for (size_t j = 0; j < visible; ++j) {
          m_normalized_time[j] = trace.normalizeToIntensity(trace.data[j]);
        }

        m_displays[i]->clear();
        m_displays[i]->processFrame(m_normalized_time.data(), visible);
      }
    }

    channel.clearNewFrame();
  }
}

// Draws oscilloscope grid lines over the main plot area.
void OscilloscopeUI::drawGridLines(double w, double h) {
  for (int i = 0; i <= 10; ++i) {
    double x = (w * i) / 10.0;
    float weight = (i == 5) ? 3.0f : 1.0f;

    plotLineSegment("##vgrid", x, 0, x, h, Colors::Grid, weight);
  }

  for (int i = 0; i <= 8; ++i) {
    double y = (h * i) / 8.0;
    float weight = (i == 4) ? 3.0f : 1.0f;

    plotLineSegment("##hgrid", 0, y, w, y, Colors::Grid, weight);
  }
}

// Draws the trigger level line when the checkbox is enabled.
void OscilloscopeUI::drawTriggerLine(Oscilloscope &osc) {
  auto *trigger = osc.getTrigger();

  if (!trigger || osc.getChannels().empty()) {
    return;
  }

  auto levels = trigger->getTriggerLevels();

  if (levels.empty()) {
    return;
  }

  auto &channel = osc.getChannels()[0];
  auto traces = channel->getTraces();

  if (traces.empty()) {
    return;
  }

  auto &trace = traces[0];

  for (float level : levels) {
    float y_normalized = trace.normalizeToIntensity(level);
    double y_level = y_normalized * m_display_height;

    plotLineSegment("##TriggerLine", 0.0, y_level,
                    static_cast<double>(m_display_width), y_level,
                    Colors::Trigger, 2.0f);
  }
}

// Draws FFT data over the scope display when FFT is enabled.
void OscilloscopeUI::drawFrequencyTraces(Oscilloscope &osc) {
  for (const auto &channel : osc.getChannels()) {
    for (const auto &trace : channel->getTraces()) {
      if (trace.domain == Domain::Frequency) {
        size_t visible =
            std::min(channel->getVisibleSamples(), trace.data.size());

        m_normalized_freq.resize(visible);

        for (size_t i = 0; i < visible; i++) {
          m_normalized_freq[i] = trace.normalizeToIntensity(trace.data[i]);
        }

        ImPlot::PlotLine(trace.name.c_str(), m_normalized_freq.data(),
                         m_normalized_freq.size(), 1.0, 0.0,
                         {ImPlotProp_LineColor, Colors::FFTLine,
                          ImPlotProp_LineWeight, 2.0f});
      }
    }
  }
}


void OscilloscopeUI::drawPlotArea(Oscilloscope &osc) {
  const double w = static_cast<double>(m_display_width);
  const double h = static_cast<double>(m_display_height);

  ImPlot::PushStyleVar(ImPlotStyleVar_PlotPadding, ImVec2(0, 0));
  ImPlot::PushStyleVar(ImPlotStyleVar_PlotBorderSize, 0.0f);

  ImVec2 cursor = ImGui::GetCursorScreenPos();
  cursor.x = std::floor(cursor.x);
  cursor.y = std::floor(cursor.y);
  ImGui::SetCursorScreenPos(cursor);

  ImPlotFlags flags = ImPlotFlags_CanvasOnly | ImPlotFlags_NoLegend;

  if (ImPlot::BeginPlot("##OscilloscopeImage", ImVec2(-1, -1), flags)) {
    ImPlot::SetupAxesLimits(0, w, 0, h, ImGuiCond_Always);
    ImPlot::SetupAxisLimitsConstraints(ImAxis_X1, 0, w);
    ImPlot::SetupAxisLimitsConstraints(ImAxis_Y1, 0, h);
    ImPlot::SetupAxis(ImAxis_X1, nullptr, ImPlotAxisFlags_NoDecorations);
    ImPlot::SetupAxis(ImAxis_Y1, nullptr, ImPlotAxisFlags_NoDecorations);

    for (size_t i = 0; i < m_displays.size(); ++i) {
      m_displays[i]->updateTexture();

      ImPlot::PlotImage(("OscilloscopeTrace" + std::to_string(i)).c_str(),
                        (ImTextureID)(intptr_t)m_displays[i]->getTextureID(),
                        ImPlotPoint(0, 0), ImPlotPoint(w, h));
    }

    drawFrequencyTraces(osc);
    drawGridLines(w, h);

    if (m_show_trigger_line) {
      drawTriggerLine(osc);
    }

    ImPlot::EndPlot();
  }

  ImPlot::PopStyleVar(2);
}

// Small reusable control for trigger mode.
void OscilloscopeUI::drawModeCombo(Oscilloscope &osc) {
  if (!osc.getTrigger()) {
    return;
  }

  const char *items[] = {"Auto", "Norm"};
  int selected = (osc.getTrigger()->getMode() == TriggerMode::AUTO) ? 0 : 1;

  ImGui::SetNextItemWidth(-1);

  if (ImGui::Combo("Mode", &selected, items, 2)) {
    TriggerMode mode = selected == 0 ? TriggerMode::AUTO : TriggerMode::NORMAL;
    osc.getTrigger()->setMode(mode);
  }
}

// Controls how many samples are visible horizontally.
void OscilloscopeUI::drawTimebaseControl(Oscilloscope &osc) {
  if (osc.getChannels().empty()) {
    return;
  }

  auto &channel = *osc.getChannels()[0];

  int samples = static_cast<int>(channel.getVisibleSamples());

  ImGui::SetNextItemWidth(-1);

  if (ImGui::SliderInt("Visible samples", &samples, 256, 16384, "%d smp")) {
    for (auto &ch : osc.getChannels()) {
      ch->setVisibleSamples(static_cast<size_t>(samples));
    }
  }
}

// FFT controls.
void OscilloscopeUI::drawFFTControl(Oscilloscope &osc) {
  bool found_fft = false;

  for (auto &channel : osc.getChannels()) {
    ImGui::PushID(channel->getLabel().c_str());

    for (auto &processor : channel->getProcessors()) {
      if (processor->getName() != "FFT") {
        continue;
      }

      found_fft = true;

      ImGui::Text("%s", channel->getLabel().c_str());

      bool enabled = processor->isEnabled();

      if (ImGui::Checkbox("Enabled", &enabled)) {
        processor->setEnabled(enabled);
      }

      float scale = processor->getScale();

      ImGui::SetNextItemWidth(-1);

      if (ImGui::SliderFloat("Scale", &scale, 0.01f, 1.00f, "%.2f")) {
        processor->setScale(scale);
      }

      bool linear = processor->getIsModeLinear();

      if (ImGui::Checkbox("Linear mode", &linear)) {
        processor->setIsModeLinear(linear);
      }

      ImGui::Separator();
    }

    ImGui::PopID();
  }

  if (!found_fft) {
    ImGui::TextDisabled("No FFT processor found.");
  }
}

void OscilloscopeUI::buildDefaultDockLayout(ImGuiID dockspace_id,
                                            const ImVec2 &dockspace_size) {
  ImGui::DockBuilderRemoveNode(dockspace_id);

  ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace);
  ImGui::DockBuilderSetNodeSize(dockspace_id, dockspace_size);

  ImGuiID main_id = dockspace_id;

  ImGuiID left_id =
      ImGui::DockBuilderSplitNode(main_id, ImGuiDir_Left, 0.22f, nullptr,
                                  &main_id);

  ImGuiID right_id =
      ImGui::DockBuilderSplitNode(main_id, ImGuiDir_Right, 0.22f, nullptr,
                                  &main_id);

  ImGuiID bottom_id =
      ImGui::DockBuilderSplitNode(main_id, ImGuiDir_Down, 0.24f, nullptr,
                                  &main_id);

  ImGui::DockBuilderDockWindow("Scope View", main_id);

  ImGui::DockBuilderDockWindow("Trigger", left_id);
  ImGui::DockBuilderDockWindow("Channels", left_id);

  ImGui::DockBuilderDockWindow("FFT", right_id);
  ImGui::DockBuilderDockWindow("Hardware", right_id);

  ImGui::DockBuilderDockWindow("Debug", bottom_id);

  ImGui::DockBuilderFinish(dockspace_id);
}

// This creates the invisible docking area.
// The mini windows can be dragged into this space.
void OscilloscopeUI::drawDockSpace() {
  const ImGuiViewport *viewport = ImGui::GetMainViewport();

  ImGui::SetNextWindowPos(viewport->WorkPos);
  ImGui::SetNextWindowSize(viewport->WorkSize);
  ImGui::SetNextWindowViewport(viewport->ID);

  constexpr ImGuiWindowFlags window_flags =
      ImGuiWindowFlags_NoDocking |
      ImGuiWindowFlags_NoTitleBar |
      ImGuiWindowFlags_NoCollapse |
      ImGuiWindowFlags_NoResize |
      ImGuiWindowFlags_NoMove |
      ImGuiWindowFlags_NoBringToFrontOnFocus |
      ImGuiWindowFlags_NoNavFocus |
      ImGuiWindowFlags_NoBackground;

  ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

  ImGui::Begin("ScopedDockSpaceHost", nullptr, window_flags);

  ImGui::PopStyleVar(3);

  ImGuiID dockspace_id = ImGui::GetID("ScopedDockSpace");

  ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

  if (m_reset_dock_layout) {
    buildDefaultDockLayout(dockspace_id, viewport->WorkSize);
    m_reset_dock_layout = false;
  }

  ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);

  ImGui::End();
}

// Top menu bar.
void OscilloscopeUI::drawMainMenu() {
  if (ImGui::BeginMainMenuBar()) {
    ImGui::Text("Scoped");

    if (ImGui::BeginMenu("View")) {
      ImGui::TextDisabled("Drag panels to move or dock them.");
      ImGui::EndMenu();
    }

    ImGui::EndMainMenuBar();
  }
}

// Main waveform window.
void OscilloscopeUI::drawScopeWindow(Oscilloscope &osc) {
  ImGui::Begin("Scope View");

  ImGui::TextDisabled("Main oscilloscope display");
  ImGui::Separator();

  drawPlotArea(osc);

  ImGui::End();
}

// Trigger controls window.
void OscilloscopeUI::drawTriggerWindow(Oscilloscope &osc) {
  ImGui::Begin("Trigger");

  auto *trigger = osc.getTrigger();

  if (!trigger) {
    ImGui::TextDisabled("No trigger configured.");
    ImGui::End();
    return;
  }

  drawModeCombo(osc);

  ImGui::Spacing();

  ImGui::Checkbox("Show trigger line", &m_show_trigger_line);

  ImGui::Separator();

  auto params = trigger->getUIParameters();

  for (const auto &param : params) {
    ImGui::PushID(param.name.c_str());

    ImGui::Text("%s", param.name.c_str());

    int value = param.current_val;

    if (param.combo_items.empty()) {
      ImGui::SetNextItemWidth(-1);

      if (ImGui::SliderInt("Value", &value, param.min_val, param.max_val)) {
        trigger->setUIParameter(param.name, value);
      }
    } else {
      std::vector<const char *> combo_items;

      for (const auto &item : param.combo_items) {
        combo_items.push_back(item.c_str());
      }

      ImGui::SetNextItemWidth(-1);

      if (ImGui::Combo("Value", &value, combo_items.data(),
                       static_cast<int>(combo_items.size()))) {
        trigger->setUIParameter(param.name, value);
      }
    }

    ImGui::Spacing();

    ImGui::PopID();
  }

  ImGui::End();
}

// FFT controls window.
void OscilloscopeUI::drawFFTWindow(Oscilloscope &osc) {
  ImGui::Begin("FFT");

  drawFFTControl(osc);

  ImGui::End();
}

// Channel controls window.
void OscilloscopeUI::drawChannelWindow(Oscilloscope &osc) {
  ImGui::Begin("Channels");

  const auto &channels = osc.getChannels();

  if (channels.empty()) {
    ImGui::TextDisabled("No channels available.");
    ImGui::End();
    return;
  }

  drawTimebaseControl(osc);

  ImGui::Separator();

  for (auto &channel : channels) {
    ImGui::PushID(channel->getLabel().c_str());

    ImGui::Text("%s", channel->getLabel().c_str());

    float gain = channel->getVerticalScale();

    ImGui::SetNextItemWidth(-1);

    if (ImGui::SliderFloat("Vertical scale", &gain, 0.1f, 10.0f, "%.1fx")) {
      channel->setVerticalScale(gain);
    }

    ImGui::TextDisabled("Visible samples: %zu", channel->getVisibleSamples());

    ImGui::Separator();

    ImGui::PopID();
  }

  ImGui::End();
}

// USB connection window.
void OscilloscopeUI::drawHardwareWindow(Oscilloscope &osc) {
  ImGui::Begin("Hardware");

  auto &usb = osc.getUSB();

  if (usb.isConnected()) {
    ImGui::TextColored(Colors::StatusOk, "USB connected");

    if (ImGui::Button("Disconnect")) {
      usb.stopStreaming();
      usb.disconnect();
    }
  } else {
    ImGui::TextColored(Colors::StatusError, "USB offline");
    ImGui::TextDisabled("Using generated test signal.");

    if (ImGui::Button("Connect")) {
      if (usb.connect()) {
        for (auto &channel : osc.getChannels()) {
          if (channel->isHardwareChannel()) {
            channel->clearBuffer();
          }
        }

        if (osc.getTrigger()) {
          osc.getTrigger()->clear();
        }

        if (!osc.getChannels().empty()) {
          if (osc.getChannels()[0]->isHardwareChannel()) {
            usb.startStreaming(osc.getChannels()[0].get());
          }
        }
      }
    }
  }

  ImGui::End();
}

// Debug window.
void OscilloscopeUI::drawDebugWindow(Oscilloscope &osc) {
  ImGui::Begin("Debug");

  ImGui::Text("Display width: %zu", m_display_width);
  ImGui::Text("Display height: %zu", m_display_height);
  ImGui::Text("Channels: %zu", osc.getChannels().size());
  ImGui::Text("Display textures: %zu", m_displays.size());

  if (!osc.getChannels().empty()) {
    auto &channel = osc.getChannels()[0];

    ImGui::Separator();

    ImGui::Text("First channel: %s", channel->getLabel().c_str());
    ImGui::Text("Visible samples: %zu", channel->getVisibleSamples());
    ImGui::Text("New frame waiting: %s",
                channel->hasNewFrame() ? "yes" : "no");
  }

  ImGui::End();
}

// ui.render(osc);
void OscilloscopeUI::render(Oscilloscope &osc) {
  processNewFrames(osc);

  drawMainMenu();
  drawDockSpace();

  drawScopeWindow(osc);
  drawTriggerWindow(osc);
  drawFFTWindow(osc);
  drawChannelWindow(osc);
  drawHardwareWindow(osc);
  drawDebugWindow(osc);
}

} // namespace Scoped