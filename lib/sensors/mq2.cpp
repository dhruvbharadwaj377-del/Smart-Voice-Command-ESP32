#include "mq2.h"

#include "pins.h"

bool Mq2::begin() {
    ready_ = pins::isAssigned(pins::kMq2Analog) || pins::isAssigned(pins::kMq2Digital);
    // TODO: configure ADC attenuation / digital input once wiring is known.
    return ready_;
}

GasReading Mq2::read() {
    GasReading reading;

    if (!ready_) {
        return reading;
    }

    // TODO: sample the sensor and evaluate against a calibrated threshold.
    return reading;
}
