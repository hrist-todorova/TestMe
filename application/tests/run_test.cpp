//
// Created by Hristina Todorova on 7/1/18.
//

#include <iostream>
#include "test_string_interpreter.cpp"
using namespace std;

//this function is static because of a compiler error
static void runAllTest() {
    cout << "Running all tests" << endl;

    runStringInterpreterTest();

    return;
}