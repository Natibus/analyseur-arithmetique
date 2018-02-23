//
// Created by nathan on 20/02/18.
//

#ifndef TP_GRAML_2_UTIL_H
#define TP_GRAML_2_UTIL_H


#include <stack>
#include "symbole.h"
#include "Etat.h"

using namespace std;

class Util {
public:
    static void printSymboles(stack<Symbole *> pileSymboles);

    static void printEtats(stack<Etat *> stack);
};


#endif //TP_GRAML_2_UTIL_H
