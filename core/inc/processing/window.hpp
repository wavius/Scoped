#pragma once
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

namespace Scoped {

/**
 * @brief Enum class for supported window function types.
 */
enum class WindowType {
  Rectangular,
  Hann,
  Hamming,
  BlackmanHarris,
  FlatTop
};

/**
 * @brief Represents a window function object that manages its own coefficients.
 * Automatically regenerates the coefficients whenever the type or size changes.
 */
class Window {
private:
  size_t m_size = 0;
  WindowType m_type = WindowType::Hann;
  std::vector<float> m_function;

public:
  /**
   * @brief Constructor for a Window object.
   * @param size Initial number of samples.
   * @param type Initial window type.
   */
  Window(size_t size = 0, WindowType type = WindowType::Hann)
      : m_size(size), m_type(type) {
    if (m_size > 0) {
      generate();
    }
  }

  // --- Getters ---
  size_t getSize() const { return m_size; }
  WindowType getType() const { return m_type; }
  const std::vector<float> &getFunction() const { return m_function; }

  /**
   * @brief Returns the human-readable name of the current window type.
   */
  std::string getTypeName() const {
    switch (m_type) {
    case WindowType::Rectangular:
      return "Rectangular";
    case WindowType::Hann:
      return "Hann";
    case WindowType::Hamming:
      return "Hamming";
    case WindowType::BlackmanHarris:
      return "Blackman-Harris";
    case WindowType::FlatTop:
      return "Flat Top";
    default:
      return "Unknown";
    }
  }

  // --- Setters ---
  /**
   * @brief Updates the window size and regenerates the coefficients.
   */
  void setSize(size_t size) {
    if (m_size == size)
      return;
    m_size = size;
    generate();
  }

  /**
   * @brief Updates the window type and regenerates the coefficients.
   */
  void setType(WindowType type) {
    if (m_type == type)
      return;
    m_type = type;
    generate();
  }

  /**
   * @brief Regenerates the window coefficients based on current members.
   */
  void generate() {
    if (m_size == 0) {
      m_function.clear();
      return;
    }

    if (m_function.size() != m_size) {
      m_function.resize(m_size);
    }

    // Rectangular window is just all ones
    if (m_type == WindowType::Rectangular) {
      std::fill(m_function.begin(), m_function.end(), 1.0f);
      return;
    }

    const float PI = 3.14159265358979323846f;
    for (size_t i = 0; i < m_size; ++i) {
      // Use (N-1) for symmetric windows
      float phase = (2.0f * PI * i) / (static_cast<float>(m_size) - 1.0f);

      switch (m_type) {
      case WindowType::Hann:
        m_function[i] = 0.5f * (1.0f - std::cos(phase));
        break;
      case WindowType::Hamming:
        m_function[i] = 0.54f - 0.46f * std::cos(phase);
        break;
      case WindowType::BlackmanHarris:
        m_function[i] = 0.35875f - 0.48829f * std::cos(phase) +
                        0.14128f * std::cos(2.0f * phase) -
                        0.01168f * std::cos(3.0f * phase);
        break;
      case WindowType::FlatTop:
        m_function[i] = 0.21557895f - 0.41663158f * std::cos(phase) +
                        0.277263158f * std::cos(2.0f * phase) -
                        0.083578947f * std::cos(3.0f * phase) +
                        0.006947368f * std::cos(4.0f * phase);
        break;
      default:
        std::fill(m_function.begin(), m_function.end(), 1.0f);
        break;
      }
    }
  }
};

} // namespace Scoped
