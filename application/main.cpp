#include <iostream>
#include "src/UserInterface.h"
#include "src/Question.h"
#include "src/Answer.h"
#include "src/Test.h"
#include "src/File.h"
#include "vector"

using namespace std;

int main() {

    //UserInterface();

    vector<Question> v = File("test4e.txt").extractQuestions();
    cout << v[0].getPrintString();

    return 0;
}