//
// Created by adam on 12.01.2021.
//

#ifndef TF_DECISION_H
#define TF_DECISION_H

#include "interface/DeviceInterface.h"

class Decision {
private:
    DeviceInterface *deviceInterface;
    bool active;
    bool choice;
public:
    Decision(DeviceInterface *deviceInterface);

    ~Decision();

    void activate();

    void deactivate();

    void choiceUser();

    bool isActivate();

    void loop();

};


#endif //TF_DECISION_H
