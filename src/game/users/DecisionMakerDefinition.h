//
// Created by adam on 12.01.2021.
//

#ifndef TF_DECISIONMAKERDEFINITION_H
#define TF_DECISIONMAKERDEFINITION_H

#include "DecisionMaker.h"
#include "interface/DeviceInterface.h"
#include "Decision.h"
#include "PinDefinition.h"
class DecisionMakerNotification {
public:
    void notify(DecisionMaker decisionMaker);
};

class ClickDecisionImpl : public ClickButtonListener {
private:
    DecisionMakerNotification *notify;
    DecisionMaker decisionMaker;
public:
    ClickDecisionImpl(DecisionMakerNotification *notify, DecisionMaker decisionMaker);

    void onClick() override;
};


class FalseDecision : public Decision {
public:
    FalseDecision(DecisionMakerNotification *notify);
};


class TrueDecision : public Decision {
public:
    TrueDecision(DecisionMakerNotification *notify);
};

#endif //TF_DECISIONMAKERDEFINITION_H
