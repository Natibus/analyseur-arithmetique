//
// Created by nathan on 20/02/18.
//

#include <iostream>
#include "Util.h"

void Util::printSymboles(stack<Symbole *> pileSymboles) {
    stack<Symbole *> copie = pileSymboles;
    cout << "pile des Symboles : [";
    Symbole * s = copie.top();
    std::cout << Etiquettes[*s];
    copie.pop();
    while(!copie.empty())
    {
        Symbole * s = copie.top();
        std::cout << "," << Etiquettes[*s];
        copie.pop();
    }
    cout << "]" << endl;
}

void Util::printEtats(stack<Etat *> pileEtats) {
    stack < Etat * > copie = pileEtats;
    cout << "pile des Etats : [";
    Etat * e = copie.top();
    std::cout << e->getNom();
    copie.pop();
    while(!copie.empty())
    {
        Etat * e = copie.top();
        std::cout << "," << e->getNom();
        copie.pop();
    }
    cout << "]" << endl;
}
