//
// Created by Hristina Todorova on 6/27/18.
//

#include <iostream>
#include "UserInterface.h"
#include "File.h"
#include "Exam.h"

using namespace std;

/*
 * Constructor of class UserInterface. When it is called it greets the user and ask questions to get the users intent.
 */
UserInterface::UserInterface() {
    greeting();
    askForSettings();
}

/*
 * A simple greeting.
 */
void UserInterface::greeting() {
    cout << "Hello! My name is TestMe and I will help you make a great exam :)" << endl << endl;
}

/*
 * User should choose if he wants to create a question file or open one which exists already to make exam
 */
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
        createExam();
        return;
    }
    string response = "This is not a possible option : ";
    response += answer;
    throw logic_error(response);
}

/*
 * This will be changed
 */
void UserInterface::createQuestionsFile() {
    cout << "How would you like to name the file? (No spaces between words)" << endl;
    string fileName = "DEFAULT";
    cin >> fileName;
    cleanInput();
    // ask for test title
    cout << "How many questions would you like to enter?" << endl;
    int questionsCount = 0;
    cin >> questionsCount;
    cleanInput();
    // append each 10 elements
    // add new class here

    cout << "Thank you. Your file is being created ..." << endl;
    //add creation code here
}

/*
 * This will be changed
 */
void UserInterface::createExam() {
    unsigned long testsCount, questionsCount = 0;
    cout << "How many tests would you like to create?" << endl;
    cin >> testsCount;
    cleanInput();
    cout << "How many questions would you like every test to have?" << endl;
    cin >> questionsCount;
    cleanInput();
//TODO : ask for the name of the exam
    Exam newExam = Exam("",testsCount, questionsCount);
    cout << "From which file whould you like to get the questions from?" << endl;
    string filename;
    cin >> filename;
    cleanInput();
    File file = File(filename);
    file.extractQuestions();
}

/*
 * A functions which cleans up the input stream.
 */
void UserInterface::cleanInput() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}