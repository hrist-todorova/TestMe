//
// Created by Hristina Todorova on 6/25/18.
//

#include "Question.h"
#include "iostream"


/*
 * Constructor for class Question.
 * It accepts one argument - the text of the question.
 */
Question::Question(string _text) {
    this->text = _text;
}

/*
 * Constructor for class Question.
 * It accepts three arguments - the text of the question, vector of tags and vector of answers.
 */
Question::Question(string _text,vector<Tag> &_tags, vector<Answer> &_answers) {
    this->text = _text;
    this->tags = _tags;
    this->answers = _answers;
}

/*
 * Copy assignment operator for class Question.
 */
Question& Question::operator=(const Question& other){
    if(this == &other)
        return* this;
    this->text = other.getString();
    this->tags = other.getTags();
    this->answers = other.getAnswers();
    return *this;
}


void Question::setTags(vector<Tag> _tags) {
    this->tags = _tags;
}


void Question::addAnswer(Answer _answers) {
    this->answers.push_back(_answers);
}

vector<Tag> Question::getTags() const{
    return this->tags;
}

vector<Answer> Question::getAnswers() const{
    return this->answers;
}

/*
 * Checks if this question has the argument as a tag.
 */
bool Question::hasTag(string tag) {
    return false;
}