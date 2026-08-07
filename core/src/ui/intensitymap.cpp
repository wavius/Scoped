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

void IntensityMap::resize(size_t width, size_t height) {
  if (width == m_width && height == m_height)
    return;

  m_width = width;
  m_height = height;

  m_grid.assign(width * height, {0.0f, 0.0f, 0.0f, 0.0f});
  m_texture_data.assign(width * height, {0, 0, 0, 0});

  if (m_texture_id != 0) {
    glDeleteTextures(1, &m_texture_id);
  }
  initTexture();
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
static inline void plotLineFast(IntensityMap::Pixel *grid, int width, int x1, int y1,
                     int x2, int y2, float r, float g, float b) {
  int dx = std::abs(x2 - x1);
  int dy = std::abs(y2 - y1);
  int sx = (x1 < x2) ? 1 : -1;
  int sy = (y1 < y2) ? 1 : -1;
  int err = dx - dy;

  while (true) {
    // Inputs are explicitly clamped by the caller, so we can skip bounds checking for extreme speed
    auto& p = grid[y1 * width + x1];
    p.r += r;
    p.g += g;
    p.b += b;
    p.a += 1.0f;
    
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

void IntensityMap::processFrame(const float *normalized, size_t count, float r, float g, float b, double x0, double dx) {
  if (count < 2 || m_width == 0 || m_height == 0)
    return;

  double actual_dx = dx;
  if (actual_dx < 0.0) {
    actual_dx = static_cast<double>(m_width - 1) / static_cast<double>(count - 1);
  }
  
  const int max_y = static_cast<int>(m_height - 1);

  auto toPixelY = [max_y](float n) -> int {
    return static_cast<int>(std::clamp((1.0f - n) * static_cast<float>(max_y) + 0.5f, 0.0f,
                                      static_cast<float>(max_y)));
  };

  int prev_x = static_cast<int>(x0);
  int prev_y = toPixelY(normalized[0]);

  if (actual_dx < 1.0) {
    // Peak-detect (Min-Max) decimation to prevent Moiré aliasing when zoomed out
    int current_pixel_x = prev_x;
    int pixel_min_y = prev_y;
    int pixel_max_y = prev_y;
    int last_drawn_y = prev_y;

    for (size_t i = 1; i <= count; ++i) {
      int next_x = (i < count) ? static_cast<int>(x0 + static_cast<double>(i) * actual_dx) : current_pixel_x + 1;
      
      if (next_x == current_pixel_x && i < count) {
        int y = toPixelY(normalized[i]);
        if (y < pixel_min_y) pixel_min_y = y;
        if (y > pixel_max_y) pixel_max_y = y;
      } else {
        if (current_pixel_x >= 0 && current_pixel_x < static_cast<int>(m_width)) {
          // Connect gaps to previous column to ensure continuous waveform
          int draw_min = std::min(pixel_min_y, last_drawn_y);
          int draw_max = std::max(pixel_max_y, last_drawn_y);
          
          plotLineFast(m_grid.data(), static_cast<int>(m_width), 
                       current_pixel_x, draw_min, 
                       current_pixel_x, draw_max, r, g, b);
          
          // Next column's connection point is the end of this wave segment
          last_drawn_y = (std::abs(last_drawn_y - pixel_min_y) < std::abs(last_drawn_y - pixel_max_y)) ? pixel_max_y : pixel_min_y;
        }
        
        if (i < count) {
          current_pixel_x = next_x;
          pixel_min_y = toPixelY(normalized[i]);
          pixel_max_y = pixel_min_y;
        }
      }
    }
  } else {
    // Standard Bresenham rendering for zoomed-in traces
    for (size_t i = 1; i < count; ++i) {
      int cur_x = static_cast<int>(x0 + static_cast<double>(i) * actual_dx);
      int cur_y = toPixelY(normalized[i]);

      if (cur_x >= 0 && cur_x < static_cast<int>(m_width) && prev_x >= 0 && prev_x < static_cast<int>(m_width)) {
        plotLineFast(m_grid.data(), static_cast<int>(m_width), prev_x, prev_y, cur_x, cur_y, r, g, b);
      } else if ((prev_x < 0 && cur_x >= 0) || (prev_x < static_cast<int>(m_width) && cur_x >= static_cast<int>(m_width))) {
        // Interpolate Y at the boundaries to prevent vertical artifact lines
        float t1 = 0.0f;
        float t2 = 1.0f;
        
        if (prev_x < 0) {
          t1 = static_cast<float>(-prev_x) / static_cast<float>(cur_x - prev_x);
        } else if (prev_x >= static_cast<int>(m_width)) {
          t1 = static_cast<float>(m_width - 1 - prev_x) / static_cast<float>(cur_x - prev_x);
        }
        
        if (cur_x < 0) {
          t2 = static_cast<float>(-prev_x) / static_cast<float>(cur_x - prev_x);
        } else if (cur_x >= static_cast<int>(m_width)) {
          t2 = static_cast<float>(m_width - 1 - prev_x) / static_cast<float>(cur_x - prev_x);
        }
        
        if (t1 > t2) std::swap(t1, t2);
        
        int draw_x1 = prev_x + static_cast<int>(t1 * (cur_x - prev_x));
        int draw_y1 = prev_y + static_cast<int>(t1 * (cur_y - prev_y));
        int draw_x2 = prev_x + static_cast<int>(t2 * (cur_x - prev_x));
        int draw_y2 = prev_y + static_cast<int>(t2 * (cur_y - prev_y));
        
        draw_x1 = std::clamp(draw_x1, 0, static_cast<int>(m_width - 1));
        draw_x2 = std::clamp(draw_x2, 0, static_cast<int>(m_width - 1));
        
        plotLineFast(m_grid.data(), static_cast<int>(m_width), draw_x1, draw_y1, draw_x2, draw_y2, r, g, b);
      }

      prev_x = cur_x;
      prev_y = cur_y;
    }
  }
}

} // namespace Scoped
