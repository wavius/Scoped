#pragma once

#include <cstdint>
#include <vector>

namespace Scoped {

/**
 * @brief Manages a collection of 8-bit signal samples captured from hardware.
 *
 * This class serves as the final data container for raw waveforms before
 * they are processed into the IntensityMap for visualization.
 */
class DisplayFrame {
private:
  std::vector<uint8_t> samples;
  size_t buffer_size;
  size_t valid_samples;

public:
  /**
   * @brief Constructor that pre-allocates memory for the sample buffer.
   * @param initial_size The total number of 8-bit samples to reserve.
   */
  DisplayFrame(size_t initial_size);

  /**
   * @brief Destructor.
   */
  ~DisplayFrame();

  /**
   * @brief Get a pointer to the raw sample data.
   * @return A pointer to the uint8_t array.
   */
  const uint8_t *getSamples() const;

  /**
   * @brief Get the total allocated size of the buffer.
   * @return Total capacity in samples.
   */
  size_t getSize() const;

  /**
   * @brief Get the number of samples actually populated with data.
   * @return Number of valid samples available for processing.
   */
  size_t getValidSamples() const;

  /**
   * @brief Populates the buffer with a full-swing (0-255) square wave.
   */
  void createTestBufferSquare();

  /**
   * @brief Populates the buffer with a full-swing (0-255) sine wave.
   */
  void createTestBufferSine();
};

} // namespace Scoped
