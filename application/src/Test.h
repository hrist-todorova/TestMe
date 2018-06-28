//
// Created by Hristina Todorova on 6/28/18.
//

#ifndef APPLICATION_TEST_H
#define APPLICATION_TEST_H

#include "vector"
#include "PrintableObject.h"
#include "Question.h"

using namespace std;

class Test : public PrintableObject{
    vector<Question> questions;
public:
    Test(int _questionsCount);
    Test& operator=(const Test& other);
    void addQuestion(Question question);
    string getPrintString();
    void deleteQuestions();
    unsigned long getQuestionsCount();
};


#endif //APPLICATION_TEST_H
