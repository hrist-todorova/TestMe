//
// Created by Hristina Todorova on 6/28/18.
//

#ifndef APPLICATION_ANSWER_H
#define APPLICATION_ANSWER_H

#include "string"
#include "PrintableObject.h"

using namespace std;

class Answer : public PrintableObject{
    bool isCorrect;
public:
    Answer(string _text, bool _isCorrect);
    Answer& operator=(const Answer& other);
    bool answerIsCorrect();
};


#endif //APPLICATION_ANSWER_H
