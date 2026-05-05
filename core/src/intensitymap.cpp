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

void IntensityMap::processFrame(const DisplayFrame &frame, size_t visible_samples) {
  const uint8_t *samples = frame.getSamples();
  const size_t length = std::min(visible_samples, frame.getSize());
  if (length < 2 || m_width == 0 || m_height == 0)
    return;

  const float x_scale = static_cast<float>(m_width - 1) / static_cast<float>(length - 1);
  const int max_y = static_cast<int>(m_height - 1);
  uint32_t *const grid_data = m_grid.data();

  // Bresenham's line algorithm to draw a solid trace between samples
  auto plot_line = [&](int x1, int y1, int x2, int y2) {
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
      // Add a "hit" to the intensity grid at the current coordinate
      if (x1 >= 0 && x1 < (int)m_width && y1 >= 0 && y1 < (int)m_height) {
        grid_data[y1 * m_width + x1]++;
      }
      if (x1 == x2 && y1 == y2)
        break;
      int e2 = 2 * err;
      if (e2 > -dy) {
        err -= dy;
        x1 += sx;
      }
      if (e2 < dx) {
        err += dx;
        y1 += sy;
      }
    }
  };

  int prev_x = 0;
  // Apply vertical scale to first sample as well
  float centered0 = static_cast<float>(samples[0]) - 128.0f;
  float scaled0 = centered0 * m_vertical_scale + 128.0f;
  int prev_y = (static_cast<int>(std::clamp(scaled0, 0.0f, 255.0f)) * max_y) >> 8;

  // Iterate through all samples and draw lines between consecutive points
  for (size_t i = 1; i < length; ++i) {
    // Map sample index to X pixel coordinate
    int cur_x = static_cast<int>(i * x_scale);
    
    // Apply vertical scale centered at 128 (mid-scale) to simulate Volts/Div zoom
    float centered = static_cast<float>(samples[i]) - 128.0f;
    float scaled = centered * m_vertical_scale + 128.0f;
    
    // Clamp to 0-255 range and map to pixel height
    int cur_y = static_cast<int>(std::clamp(scaled, 0.0f, 255.0f));
    cur_y = (cur_y * max_y) >> 8;

    // Draw the segment using Bresenham's algorithm to ensure a continuous trace
    plot_line(prev_x, prev_y, cur_x, cur_y);

    prev_x = cur_x;
    prev_y = cur_y;
  }
}


void IntensityMap::setVerticalScale(float scale) {
  m_vertical_scale = scale;
}

} // namespace Scoped
