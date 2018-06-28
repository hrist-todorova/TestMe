//
// Created by Hristina Todorova on 6/25/18.
//

#include "Question.h"
#include <algorithm>

Question::Question(string &_text, vector<string> &_tags) {
    this->text = _text;
    this->tags = _tags;
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

bool Question::hasTag(string tag) {
    if (find(this->tags.begin(), this->tags.end(), tag) != this->tags.end()) {
        return true;
    }
    return false;
}
