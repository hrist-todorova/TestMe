//
// Created by Hristina Todorova on 6/27/18.
//

#include <iostream>
#include "UserInterface.h"
#include "File.h"

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
    string answer;
    cin >> answer;
    while(answer != "Y" && answer != "N"){
        cout << "Please answer with 'Y' or 'N'\n> ";
        cleanInput();
        cin >> answer;
    }

    if(answer == "Y") {
        createQuestionsFile();
        return;
    }
    if(answer == "N") {
        createQuestionsFile();
        return;
    }
    string response = "This is not a possible option : ";
    response += answer;
    throw logic_error(response);
}

void UserInterface::createQuestionsFile() {
    cout << "How would you like to name the file?" << endl;
    cin >> fileName;
    cleanInput();
    cout << "How many questions would you like to enter?" << endl;
    cin >> questionsCount;
    cleanInput();

    // add new class here

    cout << "Thank you. Your file is being created ..." << endl;
    //add creation code here
}

void UserInterface::createExam() {}

void UserInterface::cleanInput() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}