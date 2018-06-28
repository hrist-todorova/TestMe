//
// Created by Hristina Todorova on 6/27/18.
//

#ifndef APPLICATION_USERINTERFACE_H
#define APPLICATION_USERINTERFACE_H

#include "string"
#include "vector"

using namespace std;

class UserInterface {
    string fileName;
    int questionsCount;
private:
    void greeting();
    void askForSettings();
    void createQuestionsFile();
    void createExam();
    void cleanInput();
public:
    UserInterface();
};


#endif //APPLICATION_USERINTERFACE_H
