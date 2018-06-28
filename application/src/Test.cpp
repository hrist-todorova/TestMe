//
// Created by Hristina Todorova on 6/28/18.
//

#include "Test.h"

Test::Test(int _questionsCount) {
    this->questions.reserve(_questionsCount);
}

Test& Test::operator=(const Test &other) {
    if(this == &other)
        return* this;
    this->questions = other.questions;
    return *this;
}

void Test::addQuestion(Question question) {
    questions.push_back(question);
}

string Test::getPrintString() {
    string result = "";
    for(int i = 0; i < questions.size(); i++) {
        result += questions[i].getPrintString();
    }
    return result;
}

void Test::deleteQuestions() {
    this->questions.clear();
}

unsigned long Test::getQuestionsCount() {
    return questions.size();
}