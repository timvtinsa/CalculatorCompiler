//
// Created by tverstraet on 21/01/2022.
//

#include <string>
#include <iostream>
#include "State.h"
#include "Symbol.h"

State::State(string name) {
    this->name = name;
}

void State::print() const {
    cout << "State : " << name << "; " << endl;
}

State::~State() {

}

State::State(const State &Etat) {

}

E0::E0() : State("E0") { }

bool E0::transition(Automaton &automate, Symbol *s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3());
            break;
        case OPENPAR:
            automate.decalage(s, new E2());
            break;
        case EXPR:
            automate.decalage(s, new E1());
            break;
        default:
            delete (s);
            automate.decalage(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

E1::E1() : State("E1") { }

bool E1::transition(Automaton &automate, Symbol *s) {
    switch (*s) {
        case PLUS:
            automate.decalage(s, new E4());
            break;
        case MULT:
            automate.decalage(s, new E5());
            break;
        case FIN:
            delete (s);
            return false;
        default:
            delete (s);
            automate.decalage(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

E2::E2() : State("E2") { }

bool E2::transition(Automaton &automate, Symbol *s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3());
            break;
        case OPENPAR:
            automate.decalage(s, new E2());
            break;
        case EXPR:
            automate.decalage(s, new E6());
            break;
        default:
            delete (s);
            automate.decalage(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

E3::E3() : State("E3") { }

bool E3::transition(Automaton &automate, Symbol *s) {
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            automate.reduction(1, s);
            break;
        default:
            delete (s);
            automate.decalage(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

E4::E4() : State("E4") { }

bool E4::transition(Automaton &automate, Symbol *s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3());
            break;
        case OPENPAR:
            automate.decalage(s, new E2());
            break;
        case EXPR:
            automate.decalage(s, new E7());
            break;
        default:
            delete (s);
            automate.decalage(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

E5::E5() : State("E5") { }

bool E5::transition(Automaton &automate, Symbol *s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3());
            break;
        case OPENPAR:
            automate.decalage(s, new E2());
            break;
        case EXPR:
            automate.decalage(s, new E8());
            break;
        default:
            delete (s);
            automate.decalage(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

E6::E6() : State("E6") { }

bool E6::transition(Automaton &automate, Symbol *s) {
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
        default:
            delete (s);
            automate.decalage(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

E7::E7() : State("E7") { }

bool E7::transition(Automaton &automate, Symbol *s) {
    switch (*s) {
        case PLUS:
        case CLOSEPAR:
        case FIN:
            automate.reduction(3, s);
            break;
        case MULT:
            automate.decalage(s, new E5());
            break;
        default:
            delete (s);
            automate.decalage(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

E8::E8() : State("E8") { }

bool E8::transition(Automaton &automate, Symbol *s) {
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            automate.reduction(3, s);
            break;
        default:
            delete (s);
            automate.decalage(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

E9::E9() : State("E9") { }

bool E9::transition(Automaton &automate, Symbol *s) {
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            automate.reduction(3, s);
            break;
        default:
            delete (s);
            automate.decalage(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

