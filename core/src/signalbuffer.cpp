#include "signalbuffer.hpp"

namespace Scoped {

// Constructor that pre-allocates memory for the signal data buffer
SignalBuffer::SignalBuffer(size_t initial_size)
    : buffer_size(initial_size), buffer(initial_size) {}

// Destructor
SignalBuffer::~SignalBuffer() {}

// Get a pointer to the signal data buffer
const uint8_t *SignalBuffer::getBuffer() const { return buffer.data(); }

// Get the size of the signal data buffer
size_t SignalBuffer::getSize() const { return buffer_size; }

// Get the number of valid samples in the buffer
size_t SignalBuffer::getValidSamples() const { return valid_samples; }

// Initialize the buffer with a square wave
void SignalBuffer::createTestBufferSquare() {
  for (int i = 0; i < buffer_size; i++) {
    buffer[i] = i % 2;
  }
}

} // namespace Scoped
