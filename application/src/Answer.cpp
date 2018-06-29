//
// Created by Hristina Todorova on 6/28/18.
//

#include "Answer.h"

Answer::Answer(string _text, bool _isCorrect) {
    this->text = _text;
    this->isCorrect = _isCorrect;
}

Answer::Answer(string input) {
    string positive_prefix = "[+] ";
    auto res = std::mismatch(positive_prefix.begin(), positive_prefix.end(), input.begin());
    if (res.first == positive_prefix.end()) {
        this->text = input.substr(positive_prefix.size());
        this->isCorrect = true;
    } else {
        string negative_prefix = "[-] ";
        res = std::mismatch(negative_prefix.begin(), negative_prefix.end(), input.begin());
        if (res.first == negative_prefix.end()) {
            this->text = input.substr(negative_prefix.size());
            this->isCorrect = false;
        } else {
            throw invalid_argument(input + " is not in valid Answer format");
        }
    }
}

Answer& Answer::operator=(const Answer &other) {
    if(this == &other)
        return* this;
    this->text = other.text;
    this->isCorrect = other.isCorrect;
    return *this;
}

string Answer::getPrintString() {
    if(isCorrect){
        return "[+] " + getString() + " ";
    } else {
        return "[-] " + getString() + " ";
    }
}