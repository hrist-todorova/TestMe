//
// Created by Hristina Todorova on 6/29/18.
//

#include "StringInterpreter.h"
#include <regex>

/*
 * Convert input string to object of class Answer.
 * If the prefix of the input is not of a positive or negative answer an exception is thrown.
 */
Answer StringInterpreter::stringToAnswer(string input) {
    //std::mismatch returns the first mismatching pair of elements from two ranges
    auto res = mismatch(correctAnswerPrefix.begin(), correctAnswerPrefix.end(), input.begin());
    if (res.first == correctAnswerPrefix.end()) {
        string text = input.substr(correctAnswerPrefix.size());
        return Answer(text, true);
    } else {

        res = mismatch(wrongAnswerPrefix.begin(), wrongAnswerPrefix.end(), input.begin());
        if (res.first == wrongAnswerPrefix.end()) {
            string text = input.substr(wrongAnswerPrefix.size());
            return Answer(text, false);
        }
    }
    throw invalid_argument(input + " is not in valid Answer format");
}

/*
 * Convert input string to vector of Tag objects.
 * If the prefix of the input is not of a tag an exception is thrown.
 */
vector<Tag> StringInterpreter::stringToVectorOfTags(string input) {
    vector<Tag> result;

    //std::mismatch returns the first mismatching pair of elements from two ranges
    auto res = mismatch(tagPrefix.begin(), tagPrefix.end(), input.begin());
    if (res.first == tagPrefix.end()) {
        string tags = input.substr(tagPrefix.size());
        //regex is used to discover the tags encoded into the input string
        regex rgx("(\\w+)");
        regex_iterator<string::iterator> it(tags.begin(), tags.end(), rgx);
        regex_iterator<string::iterator> end;

        for(; it != end; ++it) {
            result.push_back(it->str());
        }
    } else {
        throw invalid_argument(input + " is not in valid Tag format");
    }
    return result;
}

/*
 * Convert input string to object of class Question.
 * If the prefix of the question is not of a tag an exception is thrown.
 */
Question StringInterpreter::stringToQuestion(string input) {
    //std::mismatch returns the first mismatching pair of elements from two ranges
    auto res = mismatch(questionPrefix.begin(), questionPrefix.end(), input.begin());
    if (res.first == questionPrefix.end()) {
        string text = input.substr(questionPrefix.size());
        return Question(text);
    } else {
        throw invalid_argument(input + " is not in valid Question format");
    }
}

/*
 * Covert an object of class Answer to a string.
 */
string StringInterpreter::answerToString(Answer &answer) {
    if(answer.answerIsCorrect()){
        return correctAnswerPrefix + answer.getString();
    } else {
        return wrongAnswerPrefix + answer.getString();
    }
}


/*
 * Covert vector of Tag objects to a string.
 * Each tag is one word. The string will have the form of 'tagPrefix{tag1}{tag2}' etc.
 */
string StringInterpreter::tagsToString(vector<Tag> &tag) {
    string result = "";

    if(tag.size() > 0) {
        result += tagPrefix;
        for(int i = 0; i < tag.size(); i++) {
            string newTag = "{" + tag[i].getString() + "}";
            result += newTag;
        }
    }
    return result;
}

/*
 * Covert an object of class Question to a string. The first line is the test of the question. Then follows a line of
 * tags if there are any. After that answers are added one by one.
 */
string StringInterpreter::questionToString(Question &question) {
    string result = questionPrefix + question.getString();

    vector<Tag> tags = question.getTags();
    if(!tags.empty()) {
        result += "\n";
        result += tagsToString(tags);
    }

    vector<Answer> answers = question.getAnswers();
    if(!answers.empty()) {
        for(int i = 0; i < answers.size(); i++) {
            result += "\n";
            result += answerToString(answers[i]);
        }
    }

    return result;
}
