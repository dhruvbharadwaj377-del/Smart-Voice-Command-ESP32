#include "speaker.h"

#include "pins.h"

bool Speaker::begin() {
    ampReady_ = pins::isAssigned(pins::kAmpI2sBclk) &&
                pins::isAssigned(pins::kAmpI2sLrc) &&
                pins::isAssigned(pins::kAmpI2sDin);
    // TODO: configure I2S TX for the amplifier.

    buzzerReady_ = pins::isAssigned(pins::kBuzzer);
    // TODO: configure the buzzer pin.

    return ampReady_ || buzzerReady_;
}

void Speaker::playCue(AudioCue cue) {
    (void)cue;
    if (!ampReady_) {
        return;
    }
    // TODO: stream the audio for `cue` to the amplifier.
}

void Speaker::startAlarm() {
    alarmActive_ = true;
    if (!buzzerReady_) {
        return;
    }
    // TODO: start the buzzer tone.
}

void Speaker::stopAlarm() {
    alarmActive_ = false;
    if (!buzzerReady_) {
        return;
    }
    // TODO: stop the buzzer tone.
}
