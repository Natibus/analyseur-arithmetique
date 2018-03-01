#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
    cout << Etiquettes[ident];
}

int Symbole::GetVal() {
    return -1;
}

void Entier::Affiche() {
    Symbole::Affiche();
    cout << "(" << valeur << ")";
}

int Entier::GetVal() {
    return valeur;
}

int Expr::GetVal() {
    return valeur;
}

