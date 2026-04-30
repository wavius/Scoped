#include "signalbuffer.hpp"

namespace Scoped {

// Constructor that pre-allocates memory for the signal data buffer
SignalBuffer::SignalBuffer(size_t initial_size)
    : buffer_size(initial_size), buffer(initial_size) {}

// Destructor
SignalBuffer::~SignalBuffer() {}

// Get a pointer to the signal data buffer
uint8_t *SignalBuffer::getBuffer() { return buffer.data(); }

// Initialize the buffer with a square wave
void SignalBuffer::createTestBufferSquare() {
  for (int i = 0; i < buffer_size; i++) {
    buffer[i] = i % 2;
  }
}

} // namespace Scoped
