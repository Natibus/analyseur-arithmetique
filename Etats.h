//
// Created by nathan on 20/02/18.
//

#ifndef TP_GRAML_2_ETATS_H
#define TP_GRAML_2_ETATS_H


#include "Etat.h"

class E0 : public Etat {
public:
    E0(string nom) : Etat(nom) {}

    E0();

    bool transition(Automate &automate, Symbole *s);
};

class E1 : public Etat {
public:
    E1(string nom) : Etat(nom) {}

    E1();

    bool transition(Automate &automate, Symbole *s);
};

class E2 : public Etat {
public:
    E2(string nom) : Etat(nom) {}

    E2();

    bool transition(Automate &automate, Symbole *s);
};

class E3 : public Etat {
public:
    E3(string nom) : Etat(nom) {}

    E3();

    bool transition(Automate &automate, Symbole *s);
};

class E4 : public Etat {
public:
    E4(string nom) : Etat(nom) {}

    E4();

    bool transition(Automate &automate, Symbole *s);
};

class E5 : public Etat {
public:
    E5(string nom) : Etat(nom) {}

    E5();

    bool transition(Automate &automate, Symbole *s);
};

class E6 : public Etat {
public:
    E6(string nom) : Etat(nom) {}

    E6();

    bool transition(Automate &automate, Symbole *s);
};

class E7 : public Etat {
public:
    E7(string nom) : Etat(nom) {}

    E7();

    bool transition(Automate &automate, Symbole *s);
};

class E8 : public Etat {
public:
    E8(string nom) : Etat(nom) {}

    E8();

    bool transition(Automate &automate, Symbole *s);
};

class E9 : public Etat {
public:
    E9(string nom) : Etat(nom) {}

    E9();

    bool transition(Automate &automate, Symbole *s);
};


#endif //TP_GRAML_2_ETATS_H
