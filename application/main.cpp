#include <iostream>
#include "src/UserInterface.h"
#include "src/Question.h"
#include "vector"

using namespace std;

int main() {

    //UserInterface();

    vector<string> t;
    t.push_back("lala");
    t.push_back("data");
    t.push_back("lana del rey");
    string name = "Q";

    Question ta = Question(name, t);

    cout << ta.hasTag("katy perry") << endl;
    cout << ta.hasTag("lana del rey") << endl;

    return 0;
}