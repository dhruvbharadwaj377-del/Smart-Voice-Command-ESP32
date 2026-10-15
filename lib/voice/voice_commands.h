#pragma once

// VoiceCommands: turns microphone audio into high-level commands.
// Speech recognition is NOT implemented yet; poll() currently never
// produces a command. The rest of the system only depends on VoiceCommand,
// so the recognition engine can be swapped in later without touching it.

#include <Arduino.h>

#include "microphone.h"

enum class VoiceCommandType : uint8_t {
    None,
    RelayOn,
    RelayOff,
    AllRelaysOff,
    ReportStatus,
};

struct VoiceCommand {
    VoiceCommandType type = VoiceCommandType::None;
    uint8_t relayChannel = 0;  // Zero-based; used by RelayOn / RelayOff only.
};

class VoiceCommands {
public:
    explicit VoiceCommands(Microphone& microphone) : microphone_(microphone) {}

    bool begin();

    // Processes pending audio and fills `command` if one was recognised.
    // Returns true when a new command is available.
    bool poll(VoiceCommand& command);

private:
    Microphone& microphone_;
    bool ready_ = false;
};
