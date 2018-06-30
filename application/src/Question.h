//
// Created by Hristina Todorova on 6/25/18.
//

#ifndef APPLICATION_QUESTION_H
#define APPLICATION_QUESTION_H

#include "string"
#include "vector"
#include "PrintableObject.h"
#include "Answer.h"

using namespace std;

class Question : public PrintableObject {
    vector<string> tags;
    vector<Answer> answers;
public:
    Question(string _text, vector<string> &_tags, vector<Answer> &_answers);
    Question(string input);
    Question& operator=(const Question& other);
    void setTags(string _tags);
    void setAnswers(vector<Answer> _answers);
    string getPrintString();
    vector<string> getTags();
    vector<Answer> getAnswers();
    bool hasTag(string tag);
};


#endif //APPLICATION_QUESTION_H
