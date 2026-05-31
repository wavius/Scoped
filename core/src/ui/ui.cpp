#include "common/oscilloscope.hpp"
#include "imgui.h"
#include "imgui_internal.h"
#include "implot.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include <common/constants.hpp>
#include <processing/fft_processor.hpp>
#include <processing/filter_processor.hpp>
#include <processing/math_processor.hpp>
#include <ui/ui.hpp>

namespace {
    template <typename T>
    void drawComponentHeader(T* component, const std::string& name, Scoped::Oscilloscope& osc, size_t default_h_scale = Scoped::Constants::DEFAULT_HORIZONTAL_SCALE) {
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
            component->setHorizontalOffset(Scoped::Constants::DEFAULT_HORIZONTAL_OFFSET);
            
            if constexpr (std::is_same_v<std::remove_cv_t<T>, Scoped::FFTProcessor>) {
                component->setIsModeLinear(false);
                component->setSmoothingFactor(0.0f);
            }
            osc.forceReprocess();
        }
        ImGui::Spacing();
    }

    template <typename T, typename DrawSliderFunc>
    void drawVerticalControlsT(T* target, Scoped::Oscilloscope& osc, float v_min, float v_max, const char* format_offset, DrawSliderFunc drawSlider) {
        float scale = target->getVerticalScale();
        if (drawSlider("Vertical Scale", &scale, 0.01f, 10.0f, "%.2f", false)) {
            target->setVerticalScale(scale);
            osc.forceReprocess();
        }
        
        float offset = target->getVerticalOffset();
        if (drawSlider("Vertical Offset", &offset, v_min, v_max, format_offset, true)) {
            target->setVerticalOffset(offset);
            osc.forceReprocess();
        }
    }
}

namespace Scoped {

// colors
// Colors are defined in ui.hpp

static void plotLineSegment(const char *label, double x0, double y0, double x1,
                            double y1, ImVec4 color, float weight) {
  double xs[] = {x0, x1};
  double ys[] = {y0, y1};

  ImPlot::PlotLine(
      label, xs, ys, 2,
      {ImPlotProp_LineColor, color, ImPlotProp_LineWeight, weight});
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

bool OscilloscopeUI::drawSliderFloatWithInput(const char* label, float* v, float v_min, float v_max, const char* format, bool add_spacing) {
  bool changed = false;
  if (add_spacing) {
    ImGui::Spacing();
  }
  ImGui::Text("%s", label);
  ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x * 0.7f);
  
  std::string slider_id = std::string("##Slider_") + label;
  if (ImGui::SliderFloat(slider_id.c_str(), v, v_min, v_max, format)) {
    changed = true;
  }
  
  ImGui::SameLine();
  ImGui::SetNextItemWidth(-FLT_MIN);
  
  std::string input_id = std::string("##Input_") + label;
  if (ImGui::InputFloat(input_id.c_str(), v, 0.0f, 0.0f, format)) {
    *v = std::clamp(*v, v_min, v_max);
    changed = true;
  }
  return changed;
}

bool OscilloscopeUI::drawSliderIntWithInput(const char* label, int* v, int v_min, int v_max, const char* format, bool add_spacing) {
  bool changed = false;
  if (add_spacing) {
    ImGui::Spacing();
  }
  ImGui::Text("%s", label);
  ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x * 0.7f);
  
  std::string slider_id = std::string("##Slider_") + label;
  if (ImGui::SliderInt(slider_id.c_str(), v, v_min, v_max, format)) {
    changed = true;
  }
  
  ImGui::SameLine();
  ImGui::SetNextItemWidth(-FLT_MIN);
  
  std::string input_id = std::string("##Input_") + label;
  if (ImGui::InputInt(input_id.c_str(), v, 0, 0)) {
    *v = std::clamp(*v, v_min, v_max);
    changed = true;
  }
  return changed;
}

bool OscilloscopeUI::drawCombo(const char* label, int* current_item, const char* const items[], int items_count, bool add_spacing) {
  bool changed = false;
  if (add_spacing) {
    ImGui::Spacing();
  }
  ImGui::Text("%s", label);
  ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
  
  std::string combo_id = std::string("##Combo_") + label;
  if (ImGui::Combo(combo_id.c_str(), current_item, items, items_count)) {
    changed = true;
  }
  return changed;
}

OscilloscopeUI::OscilloscopeUI(size_t display_width, size_t display_height)
    : m_display_width(display_width), m_display_height(display_height) {}

