#include "implot.h"
#include <algorithm>
#include <cmath>
#include <ui.hpp>

namespace Scoped {

// ---------------------------------------------------------------------------
// Colormap
// ---------------------------------------------------------------------------

void setupChannelColormap(ImVec4 color) {
  static bool initialized = false;
  if (initialized)
    return;

  ImVec4 gradient[2] = {ImVec4(0, 0, 0, 1), color};
  ImPlot::AddColormap("ChannelMap", gradient, 2);
  initialized = true;
}

// ---------------------------------------------------------------------------
// OscilloscopeUI
// ---------------------------------------------------------------------------

OscilloscopeUI::OscilloscopeUI(size_t display_width, size_t display_height)
    : m_display_width(display_width), m_display_height(display_height) {}

// ---------------------------------------------------------------------------
// Display pipeline
// ---------------------------------------------------------------------------

void OscilloscopeUI::updateDisplay(Oscilloscope &osc) {
  const auto& channels = osc.getChannels();
  
  // Ensure we have an intensity map per channel
  while (m_displays.size() < channels.size()) {
      m_displays.push_back(std::make_unique<IntensityMap>(m_display_width, m_display_height));
  }

  for (size_t i = 0; i < channels.size(); ++i) {
      auto& channel = *channels[i];
      if (!channel.hasNewFrame())
          continue;

      const auto &traces = channel.getTraces();
      for (const auto& trace : traces) {
          if (trace.domain == Domain::Time) {
              size_t visible = std::min(channel.getVisibleSamples(), trace.data.size());
              m_normalized.resize(visible);
              for (size_t j = 0; j < visible; ++j) {
                m_normalized[j] = trace.normalizeToIntensity(trace.data[j]);
              }

              m_displays[i]->clear();
              m_displays[i]->processFrame(m_normalized.data(), visible);
          }
      }
      channel.clearNewFrame();
  }
}

// ---------------------------------------------------------------------------
// Plot overlays
// ---------------------------------------------------------------------------

void OscilloscopeUI::drawGrid(double w, double h) {
  const ImVec4 color(0.3f, 0.3f, 0.3f, 0.4f);

  for (int i = 0; i <= 10; ++i) {
    double x   = (w * i) / 10.0;
    double vx[] = {x, x};
    double vy[] = {0, h};
    float  wt   = (i == 5) ? 3.0f : 1.0f;
    ImPlot::PlotLine("##vgrid", vx, vy, 2,
                     {ImPlotProp_LineColor, color, ImPlotProp_LineWeight, wt});
  }

  for (int i = 0; i <= 8; ++i) {
    double y   = (h * i) / 8.0;
    double hx[] = {0, w};
    double hy[] = {y, y};
    float  wt   = (i == 4) ? 3.0f : 1.0f;
    ImPlot::PlotLine("##hgrid", hx, hy, 2,
                     {ImPlotProp_LineColor, color, ImPlotProp_LineWeight, wt});
  }
}

void OscilloscopeUI::drawTriggerLine(Oscilloscope &osc) {
  auto *trigger = osc.getTrigger();
  if (!trigger || osc.getChannels().empty())
    return;

  auto levels = trigger->getTriggerLevels();
  if (levels.empty()) return;

  auto& ch = osc.getChannels()[0];
  auto traces = ch->getTraces();
  if (traces.empty()) return;
  auto& trace = traces[0];

  for (float level : levels) {
      float y_normalized = trace.normalizeToIntensity(level);
      double y_level = y_normalized * m_display_height;

      double x[] = {0.0, static_cast<double>(m_display_width)};
      double y[] = {y_level, y_level};

      ImPlot::PlotLine("##TriggerLine", x, y, 2,
                       {ImPlotProp_LineColor, ImVec4(1, 0, 0, 0.5f),
                        ImPlotProp_LineWeight, 2.0f});
  }
}

// ---------------------------------------------------------------------------
// Plot
// ---------------------------------------------------------------------------

void OscilloscopeUI::renderPlot(Oscilloscope &osc) {
  const double w = static_cast<double>(m_display_width);
  const double h = static_cast<double>(m_display_height);

  ImPlot::PushStyleVar(ImPlotStyleVar_PlotPadding, ImVec2(0, 0));
  ImPlot::PushStyleVar(ImPlotStyleVar_PlotBorderSize, 0.0f);

  // Snap to pixel boundary to avoid sub-pixel blurring
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

    for (const auto& ch : osc.getChannels()) {
        for (const auto& trace : ch->getTraces()) {
            if (trace.domain == Domain::Frequency) {
                ImPlot::PlotLine(trace.name.c_str(), trace.data.data(), trace.data.size(), w / trace.data.size(), 0,
                    {ImPlotProp_LineColor, ImVec4(1.0f, 1.0f, 0.0f, 1.0f), ImPlotProp_LineWeight, 2.0f});
            }
        }
    }

    drawGrid(w, h);

    if (m_show_trigger_line) {
      drawTriggerLine(osc);
    }

    ImPlot::EndPlot();
  }

  ImPlot::PopStyleVar(2);
}

// ---------------------------------------------------------------------------
// Top bar
// ---------------------------------------------------------------------------



void OscilloscopeUI::drawModeCombo(Oscilloscope &osc) {
  if (!osc.getTrigger()) return;
  ImGui::SetNextItemWidth(70);
  const char *items[] = {"Auto", "Norm"};
  int sel = (osc.getTrigger()->getMode() == TriggerMode::AUTO) ? 0 : 1;
  if (ImGui::Combo("##Mode", &sel, items, 2)) {
    osc.getTrigger()->setMode(sel == 0 ? TriggerMode::AUTO
                                       : TriggerMode::NORMAL);
  }
}

