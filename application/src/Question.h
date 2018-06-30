//
// Created by Hristina Todorova on 6/25/18.
//

#ifndef APPLICATION_QUESTION_H
#define APPLICATION_QUESTION_H

#include "string"
#include "vector"
#include "PrintableObject.h"
#include "Answer.h"
#include "Tag.h"

using namespace std;

class Question : public PrintableObject {
    vector<Tag> tags;
    vector<Answer> answers;
public:
    Question(string _text);
    Question(string _text, vector<Tag> &_tags, vector<Answer> &_answers);
    Question& operator=(const Question& other);
    void setTags(vector<Tag> _tags);
    void addAnswer(Answer _answers);
    vector<Tag> getTags() const;
    vector<Answer> getAnswers() const;
    bool hasTag(string tag);
};


#endif //APPLICATION_QUESTION_H
