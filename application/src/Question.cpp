//
// Created by Hristina Todorova on 6/25/18.
//

#include "Question.h"
#include "iostream"

Question::Question(string _text, vector<string> &_tags, vector<Answer> &_answers) {
    this->text = _text;
    this->tags = _tags;
    this->answers = _answers;
}

Question::Question(string input) {
    string prefix = "[Q] ";
    auto res = std::mismatch(prefix.begin(), prefix.end(), input.begin());
    if (res.first == prefix.end()) {
        this->text = input.substr(prefix.size());
    } else {
        throw invalid_argument(input + " is not in valid Question format");
    }
    return;
}

Question& Question::operator=(const Question& other){
    if(this == &other)
        return* this;
    this->text = other.getString();
    return *this;
}

void Question::setTags(string input) {
    string prefix = "[T] ";
    auto res = std::mismatch(prefix.begin(), prefix.end(), input.begin());
    if (res.first == prefix.end()) {
        vector<string> a;
        a.push_back("todo");
        this->tags = a;
    } else {
        throw invalid_argument(input + " is not in valid Question format");
    }

}

void Question::setAnswers(vector<Answer> _answers) {
    this->answers = _answers;
}

string Question::getPrintString() {
    string result = "[Q] " + text;
    if(tags.size() > 0) {
        result += "\n";
        result += "[T] ";
        for (int i = 0; i < tags.size(); i++) {
            result += "{" + tags[i] + "}";
        }
    }
    if(answers.size() > 0) {
        result += "\n";
        for(int i = 0; i < answers.size(); i++) {
            result += answers[i].getPrintString();
        }
    }
    return result;
}

bool Question::hasTag(string tag) {
    if (find(this->tags.begin(), this->tags.end(), tag) != this->tags.end()) {
        return true;
    }
    return false;
}