#pragma once

// Mq2: reads gas / smoke level from an MQ-2 sensor.
// Alarm thresholds require calibration and are not defined yet.

#include <Arduino.h>

struct GasReading {
    bool valid = false;
    uint16_t raw = 0;       // Raw ADC value.
    bool alarm = false;     // True when gas level exceeds the alarm threshold.
};

class Mq2 {
public:
    bool begin();

    GasReading read();

private:
    bool ready_ = false;
};
