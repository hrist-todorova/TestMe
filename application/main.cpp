#include <iostream>
#include "src/UserInterface.h"
#include "src/Question.h"
#include "src/Answer.h"
#include "vector"

using namespace std;

int main() {

    //UserInterface();

    vector<string> t;
    t.push_back("lala");
    t.push_back("data");
    t.push_back("lana del rey");
    string name = "Question";

    vector<Answer> la;
    la.push_back(Answer("pate", true));
    la.push_back(Answer("papa", false));
    la.push_back(Answer("he", true));

    Question ta = Question(name, t, la);

    cout << ta.getPrintString();

    return 0;
}