//
// Created by Hristina Todorova on 6/25/18.
//

#include "Question.h"

string Question::getQuestionText() const {
    return this->text;
};

Question& Question::operator=(const Question& other){
    if(this == &other)
        return* this;
    this->text = other.getQuestionText();
    return *this;
}