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

void testTagsToStringWhenEmpty() {
    vector<Tag> tags;
    assert(StringInterpreter().tagsToString(tags) == "");
    cout << "testTagsToStringWhenEmpty passed" << endl;
}

void testTagsToString() {
    vector<Tag> tags;
    tags.push_back(Tag("first_tag"));
    tags.push_back(Tag("second_tag"));
    assert(StringInterpreter().tagsToString(tags) == "[T] {first_tag}{second_tag}");
    cout << "testTagsToString passed" << endl;
}

void runStringInterpreterTest() {
    testAnswerToStringFalseAnswer();
    testAnswerToStringTrueAnswer();
    testTagsToStringWhenEmpty();
    testTagsToString();
}