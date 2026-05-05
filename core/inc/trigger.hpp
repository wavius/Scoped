#pragma once

#include <circularbuffer.hpp>
#include <cstdint>
#include <vector>

namespace Scoped {

/**
 * @brief Represents the edge direction to trigger on.
 */
enum class TriggerType { RISING_EDGE, FALLING_EDGE };

/**
 * @brief Represents the triggering strategy.
 *        AUTO: Captures a frame even if no edge is found after a timeout.
 *        NORMAL: Only captures a frame when a valid edge is detected.
 */
enum class TriggerMode { AUTO, NORMAL };

/**
 * @brief Scans a CircularBuffer for edge-triggered events and extracts
 *        fixed-width waveform frames.
 */
class Trigger {
private:
  uint8_t m_threshold;
  TriggerType m_type;
  TriggerMode m_mode;
  uint8_t m_prev_sample;
  size_t m_frame_width;
  std::vector<uint8_t> m_output;

  uint32_t m_last_trigger_time;
  static constexpr uint32_t AUTO_TIMEOUT_MS = 100;

  static constexpr uint8_t HYSTERESIS_MARGIN = 2;

  bool checkEdge(uint8_t current) const;
  void extractFrame(CircularBuffer &buffer, size_t trigger_offset);

public:
  /**
   * @brief Constructs a trigger with a given frame width and threshold.
   * @param width Number of samples per triggered frame.
   * @param level Threshold level (0–255).
   */
  explicit Trigger(size_t width = 1024, uint8_t level = 128);

  void setThreshold(uint8_t level);
  void setType(TriggerType type);
  void setMode(TriggerMode mode);
  void clear();

  /**
   * @brief Scans the buffer for a trigger event and extracts a frame.
   * @param buffer The circular buffer to scan.
   * @return True if a complete triggered frame was extracted.
   */
  bool processStream(CircularBuffer &buffer);

  /**
   * @brief Returns the most recently extracted frame data.
   * @return Constant reference to the output sample vector.
   */
  const std::vector<uint8_t> &getOutput() const;

  /**
   * @brief Returns the number of samples per triggered frame.
   * @return The frame width.
   */
  size_t getFrameWidth() const;

  /**
   * @brief Returns the trigger threshold.
   * @return The trigger threshold.
   */
  uint8_t getThreshold() const;
};

} // namespace Scoped
