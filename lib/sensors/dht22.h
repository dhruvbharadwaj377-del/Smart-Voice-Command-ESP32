#pragma once

// Dht22: reads temperature and relative humidity from a DHT22 sensor.

#include <Arduino.h>

struct ClimateReading {
    bool valid = false;
    float temperatureC = 0.0f;
    float humidityPercent = 0.0f;
};

class Dht22 {
public:
    bool begin();

    // Performs a measurement. The DHT22 needs >= 2 s between reads; callers
    // are responsible for pacing.
    ClimateReading read();

private:
    bool ready_ = false;
};
