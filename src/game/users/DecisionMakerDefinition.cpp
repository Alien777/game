//
// Created by adam on 12.01.2021.
//

#include "DecisionMakerDefinition.h"

ClickDecisionImpl::ClickDecisionImpl(DecisionMakerNotification *notify, DecisionMaker decisionMaker) {
    this->notify = notify;
    this->decisionMaker = decisionMaker;
}

void ClickDecisionImpl::onClick() {
    notify->notify(decisionMaker);
}

FalseDecision::FalseDecision(DecisionMakerNotification *notify) : Decision(
        new DeviceInterface(B_FALSE, L_FALSE, new ClickDecisionImpl(notify, FALSE))) {}

TrueDecision::TrueDecision(DecisionMakerNotification *notify) : Decision(
        new DeviceInterface(B_TRUE, L_TRUE, new ClickDecisionImpl(notify, TRUE))) {}
