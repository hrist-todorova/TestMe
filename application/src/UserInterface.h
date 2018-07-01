//
// Created by Hristina Todorova on 6/27/18.
//

#ifndef APPLICATION_USERINTERFACE_H
#define APPLICATION_USERINTERFACE_H

#include "string"
#include "Question.h"

using namespace std;

class UserInterface {
private:
    void askForUsersIntent();
    void createQuestionsFile();
    void generateExam();
    void cleanStandardInput();
    void print(string text);
    Question getNewQuestion(int number);

public:
    UserInterface();
};


#endif //APPLICATION_USERINTERFACE_H
