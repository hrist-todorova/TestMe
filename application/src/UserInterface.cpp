//
// Created by Hristina Todorova on 6/27/18.
//

#include <iostream>
#include "UserInterface.h"

using namespace std;

UserInterface::UserInterface() {
    greeting();
    askForSettings();
}

void UserInterface::greeting() {
    cout << "Hello! My name is TestMe and I will help you make a great exam :)" << endl << endl;
}

void UserInterface::askForSettings() {
    cout << "First of all, do you want to create a file with questions? (Y/N)" << endl;
    cout << "If you have a file already please choose 'N'\n> ";
    char answer;
    cin >> answer;
    while(answer != 'Y' && answer != 'N'){
        cout << "Please answer with 'Y' or 'N'\n> ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> answer;
    }

    switch(answer) {
        case 'Y':
            createQuestionsFile();
            return;
        case 'N':
            createExam();
            return;
        default:
            string response = "This is not a possible option : ";
            response += answer;
            throw logic_error(response);
    }
}

void UserInterface::createQuestionsFile() {}

void UserInterface::createExam() {}