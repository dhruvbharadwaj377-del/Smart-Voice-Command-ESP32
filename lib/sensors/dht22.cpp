#include "dht22.h"

#include "pins.h"

bool Dht22::begin() {
    ready_ = pins::isAssigned(pins::kDht22Data);
    // TODO: configure the data line / sensor driver.
    return ready_;
}

ClimateReading Dht22::read() {
    ClimateReading reading;

    if (!ready_) {
        return reading;
    }

    // TODO: perform the DHT22 single-wire transaction and fill `reading`.
    return reading;
}
