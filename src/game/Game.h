//
// Created by adam on 09.01.2021.
//

#ifndef TF_GAME_H
#define TF_GAME_H


#include <game/users/User.h>
#include "game/users/UserDefinition.h"
#include "game/users/DecisionMakerDefinition.h"
#include <vector>
#include <algorithm>
#include "game/step/EachUserGetQuestion.h"
#include "game/step/ChoiceUserStep.h"
#include "audio/AudioWrapper.h"
using namespace std;

class Game {
private:
    std::vector<User *> users;

    Decision *falseDecision;
    Decision *trueDecision;

    NotificationUser *notify;
    DecisionMakerNotification *makerNotification;

    EachUserGetQuestion *eachUserGetQuestion;
    ChoiceUserStep *choiceUserStep;
    AudioWrapper* audio;
    int step = 0;


public:
    Game(AudioWrapper* audioWrapper);

    ~Game();

    void loop();
};


#endif //TF_GAME_H
