//
// Created by Hristina Todorova on 6/29/18.
//

#include <iostream>
#include <assert.h>
#include "../src/StringInterpreter.h"

using namespace std;

const string green("\033[1;32m");
const string red("\033[0;31m");
const string reset("\033[0m");

void static markAsPassedTest(string testName) {
    cout << green << testName << reset << endl;
}

void static markAsNotPassedTest(string testName) {
    cout << red << testName << reset << endl;
}

void static testStringToCorrectAnswer() {
    string correctAnswer = "[+] Yes";
    Answer answer = StringInterpreter().stringToAnswer(correctAnswer);
    if(!answer.answerIsCorrect()) {
        markAsNotPassedTest("testStringToCorrectAnswer failed");
        return;
    }
    if(answer.getString() != "Yes") {
        markAsNotPassedTest("testStringToCorrectAnswer failed");
        return;
    }
    markAsPassedTest("testStringToCorrectAnswer passed");
}

void static testStringToWrongAnswer() {
    string wrongAnswer = "[-] No";
    Answer answer = StringInterpreter().stringToAnswer(wrongAnswer);
    if(answer.answerIsCorrect()) {
        markAsNotPassedTest("testStringToWrongAnswer failed");
        return;
    }
    if(answer.getString() != "No") {
        markAsNotPassedTest("testStringToWrongAnswer failed");
        return;
    }
    markAsPassedTest("testStringToWrongAnswer passed");
}

void static testInvalidStringToAnswer() {
    string invalidAnswer = "[Q] invalid";
    try {
        Answer answer = StringInterpreter().stringToAnswer(invalidAnswer);
    }
    catch (invalid_argument& e) {
        markAsPassedTest("testInvalidStringToAnswer passed");
        return;
    }
    markAsNotPassedTest("testInvalidStringToAnswer failed");
}

void static testEmptyStringToVectorOfTags() {
    try {
        StringInterpreter().stringToVectorOfTags("");
    }
    catch (invalid_argument& e) {
        markAsPassedTest("testEmptyStringToVectorOfTags passed");
        return;
    }
    markAsNotPassedTest("testEmptyStringToVectorOfTags failed");
}

void static testInvalidStringToVectorOfTags() {
    try {
        StringInterpreter().stringToVectorOfTags("I'm invalid string");
    }
    catch (invalid_argument& e) {
        markAsPassedTest("testInvalidStringToVectorOfTags passed");
        return;
    }
    markAsNotPassedTest("testInvalidStringToVectorOfTags failed");
}

void static testStringToVectorOfTags() {
    string testString = "[T] {bad}{good}{three}";
    vector<Tag> vec;
    vec.push_back(Tag("bad"));
    vec.push_back(Tag("good"));
    vec.push_back(Tag("three"));
    vector<Tag> result = StringInterpreter().stringToVectorOfTags(testString);
    for(int i = 0; i < result.size(); i++) {
        if(result[i].getString() != vec[i].getString()) {
            markAsNotPassedTest("testStringToVectorOfTags failed");
            return;
        }
    }
    markAsPassedTest("testStringToVectorOfTags passed");
}

void static testStringToQuestion() {
    string questionString = "[Q] How are you";
    Question question = StringInterpreter().stringToQuestion(questionString);
    if(question.getString() != "How are you") {
        markAsNotPassedTest("testStringToQuestion failed");
        return;
    }
    markAsPassedTest("testStringToQuestion passed");
}

void static testInvalidStringToQuestion() {
    try {
        StringInterpreter().stringToQuestion("I'm invalid string");
    }
    catch (invalid_argument& e) {
        markAsPassedTest("testInvalidStringToQuestion passed");
        return;
    }
    markAsNotPassedTest("testInvalidStringToQuestion failed");
}

void static testAnswerToStringFalseAnswer() {
    Answer testString = Answer("test", false);
    string expectedString = "[-] test";
    if(StringInterpreter().answerToString(testString) != expectedString) {
        markAsNotPassedTest("testAnswerToStringFalseAnswer failed");
        return;
    }
    markAsPassedTest("testAnswerToStringFalseAnswer passed");
}

void static testAnswerToStringTrueAnswer() {
    Answer testString = Answer("test", true);
    string expectedString = "[+] test";
    if(StringInterpreter().answerToString(testString) != expectedString) {
        markAsNotPassedTest("testAnswerToStringTrueAnswer failed");
        return;
    }
    markAsPassedTest("testAnswerToStringTrueAnswer passed");
}

void static testTagsToStringWhenEmpty() {
    vector<Tag> tags;
    if(StringInterpreter().tagsToString(tags) != "") {
        markAsNotPassedTest("testTagsToStringWhenEmpty failed");
        return;
    }
    markAsPassedTest("testTagsToStringWhenEmpty passed");
}

