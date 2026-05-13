#include "imgui.h"
#include "implot.h"
#include <algorithm>
#include <cmath>
#include <ui/ui.hpp>

namespace Scoped {

// Colors are defined in ui.hpp

// Draws a single two-point line segment on the current ImPlot canvas.
static void plotLineSegment(const char *label, double x0, double y0, double x1,
                            double y1, ImVec4 color, float weight) {
  double xs[] = {x0, x1};
  double ys[] = {y0, y1};
  ImPlot::PlotLine(label, xs, ys, 2,
                   {ImPlotProp_LineColor, color, ImPlotProp_LineWeight, weight});
}

// Colormap
void setupChannelColormap(ImVec4 color) {
  static bool initialized = false;
  if (initialized)
    return;

  ImVec4 gradient[2] = {Colors::Black, color};
  ImPlot::AddColormap("ChannelMap", gradient, 2);
  initialized = true;
}

// OscilloscopeUI Lifecycle
OscilloscopeUI::OscilloscopeUI(size_t display_width, size_t display_height)
    : m_display_width(display_width), m_display_height(display_height) {}

// Data pipeline
void OscilloscopeUI::processNewFrames(Oscilloscope &osc) {
  const auto &channels = osc.getChannels();

  while (m_displays.size() < channels.size()) {
    size_t index = m_displays.size();
    auto display = std::make_unique<IntensityMap>(m_display_width, m_display_height);
    
    // Assign color based on channel index
    ImVec4 color = (index == 0) ? Colors::CH1 : (index == 1) ? Colors::CH2 : ImVec4(1, 1, 1, 1);
    display->setColor(color.x, color.y, color.z);
    
    m_displays.push_back(std::move(display));
  }

  for (size_t i = 0; i < channels.size(); ++i) {
    auto &channel = *channels[i];
    if (!channel.hasNewFrame())
      continue;

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

// Plot overlays
void OscilloscopeUI::drawGridLines(double w, double h) {
  for (int i = 0; i <= 10; ++i) {
    double x = (w * i) / 10.0;
    float wt = (i == 5) ? 3.0f : 1.0f;
    plotLineSegment("##vgrid", x, 0, x, h, Colors::Grid, wt);
  }

  for (int i = 0; i <= 8; ++i) {
    double y = (h * i) / 8.0;
    float wt = (i == 4) ? 3.0f : 1.0f;
    plotLineSegment("##hgrid", 0, y, w, y, Colors::Grid, wt);
  }
}

void OscilloscopeUI::drawTriggerLine(Oscilloscope &osc) {
  auto *trigger = osc.getTrigger();
  if (!trigger || osc.getChannels().empty())
    return;

  auto levels = trigger->getTriggerLevels();
  if (levels.empty())
    return;

  auto &ch = osc.getChannels()[0];
  auto traces = ch->getTraces();
  if (traces.empty())
    return;
  auto &trace = traces[0];

  for (float level : levels) {
    float y_normalized = trace.normalizeToIntensity(level);
    double y_level = y_normalized * m_display_height;
    plotLineSegment("##TriggerLine", 0.0, y_level,
                    static_cast<double>(m_display_width), y_level,
                    Colors::Trigger, 2.0f);
  }
}

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

// Plot canvas
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

// Top bar controls
void OscilloscopeUI::drawModeCombo(Oscilloscope &osc) {
  if (!osc.getTrigger())
    return;
  ImGui::SetNextItemWidth(70);
  const char *items[] = {"Auto", "Norm"};
  int sel = (osc.getTrigger()->getMode() == TriggerMode::AUTO) ? 0 : 1;
  if (ImGui::Combo("##Mode", &sel, items, 2)) {
    osc.getTrigger()->setMode(sel == 0 ? TriggerMode::AUTO
                                       : TriggerMode::NORMAL);
  }
}

void OscilloscopeUI::drawHorizontalControls(IChannel &channel) {
  int samples = static_cast<int>(channel.getVisibleSamples());
  ImGui::SetNextItemWidth(150);
  if (ImGui::SliderInt("##Time", &samples, 256, 16384, "%d smp")) {
    channel.setVisibleSamples(static_cast<size_t>(samples));
  }
}

void OscilloscopeUI::drawVerticalControls(IChannel &channel) {
    // V1 layout handles vertical controls in drawChannelBlock and drawBottomBar.
    // This is a placeholder for the V2 interface.
}

void OscilloscopeUI::drawFFTControl(Oscilloscope &osc) {
  for (auto &channel : osc.getChannels()) {
    ImGui::PushID(channel->getLabel().c_str());
    for (auto &proc : channel->getProcessors()) {
      if (proc->getName() == "FFT") {
        // Enable toggle
        bool enabled = proc->isEnabled();
        if (ImGui::Checkbox("FFT", &enabled)) {
          proc->setEnabled(enabled);
        }
        // Scale slider
        ImGui::SameLine();
        ImGui::SetNextItemWidth(150);
        float scale = proc->getScale();
        if (ImGui::SliderFloat("##Scale", &scale, 0.01, 1.00, "%.2f")) {
          proc->setScale(scale);
        }

        // Mode toggle
        ImGui::SameLine();
        bool mode = proc->getIsModeLinear();
        if (ImGui::Checkbox("Linear", &mode)) {
          proc->setIsModeLinear(mode);
        }
      }
    }
    ImGui::PopID();
  }
}

void OscilloscopeUI::drawTopBar(Oscilloscope &osc) {
  ImGui::PushStyleColor(ImGuiCol_ChildBg, Colors::TopBarBg);
  ImGui::BeginChild("StatusBar", ImVec2(0, 45), false);

  ImGui::SetCursorPos(ImVec2(10, 12));
  ImGui::TextDisabled("TRG:");
  ImGui::SameLine();

  bool any_hovered = false;
  auto *trigger = osc.getTrigger();
  if (trigger) {
    auto params = trigger->getUIParameters();
    for (const auto &param : params) {
      ImGui::SetNextItemWidth(100);
      int val = param.current_val;
      if (param.combo_items.empty()) {
        if (ImGui::SliderInt(("##" + param.name).c_str(), &val, param.min_val,
                             param.max_val, (param.name + ": %d").c_str())) {
          trigger->setUIParameter(param.name, val);
        }
      } else {
        std::vector<const char *> cstrs;
        for (const auto &s : param.combo_items)
          cstrs.push_back(s.c_str());
        if (ImGui::Combo(("##" + param.name).c_str(), &val, cstrs.data(),
                         cstrs.size())) {
          trigger->setUIParameter(param.name, val);
        }
      }
      if (ImGui::IsItemActive() || ImGui::IsItemHovered())
        any_hovered = true;
      ImGui::SameLine();
    }
  }
  m_show_trigger_line = any_hovered;

  drawModeCombo(osc);

  ImGui::SameLine(ImGui::GetWindowWidth() - 700);
  ImGui::TextDisabled("FFT:");
  ImGui::SameLine();
  drawFFTControl(osc);

  ImGui::SameLine(ImGui::GetWindowWidth() - 350);
  ImGui::TextDisabled("HORIZ:");
  for (auto &ch : osc.getChannels()) {
      ImGui::SameLine();
      drawHorizontalControls(*ch);
  }

  ImGui::EndChild();
  ImGui::PopStyleColor();
}

// Bottom bar controls
void OscilloscopeUI::drawChannelBlock(IChannel &channel) {
  ImGui::PushStyleColor(ImGuiCol_ChildBg, Colors::ChannelBlockBg);
  ImGui::PushStyleColor(ImGuiCol_Text, Colors::Black);

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
  auto &usb = osc.getUSB();

  ImGui::SameLine(ImGui::GetWindowWidth() - 320);
  ImGui::SetCursorPosY(12);

  if (usb.isConnected()) {
    ImGui::TextColored(Colors::StatusOk, "CONNECTED");
    ImGui::SameLine();
    if (ImGui::Button("Disconnect")) {
      usb.stopStreaming();
      usb.disconnect();
    }
  } else {
    ImGui::TextColored(Colors::StatusError, "OFFLINE");
    ImGui::SameLine();
    if (ImGui::Button("Connect")) {
      if (usb.connect()) {
        for (auto &ch : osc.getChannels()) {
          if (ch->isHardwareChannel()) {
            ch->clearBuffer();
          }
        }
        if (osc.getTrigger())
          osc.getTrigger()->clear();
        if (!osc.getChannels().empty()) {
          if (osc.getChannels()[0]->isHardwareChannel()) {
            usb.startStreaming(osc.getChannels()[0].get());
          }
        }
      }
    }
  }
}

void OscilloscopeUI::drawBottomBar(Oscilloscope &osc) {
  ImGui::PushStyleColor(ImGuiCol_ChildBg, Colors::BottomBarBg);
  ImGui::BeginChild("ChannelBar", ImVec2(0, 50), false);

  ImGui::SetCursorPos(ImVec2(10, 7));
  for (auto &ch : osc.getChannels()) {
    drawChannelBlock(*ch);
  }

  drawHardwareStatus(osc);

  ImGui::EndChild();
  ImGui::PopStyleColor();
}

// Entry point
void OscilloscopeUI::render(Oscilloscope &osc) {
  processNewFrames(osc);

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

  drawTopBar(osc);

  float plot_height = ImGui::GetContentRegionAvail().y - 50;
  ImGui::BeginChild("PlotContainer", ImVec2(0, plot_height), false);
  drawPlotArea(osc);
  ImGui::EndChild();

  drawBottomBar(osc);

  ImGui::End();
}

} // namespace Scoped
