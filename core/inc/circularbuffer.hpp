#pragma once

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace Scoped {

class CircularBuffer {
private:
  std::vector<uint8_t> m_buffer;
  size_t m_capacity;
  std::atomic<size_t> m_read_idx{0};
  std::atomic<size_t> m_write_idx{0};

public:
  /**
   * @brief Initializes the buffer memory.
   * @param capacity Maximum number of samples the buffer can hold.
   */
  explicit CircularBuffer(size_t capacity = 8192);

  /**
   * @brief Writes a single byte and advances the write pointer.
   * @param sample The 8-bit data point from hardware.
   */
  void pushSample(uint8_t sample);

  /**
   * @brief Writes a contiguous array of bytes, handling wrap-around.
   * @param data Pointer to the incoming data array.
   * @param length Number of bytes to write.
   */
  void pushBlock(const uint8_t *data, size_t length);

  /**
   * @brief Calculates how many unread samples are available.
   * @return The count of unread samples.
   */
  size_t getUnreadCount() const;

  /**
   * @brief Reads a sample relative to the read head without consuming it.
   * @param offset Index ahead of the read pointer to look.
   * @return The 8-bit sample at the calculated wrap-around index.
   */
  uint8_t peekAhead(size_t offset) const;

  /**
   * @brief Marks data as consumed by moving the read head forward.
   * @param amount The number of samples to advance past.
   */
  void advanceReadIdx(size_t amount);

  /**
   * @brief Populates the buffer with a full-swing (0–255) square wave.
   */
  void fillTestSquareWave();

  /**
   * @brief Pushes a chunk of continuous sine wave samples into the buffer.
   */
  void fillTestSineWave();

  /**
   * @brief Returns a pointer to the underlying raw array.
   * @return Constant pointer to the raw data.
   */
  const uint8_t *getRawData() const { return m_buffer.data(); }

  /**
   * @brief Returns the total capacity of the buffer.
   * @return Maximum number of samples the buffer can hold.
   */
  size_t getCapacity() const { return m_capacity; }

  /**
   * @brief Returns the current read index.
   * @return The read index value.
   */
  size_t getReadIdx() const { return m_read_idx.load(); }

  /**
   * @brief Resets read and write indices to zero, effectively clearing the buffer.
   */
  void clear() {
    m_read_idx.store(0);
    m_write_idx.store(0);
  }
};

} // namespace Scoped