void static testTagsToString() {
    vector<Tag> tags;
    tags.push_back(Tag("first_tag"));
    tags.push_back(Tag("second_tag"));
    if(StringInterpreter().tagsToString(tags) != "[T] {first_tag}{second_tag}") {
        markAsNotPassedTest("testTagsToString failed");
        return;
    }
    markAsPassedTest("testTagsToString passed");
}

void static testQuestionToStringOnlyText() {
    vector<Tag> tags;
    vector<Answer> answers;
    Question question = Question("This is a question", tags, answers);
    string expectedString = "[Q] This is a question";
    if(StringInterpreter().questionToString(question) != expectedString) {
        markAsNotPassedTest("testQuestionToStringOnlyText failed");
        return;
    }
    markAsPassedTest("testQuestionToStringOnlyText passed");
}

void static testQuestionToStringNoAnswers() {
    vector<Tag> tags;
    tags.push_back(Tag("tag1"));
    tags.push_back(Tag("tag2"));
    vector<Answer> answers;
    Question question = Question("This is a question", tags, answers);
    string expectedString = "[Q] This is a question\n[T] {tag1}{tag2}";
    if(StringInterpreter().questionToString(question) != expectedString) {
        markAsNotPassedTest("testQuestionToStringNoAnswers failed");
        return;
    }
    markAsPassedTest("testQuestionToStringNoAnswers passed");
}

void static testQuestionToStringNoTags() {
    vector<Tag> tags;
    vector<Answer> answers;
    answers.push_back(Answer("answer 1", false));
    answers.push_back(Answer("answer 2", true));
    answers.push_back(Answer("answer 3", false));
    Question question = Question("This is a question", tags, answers);
    string expectedString = "[Q] This is a question\n[-] answer 1\n[+] answer 2\n[-] answer 3";
    if(StringInterpreter().questionToString(question) != expectedString) {
        markAsNotPassedTest("testQuestionToStringNoTags failed");
        return;
    }
    markAsPassedTest("testQuestionToStringNoTags passed");
}

void static testQuestionToString() {
    vector<Tag> tags;
    tags.push_back(Tag("tag1"));
    tags.push_back(Tag("tag2"));
    vector<Answer> answers;
    answers.push_back(Answer("answer 1", false));
    answers.push_back(Answer("answer 2", true));
    answers.push_back(Answer("answer 3", false));
    Question question = Question("This is a question", tags, answers);
    string expectedString = "[Q] This is a question\n[T] {tag1}{tag2}\n[-] answer 1\n[+] answer 2\n[-] answer 3";
    if(StringInterpreter().questionToString(question) != expectedString) {
        markAsNotPassedTest("testQuestionToString failed");
        return;
    }
    markAsPassedTest("testQuestionToString passed");
}

void static testQuestionsToString() {
    vector<Tag> tags;
    tags.push_back(Tag("tag1"));
    tags.push_back(Tag("tag2"));
    vector<Answer> answers;
    Question question1 = Question("This is a question", tags, answers);
    Question question2 = Question("This is a question", tags, answers);
    vector<Question> questions;
    questions.push_back(question1);
    questions.push_back(question2);
    string expectedString = "[Q] This is a question\n[T] {tag1}{tag2}\n[Q] This is a question\n[T] {tag1}{tag2}\n";
    if(StringInterpreter().questionsToString(questions) != expectedString) {
        markAsNotPassedTest("testQuestionsToString failed");
        return;
    }
    markAsPassedTest("testQuestionsToString passed");
}

void static runStringInterpreterTest() {
    cout << "Tests for class StringInterpreter:" << endl;

    cout << "Testing function stringToAnswer ..." << endl;
    testStringToCorrectAnswer();
    testStringToWrongAnswer();
    testInvalidStringToAnswer();
    cout << endl;

    cout << "Testing function stringToVectorOfTags ..." << endl;
    testEmptyStringToVectorOfTags();
    testInvalidStringToVectorOfTags();
    testStringToVectorOfTags();
    cout << endl;

    cout << "Testing function stringToQuestion ..." << endl;
    testStringToQuestion();
    testInvalidStringToQuestion();
    cout << endl;

    cout << "Testing function answerToString ..." << endl;
    testAnswerToStringFalseAnswer();
    testAnswerToStringTrueAnswer();
    cout << endl;

    cout << "Testing function tagsToString ..." << endl;
    testTagsToStringWhenEmpty();
    testTagsToString();
    cout << endl;

    cout << "Testing function questionToString ..." << endl;
    testQuestionToStringOnlyText();
    testQuestionToStringNoAnswers();
    testQuestionToStringNoTags();
    testQuestionToString();
    cout << endl;

    cout << "Testing function questionsToString ..." << endl;
    testQuestionsToString();
    cout << endl;

}