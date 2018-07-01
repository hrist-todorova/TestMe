//
// Created by Hristina Todorova on 6/27/18.
//

#include <iostream>
#include <limits>
#include <map>
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
    string usersInput;

    print("Please enter question number " + to_string(number));
    getline(cin, usersInput);
    Question question = Question(usersInput);

    print("Please enter how many tags would you like to enter");
    int tagsCount;
    cin >> tagsCount;
    cleanStandardInput();
    vector<Tag> tagsVector;
    for(int i = 0; i < tagsCount; i++) {
        print("Please enter one word as tag number " + to_string(i + 1));
        cin >> usersInput;
        cleanStandardInput();
        tagsVector.push_back(Tag(usersInput));
    }
    question.setTags(tagsVector);

    print("Please enter how many right answers would you like to enter");
    int rightAnswersCount;
    cin >> rightAnswersCount;
    cleanStandardInput();
    for(int i = 0; i < rightAnswersCount; i++) {
        print("Please enter right answer number " + to_string(i + 1));
        getline(cin, usersInput);
        question.addAnswer(Answer(usersInput, true));
    }

    print("Please enter how many wrong answers would you like to enter");
    int wrongAnswersCount;
    cin >> wrongAnswersCount;
    cleanStandardInput();
    for(int i = 0; i < wrongAnswersCount; i++) {
        print("Please enter wrong answer number " + to_string(i + 1));
        getline(cin, usersInput);
        question.addAnswer(Answer(usersInput, false));
    }

    return question;
}

/*
 * Using an existing file with questions generates an Exam with different Tests.
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
    int availableQuestionSize = questions.size();

    // have random numbers always
    srand(time(NULL));
    for(int i = 0; i < testsCount; i++) {
        Test newTest = Test(questionsCount);

        //this map saves the indexes we have used
        map<int, bool> isSelected;

        for(int j = 0; j < questionsCount; j++) {

            //select a random index for vector questions
            int index = rand() % availableQuestionSize;

            //change the index until we find one which isn't in the test already
            auto iterator = isSelected.find(index);
            while(iterator != isSelected.end()) {
                index = rand() % availableQuestionSize;
                iterator = isSelected.find(index);
            }

            //add the question corresponding to the index in the vector
            isSelected[index] = true;
            newTest.addQuestion(questions[index]);
        }
        newExam.addTest(newTest);
    }

    for(int i = 0; i < testsCount; i++) {
        File test = File(newExam.getString() + "-test-" + to_string(i));
        vector<Question> questions = newExam.getTest(i).getQuestions();
        test.write(StringInterpreter().questionsToString(questions));
    }

    return;
}
