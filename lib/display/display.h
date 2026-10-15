#pragma once

// Display: user-facing visual output — the screen and the status LED.
// The display model/driver is not chosen yet, so this exposes only a
// model-agnostic interface; the driver will be plugged in behind it.

#include <Arduino.h>

class Display {
public:
    bool begin();

    void clear();
    void showStatus(const char* message);
    void showClimate(float temperatureC, float humidityPercent);
    void showAlert(const char* message);

    void setStatusLed(bool on);

private:
    bool screenReady_ = false;
    bool ledReady_ = false;
};
