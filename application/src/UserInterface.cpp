//
// Created by Hristina Todorova on 6/27/18.
//

#include <iostream>
#include <limits>
#include "UserInterface.h"
#include "File.h"
#include "Exam.h"
#include "StringInterpreter.h"

#define appendAfterNumberOfElements 10

/*
 * Constructor of class UserInterface. When it is called it greets the user and ask questions to get the users intent.
 */
UserInterface::UserInterface() {
    print("Hello! My name is TestMe and I will help you make a great exam :)");
    askForUsersIntent();
}

/*
 * While interacting with the user figure out if they want to create a file with questions or generate an exam.
 */
void UserInterface::askForUsersIntent() {
    print("First of all, do you want to create a file with questions? (Y/N)");
    print("If you have a file already please choose 'N'");
    string shouldCreateFile;
    cin >> shouldCreateFile;
    cleanStandardInput();

    while(shouldCreateFile != "Y" && shouldCreateFile != "N"){
        print("Please enter 'Y' or 'N'");
        cin >> shouldCreateFile;
        cleanStandardInput();
    }

    if(shouldCreateFile == "Y") {
        createQuestionsFile();
        return;
    }
    if(shouldCreateFile == "N") {
        generateExam();
        return;
    }
}

/*
 * Clears the standard input for future I/O operations.
 */
void UserInterface::cleanStandardInput() {
    //Clears the error flag
    cin.clear();
    //Skips to the next newline in order to ignore anything else on the same line
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/*
 * Writes argument text to the standard output and adds a newline.
 */
void UserInterface::print(string text) {
    cout << text << endl;
}

/*
 * Creates Test object which holds the questions the user inputs. Periodically they are appended to a file.
 */
void UserInterface::createQuestionsFile() {
    print("How would you like to name the file?");
    string fileName;
    getline(cin, fileName);

    print("How many questions would you like to enter?");
    int questionsCount = 0;
    cin >> questionsCount;
    cleanStandardInput();

    File newFile = File(fileName);
    //delete content of file if it exist
    newFile.truncate();

    Test newTest = Test(questionsCount);
    for(int i = 0; i < questionsCount; i++) {
        newTest.addQuestion(getNewQuestion(i + 1));
        if(newTest.getQuestionsCount() == appendAfterNumberOfElements) {
            //each time we have exactly appendAfterNumberOfElements questions in the test we append them to the file
            //and delete the current ones from the test object
            vector<Question> questionsVec = newTest.getQuestions();
            string questionsString = StringInterpreter().questionsToString(questionsVec);
            newFile.write(questionsString);
            newTest.deleteQuestions();
        }
    }
    //add the rest of the questions which are not yet appended
    vector<Question> questionsVec = newTest.getQuestions();
    string questionsString = StringInterpreter().questionsToString(questionsVec);
    newFile.write(questionsString);
    newTest.deleteQuestions();

    print("Your file has been created");
    return;
}

/*
 * Creates a question object.
 */
Question UserInterface::getNewQuestion(int number) {
    print("Please enter question number " + to_string(number));
    string text;
    getline(cin, text);
    Question question = Question(text);
    //TODO: Add tag creation
    //TODO: Add answers creation
    return question;
}

/*
 * Using an existing file with questions generates an Exam with different Tests
 */
void UserInterface::generateExam() {
    unsigned long testsCount, questionsCount = 0;
    print("How many tests would you like to create?");
    cin >> testsCount;
    cleanStandardInput();

    print("How many questions would you like every test to have?");
    cin >> questionsCount;
    cleanStandardInput();

    string examName;
    print("What is the name of the exam you want to create?");
    getline(cin, examName);
    Exam newExam = Exam(examName,testsCount, questionsCount);

    string filename;
    print("From which file would you like to get the questions from?");
    getline(cin, filename);
    File file = File(filename);

    vector<Question> questions = file.extractQuestions();

    //TODO: Make actual test variants

    return;
}
