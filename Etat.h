//
// Created by nathan on 20/02/18.
//

#ifndef TP_GRAML_2_ETAT_H
#define TP_GRAML_2_ETAT_H

#include <string>
#include "Automate.h"

using namespace std;

class Automate;

class Etat {
public:
    Etat(string nom);

    Etat();

    virtual ~Etat();

    void afficher() const;

    string getNom() const;

    virtual bool transition(Automate &automate, Symbole *s) = 0;

protected:
    string nom;
};


#endif //TP_GRAML_2_ETAT_H
