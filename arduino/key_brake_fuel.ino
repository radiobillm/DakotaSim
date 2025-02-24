#include <Joystick.h>

// Create the Joystick object
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD, 12, 0, false, false, true); // 12 buttons, Z-axis only

// Pin assignments for HID buttons
const int buttonPins[] = {
    2, 3, 4, 5, 6, 14, 16, 21, 20, 19, 18, 15
};

// Names for debugging
const char* buttonNames[] = {
    "Key Off", "Key A", "Key B", "Key Run", "Key Start",
    "Park Off", "Park On", "Fuel Off",
    "Left Tip", "Left Main", "Right Main", "Right Tip"
};

// Number of buttons
const int buttonCount = sizeof(buttonPins) / sizeof(buttonPins[0]);

// Pin for rudder trim potentiometer
const int rudderTrimPin = A8;

// State tracking for switches
bool lastState[buttonCount] = {false};

void setup() {
    // Initialize the Joystick library
    Joystick.setZAxisRange(-32767, 32767);
    Joystick.begin();

    // Configure button pins as input with pull-up
    for (int i = 0; i < buttonCount; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }

    // Configure the rudder trim potentiometer pin
    pinMode(rudderTrimPin, INPUT);
}

void loop() {
    // Read and update button states
    for (int i = 0; i < buttonCount; i++) {
        bool currentState = digitalRead(buttonPins[i]) == LOW; // Active LOW
        if (currentState != lastState[i]) {
            lastState[i] = currentState;
            Joystick.setButton(i, currentState);
        }
    }

    // Read and map the rudder trim potentiometer value
    int rudderTrimValue = analogRead(rudderTrimPin);
    int mappedValue = map(rudderTrimValue, 0, 1023, -32767, 32767);
    Joystick.setZAxis(mappedValue);

    // Small delay for stability
    delay(50);
}
