//
// Created by adam on 09.01.2021.
//
#define POINTS 20

#include "UserDefinition.h"
#include "PinDefinition.h"
#include "UserType.h"

void ClickImpl::onClick() {
    notify->notify(userType);
}

ClickImpl::ClickImpl(NotificationUser *notify, UserType userType) {
    this->notify = notify;
    this->userType = userType;
}

BlueUser::BlueUser(NotificationUser *notify) :
        User(new DeviceInterface(B_BLUE, L_BLUE, new ClickImpl(notify, BLUE)), POINTS) {
}

WhiteUser::WhiteUser(NotificationUser *notify) :
        User(new DeviceInterface(B_WHITE, L_WHITE, new ClickImpl(notify, WHITE)), POINTS) {
}

YellowUser::YellowUser(NotificationUser *notify) :
        User(new DeviceInterface(B_YELLOW, L_YELLOW, new ClickImpl(notify, YELLOW)), POINTS) {
}

SeeUser::SeeUser(NotificationUser *notify) :
        User(new DeviceInterface(B_SEE, L_SEE, new ClickImpl(notify, SEE)), POINTS) {
}

PurpleUser::PurpleUser(NotificationUser *notify) :
        User(new DeviceInterface(B_PURPLE, L_PURPLE, new ClickImpl(notify, PURPLE)), POINTS) {
}


