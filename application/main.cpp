#include <iostream>
#include "src/File.h"

using namespace std;

int main() {

    File("pate.txt").truncate();
    File("pate.txt").write("HELP");
    File("pate.txt").write("HELP");
    File("pate.txt").read();
    cout << "HERE" << endl;
    File("pate.txt").truncate();
    File("pate.txt").write("HELP");
    File("jaba.txt").read();


    return 0;
}