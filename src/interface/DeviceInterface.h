//
// Created by adam on 30.12.2020.
//

#ifndef TF_DEVICEINTERFACE_H
#define TF_DEVICEINTERFACE_H

#include <Arduino.h>
#include "ClickButtonListener.h"


class DeviceInterface {
private:
    int buttonPin;
    int ledPin;
    bool isLedBlink = false;
    unsigned long lastDebounceTime = 0;
    int lastButtonState = LOW;
    int buttonState{};
    unsigned long previousMillis = 0;
    ClickButtonListener *click;

    bool ledState=LOW;

    void buttonClickDetect();

    void blinkLed();

public:
    DeviceInterface(int buttonPin, int ledPin, ClickButtonListener *click);

    ~DeviceInterface();

    void turnOnLed();

    void turnOffLed();

    void turnBlinkLed();

    void loop();
};


#endif //TF_DEVICEINTERFACE_H
