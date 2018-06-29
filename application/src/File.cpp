//
// Created by Hristina Todorova on 6/25/18.
//

#include <fstream>
#include "iostream"
#include "File.h"

using namespace std;

File::File(string _filename) {
    this->filename = _filename;
}

File& File::operator=(const File &other) {
    if(this == &other)
        return* this;
    this->filename = other.filename;
    return *this;
}

vector<Question> File::extractQuestions() {
    vector<Question> questions;
    ifstream fileStream(this->filename);
    if(fileStream.is_open()) {
        string temp;
        while(std::getline(fileStream, temp)) {
            questions.push_back(Question(temp));
        }
    } else {
        throw invalid_argument("File " + this->filename + " not found");
    }
    return questions;
}

void File::write(string text) {
    ofstream fileStream;
    fileStream.open(this->filename, ofstream::app);
    if(fileStream.is_open()) {
        fileStream << text;
        fileStream.close();
    } else {
        throw invalid_argument("File " + this->filename + " not found");
    }
}

void File::truncate() {
    ofstream fileStream;
    fileStream.open(this->filename, ofstream::trunc);
    if(fileStream.is_open()) {
        fileStream.close();
    } else {
        throw invalid_argument("File " + this->filename + " not found");
    }
}