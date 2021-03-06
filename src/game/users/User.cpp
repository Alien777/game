//
// Created by adam on 09.01.2021.
//

#include "User.h"

User::User(DeviceInterface *deviceInterface, int points) {
    this->deviceInterface = deviceInterface;
    this->points = points;
    this->choiceUser();
}

void User::addPoint(int point) {
    this->points += point;
}

int User::getPoint() {
    return points;
}

User::~User() {
    delete deviceInterface;
}

void User::choiceUser() {
    choice = true;
    active = true;
    deviceInterface->turnBlinkLed();
}

void User::activate() {
    active = true;
    choice = false;
    deviceInterface->turnOnLed();
}

void User::deactivate() {
    active = false;
    choice = false;
    deviceInterface->turnOffLed();
}

bool User::isActivate() {
    return active;
}

void User::loop() {
    deviceInterface->loop();
}
