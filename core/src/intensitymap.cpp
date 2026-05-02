#include "intensitymap.hpp"
#include <algorithm>
#include <cstdint>
#include <sys/types.h>

namespace Scoped {

// Constructor that pre-allocates memory for the intensity map
IntensityMap::IntensityMap(size_t initial_width, size_t initial_height)
    : width(initial_width), height(initial_height),
      map(initial_width * initial_height, 0) {}

// Destructor
IntensityMap::~IntensityMap() {};

// Get a pointer to the intensity map
const uint8_t *IntensityMap::getMap() const { return map.data(); }

// Get width of intensity map
size_t IntensityMap::getWidth() const { return width; }

// Get height of intensity map
size_t IntensityMap::getHeight() const { return height; }

// Clear intensity map
void IntensityMap::clear() { std::fill(map.begin(), map.end(), 0); }

// Add a sample to the intensity map
void IntensityMap::addSample(uint32_t x, uint32_t y) {
  if (x < width && y < height) {
    map[static_cast<size_t>(y) * width + x]++;
  }
}

} // namespace Scoped
