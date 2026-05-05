#pragma once

#include <cstdint>
#include <vector>

namespace Scoped {

/**
 * @brief A fixed-size container for a single triggered waveform frame.
 *
 * Holds raw 8-bit samples captured from hardware. Serves as the
 * intermediate data container between the Trigger and the IntensityMap.
 */
class DisplayFrame {
private:
  std::vector<uint8_t> m_samples;

public:
  /**
   * @brief Constructs a frame with the given capacity, zero-filled.
   * @param size Number of samples to allocate.
   */
  explicit DisplayFrame(size_t size);

  /**
   * @brief Returns a pointer to the raw sample data.
   * @return Constant pointer to the sample array.
   */
  const uint8_t *getSamples() const;

  /**
   * @brief Returns the number of samples in the frame.
   * @return Sample count.
   */
  size_t getSize() const;

  /**
   * @brief Replaces the frame contents with data from a vector.
   * @param data Source vector to copy from.
   */
  void copyFrom(const std::vector<uint8_t> &data);
};

} // namespace Scoped
