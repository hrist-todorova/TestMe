//
// Created by Hristina Todorova on 6/29/18.
//

#ifndef APPLICATION_EXAM_H
#define APPLICATION_EXAM_H

#include <vector>
#include "Test.h"

class Exam {
    unsigned long numberOfTests;
    unsigned long numberOfQuestions;
    vector<Test> tests;
public:
    Exam(unsigned long _numberOfTests, unsigned long _numberOfQuestions);
    Exam &operator=(const Exam& other);
};


#endif //APPLICATION_EXAM_H
