//
// Created by adam on 17.01.2021.
//

#ifndef TF_QUESTION_H
#define TF_QUESTION_H

enum Answer {
    TRUE, FALSE, A, B, C, D
};

class Question {
public:
    Question(int size);

    char *question();

    Answer answer();
};


#endif //TF_QUESTION_H
