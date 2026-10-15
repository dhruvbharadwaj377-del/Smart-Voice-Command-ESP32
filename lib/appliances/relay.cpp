#include "relay.h"

namespace {
const int kRelayPins[RelayBank::kChannelCount] = {
    pins::kRelay1, pins::kRelay2, pins::kRelay3,
    pins::kRelay4, pins::kRelay5, pins::kRelay6,
};
}

bool RelayBank::begin() {
    ready_ = pins::kRelayActiveLevel != pins::RelayActiveLevel::Unknown;

    // TODO: once polarity and pins are confirmed, write the OFF level to each
    // assigned pin *before* switching it to OUTPUT to avoid a startup glitch.
    for (uint8_t i = 0; i < kChannelCount; ++i) {
        state_[i] = false;
    }
    return ready_;
}

bool RelayBank::set(uint8_t channel, bool on) {
    if (!canDrive(channel)) {
        return false;
    }

    // TODO: map `on` to the physical level using pins::kRelayActiveLevel
    // and write it to kRelayPins[channel].
    state_[channel] = on;
    return true;
}

bool RelayBank::isOn(uint8_t channel) const {
    return channel < kChannelCount && state_[channel];
}

void RelayBank::allOff() {
    for (uint8_t i = 0; i < kChannelCount; ++i) {
        set(i, false);
    }
}

bool RelayBank::canDrive(uint8_t channel) const {
    return ready_ && channel < kChannelCount && pins::isAssigned(kRelayPins[channel]);
}
