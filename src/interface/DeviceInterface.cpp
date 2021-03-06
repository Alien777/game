//
// Created by adam on 30.12.2020.
//

#include "DeviceInterface.h"
#include "ClickButtonListener.h"
#include <Arduino.h>

#define DEBOUNCE_DELAY 50
#define INTERVAL_LED 1000

DeviceInterface::DeviceInterface(int buttonPin, int ledPin, ClickButtonListener *click) {
    this->buttonPin = buttonPin;
    this->ledPin = ledPin;
    this->click = click;

    pinMode(this->buttonPin, INPUT);
    pinMode(this->ledPin, OUTPUT);

    this->turnOffLed();
}

void DeviceInterface::loop() {
    DeviceInterface::buttonClickDetect();
    DeviceInterface::blinkLed();
}

void DeviceInterface::turnOffLed() {
    digitalWrite(this->ledPin, LOW);
    this->isLedBlink = false;
    ledState = LOW;
}

void DeviceInterface::turnOnLed() {
    digitalWrite(this->ledPin, HIGH);
    this->isLedBlink = false;
    ledState = LOW;
}

void DeviceInterface::turnBlinkLed() {
    this->lastDebounceTime = 0;
    isLedBlink = true;
}

void DeviceInterface::buttonClickDetect() {
    int reading = digitalRead(buttonPin);
    if (reading != lastButtonState) {
        lastDebounceTime = millis();
    }
    if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
        if (reading != buttonState) {
            buttonState = reading;
            if (buttonState == HIGH) {
                this->click->onClick();
            }
        }
    }
    lastButtonState = reading;
}


void DeviceInterface::blinkLed() {
    if (isLedBlink) {
        unsigned long currentMillis = millis();

        if (currentMillis - previousMillis >= INTERVAL_LED) {

            previousMillis = currentMillis;
            if (ledState == LOW) {
                ledState = HIGH;
            } else {
                ledState = LOW;
            }
            digitalWrite(this->ledPin, ledState);
        }

    }

}

DeviceInterface::~DeviceInterface() {
    delete click;
}



