#pragma once

// Central hardware configuration: GPIO assignments and board-level options.
//
// NO GPIO NUMBERS HAVE BEEN ASSIGNED YET. Every pin is set to
// pins::kUnassigned; modules check pins::isAssigned() and skip hardware
// access until a real pin is provided here. This is the only file that
// should need editing once the wiring is confirmed.

#include <stdint.h>

namespace pins {

// Sentinel for a GPIO that has not been assigned yet.
constexpr int kUnassigned = -1;

constexpr bool isAssigned(int pin) { return pin != kUnassigned; }

// --- DHT22 temperature / humidity sensor -----------------------------------
constexpr int kDht22Data = kUnassigned;

// --- PIR motion sensor -----------------------------------------------------
constexpr int kPirOutput = kUnassigned;

// --- MQ-2 gas / smoke sensor -----------------------------------------------
constexpr int kMq2Analog  = kUnassigned;  // Analog output (AO), ADC-capable pin
constexpr int kMq2Digital = kUnassigned;  // Digital threshold output (DO), optional

// --- Relay module (6 channels) ---------------------------------------------
constexpr uint8_t kRelayChannelCount = 6;

constexpr int kRelay1 = kUnassigned;
constexpr int kRelay2 = kUnassigned;
constexpr int kRelay3 = kUnassigned;
constexpr int kRelay4 = kUnassigned;
constexpr int kRelay5 = kUnassigned;
constexpr int kRelay6 = kUnassigned;

// Relay drive polarity is NOT known yet. The relay module refuses to drive
// any output while this is Unknown. Set to ActiveLow or ActiveHigh once the
// relay board is confirmed.
enum class RelayActiveLevel : uint8_t { Unknown, ActiveLow, ActiveHigh };
constexpr RelayActiveLevel kRelayActiveLevel = RelayActiveLevel::Unknown;

// --- INMP441 I2S microphone ------------------------------------------------
constexpr int kMicI2sSck = kUnassigned;  // Bit clock (SCK / BCLK)
constexpr int kMicI2sWs  = kUnassigned;  // Word select (WS / LRCLK)
constexpr int kMicI2sSd  = kUnassigned;  // Serial data out (SD)

// --- MAX98357A I2S amplifier -----------------------------------------------
constexpr int kAmpI2sBclk = kUnassigned;  // Bit clock (BCLK)
constexpr int kAmpI2sLrc  = kUnassigned;  // Left/right clock (LRC)
constexpr int kAmpI2sDin  = kUnassigned;  // Serial data in (DIN)
constexpr int kAmpSd      = kUnassigned;  // Shutdown / enable (SD), optional

// --- Display ---------------------------------------------------------------
// Display model and bus are not confirmed. Fill in whichever set applies
// and leave the rest unassigned.
constexpr int kDisplayI2cSda   = kUnassigned;
constexpr int kDisplayI2cScl   = kUnassigned;
constexpr int kDisplaySpiMosi  = kUnassigned;
constexpr int kDisplaySpiSclk  = kUnassigned;
constexpr int kDisplaySpiCs    = kUnassigned;
constexpr int kDisplayDc       = kUnassigned;
constexpr int kDisplayReset    = kUnassigned;
constexpr int kDisplayBacklight = kUnassigned;

// --- Buzzer ----------------------------------------------------------------
constexpr int kBuzzer = kUnassigned;

// --- Status LED ------------------------------------------------------------
constexpr int kStatusLed = kUnassigned;

}  // namespace pins
