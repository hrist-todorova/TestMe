//
// Created by Hristina Todorova on 6/28/18.
//

#include "Test.h"

Test::Test(string _name, int _questionsCount) {
    this->text = _name;
    this->questions.reserve(_questionsCount);
}

Test& Test::operator=(const Test &other) {
    if(this == &other)
        return* this;
    this->text = other.text;
    this->questions = other.questions;
    return *this;
}

void Test::addQuestion(Question question) {
    questions.push_back(question);
}

string Test::getPrintString() {
    string result = "[N] " + getString() + "\n";
    for(int i = 0; i < questions.size(); i++) {
        result += questions[i].getPrintString();
    }
    return result;
}