//
// Created by adam on 09.01.2021.
//

#ifndef TF_USERDEFINITION_H
#define TF_USERDEFINITION_H

#include "User.h"
#include "UserType.h"

class NotificationUser {
public:
    void notify(UserType userType);
};

class ClickImpl : public ClickButtonListener {
private:
    NotificationUser *notify;
    UserType userType;
public:
    ClickImpl(NotificationUser *notify, UserType userType);

    void onClick() override;
};


class BlueUser : public User {
public:
    BlueUser(NotificationUser *notify);
};


class WhiteUser : public User {
public:
    WhiteUser(NotificationUser *notify);
};


class PurpleUser : public User {
public:
    PurpleUser(NotificationUser *notify);
};

class YellowUser : public User {
public:
    YellowUser(NotificationUser *notify);
};

class SeeUser : public User {
public:
    SeeUser(NotificationUser *notify);
};

#endif //TF_USERDEFINITION_H
