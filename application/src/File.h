//
// Created by Hristina Todorova on 6/25/18.
//

#ifndef APPLICATION_FILE_H
#define APPLICATION_FILE_H

#include "string"

using namespace std;

class File {
    string filename;
public:
    File(string _filename);
    File& operator=(const File& other);
    void read();
    void write(string text);
    void truncate();
};


#endif //APPLICATION_FILE_H
