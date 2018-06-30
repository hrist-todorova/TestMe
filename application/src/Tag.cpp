//
// Created by Hristina Todorova on 6/30/18.
//

#include "Tag.h"

Tag::Tag(string _text) {
    this->text = _text;
}

string Tag::getTag() {
    return this->text;
}