#ifndef AnalogKeypad_h
#define AnalogKeypad_h

#include "Arduino.h"

class AnalogKeypad {
public:
    AnalogKeypad(int analogPin);
    void begin(int numButtons, char* keyValues, int* adcValues, int tolerance, unsigned long debounceDelay);
    char getKey();
private:
    int _analogPin;
    int _numButtons;
    char* _keyValues;
    int* _adcValues;
    int _tolerance;
    unsigned long _lastKeyPressTime;
    unsigned long _debounceDelay;
    char _lastKey;
};

#endif
