//
// Created by adam on 12.01.2021.
//

#include "ChoiceUserStep.h"

#define removeObject(x) {delete x; x = NULL;}

ChoiceUserStep::ChoiceUserStep(vector<User *> &users, Decision *trueDecision, Decision *falseDecision,
                               UserType *selectedUser, DecisionMaker *selectedDecision,
                               NotificationUser *notify, int *step, AudioWrapper *audio) : users(users) {
    this->selectedUser = selectedUser;
    this->selectedDecision = selectedDecision;
    this->trueDecision = trueDecision;
    this->falseDecision = falseDecision;
    this->step = step;
    this->audio = audio;
    blue = new BlueUser(notify);
    white = new WhiteUser(notify);
    purple = new PurpleUser(notify);
    see = new SeeUser(notify);
    yellow = new YellowUser(notify);
    audio->play("start"); // wyjasnienie zaproszenia do gry wybrabia użytkownikow;
}

void ChoiceUserStep::loop() {
    decisionLoop(trueDecision);
    selectLoop(BLUE, blue);
    selectLoop(WHITE, white);
    selectLoop(PURPLE, purple);
    selectLoop(SEE, see);
    selectLoop(YELLOW, yellow);
}

void ChoiceUserStep::decisionLoop(Decision *decision) {
    if (decision != NULL)
        decision->loop();

    if (*selectedDecision == TRUE && users.size() >= 2) {
        falseDecision->activate();
        trueDecision->activate();
        *step += 1;
    }
    *selectedDecision = NON;
}

void ChoiceUserStep::selectLoop(UserType userType, User *user) {

    if (user != NULL)
        user->loop();
    if (*selectedUser == userType) {
        if (std::find(users.begin(), users.end(), user) == users.end()) {
            user->activate();
            users.push_back(user);
        } else {
            user->deactivate();
            users.erase(std::remove(users.begin(), users.end(), user), users.end());
        }
        *selectedUser = NONE;
    }
}

ChoiceUserStep::~ChoiceUserStep() {
    audio->stop();
    clearNoNeededObject(blue);
    clearNoNeededObject(white);
    clearNoNeededObject(purple);
    clearNoNeededObject(see);
    clearNoNeededObject(yellow);
}

void ChoiceUserStep::clearNoNeededObject(User *user) {
    if (find(users.begin(), users.end(), user) == users.end()) {
        user->deactivate();
        removeObject(user);
    } else {
        user->activate();
    }
}
