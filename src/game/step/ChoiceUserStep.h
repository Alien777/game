//
// Created by adam on 12.01.2021.
//

#ifndef TF_CHOICEUSERSTEP_H
#define TF_CHOICEUSERSTEP_H

#include <game/users/User.h>
#include "game/users/UserDefinition.h"
#include "game/users/DecisionMakerDefinition.h"

#include "game/users/Decision.h"
#include <vector>
#include <algorithm>
#include "audio/AudioWrapper.h"
using namespace std;

class ChoiceUserStep {
    vector<User *> &users;
    int *step;

    Decision *trueDecision;
    Decision *falseDecision;

    UserType *selectedUser;
    DecisionMaker *selectedDecision;
    AudioWrapper *audio;

    User *blue;
    User *white;
    User *purple;
    User *see;
    User *yellow;

    void selectLoop(UserType userType, User *object);

    void decisionLoop(Decision *object);

    void clearNoNeededObject(User *user);


public:
    ChoiceUserStep(vector<User *> &users, Decision *trueDecision, Decision *falseDecision, UserType *selectedUser,
                   DecisionMaker *selectedDecision,
                   NotificationUser *notificationUser, int *step, AudioWrapper* audio);

    void loop();

    ~ChoiceUserStep();
};


#endif //TF_CHOICEUSERSTEP_H
