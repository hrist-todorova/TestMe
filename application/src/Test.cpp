//
// Created by Hristina Todorova on 6/28/18.
//

#include "Test.h"

/*
 * Constructor for class Test.
 * It accepts one argument - how many questions we will have.
 */
Test::Test(int _questionsCount) {
    this->questions.reserve(_questionsCount);
}

/*
 * Copy assignment operator for class Test.
 */
Test& Test::operator=(const Test &other) {
    if(this == &other)
        return* this;
    this->questions = other.questions;
    return *this;
}

/*
 * Adds question to the vector of questions.
 */
void Test::addQuestion(Question question) {
    questions.push_back(question);
}


/*
 * Deletes all questions in the test.
 */
void Test::deleteQuestions() {
    this->questions.clear();
}

/*
 * Returns number of questions currently in the Test.
 */
unsigned long Test::getQuestionsCount() {
    return questions.size();
}