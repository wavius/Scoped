#pragma once

#include <implot.h> // IWYU pragma: keep
#include <intensitymap.hpp>

namespace Scoped {

/**
 * @brief Registers a custom colormap for the oscilloscope display.
 *
 * Creates a two-point gradient starting from black (zero intensity)
 * to the specified channel color (maximum intensity).
 *
 * @param channel_color The color assigned to the signal trace.
 */
void setupChannelColormap(ImVec4 channel_color);

/**
 * @brief Renders the intensity map as a digital phosphor heatmap.
 *
 * Utilizes ImPlot::PlotHeatmap to project the 2D accumulation grid
 * onto the UI, mapping hit counts to the current colormap.
 *
 * @param map The IntensityMap object containing the accumulated signal data.
 */
void renderIntensityMap(IntensityMap &map);

} // namespace Scoped
