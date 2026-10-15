#include "pir.h"

#include "pins.h"

bool Pir::begin() {
    ready_ = pins::isAssigned(pins::kPirOutput);
    // TODO: configure the input pin (pull mode depends on the PIR module).
    return ready_;
}

bool Pir::motionDetected() const {
    if (!ready_) {
        return false;
    }

    // TODO: read the PIR output.
    return false;
}
