#pragma once

#include <GL/gl.h>
#include <cstdint>
#include <vector>

#include <signalbuffer.hpp>

namespace Scoped {

struct RGBA {
  uint8_t r, g, b, a;
};

/**
 * @brief Manages a 2D grid of intensity values for digital phosphor display.
 *
 * This class handles the accumulation of signal samples and the temporal
 * decay required to simulate an oscilloscope's phosphor persistence.
 */
class IntensityMap {
private:
  std::vector<uint32_t> grid;
  size_t width;
  size_t height;
  std::vector<RGBA> texture_data;
  GLuint texture_id = 0;

  void initTexture();

public:
  /**
   * @brief Constructor that pre-allocates memory for the intensity map.
   * @param initial_width The horizontal resolution of the map.
   * @param initial_height The vertical resolution of the map.
   */
  IntensityMap(size_t initial_width, size_t initial_height);

  /**
   * @brief Destructor.
   */
  ~IntensityMap();

  /**
   * @brief Get a pointer to the raw intensity data.
   * @return Pointer to the uint32_t grid array.
   */
  const uint32_t *getMap() const;

  /**
   * @brief Get the width of the intensity map.
   * @return Width in pixels.
   */
  size_t getWidth() const;

  /**
   * @brief Get the height of the intensity map.
   * @return Height in pixels.
   */
  size_t getHeight() const;

  /**
   * @brief Get texture ID.
   * @return Texture ID.
   */
  GLuint getTextureID() const;

  /**
   * @brief Resets all pixels in the intensity map to zero.
   */
  void clear();

  /**
   * @brief Increments the intensity at a specific coordinate.
   * @param x Horizontal coordinate.
   * @param y Vertical coordinate.
   */
  void addSample(float x, float y);

  /**
   * @brief Reduces the intensity of all samples to simulate persistence decay.
   * @param factor Multiplying factor (typically 0.0 to 1.0).
   */
  void decay(float factor);

  /**
   * @brief Processes a signal buffer and updates the map with interpolated
   * samples.
   * @param buffer The input signal data from the hardware.
   */
  void processBuffer(const SignalBuffer &buffer);

  void updateTexture();
};

} // namespace Scoped
