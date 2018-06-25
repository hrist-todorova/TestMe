#include <iostream>
#include "src/Question.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    cout << Question("This is my first question").getQuestionText();

    return 0;
}