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

void testEmptyStringToTags() {
    try {
        StringInterpreter().stringToVectorOfTags("");
    }
    catch (invalid_argument& e) {
        cout << "testStringToTags passed" << endl;
        return;
    }
    throw logic_error("testStringToTags failed for empty string");
}

void testStringToTags() {
    string testString = "[T] {bad}{good}{three}";
    vector<Tag> vec;
    vec.push_back(Tag("bad"));
    vec.push_back(Tag("good"));
    vec.push_back(Tag("three"));
    vector<Tag> result = StringInterpreter().stringToVectorOfTags(testString);
    for(int i = 0; i < result.size(); i++) {
        assert(result[i].getString() == vec[i].getString());
    }
    cout << "testTagsToString passed" << endl;
}

void testQuestionToStringOnlyText() {
    vector<Tag> tags;
    vector<Answer> answers;
    Question question = Question("This is a question", tags, answers);
    string expectedString = "[Q] This is a question";
    assert(StringInterpreter().questionToString(question) == expectedString);
    cout << "testQuestionToStringOnlyText passed" << endl;
}

void testQuestionToStringNoAnswers() {
    vector<Tag> tags;
    tags.push_back(Tag("tag1"));
    tags.push_back(Tag("tag2"));
    vector<Answer> answers;
    Question question = Question("This is a question", tags, answers);
    string expectedString = "[Q] This is a question\n[T] {tag1}{tag2}";
    assert(StringInterpreter().questionToString(question) == expectedString);
    cout << "testQuestionToStringNoAnswers passed" << endl;
}

void testQuestionToStringNoTags() {
    vector<Tag> tags;
    vector<Answer> answers;
    answers.push_back(Answer("answer 1", false));
    answers.push_back(Answer("answer 2", true));
    answers.push_back(Answer("answer 3", false));
    Question question = Question("This is a question", tags, answers);
    string expectedString = "[Q] This is a question\n[-] answer 1\n[+] answer 2\n[-] answer 3";
    assert(StringInterpreter().questionToString(question) == expectedString);
    cout << "testQuestionToStringNoTags passed" << endl;
}

void testQuestionToString() {
    vector<Tag> tags;
    tags.push_back(Tag("tag1"));
    tags.push_back(Tag("tag2"));
    vector<Answer> answers;
    answers.push_back(Answer("answer 1", false));
    answers.push_back(Answer("answer 2", true));
    answers.push_back(Answer("answer 3", false));
    Question question = Question("This is a question", tags, answers);
    string expectedString = "[Q] This is a question\n[T] {tag1}{tag2}\n[-] answer 1\n[+] answer 2\n[-] answer 3";
    assert(StringInterpreter().questionToString(question) == expectedString);
    cout << "testQuestionToString passed" << endl;
}

void testStringToPositiveAnswer() {
    string positiveAnswer = "[+] Yes";
    Answer answer = StringInterpreter().stringToAnswer(positiveAnswer);
    assert(answer.answerIsCorrect());
    assert(answer.getString() == "Yes");
    cout << "testStringToPositiveAnswer passed" << endl;
}

void testStringToNegativeAnswer() {
    string negativeAnswer = "[-] No";
    Answer answer = StringInterpreter().stringToAnswer(negativeAnswer);
    assert(!answer.answerIsCorrect());
    assert(answer.getString() == "No");
    cout << "testStringToNegativeAnswer passed" << endl;
}

void testStringToQuestion() {
    string questionString = "[Q] How are you";
    Question question = StringInterpreter().stringToQuestion(questionString);
    assert(question.getString() == "How are you");
    cout << "testStringToQuestion passed" << endl;
}

void runStringInterpreterTest() {
    //AnswerToString
    testAnswerToStringFalseAnswer();
    testAnswerToStringTrueAnswer();

    //TagsToString
    testTagsToStringWhenEmpty();
    testTagsToString();

    //QuestionToString
    testQuestionToStringOnlyText();
    testQuestionToStringNoAnswers();
    testQuestionToStringNoTags();
    testQuestionToString();

    //StringToAnswer
    testStringToPositiveAnswer();
    testStringToNegativeAnswer();

    //StringToTags
    testEmptyStringToTags();
    testStringToTags();

    //StringToQuestion
    testStringToQuestion();
}