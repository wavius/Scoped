#pragma once
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

namespace Scoped {

enum class WindowType {
  RECTANGULAR,
  HANN,
  HAMMING,
  BLACKMAN_HARRIS,
  FLAT_TOP
};

class Window {
private:
  size_t m_size = 0;
  WindowType m_type = WindowType::HANN;
  std::vector<float> m_function;

public:
  // Lifecycle
  Window(size_t size = 0, WindowType type = WindowType::HANN)
      : m_size(size), m_type(type) {
    if (m_size > 0) {
      generate();
    }
  }

  // Accessors
  size_t getSize() const { return m_size; }
  WindowType getType() const { return m_type; }
  const std::vector<float> &getFunction() const { return m_function; }
  std::string getTypeName() const {
    switch (m_type) {
    case WindowType::RECTANGULAR:
      return "Rectangular";
    case WindowType::HANN:
      return "Hann";
    case WindowType::HAMMING:
      return "Hamming";
    case WindowType::BLACKMAN_HARRIS:
      return "Blackman-Harris";
    case WindowType::FLAT_TOP:
      return "Flat Top";
    default:
      return "Unknown";
    }
  }

  // Setters 
  void setSize(size_t size) {
    if (m_size == size)
      return;
    m_size = size;
    generate();
  }

  void setType(WindowType type) {
    if (m_type == type)
      return;
    m_type = type;
    generate();
  }

  // Utilities
  void generate() {
    if (m_size == 0) {
      m_function.clear();
      return;
    }

    if (m_function.size() != m_size) {
      m_function.resize(m_size);
    }

    // Rectangular window is just all ones
    if (m_type == WindowType::RECTANGULAR) {
      std::fill(m_function.begin(), m_function.end(), 1.0f);
      return;
    }

    const float PI = 3.14159265358979323846f;
    for (size_t i = 0; i < m_size; ++i) {
      // Use (N-1) for symmetric windows
      float phase = (2.0f * PI * i) / (static_cast<float>(m_size) - 1.0f);

      switch (m_type) {
      case WindowType::HANN:
        m_function[i] = 0.5f * (1.0f - std::cos(phase));
        break;
      case WindowType::HAMMING:
        m_function[i] = 0.54f - 0.46f * std::cos(phase);
        break;
      case WindowType::BLACKMAN_HARRIS:
        m_function[i] = 0.35875f - 0.48829f * std::cos(phase) +
                        0.14128f * std::cos(2.0f * phase) -
                        0.01168f * std::cos(3.0f * phase);
        break;
      case WindowType::FLAT_TOP:
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
