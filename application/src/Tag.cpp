//
// Created by Hristina Todorova on 6/30/18.
//

#include "Tag.h"

void Tag::addLabel(string _label) {
    this->labels.push_back(_label);
}

vector<string> Tag::getLabels() {
    return this->labels;
}