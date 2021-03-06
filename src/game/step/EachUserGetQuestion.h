//
// Created by adam on 12.01.2021.
//

#ifndef TF_EACHUSERGETQUESTION_H
#define TF_EACHUSERGETQUESTION_H

#include <vector>
#include <algorithm>
#include "game/users/User.h"
#include "game/users/UserType.h"
#include "game/users/DecisionMaker.h"
#include "game/users/Decision.h"
#include <ctime>
#include <cstdlib>
#include "audio/AudioWrapper.h"
#include <string>
#include <HTTPClient.h>
using namespace std;

class EachUserGetQuestion {
private:
    vector<User *> &users;
    int *step;

    Decision *trueDecision;
    Decision *falseDecision;
    AudioWrapper *audio;
    UserType *selectedUser;
    DecisionMaker *selectedDecision;
    long previousMillis = 0;
    int currentUser = 0;

    int intStep = 0;
    vector<int> question;

public:
    EachUserGetQuestion(vector<User *> &users, Decision *trueDecision,
                        Decision *falseDecision, UserType *selectedUser,
                        DecisionMaker *selectedDecision, int *step, AudioWrapper *audio);

    void loop();

    ~EachUserGetQuestion();
};


#endif //TF_EACHUSERGETQUESTION_H
