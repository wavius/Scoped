#include "signalbuffer.h"

namespace Scoped {

    // Constructor that pre-allocates memory for the signal data buffer
    SignalBuffer::SignalBuffer(size_t initial_size) 
            : buffer_size(initial_size) {
        buffer.reserve(buffer_size);
    }

    // Destructor
    SignalBuffer::~SignalBuffer() {
    }

    // Get a pointer to the signal data buffer
    uint8_t* SignalBuffer::getBuffer() {
        return buffer.data();
    }
}
