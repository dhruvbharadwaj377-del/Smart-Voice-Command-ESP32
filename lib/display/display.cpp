#include "display.h"

#include "pins.h"

bool Display::begin() {
    // TODO: initialise the display driver once the model and bus are known.
    screenReady_ = false;

    ledReady_ = pins::isAssigned(pins::kStatusLed);
    // TODO: configure the status LED pin.

    return screenReady_;
}

void Display::clear() {
    if (!screenReady_) {
        return;
    }
    // TODO: clear the screen.
}

void Display::showStatus(const char* message) {
    if (!screenReady_ || message == nullptr) {
        return;
    }
    // TODO: render status text.
}

void Display::showClimate(float temperatureC, float humidityPercent) {
    (void)temperatureC;
    (void)humidityPercent;
    if (!screenReady_) {
        return;
    }
    // TODO: render temperature / humidity.
}

void Display::showAlert(const char* message) {
    if (!screenReady_ || message == nullptr) {
        return;
    }
    // TODO: render a prominent alert.
}

void Display::setStatusLed(bool on) {
    (void)on;
    if (!ledReady_) {
        return;
    }
    // TODO: drive the status LED.
}
