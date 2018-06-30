//
// Created by Hristina Todorova on 6/29/18.
//

#ifndef APPLICATION_STRINGINTERPRETER_H
#define APPLICATION_STRINGINTERPRETER_H

#include "Question.h"
#include "Tag.h"
#include "Answer.h"
#include "string"

using namespace std;

class StringInterpreter {
private:
    string questionPrefix      = "[Q] ";
    string tagPrefix           = "[T] ";
    string correctAnswerPrefix = "[+] ";
    string wrongAnswerPrefix   = "[-] ";
public:
    Answer stringToAnswer(string input);
    vector<Tag> stringToVectorOfTags(string input);
    Question stringToQuestion(string input);

    string answerToString(Answer& answer);
    string tagsToString(vector<Tag>& tag);
    string questionToString(Question& question);
};


#endif //APPLICATION_STRINGINTERPRETER_H
