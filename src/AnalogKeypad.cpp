#include "AnalogKeypad.h"

AnalogKeypad::AnalogKeypad(int analogPin) {
    _analogPin = analogPin;
    _numButtons = 0;
    _keyValues = nullptr;
    _adcValues = nullptr;
    _tolerance = 50; // Default tolerance value, you can adjust it later
    _debounceDelay = 300; // Default debounce delay in milliseconds, you can adjust it later
    _lastKeyPressTime = 0;
    _lastKey = '\0';
}

void AnalogKeypad::begin(int numButtons, char* keyValues, int* adcValues, int tolerance, unsigned long debounceDelay) {
    _numButtons = numButtons;
    _keyValues = keyValues;
    _adcValues = adcValues;
    _tolerance = tolerance;
    _debounceDelay = debounceDelay;
}

char AnalogKeypad::getKey() {
    int adcValue = analogRead(_analogPin);
    unsigned long currentTime = millis();

    for (int i = 0; i < _numButtons; i++) {
        if (adcValue >= _adcValues[i] - _tolerance && adcValue <= _adcValues[i] + _tolerance) {
            if (_lastKey != _keyValues[i] || (currentTime - _lastKeyPressTime >= _debounceDelay)) {
                _lastKey = _keyValues[i];
                _lastKeyPressTime = currentTime;
                return _lastKey;
            }
        }
    }

    return '\0'; // No valid key press
}
