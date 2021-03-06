//
// Created by adam on 12.01.2021.
//

#include "Decision.h"

Decision::Decision(DeviceInterface *deviceInterface) {
    this->deviceInterface = deviceInterface;
    this->choiceUser();
}

Decision::~Decision() {
    delete deviceInterface;
}

void Decision::choiceUser() {
    choice = true;
    active = true;
    deviceInterface->turnBlinkLed();
}

void Decision::activate() {
    active = true;
    choice = false;
    deviceInterface->turnOnLed();
}

void Decision::deactivate() {
    active = false;
    choice = false;
    deviceInterface->turnOffLed();
}

bool Decision::isActivate() {
    return active;
}

void Decision::loop() {
    deviceInterface->loop();
}