#include <iostream>
#include "Automate.h"

using namespace std;

int main() {
    string chaine("(1+2)*10");

    Automate a(chaine);
    a.lecture();
    stack<Symbole *> pile;

    return 0;
}

