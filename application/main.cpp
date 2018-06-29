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

    string t = Answer("This is true", false).getPrintString();

    Answer two = Answer(t);
    cout << two.getPrintString();

    return 0;
}