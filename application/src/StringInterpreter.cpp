//
// Created by Hristina Todorova on 6/29/18.
//

#include "StringInterpreter.h"
#include <regex>

Answer StringInterpreter::stringToAnswer(string input) {
    string prefix = "[+] ";
    auto res = std::mismatch(prefix.begin(), prefix.end(), input.begin());
    if (res.first == prefix.end()) {
        string text = input.substr(prefix.size());
        bool isCorrect = true;
        return Answer(text, isCorrect);
    } else {
        prefix = "[-] ";
        res = std::mismatch(prefix.begin(), prefix.end(), input.begin());
        if (res.first == prefix.end()) {
            string text = input.substr(prefix.size());
            bool isCorrect = false;
            return Answer(text, isCorrect);
        }
    }
    throw invalid_argument(input + " is not in valid Answer format");
}

vector<Tag> StringInterpreter::stringToTags(string input) {
    string prefix = "[T] ";
    vector<Tag> result;
    auto res = std::mismatch(prefix.begin(), prefix.end(), input.begin());
    if (res.first == prefix.end()) {
        string seq = input.substr(prefix.size());
        regex rgx("(\\w+)");
        regex_iterator<string::iterator> it(seq.begin(), seq.end(), rgx);
        regex_iterator<string::iterator> end;
        for(; it != end; ++it) {
            result.push_back(it->str());
        }
    } else {
        throw invalid_argument(input + " is not in valid Tag format");
    }
    return result;
}

Question StringInterpreter::stringToQuestion(string input) {
    string prefix = "[Q] ";
    auto res = std::mismatch(prefix.begin(), prefix.end(), input.begin());
    if (res.first == prefix.end()) {
        string text = input.substr(prefix.size());
        return Question(text);
    } else {
        throw invalid_argument(input + " is not in valid Question format");
    }
}

string StringInterpreter::answerToString(Answer &answer) {
    if(answer.answerIsCorrect()){
        return "[+] " + answer.getString();
    } else {
        return "[-] " + answer.getString();
    }
}


string StringInterpreter::tagsToString(vector<Tag> &tag) {
    string result = "";
    if(tag.size() > 0) {
        result += "[T] ";
        for(int i = 0; i < tag.size(); i++) {
            string newTag = "{" + tag[i].getTag() + "}";
            result += newTag;
        }
    }
    return result;
}

string StringInterpreter::questionToString(Question &question) {
    string result = "[Q] " + question.getString();
    vector<Tag> tags = question.getTags();
    if(tags.size() > 0) {
        result += "\n";
        result += tagsToString(tags);
    }
    vector<Answer> answers = question.getAnswers();
    if(answers.size() > 0) {
        for(int i = 0; i < answers.size(); i++) {
            result += "\n";
            result += answerToString(answers[i]);
        }
    }
    return result;
}
