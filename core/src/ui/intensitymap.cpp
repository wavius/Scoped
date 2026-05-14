#include <algorithm>
#include <cmath>
#include <cstdint>
#include <ui/intensitymap.hpp>

namespace Scoped {

// Lifecycle
IntensityMap::IntensityMap(size_t width, size_t height)
    : m_width(width), m_height(height), m_grid(width * height, {0.0f, 0.0f, 0.0f, 0.0f}),
      m_texture_data(width * height, {0, 0, 0, 255}) {
  initTexture();
}

IntensityMap::~IntensityMap() {
  if (m_texture_id != 0) {
    glDeleteTextures(1, &m_texture_id);
  }
}

// Accessors
size_t IntensityMap::getWidth() const { return m_width; }
size_t IntensityMap::getHeight() const { return m_height; }
GLuint IntensityMap::getTextureID() const { return m_texture_id; }

// OpenGL texture
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
    float a = m_grid[i].a;
    if (a > 0.0f) {
      uint8_t r = static_cast<uint8_t>(std::min(m_grid[i].r * 255.0f, 255.0f));
      uint8_t g = static_cast<uint8_t>(std::min(m_grid[i].g * 255.0f, 255.0f));
      uint8_t b = static_cast<uint8_t>(std::min(m_grid[i].b * 255.0f, 255.0f));
      // For brightness, we scale alpha by some factor so that low hits are still visible
      // but higher hits are brighter.
      // Wait, let's keep the existing logic where a hit directly translates to alpha.
      // But we will use the a channel. Let's say alpha = min(a * 255.0f, 255.0f)
      uint8_t brightness = static_cast<uint8_t>(std::min(a * 255.0f, 255.0f));
      m_texture_data[i] = {r, g, b, brightness};
    } else {
      m_texture_data[i] = {0, 0, 0, 0};
    }
  }

  glBindTexture(GL_TEXTURE_2D, m_texture_id);
  glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, m_width, m_height, GL_RGBA,
                  GL_UNSIGNED_BYTE, m_texture_data.data());
}

// Grid operations
void IntensityMap::clear() { std::fill(m_grid.begin(), m_grid.end(), Pixel{0.0f, 0.0f, 0.0f, 0.0f}); }

void IntensityMap::addSample(float x, float y, float r, float g, float b) {
  uint32_t x0 = static_cast<uint32_t>(x);
  uint32_t y0 = static_cast<uint32_t>(y);

  if (x0 + 1 >= m_width || y0 + 1 >= m_height)
    return;

  float fx = x - x0;
  float fy = y - y0;

  // Bilinear distribution across 4 nearest pixels
  auto add_to_pixel = [&](uint32_t idx, float weight) {
    m_grid[idx].r += r * weight;
    m_grid[idx].g += g * weight;
    m_grid[idx].b += b * weight;
    m_grid[idx].a += weight;
  };

  add_to_pixel(y0 * m_width + x0, (1.0f - fx) * (1.0f - fy) * 10.0f);
  add_to_pixel(y0 * m_width + (x0 + 1), fx * (1.0f - fy) * 10.0f);
  add_to_pixel((y0 + 1) * m_width + x0, (1.0f - fx) * fy * 10.0f);
  add_to_pixel((y0 + 1) * m_width + (x0 + 1), fx * fy * 10.0f);
}

void IntensityMap::decay(float factor) {
  for (auto &val : m_grid) {
    val.r *= factor;
    val.g *= factor;
    val.b *= factor;
    val.a *= factor;
  }
}

// Frame rasterization
static void plotLine(IntensityMap::Pixel *grid, int width, int height, int x1, int y1,
                     int x2, int y2, float r, float g, float b) {
  int dx = std::abs(x2 - x1);
  int dy = std::abs(y2 - y1);
  int sx = (x1 < x2) ? 1 : -1;
  int sy = (y1 < y2) ? 1 : -1;
  int err = dx - dy;

  while (true) {
    if (x1 >= 0 && x1 < width && y1 >= 0 && y1 < height) {
      grid[y1 * width + x1].r += r;
      grid[y1 * width + x1].g += g;
      grid[y1 * width + x1].b += b;
      grid[y1 * width + x1].a += 1.0f;
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
}

void IntensityMap::processFrame(const float *normalized, size_t count, float r, float g, float b) {
  if (count < 2 || m_width == 0 || m_height == 0)
    return;

  const float x_scale =
      static_cast<float>(m_width - 1) / static_cast<float>(count - 1);
  const int max_y = static_cast<int>(m_height - 1);

  auto toPixelY = [max_y](float n) -> int {
    return static_cast<int>(std::clamp(n, 0.0f, 1.0f) * max_y);
  };

  int prev_x = 0;
  int prev_y = toPixelY(normalized[0]);

  for (size_t i = 1; i < count; ++i) {
    int cur_x = static_cast<int>(i * x_scale);
    int cur_y = toPixelY(normalized[i]);

    plotLine(m_grid.data(), static_cast<int>(m_width),
             static_cast<int>(m_height), prev_x, prev_y, cur_x, cur_y, r, g, b);

    prev_x = cur_x;
    prev_y = cur_y;
  }
}

} // namespace Scoped
