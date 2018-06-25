//
// Created by Hristina Todorova on 6/25/18.
//

#ifndef APPLICATION_QUESTION_H
#define APPLICATION_QUESTION_H

#include "string"

using namespace std;

class Question {
    string text;

public:
    Question(string _text) : text(_text) {}
    Question& operator=(const Question& other);
    string getQuestionText() const;
};


#endif //APPLICATION_QUESTION_H
