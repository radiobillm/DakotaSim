//Arduino Micro Pro Trim and Flaps from Bill Moore

#include <Joystick.h>

// Create the Joystick object
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD, 4, 0, true, false, false); // 4 buttons, 1 axis

// Pin assignments for trim and flaps
const int trimPin = A8;
const int flapPins[] = {2, 3, 4, 5};

// Number of flaps
const int flapCount = sizeof(flapPins) / sizeof(flapPins[0]);

// State tracking for flap switches
bool lastState[flapCount] = {false};

void setup() {
    // Initialize the Joystick library
    Joystick.setXAxisRange(0, 1023); // Set trim axis range
    Joystick.begin();

    // Configure trim pin as input
    pinMode(trimPin, INPUT);

    // Configure flap pins as input with pull-up resistors
    for (int i = 0; i < flapCount; i++) {
        pinMode(flapPins[i], INPUT_PULLUP);
    }
}

void loop() {
    // Read the trim value and update the joystick axis
    int trimValue = analogRead(trimPin);
    Joystick.setXAxis(trimValue);

    // Read and update flap switches
    for (int i = 0; i < flapCount; i++) {
        bool currentState = digitalRead(flapPins[i]) == LOW; // Active LOW
        if (currentState != lastState[i]) {
            lastState[i] = currentState;
            Joystick.setButton(i, currentState);
        }
    }
}