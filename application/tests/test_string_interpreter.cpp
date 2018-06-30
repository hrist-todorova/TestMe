//
// Created by Hristina Todorova on 6/29/18.
//

#include <iostream>
#include <assert.h>
#include "../src/StringInterpreter.h"


using namespace std;

void testAnswerToStringFalseAnswer() {
    Answer testString = Answer("test", false);
    string expectedString = "[-] test";
    assert(StringInterpreter().answerToString(testString) == expectedString);
    cout << "testAnswerToStringFalseAnswer passed" << endl;
}

void testAnswerToStringTrueAnswer() {
    Answer testString = Answer("test", true);
    string expectedString = "[+] test";
    assert(StringInterpreter().answerToString(testString) == expectedString);
    cout << "testAnswerToStringTrueAnswer passed" << endl;
}

void runStringInterpreterTest() {
    testAnswerToStringFalseAnswer();
    testAnswerToStringTrueAnswer();
}