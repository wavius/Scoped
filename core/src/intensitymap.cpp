#include <algorithm>
#include <cstdint>
#include <intensitymap.hpp>
#include <sys/types.h>

namespace Scoped {

// Constructor that pre-allocates memory for the intensity map
IntensityMap::IntensityMap(size_t w, size_t h)
    : width(w), height(h), grid(w * h), texture_data(w * h, {0, 0, 0, 255}) {
  initTexture();
}

// Destructor
IntensityMap::~IntensityMap() {
  if (texture_id != 0) {
    glDeleteTextures(1, &texture_id);
  }
};

// Get a pointer to the intensity map
const uint32_t *IntensityMap::getMap() const { return grid.data(); }

// Get width of intensity map
size_t IntensityMap::getWidth() const { return width; }

// Get height of intensity map
size_t IntensityMap::getHeight() const { return height; }

// Get texture ID
GLuint IntensityMap::getTextureID() const { return texture_id; }

void IntensityMap::initTexture() {
  glGenTextures(1, &texture_id);
  glBindTexture(GL_TEXTURE_2D, texture_id);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  // Allocate the memory on the GPU
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
               GL_UNSIGNED_BYTE, nullptr);
}

void IntensityMap::updateTexture() {
  const size_t pixel_count = width * height;

  for (size_t i = 0; i < pixel_count; ++i) {
    uint32_t intensity = grid[i];

    // Convert intensity to a brightness value (0-255)
    uint32_t brightness = std::min(intensity * 255, 255u);

    // Set pixel to Cyan (R=0, G=brightness, B=brightness, A=255)
    texture_data[i] = {0, static_cast<uint8_t>(brightness),
                       static_cast<uint8_t>(brightness), 255};
  }

  // Upload the new pixel data to the GPU
  glBindTexture(GL_TEXTURE_2D, texture_id);
  glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA,
                  GL_UNSIGNED_BYTE, texture_data.data());
}

// Clear intensity map
void IntensityMap::clear() { std::fill(grid.begin(), grid.end(), 0); }

// Add a sample to the intensity map
void IntensityMap::addSample(float x, float y) {
  uint32_t x0 = static_cast<uint32_t>(x);
  uint32_t y0 = static_cast<uint32_t>(y);
  float x_frac = x - x0;
  float y_frac = y - y0;

  // Distribute intensity to the 4 nearest pixels
  if (x0 + 1 < width && y0 + 1 < height) {
    grid[y0 * width + x0] +=
        static_cast<uint32_t>((1.0f - x_frac) * (1.0f - y_frac) * 10);
    grid[y0 * width + (x0 + 1)] +=
        static_cast<uint32_t>(x_frac * (1.0f - y_frac) * 10);
    grid[(y0 + 1) * width + x0] +=
        static_cast<uint32_t>((1.0f - x_frac) * y_frac * 10);
    grid[(y0 + 1) * width + (x0 + 1)] +=
        static_cast<uint32_t>(x_frac * y_frac * 10);
  }
}

// Decay old samples in intensity map
void IntensityMap::decay(float factor) {
  for (auto &pixel : grid) {
    pixel = static_cast<uint32_t>(pixel * factor);
  }
}

// Fill intensity map from buffer
void IntensityMap::processBuffer(const DisplayFrame &buffer) {
  const uint8_t *samples = buffer.getSamples();
  const size_t length = buffer.getValidSamples();
  if (length == 0)
    return;

  const uint32_t h_m_1 = static_cast<uint32_t>(height - 1);
  const size_t w = width;
  uint32_t *const data = grid.data();
  const size_t end_x = std::min(length, w);

  uint32_t prevY = (static_cast<uint32_t>(samples[0]) * h_m_1) >> 8;

  data[prevY * w]++;

  for (size_t x = 1; x < end_x; ++x) {
    const uint32_t currY = (static_cast<uint32_t>(samples[x]) * h_m_1) >> 8;

    uint32_t *const col_ptr = &data[x];

    const uint32_t startY = (prevY < currY) ? prevY : currY;
    const uint32_t endY = (prevY > currY) ? prevY : currY;

    for (uint32_t y = startY; y <= endY; ++y) {
      col_ptr[y * w]++;
    }

    prevY = currY;
  }
}

} // namespace Scoped
