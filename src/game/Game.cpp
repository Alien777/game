//
// Created by adam on 09.01.2021.
//

#include "Game.h"

#define removeObject(x) {delete x; x = NULL;}

UserType selectedUser = NONE;
DecisionMaker selectedDecision = NON;

void NotificationUser::notify(UserType userType) {
    selectedUser = userType;
}

void DecisionMakerNotification::notify(DecisionMaker decisionMaker) {
    selectedDecision = decisionMaker;
}

Game::Game(AudioWrapper *audio) {
    makerNotification = new DecisionMakerNotification();
    falseDecision = new FalseDecision(makerNotification);
    trueDecision = new TrueDecision(makerNotification);
    notify = new NotificationUser();
    this->audio = audio;
    choiceUserStep = new ChoiceUserStep(users, trueDecision, falseDecision, &selectedUser, &selectedDecision, notify,
                                        &step, audio);
}


void Game::loop() {
    if (step != 0) {
        falseDecision->loop();
        trueDecision->loop();
        for (auto &u: users) {
            u->loop();
        }

    }

    if (step == 0) {
        choiceUserStep->loop();
    } else if (step == 1) {
        removeObject(choiceUserStep);
        step += 1;
        eachUserGetQuestion = new EachUserGetQuestion(users, trueDecision, falseDecision, &selectedUser,
                                                      &selectedDecision, &step, audio);
    } else if (step == 2) {
        eachUserGetQuestion->loop();
    }
}


Game::~Game() {
    users.clear();
    removeObject(notify);
    removeObject(makerNotification);
    removeObject(eachUserGetQuestion);
    removeObject(choiceUserStep);
}

