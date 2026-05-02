#pragma once

#include <cstdint>
#include <vector>

namespace Scoped {

class SignalBuffer {
private:
  std::vector<uint8_t> buffer;
  size_t buffer_size;   // Size of the buffer
  size_t valid_samples; // Number of valid samples in the buffer

public:
  /**
   * @brief Constructor that pre-allocates memory for the signal data buffer.
   * @param initial_size The number of 8-bit samples to reserve.
   */
  SignalBuffer(size_t initial_size);

  /**
   * @brief Destructor.
   */
  ~SignalBuffer();

  /**
   * @brief Get a pointer to the signal data buffer.
   * @return A pointer to the signal data buffer.
   */
  const uint8_t *getBuffer() const;

  /**
   * @brief Get the size of the signal data buffer.
   * @return Size of the signal data buffer.
   */
  size_t getSize() const;

  /**
   * @brief Get the number of valid samples in the buffer.
   * @return Number of valid samples in the buffer.
   */
  size_t getValidSamples() const;

  /**
   * @brief Initialize the buffer with a square wave.
   * @param
   */
  void createTestBufferSquare();
};
} // namespace Scoped
