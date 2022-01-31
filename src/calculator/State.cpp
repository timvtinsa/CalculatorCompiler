/*************************************************************************
                        Automaton  -  Implementation
                             -------------------
*************************************************************************/



//-------------------------------------------------------- System include
#include <string>
#include <iostream>

//------------------------------------------------------- Personal include
#include "State.h"
#include "Symbol.h"

//---------- Implementation of the class <State> (file State.cpp) --------

//------------------------------------------------- State - Public methods
void State::print() const {
    cout << "State : " << name << "; " << endl;
}

//------------------------------------ State --- Constructors & Destructor
State::State(string name) {
    this->name = name;
}

State::~State() {

}

//---------- Implementation of the class <E0> (file State.cpp) -----------

//---------------------------------------------------- E0 - Public methods
bool E0::transition(Automaton &automate, Symbol *s) {
    switch (*s) {
        case INT:
            automate.shift(s, new E3());
            break;
        case OPENPAR:
            automate.shift(s, new E2());
            break;
        case EXPR:
            automate.shift(s, new E1());
            break;
        default:
            delete (s);
            automate.shift(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

//---------------------------------__---- E0 --- Constructors & Destructor
E0::E0() : State("E0") { }

//---------- Implementation of the class <E1> (file State.cpp) -----------

//---------------------------------------------------- E1 - Public methods
bool E1::transition(Automaton &automate, Symbol *s) {
    switch (*s) {
        case PLUS:
            automate.shift(s, new E4());
            break;
        case MULT:
            automate.shift(s, new E5());
            break;
        case FIN:
            delete (s);
            return false;
        default:
            delete (s);
            automate.shift(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

//--------------------------------------- E1 --- Constructors & Destructor
E1::E1() : State("E1") { }

//---------- Implementation of the class <E2> (file State.cpp) -----------

//---------------------------------------------------- E2 - Public methods
bool E2::transition(Automaton &automate, Symbol *s) {
    switch (*s) {
        case INT:
            automate.shift(s, new E3());
            break;
        case OPENPAR:
            automate.shift(s, new E2());
            break;
        case EXPR:
            automate.shift(s, new E6());
            break;
        default:
            delete (s);
            automate.shift(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

//--------------------------------------- E2 --- Constructors & Destructor
E2::E2() : State("E2") { }

//---------- Implementation of the class <E3> (file State.cpp) -----------

//---------------------------------------------------- E3 - Public methods
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
            automate.shift(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

//--------------------------------------- E3 --- Constructors & Destructor
E3::E3() : State("E3") { }

//---------- Implementation of the class <E4> (file State.cpp) -----------

//---------------------------------------------------- E4 - Public methods
bool E4::transition(Automaton &automate, Symbol *s) {
    switch (*s) {
        case INT:
            automate.shift(s, new E3());
            break;
        case OPENPAR:
            automate.shift(s, new E2());
            break;
        case EXPR:
            automate.shift(s, new E7());
            break;
        default:
            delete (s);
            automate.shift(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

//--------------------------------------- E4 --- Constructors & Destructor
E4::E4() : State("E4") { }

//---------- Implementation of the class <E5> (file State.cpp) -----------

//---------------------------------------------------- E5 - Public methods
bool E5::transition(Automaton &automate, Symbol *s) {
    switch (*s) {
        case INT:
            automate.shift(s, new E3());
            break;
        case OPENPAR:
            automate.shift(s, new E2());
            break;
        case EXPR:
            automate.shift(s, new E8());
            break;
        default:
            delete (s);
            automate.shift(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

//--------------------------------------- E5 --- Constructors & Destructor
E5::E5() : State("E5") { }

//---------- Implementation of the class <E6> (file State.cpp) -----------

//---------------------------------------------------- E6 - Public methods
bool E6::transition(Automaton &automate, Symbol *s) {
    switch (*s) {
        case PLUS:
            automate.shift(s, new E4());
            break;
        case MULT:
            automate.shift(s, new E5());
            break;
        case CLOSEPAR:
            automate.shift(s, new E9());
            break;
        default:
            delete (s);
            automate.shift(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

//--------------------------------------- E6 --- Constructors & Destructor
E6::E6() : State("E6") { }

//---------- Implementation of the class <E7> (file State.cpp) -----------

//---------------------------------------------------- E7 - Public methods
bool E7::transition(Automaton &automate, Symbol *s) {
    switch (*s) {
        case PLUS:
        case CLOSEPAR:
        case FIN:
            automate.reduction(3, s);
            break;
        case MULT:
            automate.shift(s, new E5());
            break;
        default:
            delete (s);
            automate.shift(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

//--------------------------------------- E7 --- Constructors & Destructor
E7::E7() : State("E7") { }

//---------- Implementation of the class <E8> (file State.cpp) -----------

//---------------------------------------------------- E8 - Public methods
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
            automate.shift(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

//--------------------------------------- E8 --- Constructors & Destructor
E8::E8() : State("E8") { }

//---------- Implementation of the class <E9> (file State.cpp) -----------

//---------------------------------------------------- E9 - Public methods
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
            automate.shift(new Symbol(ERREUR, true), nullptr);
            return false;
    }
    return true;
}

//--------------------------------------- E9 --- Constructors & Destructor
E9::E9() : State("E9") { }
