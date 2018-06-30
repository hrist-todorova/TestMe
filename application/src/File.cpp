//
// Created by Hristina Todorova on 6/25/18.
//

#include <fstream>
#include "iostream"
#include "File.h"
#include "StringInterpreter.h"

using namespace std;

/*
 * Constructor for class File.
 * It accepts one argument - the name of the file.
 */
File::File(string _filename) {
    this->filename = _filename;
}

/*
 * Copy assignment operator for class File.
 */
File& File::operator=(const File &other) {
    if(this == &other)
        return* this;
    this->filename = other.filename;
    return *this;
}

/*
 * This should be in another class.
 */
vector<Question> File::extractQuestions() {
    vector<Question> questions;
    ifstream fileStream(this->filename);
    if(fileStream.is_open()) {
        string temp;

        string question_prefix = "[Q] ";
        string tags_prefix = "[T] ";
        string positive_answer_prefix = "[+] ";
        string negative_answer_prefix = "[-] ";

        while(std::getline(fileStream, temp)) {
            //question
            auto res = std::mismatch(question_prefix.begin(), question_prefix.end(), temp.begin());
            if(res.first == question_prefix.end()) {
                Question q = Question(temp);
                questions.push_back(q);
                continue;
            }
            //tags
            res = std::mismatch(tags_prefix.begin(), tags_prefix.end(), temp.begin());
            if(res.first == tags_prefix.end()) {
                questions[questions.size() - 1].setTags(StringInterpreter().stringToTags(temp));
                continue;
            }
            //positive_answer or negative_answer
            auto positive_answer = std::mismatch(positive_answer_prefix.begin(), positive_answer_prefix.end(), temp.begin());
            auto negative_answer = std::mismatch(negative_answer_prefix.begin(), negative_answer_prefix.end(), temp.begin());
            if(positive_answer.first == positive_answer_prefix.end() || negative_answer.first == negative_answer_prefix.end()) {
                questions[questions.size() - 1].addAnswer(StringInterpreter().stringToAnswer(temp));
                continue;
            }
        }
    } else {
        throw invalid_argument("File " + this->filename + " not found");
    }
    return questions;
}

/*
 * Append argument to the file.
 */
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

/*
 * Delete the contents of the file.
 */
void File::truncate() {
    ofstream fileStream;
    fileStream.open(this->filename, ofstream::trunc);
    if(fileStream.is_open()) {
        fileStream.close();
    } else {
        throw invalid_argument("File " + this->filename + " not found");
    }
}