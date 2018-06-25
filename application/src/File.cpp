//
// Created by Hristina Todorova on 6/25/18.
//

#include <fstream>
#include "iostream"
#include "File.h"

using namespace std;

void File::read() {
    ifstream fileStream(this->filename);
    if(fileStream.is_open()) {
        string temp;
        while(std::getline(fileStream, temp)) {
            cout << temp;
        }
    } else {
        throw invalid_argument("File " + this->filename + " not found");
    }
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