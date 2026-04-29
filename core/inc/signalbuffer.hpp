#pragma once

#include <cstdint>
#include <vector>

namespace Scoped {

    class SignalBuffer {
        private:
            size_t buffer_size;
            std::vector<uint8_t> buffer;
            
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
            uint8_t* getBuffer();

    };
}