//
// Created by Hristina Todorova on 6/27/18.
//

#ifndef APPLICATION_PRINTABLEOBJECT_H
#define APPLICATION_PRINTABLEOBJECT_H

#include "string"

using namespace std;

class PrintableObject {
protected:
    string text;
public:
    virtual string printString() = 0;
    string getString() const;
};


#endif //APPLICATION_PRINTABLEOBJECT_H
