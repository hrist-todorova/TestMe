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

        string question_prefix = "[Q] ";

        while(std::getline(fileStream, temp)) {
            auto res = std::mismatch(question_prefix.begin(), question_prefix.end(), temp.begin());
            if(res.first == question_prefix.end()) {
                Question q = Question(temp);
                questions.push_back(q);
            }
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