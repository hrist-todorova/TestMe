#include <iostream>
#include "src/Question.h"

using namespace std;

int main() {

    Question test = Question("Oh, hi Mark");
    cout << test.printString();

    return 0;
}