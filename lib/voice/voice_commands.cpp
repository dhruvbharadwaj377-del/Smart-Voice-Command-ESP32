#include "voice_commands.h"

bool VoiceCommands::begin() {
    // TODO: initialise the speech-recognition engine once it is chosen.
    ready_ = microphone_.isReady();
    return ready_;
}

bool VoiceCommands::poll(VoiceCommand& command) {
    command = VoiceCommand{};

    if (!ready_) {
        return false;
    }

    // TODO: pull audio from microphone_ and run recognition.
    return false;
}
