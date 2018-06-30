//
// Created by Hristina Todorova on 6/30/18.
//

#ifndef APPLICATION_TAG_H
#define APPLICATION_TAG_H

#include "PrintableObject.h"
#include "string"

using namespace std;

class Tag : public PrintableObject {
public:
    Tag(string _text);
};


#endif //APPLICATION_TAG_H