void OscilloscopeUI::processNewFrames(Oscilloscope &osc) {
  const auto &hw_channels = osc.getHardwareChannels();
  const auto &vc_channels = osc.getVirtualChannels();

  if (!m_display) {
    m_display =
        std::make_unique<IntensityMap>(m_display_width, m_display_height);
  }

  bool any_new_frame = false;
  for (const auto &channel : hw_channels) {
    if (channel->hasNewFrame()) {
      any_new_frame = true;
      break;
    }
  }
  if (!any_new_frame) {
    for (const auto &channel : vc_channels) {
      if (channel->hasNewFrame()) {
        any_new_frame = true;
        break;
      }
    }
  }

  bool any_active = false;
  for (const auto &ch : hw_channels) {
    if (ch->isEnabled()) {
      any_active = true;
      break;
    }
    for (const auto *proc : ch->getProcessors()) {
      if (proc->isEnabled()) {
        any_active = true;
        break;
      }
    }
  }
  if (!any_active) {
    for (const auto &ch : vc_channels) {
      if (ch->isEnabled()) {
        any_active = true;
        break;
      }
      for (const auto *proc : ch->getProcessors()) {
        if (proc->isEnabled()) {
          any_active = true;
          break;
        }
      }
    }
  }

  if (any_new_frame || !any_active) {
    m_display->clear();

    if (!any_active)
      return; // Nothing to draw

    auto processChannelTraces = [&](IChannel &channel, size_t index,
                                    bool is_virtual) {
      if (!channel.isEnabled()) {
        channel.clearNewFrame();
        return;
      }

      const auto &traces = channel.getTraces();

      for (const auto &trace : traces) {
        if (trace.domain == Domain::Time && channel.isEnabled()) {
          size_t count = trace.data.size();

          m_normalized_time.resize(count);

          for (size_t j = 0; j < count; ++j) {
            m_normalized_time[j] = trace.normalizeToIntensity(trace.data[j]);
          }

          ImVec4 color = toImVec4(trace.color);
          m_display->processFrame(m_normalized_time.data(), count, color.x,
                                  color.y, color.z);
        }
      }

      channel.clearNewFrame();
    };

    for (size_t i = 0; i < hw_channels.size(); ++i) {
      processChannelTraces(*hw_channels[i], i, false);
    }
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

void OscilloscopeUI::drawTriggerMarker(const std::string &label, double h_scale,
                                       double h_offset, double w, double h,
                                       const ImVec4 &color,
                                       float y_offset_rect) {
  double trigger_frac = 0.5 - (h_offset / h_scale);
  double trigger_x = w * trigger_frac;

  std::string badge_text = label;
  bool is_offscreen_left = trigger_x < 0.0;
  bool is_offscreen_right = trigger_x > w;

  if (is_offscreen_left) {
    badge_text = "< " + label;
  } else if (is_offscreen_right) {
    badge_text = label + " >";
  }

  ImVec2 text_size = ImGui::CalcTextSize(badge_text.c_str());
  float badge_width = std::max(14.0f, text_size.x + 6.0f);
  float half_badge_w = badge_width * 0.5f;

  double trigger_x_clamped = trigger_x;
  if (is_offscreen_left) {
    trigger_x_clamped = half_badge_w + 2.0f;
  } else if (is_offscreen_right) {
    trigger_x_clamped = w - half_badge_w - 2.0f;
  }

  ImVec2 center_pix = ImPlot::PlotToPixels(ImPlotPoint(trigger_x_clamped, h));
  ImDrawList *draw_list = ImPlot::GetPlotDrawList();

  ImU32 badge_color_u32 = ImGui::GetColorU32(color);
  ImU32 text_color_u32 = ImGui::GetColorU32(ImVec4(0, 0, 0, 1)); // Black

  // Draw background rounded rect
  ImVec2 rect_min(center_pix.x - half_badge_w,
                  center_pix.y - y_offset_rect - 13.0f);
  ImVec2 rect_max(center_pix.x + half_badge_w, center_pix.y - y_offset_rect);
  draw_list->AddRectFilled(rect_min, rect_max, badge_color_u32, 3.0f);

  // Draw a small triangle pointing down to the exact horizontal position if
  // it's on-screen
  if (!is_offscreen_left && !is_offscreen_right) {
    ImVec2 tri_p1(center_pix.x - 4.0f, center_pix.y - y_offset_rect);
    ImVec2 tri_p2(center_pix.x + 4.0f, center_pix.y - y_offset_rect);
    ImVec2 tri_p3(center_pix.x, center_pix.y - y_offset_rect + 5.0f);
    draw_list->AddTriangleFilled(tri_p1, tri_p2, tri_p3, badge_color_u32);
  }

  // Draw text centered in the badge
  ImVec2 text_pos(center_pix.x - text_size.x * 0.5f,
                  center_pix.y - y_offset_rect - 6.5f - text_size.y * 0.5f);
  draw_list->AddText(text_pos, text_color_u32, badge_text.c_str());
}

// Draws the trigger level line when the checkbox is enabled.
void OscilloscopeUI::drawTriggerLine(Oscilloscope &osc) {
  auto *trigger = osc.getTrigger();

  if (!trigger || osc.getHardwareChannels().empty()) {
    return;
  }

  auto levels = trigger->getTriggerLevels();

  if (levels.empty()) {
    return;
  }

  size_t src_idx = osc.getTriggerSourceIndex();
  if (src_idx >= osc.getHardwareChannels().size()) {
    src_idx = 0;
  }
  auto &channel = osc.getHardwareChannels()[src_idx];
  auto traces = channel->getTraces();

  if (traces.empty()) {
    return;
  }

  auto &trace = traces[0];

  ImVec4 trigger_color =
      toImVec4(osc.getHardwareChannels()[src_idx]->getColor());
  trigger_color.w = 0.5f;

  for (float level : levels) {
    float y_normalized = trace.normalizeToIntensity(level);
    // After flipping PlotImage, y_normalized=1.0 is top (h) and 0.0 is bottom
    // (0)
    double y_level = y_normalized * m_display_height;

    plotLineSegment("##TriggerLine", 0.0, y_level,
                    static_cast<double>(m_display_width), y_level,
                    trigger_color, 2.0f);
  }
}

// Draws FFT data over the scope display when FFT is enabled.
void OscilloscopeUI::drawFrequencyTraces(Oscilloscope &osc) {
  for (const auto &channel : osc.getHardwareChannels()) {
    for (const auto &trace : channel->getTraces()) {
      if (trace.domain == Domain::Frequency) {
        size_t visible = trace.data.size();
        if (visible < 2)
          continue;

        m_normalized_freq.resize(visible);

        for (size_t i = 0; i < visible; i++) {
          m_normalized_freq[i] = trace.normalizeToIntensity(trace.data[i]) *
                                 static_cast<float>(m_display_height);
        }

        ImVec4 trace_color = toImVec4(trace.color);

        double xscale = static_cast<double>(m_display_width) /
                        static_cast<double>(visible - 1);

        ImPlot::PlotLine(
            trace.name.c_str(), m_normalized_freq.data(),
            m_normalized_freq.size(), xscale, 0.0,
            {ImPlotProp_LineColor, trace_color, ImPlotProp_LineWeight, 2.0f});
      }
    }
  }
}

void OscilloscopeUI::drawVirtualTimeTraces(Oscilloscope &osc) {
  const double w = static_cast<double>(m_display_width);
  const double h = static_cast<double>(m_display_height);
  for (const auto &channel : osc.getVirtualChannels()) {
    if (!channel->isEnabled()) continue;
    
    for (const auto &trace : channel->getTraces()) {
      if (trace.domain == Domain::Time) {
        size_t count = trace.data.size();
        if (count < 2) continue;
        
        m_normalized_time.resize(count);
        for (size_t i = 0; i < count; ++i) {
          m_normalized_time[i] = trace.normalizeToIntensity(trace.data[i]) * h;
        }

        ImVec4 trace_color = toImVec4(trace.color);
        double h_scale = static_cast<double>(trace.horizontal_scale);
        double h_offset = static_cast<double>(trace.horizontal_offset);
        
        double xscale = w / h_scale;
        double trigger_frac = 0.5 - (h_offset / h_scale);
        double trigger_x = w * trigger_frac;
        double x0 = trigger_x - (static_cast<double>(trace.trigger_index) * xscale);

        ImPlot::PlotLine(
            trace.name.c_str(), m_normalized_time.data(),
            static_cast<int>(m_normalized_time.size()), xscale, x0,
            {ImPlotProp_LineColor, trace_color, ImPlotProp_LineWeight, 2.0f});
      }
    }
  }
}

void OscilloscopeUI::drawPlotArea(Oscilloscope &osc) {
  const double w = static_cast<double>(m_display_width);
  const double h = static_cast<double>(m_display_height);

  // Add a tab bar for active channel selection
  ImGui::BeginChild("ActiveChannelSelector", ImVec2(-1, 30), false, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
  if (ImGui::BeginTabBar("##ActiveChannelTabs", ImGuiTabBarFlags_FittingPolicyScroll)) {
      
      // 1. Hardware Channels first
      for (auto& ch : osc.getHardwareChannels()) {
          if (ch->isEnabled()) {
              ImVec4 color = toImVec4(ch->getColor());
              ImGui::PushStyleColor(ImGuiCol_Text, color);
              if (ImGui::BeginTabItem(ch->getLabel().c_str())) {
                  m_active_channel = ch.get();
                  m_active_processor = nullptr;
                  ImGui::EndTabItem();
              }
              ImGui::PopStyleColor();
          }
      }

      // 2. Processors grouped by type
      auto draw_processors_of_type = [&](ProcessorType type) {
          auto process_channel = [&](IChannel* channel) {
              for (auto* proc : channel->getProcessors()) {
                  if (!proc->isEnabled() || proc->getType() != type) continue;
                  ImVec4 color = toImVec4(proc->getColor());
                  ImGui::PushStyleColor(ImGuiCol_Text, color);
                  std::string label = proc->getName() + "###" + channel->getLabel() + proc->getName();
                  if (ImGui::BeginTabItem(label.c_str())) {
                      m_active_channel = nullptr;
                      m_active_processor = proc;
                      ImGui::EndTabItem();
                  }
                  ImGui::PopStyleColor();
              }
          };
          for (auto& ch : osc.getHardwareChannels()) process_channel(ch.get());
          for (auto& vc : osc.getVirtualChannels()) process_channel(vc.get());
      };

      draw_processors_of_type(ProcessorType::Math);
      draw_processors_of_type(ProcessorType::Filter);
      draw_processors_of_type(ProcessorType::FFT);
      draw_processors_of_type(ProcessorType::Unknown);

      ImGui::EndTabBar();
  }
  ImGui::EndChild();

  ImPlot::PushStyleVar(ImPlotStyleVar_PlotPadding, ImVec2(0, 0));
  ImPlot::PushStyleVar(ImPlotStyleVar_PlotBorderSize, 0.0f);

  ImVec2 cursor = ImGui::GetCursorScreenPos();
  cursor.x = std::floor(cursor.x);
  cursor.y = std::floor(cursor.y);
  ImGui::SetCursorScreenPos(cursor);

  ImPlotFlags flags = ImPlotFlags_CanvasOnly | ImPlotFlags_NoLegend;

  if (ImPlot::BeginPlot("##OscilloscopeImage", ImVec2(-1, -1), flags)) {
    ImPlot::SetupAxesLimits(0, w, -12, h + 12, ImGuiCond_Always);
    ImPlot::SetupAxisLimitsConstraints(ImAxis_X1, 0, w);
    ImPlot::SetupAxisLimitsConstraints(ImAxis_Y1, -12, h + 12);
    ImPlot::SetupAxis(ImAxis_X1, nullptr, ImPlotAxisFlags_NoDecorations);
    ImPlot::SetupAxis(ImAxis_Y1, nullptr, ImPlotAxisFlags_NoDecorations);

    if (m_display) {
      m_display->updateTexture();

      ImPlot::PlotImage("OscilloscopeTrace",
                        (ImTextureID)(intptr_t)m_display->getTextureID(),
                        ImPlotPoint(0, h), ImPlotPoint(w, 0));
    }

    drawFrequencyTraces(osc);
    drawVirtualTimeTraces(osc);
    drawGridLines(w, h);

    if (m_show_trigger_line) {
      drawTriggerLine(osc);
    }

    // Handle Dragging and Zooming on the active channel
    if (ImPlot::IsPlotHovered() && (m_active_channel != nullptr || m_active_processor != nullptr)) {
        ImVec2 delta = ImGui::IsMouseDragging(0) ? ImGui::GetIO().MouseDelta : ImVec2(0,0);
        float scroll = ImGui::GetIO().MouseWheel;

        bool changed = false;
        static double h_remainder = 0.0;

        auto apply_interaction = [&](auto* target, double max_buf, bool is_fft, bool is_channel) {
            double h_scale = static_cast<double>(target->getHorizontalScale());
            if (h_scale == 0.0) h_scale = max_buf;
            
            if (delta.x != 0.0f) {
                double samples_delta = (delta.x / w) * h_scale;
                h_remainder -= samples_delta;
                int int_delta = static_cast<int>(h_remainder);
                
                if (int_delta != 0) {
                    double current_offset = static_cast<double>(static_cast<int>(target->getHorizontalOffset()));
                    double new_offset = current_offset + static_cast<double>(int_delta);
                    
                    double min_off, max_off;
                    if (is_fft) {
                        min_off = 0.0;
                        max_off = std::max(0.0, max_buf - h_scale);
                    } else {
                        double limit = std::max(0.0, max_buf / 2.0 - 0.5 * h_scale);
                        min_off = -limit;
                        max_off = limit;
                    }
                    
                    new_offset = std::max(min_off, std::min(max_off, new_offset));
                    int actual_delta = static_cast<int>(new_offset - current_offset);
                    if (actual_delta != 0) {
                        target->setHorizontalOffset(static_cast<int>(new_offset));
                        changed = true;
                    }
                    h_remainder -= int_delta;
                }
            }
            if (delta.y != 0.0f) {
                double doffset = (delta.y / h) * static_cast<double>(Constants::ADC_LEVELS);
                double current_offset = target->getVerticalOffset();
                double new_offset = current_offset - doffset;
                new_offset = std::max(-128.0, std::min(128.0, new_offset));
                target->setVerticalOffset(static_cast<float>(new_offset));
                changed = true;
            }
            if (scroll != 0.0f) {
                ImPlotPoint mouse_pt = ImPlot::GetPlotMousePos();
                double mouse_x = mouse_pt.x;
                double mouse_y = mouse_pt.y;
                
                if (ImGui::GetIO().KeyShift) {
                    double current_v_scale = static_cast<double>(target->getVerticalScale());
                    double current_v_offset = static_cast<double>(target->getVerticalOffset());
                    
                    double factor = std::pow(1.1, static_cast<double>(scroll));
                    double new_v_scale = current_v_scale * factor;
                    
                    double y_val = (mouse_y / h * static_cast<double>(Constants::ADC_LEVELS)) - static_cast<double>(Constants::ADC_MIDPOINT);
                    double centered = (y_val - current_v_offset) / current_v_scale;
                    double new_v_offset = current_v_offset + centered * (current_v_scale - new_v_scale);
                    
                    target->setVerticalScale(static_cast<float>(std::max(0.01, new_v_scale)));
                    target->setVerticalOffset(static_cast<float>(new_v_offset));
                } else {
                    double current_h_offset = static_cast<double>(static_cast<int>(target->getHorizontalOffset()));
                    
                    double factor = std::pow(0.9, static_cast<double>(scroll));
                    double new_h_scale = std::max(2.0, std::min(max_buf, h_scale * factor));
                    
                    double x_frac = mouse_x / w;
                    double new_h_offset;
                    if (is_fft) {
                        new_h_offset = current_h_offset + (h_scale - new_h_scale) * x_frac;
                    } else {
                        new_h_offset = current_h_offset + (new_h_scale - h_scale) * (0.5 - x_frac);
                    }
                    
                    double min_off, max_off;
                    if (is_fft) {
                        min_off = 0.0;
                        max_off = std::max(0.0, max_buf - new_h_scale);
                    } else {
                        double limit = std::max(0.0, max_buf / 2.0 - 0.5 * new_h_scale);
                        min_off = -limit;
                        max_off = limit;
                    }
                    
                    new_h_offset = std::max(min_off, std::min(max_off, new_h_offset));
                    
                    target->setHorizontalScale(static_cast<size_t>(std::round(new_h_scale)));
                    target->setHorizontalOffset(static_cast<int>(std::round(new_h_offset)));
                }
                changed = true;
            }
        };

        if (m_active_channel) {
            apply_interaction(m_active_channel, 16384.0, false, true);
        } else if (m_active_processor) {
            bool is_fft = dynamic_cast<FFTProcessor*>(m_active_processor) != nullptr;
            double max_buf = 16384.0;
            if (is_fft) {
                max_buf = static_cast<double>(static_cast<FFTProcessor*>(m_active_processor)->getWindowSize() / 2);
            } else {
                for (auto& vc : osc.getVirtualChannels()) {
                    for (auto* proc : vc->getProcessors()) {
                        if (proc == m_active_processor && !vc->getTraces().empty()) {
                            max_buf = static_cast<double>(vc->getTraces().front().data.size());
                        }
                    }
                }
            }
            apply_interaction(m_active_processor, max_buf, is_fft, false);
        }

        if (changed) osc.forceReprocess();
    }

    // Draw horizontal trigger position indicator badge at the top of the grid
    if (!osc.getHardwareChannels().empty()) {
      size_t src_idx = osc.getTriggerSourceIndex();
      if (src_idx >= osc.getHardwareChannels().size()) {
        src_idx = 0;
      }
      auto &channel = osc.getHardwareChannels()[src_idx];
      double h_scale = static_cast<double>(channel->getHorizontalScale());
      double h_offset = static_cast<double>(channel->getHorizontalOffset());

      ImVec4 badge_color =
          toImVec4(osc.getHardwareChannels()[src_idx]->getColor());
      badge_color.w = 1.0f;

      // only draw trigger marker if any hardware channels are enabled
      if (std::any_of(osc.getHardwareChannels().begin(),
                      osc.getHardwareChannels().end(),
                      [](const auto &ch) { return ch->isEnabled(); })) {
        drawTriggerMarker("T", h_scale, h_offset, w, h, badge_color, 5.0f);
      }
    }

    // Draw horizontal trigger position indicator badge for the virtual channel
    // (math)
    for (auto &vc : osc.getVirtualChannels()) {
      bool has_enabled_processor = false;
      double v_scale = 2048.0;
      double v_offset = 0.0;
      ImVec4 v_badge_color = toImVec4(vc->getColor());
      for (auto &proc : vc->getProcessors()) {
        if (proc->isEnabled()) {
          has_enabled_processor = true;
          v_scale = static_cast<double>(proc->getHorizontalScale());
          v_offset = static_cast<double>(
              static_cast<int>(proc->getHorizontalOffset()));
          v_badge_color = toImVec4(proc->getColor());
          break;
        }
      }
      if (vc->isEnabled() && has_enabled_processor) {
        drawTriggerMarker("TM", v_scale, v_offset, w, h, v_badge_color, 22.0f);
      }
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

  ImGui::Text("Mode");
  ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
  if (ImGui::Combo("##Mode", &selected, items, 2)) {
    TriggerMode mode = selected == 0 ? TriggerMode::AUTO : TriggerMode::NORMAL;
    osc.getTrigger()->setMode(mode);
  }
}

// Control Helpers
// Controls how many samples are visible horizontally.
// TODO: Change this to time division instead of samples
void OscilloscopeUI::drawHorizontalControls(IChannel &channel,
                                            Oscilloscope &osc) {
  int samples = static_cast<int>(channel.getHorizontalScale());
  if (drawSliderIntWithInput("Horizontal Scale", &samples, 256, 16384, "%d samples", false)) {
    channel.setHorizontalScale(static_cast<size_t>(samples));
    osc.forceReprocess();
  }

  int h_offset = channel.getHorizontalOffset();
  int capture_width = static_cast<int>(osc.getMaxCaptureWidth());
  int visible_width = static_cast<int>(channel.getHorizontalScale());
  int max_offset = std::max(0, (capture_width - visible_width) / 2);

  if (drawSliderIntWithInput("Horizontal Offset", &h_offset, -max_offset, max_offset, "%d samples", true)) {
    channel.setHorizontalOffset(h_offset);
    osc.forceReprocess();
  }
}

// TODO: Change this to voltage division instead of Scale
void OscilloscopeUI::drawVerticalControls(IChannel &channel,
                                          Oscilloscope &osc) {
  auto drawSlider = [&](const char* label, float* v, float v_min, float v_max, const char* format, bool add_spacing) {
      return this->drawSliderFloatWithInput(label, v, v_min, v_max, format, add_spacing);
  };
  drawVerticalControlsT(&channel, osc, -255.0f, 255.0f, "%.1f", drawSlider);
}

// Control pannels

void OscilloscopeUI::drawFFTControls(Oscilloscope &osc) {
  bool found_fft = false;

  for (auto &channel : osc.getHardwareChannels()) {
    ImGui::PushID(channel->getLabel().c_str());

    for (auto &processor : channel->getProcessors()) {
      if (processor->getType() != ProcessorType::FFT) {
        continue;
      }

      auto *fft_proc = dynamic_cast<FFTProcessor *>(processor);
      if (!fft_proc) {
        continue;
      }

      found_fft = true;

      drawComponentHeader(fft_proc, fft_proc->getName(), osc, fft_proc->getWindowSize() / 2);
      
      auto drawSlider = [&](const char* label, float* v, float v_min, float v_max, const char* format, bool add_spacing) {
          return this->drawSliderFloatWithInput(label, v, v_min, v_max, format, add_spacing);
      };
      drawVerticalControlsT(fft_proc, osc, -500.0f, 500.0f, "%.1f", drawSlider);

      int fft_size = static_cast<int>(fft_proc->getWindowSize());
      int num_bins = fft_size / 2;
      int h_scale = static_cast<int>(fft_proc->getHorizontalScale());
      if (h_scale == 0 || h_scale > num_bins)
        h_scale = num_bins;
      if (drawSliderIntWithInput("Horizontal Scale", &h_scale, 2, num_bins, "%d bins", false)) {
        fft_proc->setHorizontalScale(static_cast<size_t>(h_scale));
        osc.forceReprocess();
      }

      int h_offset = static_cast<int>(fft_proc->getHorizontalOffset());
      int max_offset = std::max(1, num_bins - h_scale);
      if (h_offset > max_offset) {
        h_offset = max_offset;
        fft_proc->setHorizontalOffset(static_cast<size_t>(h_offset));
      }
      if (drawSliderIntWithInput("Horizontal Offset", &h_offset, 0, max_offset, "%d bins", true)) {
        fft_proc->setHorizontalOffset(static_cast<size_t>(h_offset));
        osc.forceReprocess();
      }

      int selected_mode = fft_proc->getIsModeLinear() ? 0 : 1;
      const char *modes[] = {"Linear", "Decibel"};
      if (drawCombo("Representation", &selected_mode, modes, 2, true)) {
        fft_proc->setIsModeLinear(selected_mode == 0);
        osc.forceReprocess();
      }

      // Window Type Selection
      const char *window_types[] = {"Rectangular", "Hann", "Hamming",
                                    "Blackman-Harris", "Flat Top"};
      int current_type = 0;
      std::string current_name = fft_proc->getWindowTypeName();
      for (int i = 0; i < 5; i++) {
        if (current_name == window_types[i]) {
          current_type = i;
          break;
        }
      }

      if (drawCombo("Window Function", &current_type, window_types, 5, true)) {
        fft_proc->setWindowType(current_type);
        osc.forceReprocess();
      }

      float smoothing_factor = fft_proc->getSmoothingFactor();
      if (drawSliderFloatWithInput("Smoothing", &smoothing_factor, 0.0f, 1.00f, "%.2f", true)) {
        fft_proc->setSmoothingFactor(smoothing_factor);
        osc.forceReprocess();
      }

      if (drawSliderIntWithInput("Resolution", &fft_size, 256, 16384, "%d samples", true)) {
        fft_proc->setWindowSize(static_cast<size_t>(fft_size));
        osc.forceReprocess();
      }

      ImGui::Spacing();
      ImGui::Separator();
      ImGui::Spacing();
    }

    ImGui::PopID();
  }

  if (!found_fft) {
    ImGui::TextDisabled("No FFT processor found.");
  }
}

void OscilloscopeUI::drawMathControls(Oscilloscope &osc) {
  bool found_math = false;

  for (auto &channel : osc.getVirtualChannels()) {
    ImGui::PushID(channel->getLabel().c_str());

    for (auto &processor : channel->getProcessors()) {
      if (processor->getType() != ProcessorType::Math) {
        continue;
      }

      found_math = true;

      drawComponentHeader(processor, processor->getName(), osc);
      
      auto drawSlider = [&](const char* label, float* v, float v_min, float v_max, const char* format, bool add_spacing) {
          return this->drawSliderFloatWithInput(label, v, v_min, v_max, format, add_spacing);
      };
      drawVerticalControlsT(processor, osc, -500.0f, 500.0f, "%.1f", drawSlider);

      int h_scale = static_cast<int>(processor->getHorizontalScale());
      if (drawSliderIntWithInput("Horizontal Scale", &h_scale, 256, 16384, "%d samples", false)) {
        processor->setHorizontalScale(static_cast<size_t>(h_scale));
        osc.forceReprocess();
      }

      int h_offset = static_cast<int>(processor->getHorizontalOffset());
      int capture_width = static_cast<int>(osc.getMaxCaptureWidth());
      int max_offset = std::max(0, (capture_width - h_scale) / 2);

      if (drawSliderIntWithInput("Horizontal Offset", &h_offset, -max_offset, max_offset, "%d samples", true)) {
        processor->setHorizontalOffset(static_cast<size_t>(h_offset));
        osc.forceReprocess();
      }

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
        for (size_t i = 0; i < num_channels; i++) {
          channel_labels[i] = osc.getHardwareChannels()[i]->getLabel();
          channel_labels_cstr[i] = channel_labels[i].c_str();
          if (channel_labels[i] == math_proc->getSource1Label()) {
            src1_idx = static_cast<int>(i);
          }
          if (channel_labels[i] == math_proc->getSource2Label()) {
            src2_idx = static_cast<int>(i);
          }
        }

        if (drawCombo("Source 1", &src1_idx, channel_labels_cstr.data(), static_cast<int>(num_channels), true)) {
          math_proc->setSource1Label(channel_labels[src1_idx]);
          osc.forceReprocess();
        }

        // Source 2 Selection (hidden for single-source operations)
        if (math_proc->getOperation() != MathOperation::INVERT &&
            math_proc->getOperation() != MathOperation::INTEGRATE &&
            math_proc->getOperation() != MathOperation::DIFFERENTIATE) {
          if (drawCombo("Source 2", &src2_idx, channel_labels_cstr.data(), static_cast<int>(num_channels), true)) {
            math_proc->setSource2Label(channel_labels[src2_idx]);
            osc.forceReprocess();
          }
        }

        // Smoothing control for differentiation
        if (math_proc->getOperation() == MathOperation::DIFFERENTIATE) {
          int radius = static_cast<int>(math_proc->getDiffSmoothRadius());
          if (drawSliderIntWithInput("Smoothing Radius", &radius, 0, 128, "%d samples", true)) {
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

void OscilloscopeUI::drawFilterControls(Oscilloscope &osc) {
  bool found_filter = false;

  for (auto &channel : osc.getVirtualChannels()) {
    ImGui::PushID(channel->getLabel().c_str());

    for (auto &processor : channel->getProcessors()) {
      if (processor->getType() != ProcessorType::Filter) {
        continue;
      }

      auto *filter_proc = dynamic_cast<FilterProcessor *>(processor);
      if (!filter_proc) {
        continue;
      }

      found_filter = true;

      drawComponentHeader(filter_proc, filter_proc->getName(), osc, Scoped::Constants::DEFAULT_HORIZONTAL_SCALE);
      
      auto drawSlider = [&](const char* label, float* v, float v_min, float v_max, const char* format, bool add_spacing) {
          return this->drawSliderFloatWithInput(label, v, v_min, v_max, format, add_spacing);
      };
      drawVerticalControlsT(filter_proc, osc, -500.0f, 500.0f, "%.1f", drawSlider);

      int h_scale = static_cast<int>(filter_proc->getHorizontalScale());
      if (drawSliderIntWithInput("Horizontal Scale", &h_scale, 256, 16384, "%d samples", false)) {
        filter_proc->setHorizontalScale(static_cast<size_t>(h_scale));
        osc.forceReprocess();
      }

      int h_offset = static_cast<int>(filter_proc->getHorizontalOffset());
      int capture_width = static_cast<int>(osc.getMaxCaptureWidth());
      int visible_width = static_cast<int>(filter_proc->getHorizontalScale());
      int max_offset = std::max(0, (capture_width - visible_width) / 2);
      if (h_offset > max_offset) {
        h_offset = max_offset;
        filter_proc->setHorizontalOffset(static_cast<size_t>(h_offset));
      }
      if (drawSliderIntWithInput("Horizontal Offset", &h_offset, -max_offset, max_offset, "%d samples", true)) {
        filter_proc->setHorizontalOffset(static_cast<size_t>(h_offset));
        osc.forceReprocess();
      }

      int selected_type = static_cast<int>(filter_proc->getFilterType());
      const char *types[] = {"Lowpass", "Highpass", "Bandpass", "Bandstop"};
      if (drawCombo("Filter Type", &selected_type, types, 4, true)) {
        filter_proc->setFilterType(static_cast<FilterType>(selected_type));
        osc.forceReprocess();
      }

      int selected_resp = static_cast<int>(filter_proc->getFilterResponse());
      const char *resps[] = {"Butterworth", "Chebyshev", "Bessel", "Basic"};
      if (drawCombo("Response", &selected_resp, resps, 4, true)) {
        filter_proc->setFilterResponse(static_cast<FilterResponse>(selected_resp));
        osc.forceReprocess();
      }

      std::vector<std::string> channel_labels;
      std::vector<const char *> channel_labels_cstr;
      size_t num_channels = osc.getHardwareChannels().size();
      channel_labels.resize(num_channels);
      channel_labels_cstr.resize(num_channels);
      int src1_idx = 0;
      for (size_t i = 0; i < num_channels; i++) {
        channel_labels[i] = osc.getHardwareChannels()[i]->getLabel();
        channel_labels_cstr[i] = channel_labels[i].c_str();
        if (channel_labels[i] == filter_proc->getSource1Label()) {
          src1_idx = static_cast<int>(i);
        }
      }

      float cutoff = filter_proc->getCutoff();
      float nyquist = Scoped::Constants::ADC_SAMPLE_RATE_HZ / 2.0f;
      ImGui::Text("Cutoff Frequency");
      ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
      if (ImGui::InputFloat("##Cutoff Frequency", &cutoff, 0.0f, 0.0f, "%.1f Hz")) {
        filter_proc->setCutoff(std::clamp(cutoff, 1.0f, nyquist));
        osc.forceReprocess();
      }
      
      if (drawCombo("Source", &src1_idx, channel_labels_cstr.data(), static_cast<int>(num_channels), true)) {
        filter_proc->setSource1Label(channel_labels[src1_idx]);
        osc.forceReprocess();
      }

      ImGui::Spacing();
      ImGui::Separator();
      ImGui::Spacing();
    }

    ImGui::PopID();
  }

  if (!found_filter) {
    ImGui::TextDisabled("No filter processor found.");
  }
}

void OscilloscopeUI::buildDefaultDockLayout(ImGuiID dockspace_id,
                                            const ImVec2 &dockspace_size) {
  ImGui::DockBuilderRemoveNode(dockspace_id);

  ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace);
  ImGui::DockBuilderSetNodeSize(dockspace_id, dockspace_size);

  ImGuiID main_id = dockspace_id;

  ImGuiID left_id = ImGui::DockBuilderSplitNode(main_id, ImGuiDir_Left, 0.22f,
                                                nullptr, &main_id);

  ImGuiID right_id = ImGui::DockBuilderSplitNode(main_id, ImGuiDir_Right,
                                                 0.282f, nullptr, &main_id);

  ImGuiID bottom_id = ImGui::DockBuilderSplitNode(main_id, ImGuiDir_Down, 0.24f,
                                                  nullptr, &main_id);

  ImGui::DockBuilderDockWindow("Scope View", main_id);

  ImGui::DockBuilderDockWindow("Channels", left_id);
  ImGui::DockBuilderDockWindow("Trigger", left_id);

  ImGui::DockBuilderDockWindow("FFT", right_id);
  ImGui::DockBuilderDockWindow("Math", right_id);
  ImGui::DockBuilderDockWindow("Filter", right_id);
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
      ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar |
      ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
      ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus |
      ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground;

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

  ImGui::TextDisabled("Display");
  ImGui::Separator();

  drawPlotArea(osc);

  ImGui::End();
}

// Trigger controls window.
void OscilloscopeUI::drawTriggerWindow(Oscilloscope &osc) {
  ImGui::Begin("Trigger");
  ImGui::SetWindowFontScale(1.15f);

  auto *trigger = osc.getTrigger();

  if (!trigger) {
    ImGui::TextDisabled("No trigger configured.");
    ImGui::End();
    return;
  }

  bool enabled = trigger->isEnabled();
  ImGui::PushStyleColor(ImGuiCol_Text,
                        enabled ? Colors::StatusError : Colors::StatusOk);
  if (ImGui::Button(enabled ? "Stop" : "Start", ImVec2(-1, 0))) {
    trigger->setEnabled(!enabled);
  }
  ImGui::PopStyleColor();

  ImGui::Spacing();
  ImGui::Text("Source");
  int trigger_source_idx = static_cast<int>(osc.getTriggerSourceIndex());
  std::vector<std::string> channel_labels;
  std::vector<const char *> channel_labels_cstr;
  size_t num_hw = osc.getHardwareChannels().size();
  channel_labels.resize(num_hw);
  channel_labels_cstr.resize(num_hw);
  for (size_t i = 0; i < num_hw; i++) {
    channel_labels[i] = osc.getHardwareChannels()[i]->getLabel();
    channel_labels_cstr[i] = channel_labels[i].c_str();
  }

  ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
  if (ImGui::Combo("##Source", &trigger_source_idx, channel_labels_cstr.data(),
                   static_cast<int>(num_hw))) {
    osc.setTriggerSource(static_cast<size_t>(trigger_source_idx));
    osc.forceReprocess();
  }

  drawModeCombo(osc);

  ImGui::Spacing();

  ImGui::Checkbox("Show trigger line", &m_show_trigger_line);

  ImGui::Separator();

  // Parameters are set in trigger.hpp
  auto params = trigger->getUIParameters();

  for (const auto &param : params) {
    ImGui::PushID(param.name.c_str());

    ImGui::Text("%s", param.name.c_str());

    int value = param.current_val;

    if (param.combo_items.empty()) {
      ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x * 0.7f);
      if (ImGui::SliderInt("##Value", &value, param.min_val, param.max_val)) {
        trigger->setUIParameter(param.name, value);
        osc.forceReprocess();
      }
      ImGui::SameLine();
      ImGui::SetNextItemWidth(-FLT_MIN);
      if (ImGui::InputInt("##ValueInput", &value, 0, 0)) {
        trigger->setUIParameter(
            param.name, std::clamp(value, param.min_val, param.max_val));
        osc.forceReprocess();
      }
    } else {
      std::vector<const char *> combo_items;

      for (const auto &item : param.combo_items) {
        combo_items.push_back(item.c_str());
      }

      ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);

      if (ImGui::Combo("##Value", &value, combo_items.data(),
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
  ImGui::SetWindowFontScale(1.15f);

  drawFFTControls(osc);

  ImGui::End();
}

void OscilloscopeUI::drawMathWindow(Oscilloscope &osc) {
  ImGui::Begin("Math");
  ImGui::SetWindowFontScale(1.15f);

  drawMathControls(osc);

  ImGui::End();
}

void OscilloscopeUI::drawFilterWindow(Oscilloscope &osc) {
  ImGui::Begin("Filter");
  ImGui::SetWindowFontScale(1.15f);

  drawFilterControls(osc);

  ImGui::End();
}

// Channel controls window.
void OscilloscopeUI::drawChannelWindow(Oscilloscope &osc) {
  ImGui::Begin("Channels");
  ImGui::SetWindowFontScale(1.15f);

  if (osc.getHardwareChannels().empty()) {
    ImGui::TextDisabled("No channels available.");
    ImGui::End();
    return;
  }

  // Per-Channel Controls
  for (auto &channel : osc.getHardwareChannels()) {
    ImGui::PushID(channel->getLabel().c_str());

    drawComponentHeader(channel.get(), channel->getLabel(), osc);
    drawVerticalControls(*channel, osc);
    drawHorizontalControls(*channel, osc);

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::PopID();
  }

  ImGui::End();
}

// USB connection window.
void OscilloscopeUI::drawHardwareWindow(Oscilloscope &osc) {
  ImGui::Begin("Hardware");
  ImGui::SetWindowFontScale(1.15f);

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
        for (auto &channel : osc.getHardwareChannels()) {
          channel->clearBuffer();
        }

        if (osc.getTrigger()) {
          osc.getTrigger()->clear();
        }

        if (!osc.getHardwareChannels().empty()) {
          usb.startStreaming(osc.getHardwareChannels()[0].get());
        }
      }
    }
  }

  ImGui::End();
}

// Debug window.
void OscilloscopeUI::drawDebugWindow(Oscilloscope &osc) {
  ImGui::Begin("Debug");
  ImGui::SetWindowFontScale(1.15f);

  ImGui::Text("Display width: %zu", m_display_width);
  ImGui::Text("Display height: %zu", m_display_height);
  ImGui::Text("Hardware Channels: %zu", osc.getHardwareChannels().size());
  ImGui::Text("Virtual Channels: %zu", osc.getVirtualChannels().size());

  ImGui::Separator();
  ImGui::Text("ADC Configuration:");
  ImGui::Text("  Resolution: %zu-bit", Constants::ADC_BITS);
  ImGui::Text("  Levels: %.0f", Constants::ADC_LEVELS);
  ImGui::Text("  Sample Rate: %.0f Hz", Constants::ADC_SAMPLE_RATE_HZ);

  if (!osc.getHardwareChannels().empty()) {
    auto &channel = osc.getHardwareChannels()[0];

    ImGui::Separator();
    // TODO: add channel specific debug info
  }

  ImGui::End();
}

// ui.render(osc);
void OscilloscopeUI::render(Oscilloscope &osc) {
  processNewFrames(osc);

  drawMainMenu();
  drawDockSpace();

  drawScopeWindow(osc);
  drawChannelWindow(osc);
  drawTriggerWindow(osc);
  drawFFTWindow(osc);
  drawMathWindow(osc);
  drawFilterWindow(osc);
  drawHardwareWindow(osc);
  drawDebugWindow(osc);
}

} // namespace Scoped
