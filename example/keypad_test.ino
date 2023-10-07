#include "AnalogKeypad.h"

AnalogKeypad keypad(34); // Connect the analog pin to your keypad

int numButtons = 6;
char keyValues[] = {'1', '2', '3', '4','5','6'}; // Adjust to match your keypad layout
int adcValues[] = {4095, 3500, 2700, 2000, 1300, 550}; // Adjust these values based on your keypad
int tolerance = 50; // Adjust the tolerance value as needed
unsigned long debounceDelay = 300; // Adjust the debounce delay as needed

void setup() {
    Serial.begin(115200);
    keypad.begin(numButtons, keyValues, adcValues, tolerance, debounceDelay);
}

void loop() {
    char key = keypad.getKey();

    if (key != '\0') {
        Serial.println(key);
        // Handle the key press here
    }

    // Add any other code or functionality you need in your loop
}
