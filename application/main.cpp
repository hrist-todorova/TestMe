#include <iostream>
#include "src/UserInterface.h"
#include "src/Question.h"
#include "src/Answer.h"
#include "src/Test.h"
#include "src/File.h"
#include "vector"

using namespace std;

int main() {

    //UserInterface();

    string t = Question("[Q] This is question").getPrintString();
    vector<string> tags;
    vector<Answer> ans;

    tags.push_back("tag1");
    tags.push_back("beb");
    ans.push_back(Answer("This is correct", true));
    ans.push_back(Answer("This is correct", true));
    ans.push_back(Answer("This is incorrect", false));



    Question two = Question(t);
    two.setAnswers(ans);
    two.setTags(tags);
    cout << two.getPrintString();

    return 0;
}