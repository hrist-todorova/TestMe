#include <iostream>
#include "src/UserInterface.h"
#include "src/Question.h"
#include "src/Answer.h"
#include "src/Test.h"
#include "vector"

using namespace std;

int main() {

    //UserInterface();

    vector<string> a;
    vector<Answer> b;
    b.emplace_back(Answer("answer", false));

    Test one = Test("First Test", 3);
    one.addQuestion(Question("question one", a, b));
    one.addQuestion(Question("question two", a, b));
    one.addQuestion(Question("question three", a, b));
    one.addQuestion(Question("question four", a, b));


    cout << one.getPrintString();

    return 0;
}