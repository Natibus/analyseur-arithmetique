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
    while (!fini && iterations <= 20) {
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
    cout << "Valeur de l'expression : " << pileSymboles.top()->GetVal() << endl;

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
    int a,b;
    switch (n) {
        case 2:
            a = pileSymboles.top()->GetVal();
            depilerEtatsEtSymboles(2);
            b = pileSymboles.top()->GetVal();
            depilerEtatsEtSymboles(1);
            pileSymboles.push(new Expr(a+b));
            transitionPostReduction(s);
            break;
        case 3:
            a = pileSymboles.top()->GetVal();
            depilerEtatsEtSymboles(2);
            b = pileSymboles.top()->GetVal();
            depilerEtatsEtSymboles(1);
            pileSymboles.push(new Expr(a*b));
            transitionPostReduction(s);
            break;
        case 4:
            depilerEtatsEtSymboles(1);
            a = pileSymboles.top()->GetVal();
            depilerEtatsEtSymboles(2);
            pileSymboles.push(new Expr(a));
            transitionPostReduction(s);
            break;
        case 5:
            Symbole *E = pileSymboles.top();
            depilerEtatsEtSymboles(1);
            pileSymboles.push(new Expr(E->GetVal()));
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
