#include <iostream>
#include "src/UserInterface.h"
#include "src/Question.h"
#include "src/Answer.h"
#include "src/Test.h"
#include "src/File.h"
#include "vector"
#include "tests/test_string_interpreter.cpp"

using namespace std;

int main() {

    //UserInterface();

   vector<Question> q = File("test4e.txt").extractQuestions();

   cout << q[0].getPrintString();

    return 0;
}