//
// Created by Hristina Todorova on 6/29/18.
//

#include "StringInterpreter.h"

Answer StringInterpreter::stringToAnswer(string input) {
    return Answer("todo", true); // do later
}

vector<Tag> StringInterpreter::stringToTags(string input) {

}

Question StringInterpreter::stringToQuestion(string input) {
    vector<string> tags;
    vector<Answer> answers;
    return Question("doto", tags, answers);
}

string StringInterpreter::answerToString(Answer &answer) { //TESTED
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
    vector<string> tags = question.getTags();
    if(tags.size() > 0) {
        result += "\n";
        result += "[T] ";
        for (int i = 0; i < tags.size(); i++) {
            result += "{" + tags[i] + "}";
        }
    }
   /* if(answers.size() > 0) {
        result += "\n";
        for(int i = 0; i < answers.size(); i++) {
            result += answers[i].getPrintString();
        }
    }*/
    return result;
}
