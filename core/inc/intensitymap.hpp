#pragma once

#include <cstdint>
#include <vector>

namespace Scoped {

class IntensityMap {
private:
  std::vector<uint32_t> map;
  size_t width;
  size_t height;

public:
  /**
   * @brief Constructor that pre-allocates memory for the intensity map.
   * @param height The height of the intensity map.
   * @param width The width of the intensity map.
   */
  IntensityMap(size_t initial_width, size_t initial_height);

  /**
   * @brief Destructor.
   */
  ~IntensityMap();

  /**
   * @brief Get a pointer to the intensity map.
   * @return Pointer to the intensity map.
   */
  const uint8_t *getMap() const;

  /**
   * @brief Get the width of the intensity map.
   * @return Width of intensity map;
   */
  size_t getWidth() const;

  /**
   * @brief Get the height of the intensity map.
   * @return Height of intensity map.
   */
  size_t getHeight() const;

  /**
   * @brief Clear intensity map.
   */
  void clear();

  /**
   * @brief Add a sample to the intensity map.
   * @param x
   * @param y
   */
  void addSample(uint32_t x, uint32_t y);
};

} // namespace Scoped
