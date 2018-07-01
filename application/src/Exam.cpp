//
// Created by Hristina Todorova on 6/29/18.
//

#include "Exam.h"

/*
 * Constructor for class Exam.
 * It accepts three arguments - the name of the exam, the number of tests for this exam and the number of questions
 * each test should contain.
 */
Exam::Exam(string _name, unsigned long _numberOfTests, unsigned long _numberOfQuestions) {
    this->text = _name;
    this->numberOfTests = _numberOfTests;
    this->numberOfQuestions = _numberOfQuestions;
}

/*
 * Copy assignment operator for class Exam.
 */
Exam& Exam::operator=(const Exam &other) {
    if(this == &other)
        return* this;
    this->text = other.text;
    this->numberOfTests = other.numberOfTests;
    this->numberOfQuestions = other.numberOfQuestions;
    this->tests = other.tests;
    return *this;
}

/*
 * Add a test to the vector with tests.
 */
void Exam::addTest(Test &test) {
    this->tests.push_back(test);
}

/*
 * Get the test at a specified index;
 */
Test Exam::getTest(int index) {
    return this->tests[index];
}