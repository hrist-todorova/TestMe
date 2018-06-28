//
// Created by Hristina Todorova on 6/27/18.
//

#ifndef APPLICATION_USERINTERFACE_H
#define APPLICATION_USERINTERFACE_H

#include "string"
#include "vector"
#include "Question.h"

using namespace std;

class UserInterface {
    string fileName;
    int questionsCount;
    vector<Question> inputQuestions;
private:
    void greeting();
    void askForSettings();
    void createQuestionsFile();
    void createExam();
    void cleanInput();
    void addUserQuestion();
public:
    UserInterface();
};


#endif //APPLICATION_USERINTERFACE_H
