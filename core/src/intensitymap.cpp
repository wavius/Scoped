#include <algorithm>
#include <cstdint>
#include <intensitymap.hpp>
#include <sys/types.h>

namespace Scoped {

// Constructor that pre-allocates memory for the intensity map
IntensityMap::IntensityMap(size_t initial_width, size_t initial_height)
    : width(initial_width), height(initial_height),
      grid(initial_width * initial_height, 0) {}

// Destructor
IntensityMap::~IntensityMap() {};

// Get a pointer to the intensity map
const uint32_t *IntensityMap::getMap() const { return grid.data(); }

// Get width of intensity map
size_t IntensityMap::getWidth() const { return width; }

// Get height of intensity map
size_t IntensityMap::getHeight() const { return height; }

// Clear intensity map
void IntensityMap::clear() { std::fill(grid.begin(), grid.end(), 0); }

// Add a sample to the intensity map
/*
void IntensityMap::addSample(uint32_t x, uint32_t y) {
  if (x < width && y < height) {
    grid[static_cast<size_t>(y) * width + x]++;
  }
}
*/

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
void IntensityMap::processBuffer(const SignalBuffer &buffer) {
  const uint8_t *samples = buffer.getSamples();
  const size_t length = buffer.getValidSamples();
  if (length == 0)
    return;

  // Cache constants
  const uint32_t h_m_1 = static_cast<uint32_t>(height - 1);
  const size_t w = width;
  uint32_t *const data = grid.data();
  const size_t end_x = std::min(length, w);

  // Calculate the first sample
  uint32_t prevY = (static_cast<uint32_t>(samples[0]) * h_m_1) >> 8;

  // Prime the very first column (x = 0) so it doesn't stay blank
  data[prevY * w]++;

  // Start loop at x = 1
  for (size_t x = 1; x < end_x; ++x) {
    const uint32_t currY = (static_cast<uint32_t>(samples[x]) * h_m_1) >> 8;

    // Base pointer for the current X column
    uint32_t *const col_ptr = &data[x];

    // Branchless min/max for the vertical span
    const uint32_t startY = (prevY < currY) ? prevY : currY;
    const uint32_t endY = (prevY > currY) ? prevY : currY;

    // Draw the vertical line connecting the previous Y to the current Y
    for (uint32_t y = startY; y <= endY; ++y) {
      col_ptr[y * w]++;
    }

    // Shift pipeline
    prevY = currY;
  }
}

} // namespace Scoped
