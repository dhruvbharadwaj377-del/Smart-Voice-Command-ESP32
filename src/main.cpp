// Entry point. All behaviour lives in SystemController; main.cpp only owns
// the single controller instance and forwards the Arduino lifecycle to it.

#include <Arduino.h>

#include "system.h"

namespace {
SystemController controller;
}

void setup() {
    controller.begin();
}

void loop() {
    controller.update();
}
