#include <cmath>
#include <displayframe.hpp>

namespace Scoped {

// Constructor that pre-allocates memory for the signal data buffer
DisplayFrame::DisplayFrame(size_t initial_size)
    : buffer_size(initial_size), samples(initial_size) {}

// Destructor
DisplayFrame::~DisplayFrame() {}

// Get a pointer to the signal data buffer
const uint8_t *DisplayFrame::getSamples() const { return samples.data(); }

// Get the size of the signal data buffer
size_t DisplayFrame::getSize() const { return buffer_size; }

// Get the number of valid samples in the buffer
size_t DisplayFrame::getValidSamples() const { return valid_samples; }

// ------------------------------
// TEST FUNCTIONS
// ------------------------------

// Initialize the buffer with a square wave
void DisplayFrame::createTestBufferSquare() {
  for (size_t i = 0; i < buffer_size; i++) {
    if ((i % 8) < 4) {
      samples[i] = 255;
    } else {
      samples[i] = 0;
    }
  }
  valid_samples = buffer_size;
}

// Initialize the buffer with a sine wave
void DisplayFrame::createTestBufferSine() {
  static float current_phase = 0.0f;
  const float frequency = 5.23f;

  for (size_t i = 0; i < buffer_size; ++i) {
    float angle = current_phase + (2.0f * M_PI * frequency * i) / buffer_size;

    float sineValue = std::sin(angle);
    samples[i] = static_cast<uint8_t>((sineValue * 127.5f) + 127.5f);
  }

  current_phase += 0.5f;

  if (current_phase > 2.0f * M_PI) {
    current_phase -= 2.0f * M_PI;
  }

  valid_samples = buffer_size;
}

} // namespace Scoped
