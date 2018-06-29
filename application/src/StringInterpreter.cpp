//
// Created by Hristina Todorova on 6/29/18.
//

#include "StringInterpreter.h"

Answer StringInterpreter::stringToAnswer(string input) {
}

Question StringInterpreter::stringToQuestion(string input) {
}

string StringInterpreter::answerToString(Answer &answer) {
    if(answer.answerIsCorrect()){
        return "[+] " + answer.getString();
    } else {
        return "[-] " + answer.getString();
    }
}

string StringInterpreter::questionToString(Question &question) {
}
