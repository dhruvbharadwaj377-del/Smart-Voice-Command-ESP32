#pragma once

// RelayBank: switches the 6-channel relay module that drives appliances.
// Tracks the logical on/off state of each channel. Physical drive polarity
// comes from pins::kRelayActiveLevel; while it is Unknown (or a channel's
// pin is unassigned) no GPIO is ever driven.

#include <Arduino.h>

#include "pins.h"

class RelayBank {
public:
    static constexpr uint8_t kChannelCount = pins::kRelayChannelCount;

    bool begin();

    // Returns false if the channel is out of range or cannot be driven.
    bool set(uint8_t channel, bool on);
    bool isOn(uint8_t channel) const;
    void allOff();

private:
    bool canDrive(uint8_t channel) const;

    bool state_[kChannelCount] = {};
    bool ready_ = false;
};
