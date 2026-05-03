#include <cmath>
#include <signalbuffer.hpp>

namespace Scoped {

// Constructor that pre-allocates memory for the signal data buffer
SignalBuffer::SignalBuffer(size_t initial_size)
    : buffer_size(initial_size), samples(initial_size) {}

// Destructor
SignalBuffer::~SignalBuffer() {}

// Get a pointer to the signal data buffer
const uint8_t *SignalBuffer::getSamples() const { return samples.data(); }

// Get the size of the signal data buffer
size_t SignalBuffer::getSize() const { return buffer_size; }

// Get the number of valid samples in the buffer
size_t SignalBuffer::getValidSamples() const { return valid_samples; }

// Initialize the buffer with a square wave
void SignalBuffer::createTestBufferSquare() {
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
void SignalBuffer::createTestBufferSine() {

  // Frequency control: how ma// IWYU pragma: keepny cycles fit in the 1024
  // buffer
  float cycles = 5.0f;

  for (size_t i = 0; i < buffer_size; ++i) {
    // Calculate the angle based on the current sample index
    float angle = (2.0f * M_PI * cycles * i) / buffer_size;

    // Offset and scale the sine wave to fit 0-255 (uint8_t)
    float sineValue = std::sin(angle);
    samples[i] = static_cast<uint8_t>((sineValue * 127.5f) + 127.5f);
  }
}

} // namespace Scoped
