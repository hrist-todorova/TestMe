//
// Created by Hristina Todorova on 6/25/18.
//

#ifndef APPLICATION_FILE_H
#define APPLICATION_FILE_H

#include "string"
#include "vector"
#include "Question.h"

using namespace std;

class File {
    string filename;
public:
    File(string _filename);
    File& operator=(const File& other);
    vector<Question> extractQuestions();
    void write(string text);
    void truncate();
};


#endif //APPLICATION_FILE_H
