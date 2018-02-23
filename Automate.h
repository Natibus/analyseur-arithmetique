//
// Created by nathan on 20/02/18.
//

#ifndef TP_GRAML_2_AUTOMATE_H
#define TP_GRAML_2_AUTOMATE_H

#include <string>
#include <stack>
#include "lexer.h"
#include "Etat.h"

using namespace std;

class Etat;

class Automate {

public:
    void lecture();

    Automate(string chaine);

    void decalage(Symbole *s, Etat *e, bool avance = true);

    void reduction(int n, Symbole *s);

    void transitionPostReduction(Symbole *s);

    void depilerEtatsEtSymboles(int n);

protected:
    Lexer lex;
    stack<Symbole *> pileSymboles;
    stack<Etat *> pileEtats;
};


#endif //TP_GRAML_2_AUTOMATE_H
