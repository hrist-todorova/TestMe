//
// Created by Hristina Todorova on 6/30/18.
//

#ifndef APPLICATION_TAG_H
#define APPLICATION_TAG_H

#include "vector"
#include "string"

using namespace std;

class Tag {
    vector<string> labels;
public:
    void addLabel(string _label);
    vector<string> getLabels();
};


#endif //APPLICATION_TAG_H
