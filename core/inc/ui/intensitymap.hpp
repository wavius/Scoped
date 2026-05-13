#pragma once

#include <GL/gl.h>
#include <cstdint>
#include <vector>

namespace Scoped {

// 2D accumulation grid for digital phosphor display.
// Accepts normalized waveform data [0.0, 1.0] and rasterizes it into
// a hit-count grid using Bresenham lines, then uploads to an OpenGL texture.
class IntensityMap {
private:
  struct RGBA {
    uint8_t r, g, b, a;
  };

  size_t m_width;
  size_t m_height;
  std::vector<uint32_t> m_grid;
  std::vector<RGBA> m_texture_data;
  GLuint m_texture_id = 0;
  float m_r = 0.0f;
  float m_g = 1.0f;
  float m_b = 1.0f;

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
  void clear();

  // Bilinearly distributes intensity at a sub-pixel coordinate.
  void addSample(float x, float y);

  // Multiplies all intensity values by a decay factor (0.0–1.0).
  void decay(float factor);

  // Rasterizes normalized waveform data into the intensity grid.
  // Values in [0.0, 1.0] map to [bottom, top] of the display.
  void processFrame(const float *normalized, size_t count);

  void updateTexture();
  void setColor(float r, float g, float b) {
    m_r = r;
    m_g = g;
    m_b = b;
  }
};

} // namespace Scoped
