//
// Created by Hristina Todorova on 6/29/18.
//

#ifndef APPLICATION_EXAM_H
#define APPLICATION_EXAM_H

#include <vector>
#include "string"
#include "Test.h"

using namespace std;

class Exam : public PrintableObject {
    unsigned long numberOfTests;
    unsigned long numberOfQuestions;
    vector<Test> tests;
public:
    Exam(string _name, unsigned long _numberOfTests, unsigned long _numberOfQuestions);
    Exam &operator=(const Exam& other);
    void addTest(Test& test);
    Test getTest(int index);
};


#endif //APPLICATION_EXAM_H
