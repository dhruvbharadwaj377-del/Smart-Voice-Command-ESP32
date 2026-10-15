#pragma once

// Microphone: captures raw audio samples from the INMP441 I2S microphone.
// Owns the I2S input peripheral; knows nothing about what the audio means.

#include <Arduino.h>

class Microphone {
public:
    // Configures the I2S input. Returns false if pins are unassigned or
    // the peripheral could not be started.
    bool begin();

    // Reads up to maxSamples PCM samples into buffer. Returns the number of
    // samples actually read (0 if not ready).
    size_t readSamples(int16_t* buffer, size_t maxSamples);

    bool isReady() const { return ready_; }

private:
    bool ready_ = false;
};
