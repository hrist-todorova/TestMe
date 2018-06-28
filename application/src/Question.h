//
// Created by Hristina Todorova on 6/25/18.
//

#ifndef APPLICATION_QUESTION_H
#define APPLICATION_QUESTION_H

#include "string"
#include "vector"
#include "PrintableObject.h"
#include "Answer.h"

using namespace std;

class Question : public PrintableObject {
    vector<string> tags;
    vector<Answer> answers;
public:
    Question(string _text, vector<string> &_tags, vector<Answer> &_answers);
    Question& operator=(const Question& other);
    string getPrintString();
    bool hasTag(string tag);
};


#endif //APPLICATION_QUESTION_H