void OscilloscopeUI::drawTimebaseControl(Oscilloscope &osc) {
  if (osc.getChannels().empty()) return;
  auto& channel = *osc.getChannels()[0];
  
  int samples = static_cast<int>(channel.getVisibleSamples());
  ImGui::SetNextItemWidth(150);
  if (ImGui::SliderInt("##Time", &samples, 256, 16384, "%d smp")) {
    // Apply timebase to all channels
    for (auto& ch : osc.getChannels()) {
        ch->setVisibleSamples(static_cast<size_t>(samples));
    }
  }
}

void OscilloscopeUI::renderTopBar(Oscilloscope &osc) {
  ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.11f, 0.14f, 0.18f, 1.0f));
  ImGui::BeginChild("StatusBar", ImVec2(0, 45), false);

  ImGui::SetCursorPos(ImVec2(10, 12));
  ImGui::TextDisabled("TRG:");
  ImGui::SameLine();

  bool any_hovered = false;
  auto* trigger = osc.getTrigger();
  if (trigger) {
      auto params = trigger->getUIParameters();
      for (const auto& param : params) {
          ImGui::SetNextItemWidth(100);
          int val = param.current_val;
          if (param.combo_items.empty()) {
              if (ImGui::SliderInt(("##" + param.name).c_str(), &val, param.min_val, param.max_val, (param.name + ": %d").c_str())) {
                  trigger->setUIParameter(param.name, val);
              }
          } else {
              std::vector<const char*> cstrs;
              for (const auto& s : param.combo_items) cstrs.push_back(s.c_str());
              if (ImGui::Combo(("##" + param.name).c_str(), &val, cstrs.data(), cstrs.size())) {
                  trigger->setUIParameter(param.name, val);
              }
          }
          if (ImGui::IsItemActive() || ImGui::IsItemHovered()) any_hovered = true;
          ImGui::SameLine();
      }
  }
  m_show_trigger_line = any_hovered;

  drawModeCombo(osc);

  ImGui::SameLine(ImGui::GetWindowWidth() - 250);
  ImGui::TextDisabled("HORIZ:");
  ImGui::SameLine();
  drawTimebaseControl(osc);

  ImGui::EndChild();
  ImGui::PopStyleColor();
}

// ---------------------------------------------------------------------------
// Bottom bar
// ---------------------------------------------------------------------------

void OscilloscopeUI::drawChannelBlock(IChannel &channel) {
  ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(1.0f, 0.8f, 0.0f, 1.0f));
  ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0, 0, 0, 1));

  ImGui::BeginChild(channel.getLabel().c_str(), ImVec2(180, 36), true);
  ImGui::Text("%s", channel.getLabel().c_str());
  ImGui::SameLine(40);
  float gain = channel.getVerticalScale();
  ImGui::SetNextItemWidth(120);
  if (ImGui::SliderFloat("##Gain", &gain, 0.1f, 10.0f, "G: %.1fx")) {
    channel.setVerticalScale(gain);
  }
  ImGui::EndChild();

  ImGui::PopStyleColor(2);
  ImGui::SameLine();
}

void OscilloscopeUI::drawHardwareStatus(Oscilloscope &osc) {
  auto& usb = osc.getUSB();
  
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
        for (auto& ch : osc.getChannels()) {
            if (ch->isHardwareChannel()) {
                ch->clearBuffer();
            }
        }
        if (osc.getTrigger()) osc.getTrigger()->clear();
        if (!osc.getChannels().empty()) {
            if (osc.getChannels()[0]->isHardwareChannel()) {
                usb.startStreaming(osc.getChannels()[0].get());
            }
        }
      }
    }
  }
}

void OscilloscopeUI::renderBottomBar(Oscilloscope &osc) {
  ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.08f, 0.1f, 0.12f, 1.0f));
  ImGui::BeginChild("ChannelBar", ImVec2(0, 50), false);

  ImGui::SetCursorPos(ImVec2(10, 7));
  for (auto& ch : osc.getChannels()) {
      drawChannelBlock(*ch);
  }
  
  drawHardwareStatus(osc);

  ImGui::EndChild();
  ImGui::PopStyleColor();
}

// ---------------------------------------------------------------------------
// Entry point
// ---------------------------------------------------------------------------

void OscilloscopeUI::render(Oscilloscope &osc) {
  updateDisplay(osc);

  const ImGuiViewport *vp = ImGui::GetMainViewport();
  ImGui::SetNextWindowPos(vp->WorkPos);
  ImGui::SetNextWindowSize(vp->WorkSize);
  ImGui::SetNextWindowViewport(vp->ID);

  constexpr ImGuiWindowFlags kFlags =
      ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar |
      ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
      ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus |
      ImGuiWindowFlags_NoNavFocus;

  ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

  ImGui::Begin("OscilloscopeMain", nullptr, kFlags);
  ImGui::PopStyleVar(3);

  renderTopBar(osc);

  float plot_height = ImGui::GetContentRegionAvail().y - 50;
  ImGui::BeginChild("PlotContainer", ImVec2(0, plot_height), false);
  renderPlot(osc);
  ImGui::EndChild();

  renderBottomBar(osc);

  ImGui::End();
}

} // namespace Scoped
