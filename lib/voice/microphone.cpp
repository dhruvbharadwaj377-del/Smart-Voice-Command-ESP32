#include "microphone.h"

#include "pins.h"

bool Microphone::begin() {
    ready_ = false;

    if (!pins::isAssigned(pins::kMicI2sSck) ||
        !pins::isAssigned(pins::kMicI2sWs) ||
        !pins::isAssigned(pins::kMicI2sSd)) {
        return false;
    }

    // TODO: configure I2S RX (sample rate, bit depth, channel format) once
    // the voice-recognition implementation defines its audio requirements.
    return ready_;
}

size_t Microphone::readSamples(int16_t* buffer, size_t maxSamples) {
    if (!ready_ || buffer == nullptr || maxSamples == 0) {
        return 0;
    }

    // TODO: read from the I2S RX DMA buffer.
    return 0;
}
