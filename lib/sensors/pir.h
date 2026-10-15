#pragma once

// Pir: reports motion from a PIR sensor's digital output.

#include <Arduino.h>

class Pir {
public:
    bool begin();

    bool motionDetected() const;

private:
    bool ready_ = false;
};
