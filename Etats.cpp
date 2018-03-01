//
// Created by nathan on 20/02/18.
//
#include <iostream>
#include "Etats.h"

// ------ constructeurs --------

E0::E0() { this->nom = "E0"; }
E1::E1() { this->nom = "E1"; }
E2::E2() { this->nom = "E2"; }
E3::E3() { this->nom = "E3"; }
E4::E4() { this->nom = "E4"; }
E5::E5() { this->nom = "E5"; }
E6::E6() { this->nom = "E6"; }
E7::E7() { this->nom = "E7"; }
E8::E8() { this->nom = "E8"; }
E9::E9() { this->nom = "E9"; }

// ------ transitions -------

bool E0::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3());
            break;
        case OPENPAR:
            automate.decalage(s, new E2());
            break;
    }
    return false;
}

bool E1::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS:
            automate.decalage(s, new E4());
            break;
        case MULT:
            automate.decalage(s, new E5());
            break;
        case FIN:
            return true;
    }
    return false;
}

bool E2::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3());
            break;
        case OPENPAR:
            automate.decalage(s, new E2());
            break;
    }
    return false;
}

bool E3::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS:
            automate.reduction(5, s);
            break;
        case MULT:
            automate.reduction(5, s);
            break;
        case CLOSEPAR:
            automate.reduction(5, s);
            break;
        case FIN:
            automate.reduction(5, s);
            break;
    }
    return false;
}

bool E4::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3());
            break;
        case OPENPAR:
            automate.decalage(s, new E2());
            break;
    }
    return false;
}

bool E5::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3());
            break;
        case OPENPAR:
            automate.decalage(s, new E2());
            break;
    }
    return false;
}

bool E6::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS:
            automate.decalage(s, new E4());
            break;
        case MULT:
            automate.decalage(s, new E5());
            break;
        case CLOSEPAR:
            automate.decalage(s, new E9());
            break;
    }
    return false;
}

bool E7::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS:
            automate.reduction(2, s);
            break;
        case MULT:
            automate.decalage(s, new E5());
            break;
        case CLOSEPAR:
            automate.reduction(2, s);
            break;
        case FIN:
            automate.reduction(2, s);
            break;
    }
    return false;
}

bool E8::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS:
            automate.reduction(3, s);
            break;
        case MULT:
            automate.reduction(3, s);
            break;
        case CLOSEPAR:
            automate.reduction(3, s);
            break;
        case FIN:
            automate.reduction(3, s);
            break;
    }
    return false;
}

bool E9::transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS:
            automate.reduction(4, s);
            break;
        case MULT:
            automate.reduction(4, s);
            break;
        case OPENPAR:
            automate.reduction(4, s);
            break;
        case FIN:
            automate.reduction(4, s);
            break;
    }
    return false;
}