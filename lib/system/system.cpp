#include "system.h"

namespace {
// DHT22 must not be read more often than every 2 s.
constexpr uint32_t kClimatePollIntervalMs = 2000;
constexpr uint32_t kGasPollIntervalMs = 500;
}

SystemController::SystemController() : voiceCommands_(microphone_) {}

void SystemController::begin() {
    Serial.begin(115200);
    Serial.println(F("[system] starting"));

    // Report which modules came up; unassigned hardware simply stays idle.
    Serial.printf("[system] display:    %s\n", display_.begin() ? "ok" : "not configured");
    Serial.printf("[system] speaker:    %s\n", speaker_.begin() ? "ok" : "not configured");
    Serial.printf("[system] relays:     %s\n", relays_.begin() ? "ok" : "not configured");
    Serial.printf("[system] dht22:      %s\n", dht22_.begin() ? "ok" : "not configured");
    Serial.printf("[system] pir:        %s\n", pir_.begin() ? "ok" : "not configured");
    Serial.printf("[system] mq2:        %s\n", mq2_.begin() ? "ok" : "not configured");
    Serial.printf("[system] microphone: %s\n", microphone_.begin() ? "ok" : "not configured");
    Serial.printf("[system] voice:      %s\n", voiceCommands_.begin() ? "ok" : "not configured");

    display_.showStatus("Ready");
    display_.setStatusLed(true);
}

void SystemController::update() {
    const uint32_t nowMs = millis();

    pollSensors(nowMs);
    checkSafety();
    pollVoice();
}

void SystemController::pollVoice() {
    VoiceCommand command;
    if (voiceCommands_.poll(command)) {
        handleCommand(command);
    }
}

void SystemController::pollSensors(uint32_t nowMs) {
    if (nowMs - lastClimatePollMs_ >= kClimatePollIntervalMs) {
        lastClimatePollMs_ = nowMs;
        lastClimate_ = dht22_.read();
        if (lastClimate_.valid) {
            display_.showClimate(lastClimate_.temperatureC, lastClimate_.humidityPercent);
        }
    }

    if (nowMs - lastGasPollMs_ >= kGasPollIntervalMs) {
        lastGasPollMs_ = nowMs;
        lastGas_ = mq2_.read();
    }

    motion_ = pir_.motionDetected();
    // TODO: decide motion-triggered behaviour (e.g. lighting, presence).
}

void SystemController::checkSafety() {
    const bool gasHazard = lastGas_.valid && lastGas_.alarm;

    if (gasHazard && !gasAlertActive_) {
        gasAlertActive_ = true;
        speaker_.startAlarm();
        display_.showAlert("Gas detected");
        Serial.println(F("[safety] gas alarm raised"));
        // TODO: define which appliances (if any) to cut on a gas alarm.
    } else if (!gasHazard && gasAlertActive_) {
        gasAlertActive_ = false;
        speaker_.stopAlarm();
        display_.showStatus("Gas cleared");
        Serial.println(F("[safety] gas alarm cleared"));
    }
}

void SystemController::handleCommand(const VoiceCommand& command) {
    bool ok = true;

    switch (command.type) {
        case VoiceCommandType::RelayOn:
            ok = relays_.set(command.relayChannel, true);
            break;
        case VoiceCommandType::RelayOff:
            ok = relays_.set(command.relayChannel, false);
            break;
        case VoiceCommandType::AllRelaysOff:
            relays_.allOff();
            break;
        case VoiceCommandType::ReportStatus:
            // TODO: announce status through the speaker / display.
            break;
        case VoiceCommandType::None:
            return;
    }

    speaker_.playCue(ok ? AudioCue::Acknowledge : AudioCue::Error);
}
