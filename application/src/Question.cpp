//
// Created by Hristina Todorova on 6/25/18.
//

#include "Question.h"

Question::Question(string _text) {
    this->text = _text;
}

Question& Question::operator=(const Question& other){
    if(this == &other)
        return* this;
    this->text = other.getString();
    return *this;
}

string Question::printString() {
    return "[Q] " + getString();
}
