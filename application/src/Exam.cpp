//
// Created by Hristina Todorova on 6/29/18.
//

#include "Exam.h"

/*
 * Constructor for class Exam.
 * It accepts two arguments - the number of tests for this exam and the number of questions each test should contain.
 * Also we reserve the capacity of vector tests to hold all tests which will be in this exam.
 */
Exam::Exam(unsigned long _numberOfTests, unsigned long _numberOfQuestions) {
    this->numberOfTests = _numberOfTests;
    this->numberOfQuestions = _numberOfQuestions;
    this->tests.reserve(numberOfTests);
}

/*
 * Copy assignment operator for class Exam.
 */
Exam& Exam::operator=(const Exam &other) {
    if(this == &other)
        return* this;
    this->numberOfTests = other.numberOfTests;
    this->numberOfQuestions = other.numberOfQuestions;
    this->tests = other.tests;
    return *this;
}