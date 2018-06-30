//
// Created by Hristina Todorova on 6/29/18.
//

#ifndef APPLICATION_STRINGINTERPRETER_H
#define APPLICATION_STRINGINTERPRETER_H

#include "Question.h"
#include "Tag.h"
#include "Answer.h"

class StringInterpreter {
public:
    Answer stringToAnswer(string input);
    vector<Tag> stringToTags(string input);
    Question stringToQuestion(string input);
    string answerToString(Answer& answer);
    string tagsToString(vector<Tag>& tag);
    string questionToString(Question& question);
};


#endif //APPLICATION_STRINGINTERPRETER_H
