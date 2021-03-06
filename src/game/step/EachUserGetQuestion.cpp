//
// Created by adam on 12.01.2021.
//

#include "EachUserGetQuestion.h"
#include <vector>
#include <Common.h>
#include "game/users/User.h"


int myrandom(int i) { return std::rand() % i; }


EachUserGetQuestion::EachUserGetQuestion(vector<User *> &users, Decision *trueDecision,
                                         Decision *falseDecision, UserType *selectedUser,
                                         DecisionMaker *selectedDecision, int *step, AudioWrapper *audio) : users(
        users) {
    this->selectedUser = selectedUser;
    this->selectedDecision = selectedDecision;
    this->trueDecision = trueDecision;
    this->falseDecision = falseDecision;
    this->step = step;
    this->audio = audio;
    srand(unsigned(std::time(0)));

    for (int i = 1; i < users.size() * 2; ++i) question.push_back(i);
    random_shuffle(question.begin(), question.end());
    random_shuffle(question.begin(), question.end(), myrandom);
    trueDecision->choiceUser();
    audio->play("round_one");
}

int answer;
User *user;
static long currentMillis;
static byte statCounter = 0;
void EachUserGetQuestion::loop() {
    if (*selectedDecision == TRUE && intStep == 0) {
        intStep++;
        audio->stop();
        trueDecision->activate();
    } else if (intStep == 1) {

        user = users.at(currentUser % users.size());
        currentUser++;
        user->choiceUser();
        HTTPClient http;

        String rand = "randQuestion";
        http.begin((IP_SERVER + rand).c_str());
        int httpResponseCode = http.GET();
        String response;
        if (httpResponseCode > 0) {
            response = http.getString();
        }
        http.end();

        String question = response.substring(0, response.indexOf(";"));
        Serial.println(response.substring(response.indexOf(";") + 1, response.length()));
        answer = (int) response.substring(response.indexOf(";") + 1, response.length()).toInt();

        audio->play(question);
        user->choiceUser();

        intStep++;
        *selectedDecision = NON;
        *selectedUser = NONE;

        trueDecision->deactivate();
        falseDecision->deactivate();

        trueDecision->choiceUser();
        falseDecision->choiceUser();
    } else if (intStep == 2) {
        if ((*selectedDecision == TRUE && answer == 1) ||
            (*selectedDecision == FALSE && answer == 0)) {
            user->addPoint(2);
            Serial.println(*selectedDecision);
            if (*selectedDecision == TRUE) {
                trueDecision->activate();
                falseDecision->deactivate();
            } else if (*selectedDecision == FALSE) {
                trueDecision->deactivate();
                falseDecision->activate();
            }
            *selectedDecision = NON;
            *selectedUser = NONE;
            audio->play("correct");
            intStep++;
        } else if ((*selectedDecision == TRUE && answer == 0) ||
                   (*selectedDecision == FALSE && answer == 1)) {

            if (*selectedDecision == TRUE) {
                trueDecision->activate();
                falseDecision->deactivate();
            } else if (*selectedDecision == FALSE) {
                trueDecision->deactivate();
                falseDecision->activate();
            }
            *selectedDecision = NON;
            *selectedUser = NONE;
            audio->play("not_correct");
            intStep++;
        }
    } else if (intStep == 3) {

        if (millis() - currentMillis >= 2000)
        {
            if (statCounter> 1)
            {
                previousMillis = currentMillis;
                intStep = 1;
                trueDecision->activate();
                falseDecision->activate();
                *selectedDecision = NON;
                *selectedUser = NONE;
                user->activate();
                audio->stop();
                statCounter = 0;
            }
            statCounter++;
            Serial.println(statCounter);

            currentMillis = millis();
        }

    }

}

EachUserGetQuestion::~EachUserGetQuestion() {

}