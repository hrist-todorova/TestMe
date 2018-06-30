//
// Created by Hristina Todorova on 6/28/18.
//

#include "Answer.h"

/*
 * Constructor for class Answer.
 * It accepts two arguments - the text of the answer and a boolean indicating if the answer is true or false.
 */
Answer::Answer(string _text, bool _isCorrect) {
    this->text = _text;
    this->isCorrect = _isCorrect;
}

/*
 * Copy assignment operator for class Answer.
 */
Answer& Answer::operator=(const Answer &other) {
    if(this == &other)
        return* this;
    this->text = other.text;
    this->isCorrect = other.isCorrect;
    return *this;
}

/*
 * Returns boolean is the answer is correct or not.
 */
bool Answer::answerIsCorrect() {
    return isCorrect;
}