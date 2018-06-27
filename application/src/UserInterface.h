//
// Created by Hristina Todorova on 6/27/18.
//

#ifndef APPLICATION_USERINTERFACE_H
#define APPLICATION_USERINTERFACE_H

#include "string"

using namespace std;

class UserInterface {
    string fileName;
private:
    void greeting();
    void askForSettings();
    void createQuestionsFile();
    void createExam();
public:
    UserInterface();
};


#endif //APPLICATION_USERINTERFACE_H
