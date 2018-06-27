//
// Created by Hristina Todorova on 6/25/18.
//

#ifndef APPLICATION_QUESTION_H
#define APPLICATION_QUESTION_H

#include "string"
#include "PrintableObject.h"

using namespace std;

class Question : public PrintableObject {
public:
    Question(string _text);
    Question& operator=(const Question& other);
    string printString();
};


#endif //APPLICATION_QUESTION_H
