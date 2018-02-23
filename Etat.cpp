//
// Created by nathan on 20/02/18.
//

#include <iostream>
#include "Etat.h"

Etat::Etat() {}
Etat::Etat(string nom) : nom(nom) {}

Etat::~Etat() {}

void Etat::afficher() const {
    cout << "Etat" + nom << endl;
}
string Etat::getNom() const {
    return nom;
}
