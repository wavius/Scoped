#pragma once

#include <GL/gl.h>
#include <cstdint>
#include <vector>

#include <displayframe.hpp>

namespace Scoped {

struct RGBA {
  uint8_t r, g, b, a;
};

/**
 * @brief A 2D accumulation grid for digital phosphor display.
 *
 * Converts 1D waveform data into a 2D hit-count grid, then maps
 * the grid to an OpenGL texture for rendering.
 */
class IntensityMap {
private:
  size_t m_width;
  size_t m_height;
  std::vector<uint32_t> m_grid;
  std::vector<RGBA> m_texture_data;
  GLuint m_texture_id = 0;
  float m_vertical_scale = 1.0f;

  void initTexture();

public:
  /**
   * @brief Constructs an intensity map with the given resolution.
   * @param width Horizontal resolution in pixels.
   * @param height Vertical resolution in pixels.
   */
  IntensityMap(size_t width, size_t height);

  ~IntensityMap();

  const uint32_t *getMap() const;
  size_t getWidth() const;
  size_t getHeight() const;
  GLuint getTextureID() const;

  void setVerticalScale(float scale);

  /**
   * @brief Resets all intensity values to zero.
   */
  void clear();

  /**
   * @brief Bilinearly distributes intensity at a sub-pixel coordinate.
   * @param x Horizontal coordinate (can be fractional).
   * @param y Vertical coordinate (can be fractional).
   */
  void addSample(float x, float y);

  /**
   * @brief Multiplies all intensity values by a decay factor.
   * @param factor Decay multiplier (typically 0.0–1.0).
   */
  void decay(float factor);

  /**
   * @brief Rasterizes a waveform frame into the intensity grid.
   *
   * Maps each sample to a Y coordinate and draws vertical lines
   * between consecutive samples to fill gaps.
   *
   * @param frame The triggered waveform data.
   * @param visible_samples Number of samples from the start of the frame to display.
   */
  void processFrame(const DisplayFrame &frame, size_t visible_samples);

  /**
   * @brief Uploads the current intensity data to the GPU texture.
   */
  void updateTexture();

};

} // namespace Scoped
