#pragma once

// Speaker: audible output — the MAX98357A I2S amplifier for voice/audio
// feedback and the buzzer for simple alarm tones.

#include <Arduino.h>

enum class AudioCue : uint8_t {
    Acknowledge,  // Command understood.
    Error,        // Command not understood / failed.
};

class Speaker {
public:
    bool begin();

    void playCue(AudioCue cue);

    // Buzzer alarm; stays on until stopAlarm() is called.
    void startAlarm();
    void stopAlarm();
    bool isAlarmActive() const { return alarmActive_; }

private:
    bool ampReady_ = false;
    bool buzzerReady_ = false;
    bool alarmActive_ = false;
};
