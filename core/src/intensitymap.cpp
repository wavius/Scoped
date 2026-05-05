#include <algorithm>
#include <cstdint>
#include <intensitymap.hpp>

namespace Scoped {

IntensityMap::IntensityMap(size_t width, size_t height)
    : m_width(width), m_height(height), m_grid(width * height, 0),
      m_texture_data(width * height, {0, 0, 0, 255}) {
  initTexture();
}

IntensityMap::~IntensityMap() {
  if (m_texture_id != 0) {
    glDeleteTextures(1, &m_texture_id);
  }
}

const uint32_t *IntensityMap::getMap() const { return m_grid.data(); }

size_t IntensityMap::getWidth() const { return m_width; }

size_t IntensityMap::getHeight() const { return m_height; }

GLuint IntensityMap::getTextureID() const { return m_texture_id; }

void IntensityMap::initTexture() {
  glGenTextures(1, &m_texture_id);
  glBindTexture(GL_TEXTURE_2D, m_texture_id);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA,
               GL_UNSIGNED_BYTE, nullptr);
}

void IntensityMap::updateTexture() {
  const size_t pixel_count = m_width * m_height;

  for (size_t i = 0; i < pixel_count; ++i) {
    uint8_t brightness =
        static_cast<uint8_t>(std::min(m_grid[i] * 255, 255u));
    m_texture_data[i] = {0, brightness, brightness, 255};
  }

  glBindTexture(GL_TEXTURE_2D, m_texture_id);
  glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, m_width, m_height, GL_RGBA,
                  GL_UNSIGNED_BYTE, m_texture_data.data());
}

void IntensityMap::clear() {
  std::fill(m_grid.begin(), m_grid.end(), 0);
}

void IntensityMap::addSample(float x, float y) {
  uint32_t x0 = static_cast<uint32_t>(x);
  uint32_t y0 = static_cast<uint32_t>(y);

  if (x0 + 1 >= m_width || y0 + 1 >= m_height)
    return;

  float fx = x - x0;
  float fy = y - y0;

  // Bilinear distribution across the 4 nearest pixels
  m_grid[y0 * m_width + x0] +=
      static_cast<uint32_t>((1.0f - fx) * (1.0f - fy) * 10);
  m_grid[y0 * m_width + (x0 + 1)] +=
      static_cast<uint32_t>(fx * (1.0f - fy) * 10);
  m_grid[(y0 + 1) * m_width + x0] +=
      static_cast<uint32_t>((1.0f - fx) * fy * 10);
  m_grid[(y0 + 1) * m_width + (x0 + 1)] +=
      static_cast<uint32_t>(fx * fy * 10);
}

void IntensityMap::decay(float factor) {
  for (auto &val : m_grid) {
    val = static_cast<uint32_t>(val * factor);
  }
}

void IntensityMap::processFrame(const DisplayFrame &frame) {
  const uint8_t *samples = frame.getSamples();
  const size_t length = frame.getSize();
  if (length == 0)
    return;

  const uint32_t max_y = static_cast<uint32_t>(m_height - 1);
  uint32_t *const grid_data = m_grid.data();
  const size_t cols = std::min(length, m_width);

  // Plot the first sample
  uint32_t prev_y = (static_cast<uint32_t>(samples[0]) * max_y) >> 8;
  grid_data[prev_y * m_width]++;

  // For each subsequent column, draw a vertical line connecting
  // the previous Y to the current Y to avoid gaps.
  for (size_t x = 1; x < cols; ++x) {
    uint32_t cur_y = (static_cast<uint32_t>(samples[x]) * max_y) >> 8;

    uint32_t y_start = std::min(prev_y, cur_y);
    uint32_t y_end = std::max(prev_y, cur_y);

    uint32_t *col = &grid_data[x];
    for (uint32_t y = y_start; y <= y_end; ++y) {
      col[y * m_width]++;
    }

    prev_y = cur_y;
  }
}

} // namespace Scoped
