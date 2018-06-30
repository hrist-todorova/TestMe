//
// Created by Hristina Todorova on 6/25/18.
//

#include "Question.h"

/*
 * Constructor for class Question.
 * It accepts one argument - the text of the question.
 * The tags and answers stay empty vectors.
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
    this->text = other.text;
    this->tags = other.tags;
    this->answers = other.answers;
    return *this;
}

/*
 * Standard setter for the vector with tags.
 */
void Question::setTags(vector<Tag> _tags) {
    this->tags = _tags;
}

/*
 * Add answer to the vector with answers.
 */
void Question::addAnswer(Answer _answer) {
    this->answers.push_back(_answer);
}

/*
 * Standard getter for the vector with tags.
 */
vector<Tag> Question::getTags() const{
    return this->tags;
}

/*
 * Standard getter for the vector with answers.
 */
vector<Answer> Question::getAnswers() const{
    return this->answers;
}