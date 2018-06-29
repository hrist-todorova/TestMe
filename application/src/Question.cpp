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
    this->text = "done";
    return;
}

Question& Question::operator=(const Question& other){
    if(this == &other)
        return* this;
    this->text = other.getString();
    return *this;
}

string Question::getPrintString() {
    string result = "[Q] " + text + "\n";
    if(tags.size() > 0) {
        result += "[T] ";
        for (int i = 0; i < tags.size(); i++) {
            result += "{" + tags[i] + "}";
        }
        result += "\n";
    }
    for(int i = 0; i < answers.size(); i++) {
        result += answers[i].getPrintString();
    }
    return result;
}

bool Question::hasTag(string tag) {
    if (find(this->tags.begin(), this->tags.end(), tag) != this->tags.end()) {
        return true;
    }
    return false;
}