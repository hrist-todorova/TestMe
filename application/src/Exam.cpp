//
// Created by Hristina Todorova on 6/29/18.
//

#include "Exam.h"

Exam::Exam(unsigned long _numberOfTests, unsigned long _numberOfQuestions) {
    //add asserts here
    this->numberOfTests = _numberOfTests;
    this->numberOfQuestions = _numberOfQuestions;
    this->tests.reserve(numberOfTests);
}

Exam& Exam::operator=(const Exam &other) {
    if(this == &other)
        return* this;
    this->numberOfTests = other.numberOfTests;
    this->tests = other.tests;
    return *this;
}