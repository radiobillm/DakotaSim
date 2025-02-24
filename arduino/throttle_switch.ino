#include <Joystick.h>

// Create the Joystick object
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD, 19, 0, true, true, true);

// Analog input pins for axes
const int axisPins[] = {A0, A1, A2}; // Throttle, Mixture, Prop

// Digital input pins for switches
const int buttonPins[] = {
    12, // Avionics On
    11, // Avionics Off
    10, // Master On
    9,  // Master Off
    8,  // Fuel On
    7,  // Fuel Off
    6,  // Landing On
    2,  // Landing Off
    5,  // Beacon On
    4,  // Beacon Off
    3,  // Collision On
    0,  // Collision Off
    1,  // Pitot On
    13, // Pitot Off
    16, // Nav On
    15, // Nav Off
    A3, // Carb Heat On
    A4, // Carb Heat Off
    14  // GA
};

// Number of axes and buttons
const int axisCount = sizeof(axisPins) / sizeof(axisPins[0]);
const int buttonCount = sizeof(buttonPins) / sizeof(buttonPins[0]);

// State tracking for switches and axes
bool lastState[buttonCount] = {false};
int lastAxisValue[axisCount] = {0};

// Predefined min and max values for each axis
const int axisMin[axisCount] = {425, 430, 470}; // Throttle, Mixture, Prop
const int axisMax[axisCount] = {825, 850, 866};

// Define the size of the moving average buffer
const int bufferSize = 5;
int axisBuffers[axisCount][bufferSize] = {0};
int bufferIndex[axisCount] = {0};

// Dead zone threshold to ignore minor fluctuations
const int deadZone = 5; // Adjust this value based on your needs

int calculateAverage(int axisIndex) {
    int sum = 0;
    for (int j = 0; j < bufferSize; j++) {
        sum += axisBuffers[axisIndex][j];
    }
    return sum / bufferSize;
}

void setup() {
    // Initialize the Serial Monitor
    Serial.begin(9600);

    // Initialize the Joystick library
    Joystick.setXAxisRange(0, 1023);
    Joystick.setYAxisRange(0, 1023);
    Joystick.setZAxisRange(0, 1023);
    Joystick.begin();

    // Configure axis pins as input
    for (int i = 0; i < axisCount; i++) {
        pinMode(axisPins[i], INPUT);
    }

    // Configure button pins as input with pull-up
    for (int i = 0; i < buttonCount; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }
}

void loop() {
    int normalizedValues[axisCount];

    // Read and update axes
    for (int i = 0; i < axisCount; i++) {
        int axisValue = analogRead(axisPins[i]);

        // Add the raw value to the buffer for smoothing
        axisBuffers[i][bufferIndex[i]] = axisValue;
        bufferIndex[i] = (bufferIndex[i] + 1) % bufferSize; // Circular buffer

        // Calculate the smoothed value
        int smoothedValue = calculateAverage(i);

        // Map the smoothed values to the full range (0–1023)
        int normalizedValue = map(smoothedValue, axisMin[i], axisMax[i], 0, 1023);

        // Ensure the value stays within bounds
        normalizedValue = constrain(normalizedValue, 0, 1023);

        // Apply dead zone: only update if the change is greater than the threshold
        if (abs(normalizedValue - lastAxisValue[i]) > deadZone) {
            lastAxisValue[i] = normalizedValue;

            // Send the value to the joystick and log it
            switch (i) {
                case 0:
                    Joystick.setXAxis(normalizedValue);
                    Serial.print("USB X sent: ");
                    break;
                case 1:
                    Joystick.setYAxis(normalizedValue);
                    Serial.print("USB Y sent: ");
                    break;
                case 2:
                    Joystick.setZAxis(normalizedValue);
                    Serial.print("USB Z sent: ");
                    break;
            }
            Serial.println(normalizedValue); // Print the value sent
        }
        normalizedValues[i] = normalizedValue;
    }

    // Read and update button states
    for (int i = 0; i < buttonCount; i++) {
        bool currentState = digitalRead(buttonPins[i]) == LOW; // Active LOW
        if (currentState != lastState[i]) {
            lastState[i] = currentState;
            Joystick.setButton(i, currentState);
       }
    }

    // Small delay for stability
    delay(100);
}
