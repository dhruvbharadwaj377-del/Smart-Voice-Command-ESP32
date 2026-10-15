#pragma once

// SystemController: the central coordinator. Owns every module and wires
// them together — voice commands drive relays, sensors feed the display,
// and hazardous readings raise safety alerts. Contains no hardware access
// of its own; all GPIO / peripheral work stays inside the modules.

#include <Arduino.h>

#include "display.h"
#include "dht22.h"
#include "microphone.h"
#include "mq2.h"
#include "pir.h"
#include "relay.h"
#include "speaker.h"
#include "voice_commands.h"

class SystemController {
public:
    SystemController();

    void begin();
    void update();  // Non-blocking; call from loop().

private:
    void pollVoice();
    void pollSensors(uint32_t nowMs);
    void checkSafety();
    void handleCommand(const VoiceCommand& command);

    Microphone microphone_;
    VoiceCommands voiceCommands_;
    Dht22 dht22_;
    Pir pir_;
    Mq2 mq2_;
    RelayBank relays_;
    Display display_;
    Speaker speaker_;

    ClimateReading lastClimate_;
    GasReading lastGas_;
    bool motion_ = false;
    bool gasAlertActive_ = false;

    uint32_t lastClimatePollMs_ = 0;
    uint32_t lastGasPollMs_ = 0;
};
