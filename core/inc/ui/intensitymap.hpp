#pragma once

#include <GL/gl.h>
#include <cstdint>
#include <vector>

namespace Scoped {

// 2D accumulation grid for digital phosphor display.
// Accepts normalized waveform data [0.0, 1.0] and rasterizes it into
// a hit-count grid using Bresenham lines, then uploads to an OpenGL texture.
class IntensityMap {
public:
  struct Pixel {
    float r, g, b, a;
  };

private:
  struct RGBA {
    uint8_t r, g, b, a;
  };

  size_t m_width;
  size_t m_height;
  std::vector<Pixel> m_grid;
  std::vector<RGBA> m_texture_data;
  GLuint m_texture_id = 0;

  void initTexture();

public:
  // Lifecycle
  IntensityMap(size_t width, size_t height);
  ~IntensityMap();

  // Accessors
  size_t getWidth() const;
  size_t getHeight() const;
  GLuint getTextureID() const;

  // Rendering
  void resize(size_t width, size_t height);
  void clear();

  // Bilinearly distributes intensity at a sub-pixel coordinate.
  void addSample(float x, float y, float r, float g, float b);

  // Multiplies all intensity values by a decay factor (0.0–1.0).
  void decay(float factor);

  // Rasterizes normalized waveform data into the intensity grid.
  // Values in [0.0, 1.0] map to [bottom, top] of the display.
  void processFrame(const float *normalized, size_t count, float r, float g, float b);

  void updateTexture();
};

} // namespace Scoped
