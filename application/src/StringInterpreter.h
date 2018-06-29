//
// Created by Hristina Todorova on 6/29/18.
//

#ifndef APPLICATION_STRINGINTERPRETER_H
#define APPLICATION_STRINGINTERPRETER_H

#include "Question.h"

class StringInterpreter {
public:
    Answer stringToAnswer(string input);
    Question stringToQuestion(string input);
    string answerToString(Answer& answer);
    string questionToString(Question& question);
};


#endif //APPLICATION_STRINGINTERPRETER_H
