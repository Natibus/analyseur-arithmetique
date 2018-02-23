//
// Created by nathan on 20/02/18.
//

#include <iostream>
#include "Automate.h"
#include "Etats.h"
#include "Util.h"

void Automate::lecture() {
    Symbole *s;
    E0 *etat = new E0();
    pileEtats.push(etat);
    bool fini = false;
    int iterations = 1;
    while (!fini) {
        s = lex.Consulter();
        cout << "Symbole rencontré : ";
        s->Affiche();
        cout << endl;
        fini = pileEtats.top()->transition(*this, s);
        Util::printSymboles(pileSymboles);
        Util::printEtats(pileEtats);
        cout << "_______________________________" << endl;
        iterations++;
    }

}

Automate::Automate(string chaine) : lex(chaine) {}

void Automate::decalage(Symbole *s, Etat *e, bool avance) {
    cout << "décalage vers " + e->getNom() << endl;
    if (avance) { pileSymboles.push(s); }
    pileEtats.push(e);
    if (avance) { lex.Avancer(); }
}

void Automate::reduction(int n, Symbole *s) {
    cout << "reduction de la regle " << n << endl;
    switch (n) {
        case 2:
            depilerEtatsEtSymboles(3);
            pileSymboles.push(new Symbole(EXPR));
            transitionPostReduction(s);
            break;
        case 3:
            depilerEtatsEtSymboles(3);
            pileSymboles.push(new Symbole(EXPR));
            transitionPostReduction(s);
            break;
        case 4:
            depilerEtatsEtSymboles(3);
            pileSymboles.push(new Symbole(EXPR));
            transitionPostReduction(s);
            break;
        case 5:
            depilerEtatsEtSymboles(1);
            pileSymboles.push(new Symbole(EXPR));
            transitionPostReduction(s);
            break;
    }
}

void Automate::transitionPostReduction(Symbole *s) {
    string etatSommetPile = pileEtats.top()->getNom();
    if (etatSommetPile == "E0") {
        this->decalage(s, new E1(), false);
    } else if (etatSommetPile == "E2") {
        this->decalage(s, new E6(), false);
    } else if (etatSommetPile == "E4") {
        this->decalage(s, new E7(), false);
    } else if (etatSommetPile == "E5") {
        this->decalage(s, new E8(), false);
    }
}

void Automate::depilerEtatsEtSymboles(int n) {
    for (int i = 0; i < n; i++) {
        pileSymboles.pop();
        pileEtats.pop();
    }
}
