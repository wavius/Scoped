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
 */
void renderIntensityMap(IntensityMap &map);

/**
 * @brief Renders the complete oscilloscope UI including plot and controls.
 * @param trigger The trigger object to configure.
 * @param map The intensity map to display.
 */
void renderOscilloscopeUI(Trigger &trigger, IntensityMap &map, USBDevice &usb, CircularBuffer &buffer);

} // namespace Scoped
