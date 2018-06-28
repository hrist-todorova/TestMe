//
// Created by Hristina Todorova on 6/25/18.
//

#ifndef APPLICATION_QUESTION_H
#define APPLICATION_QUESTION_H

#include "string"
#include "PrintableObject.h"
#include "vector"

using namespace std;

class Question : public PrintableObject {
    vector<string> tags;
public:
    Question(string &_text, vector<string> &_tags);
    Question& operator=(const Question& other);
    string printString();
    bool hasTag(string tag);
};


#endif //APPLICATION_QUESTION_H
