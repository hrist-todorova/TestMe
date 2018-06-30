//
// Created by Hristina Todorova on 6/25/18.
//

#include <fstream>
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
 * Read the contents of the file and create and return a vector of questions.
 */
vector<Question> File::extractQuestions() {
    vector<Question> questions;
    ifstream fileStream(this->filename);
    if(fileStream.is_open()) {
        string file_line;

        //Types of possible prefixes of each line
        string question_prefix = "[Q] ";
        string tags_prefix = "[T] ";
        string positive_answer_prefix = "[+] ";
        string negative_answer_prefix = "[-] ";

        while(getline(fileStream, file_line)) {
            //Check the prefix of file_line and either add a new question or change last one
            //std::mismatch returns the first mismatching pair of elements from two ranges

            //question
            auto question_mismatch = mismatch(question_prefix.begin(), question_prefix.end(), file_line.begin());
            if(question_mismatch.first == question_prefix.end()) {
                questions.push_back(Question(file_line));
                continue;
            }
            //tags
            auto tags_mismatch = mismatch(tags_prefix.begin(), tags_prefix.end(), file_line.begin());
            if(tags_mismatch.first == tags_prefix.end()) {
                questions[questions.size() - 1].setTags(StringInterpreter().stringToTags(file_line));
                continue;
            }
            //positive_answer or negative_answer
            auto positive_answer_mismatch = mismatch(positive_answer_prefix.begin(), positive_answer_prefix.end(), file_line.begin());
            auto negative_answer_mismatch = mismatch(negative_answer_prefix.begin(), negative_answer_prefix.end(), file_line.begin());
            if(positive_answer_mismatch.first == positive_answer_prefix.end() || negative_answer_mismatch.first == negative_answer_prefix.end()) {
                questions[questions.size() - 1].addAnswer(StringInterpreter().stringToAnswer(file_line));
                continue;
            }
        }
    } else {
        throw invalid_argument("File " + this->filename + " not found");
    }
    return questions;
}

/*
 * Append text to the file. If the file doesn't exist it is created.
 */
void File::write(string text) {
    ofstream fileStream;
    fileStream.open(this->filename, ofstream::app);
    if(fileStream.is_open()) {
        fileStream << text;
        fileStream.close();
    } else {
        throw invalid_argument("Error opening file " + this->filename);
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
        throw invalid_argument("Error opening file " + this->filename);
    }
}