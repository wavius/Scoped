#pragma once

#include <implot.h> // IWYU pragma: keep
#include <intensitymap.hpp>
#include <trigger.hpp>
#include <usb.hpp>
#include <circularbuffer.hpp>

namespace Scoped {

/**
 * @brief Registers a custom colormap for the oscilloscope display.
 *
 * Creates a two-point gradient from black (zero intensity)
 * to the specified channel color (maximum intensity).
 *
 * @param color The color assigned to the signal trace.
 */
void setupChannelColormap(ImVec4 color);

/**
 * @brief Renders the intensity map as a textured quad inside an ImPlot region.
 * @param map The IntensityMap to render.
 * @param trigger The trigger object to pull threshold from.
 */
void renderIntensityMap(IntensityMap &map, Trigger &trigger);

/**
 * @brief Renders the complete oscilloscope UI including plot and controls.
 * @param trigger The trigger object to configure.
 * @param map The intensity map to display.
 */
void renderOscilloscopeUI(Trigger &trigger, IntensityMap &map, USBDevice &usb, CircularBuffer &buffer, size_t &visible_samples);

/**
 * @brief Renders a horizontal line indicator at the trigger level.
 * @param trigger The trigger object containing the threshold level.
 * @param map The intensity map used to determine the scale.
 */
void renderTriggerIndicator(Trigger &trigger, IntensityMap &map);

/**
 * @brief Renders a standard 10x8 oscilloscope grid.
 */
void renderGrid(IntensityMap &map);

} // namespace Scoped
