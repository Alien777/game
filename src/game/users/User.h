//
// Created by adam on 09.01.2021.
//

#ifndef TF_USER_H
#define TF_USER_H

#include "interface/DeviceInterface.h"

class User {
private:
    DeviceInterface *deviceInterface;
    int points;
    bool active;
    bool choice;
public:
    User(DeviceInterface *deviceInterface, int points);

    ~User();

    void addPoint(int point);

    int getPoint();

    void activate();

    void deactivate();

    void choiceUser();

    bool isActivate();

    void loop();

};


#endif //TF_USER_H
