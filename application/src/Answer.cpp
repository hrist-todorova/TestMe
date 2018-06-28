//
// Created by Hristina Todorova on 6/28/18.
//

#include "Answer.h"

Answer::Answer(string _text, bool _isCorrect) {
    this->text = _text;
    this->isCorrect = _isCorrect;
}

string Answer::getPrintString() {
    if(isCorrect){
        return "[+] " + getString() + "\n";
    } else {
        return "[-] " + getString() + "\n";
    }
}