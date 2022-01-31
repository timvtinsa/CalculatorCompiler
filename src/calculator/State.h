/*************************************************************************
                             State  -  Interface
                             -------------------
*************************************************************************/

//--- Interface of the class <State> and its descendants (file State.h) --
#pragma once

#ifndef CALCULATORCOMPILER_STATE_H
#define CALCULATORCOMPILER_STATE_H

//--------------------------------------------------- Interfaces used
using namespace std;
#include <string>
#include "Automaton.h"
//------------------------------------------------------------------ Types


// Déclaration de la classe abstraite State
class State {

//----------------------------------------------------------------- PUBLIC
public:

//--------------------------------------------------------- Public methods
    void print() const;
    // This method allows to displays the name of the state which call the method.

    virtual bool transition(Automaton &automate, Symbol *s) = 0;
    // This pure virtual method is redefined by all the states of the automaton
    // and allows to realize the transition from the state that call the method
    // to another state of the automaton with the symbol s.

//---------------------------------------------- Constructors & Destructor
    State ( const State & Etat );
    // Copy Constructor

    State(string name);
    // Constructor

    virtual ~State();
    // Destructor

//---------------------------------------------------------------- PROTEGE
protected:
    string name;
};


//------ Declaration of the different states from the abstract class State

//--------------------------------------------- Definition of the class E0
class E0 : public State {

public:
//--------------------------------------------------------- Public methods
    bool transition(Automaton &automate, Symbol *s);

//---------------------------------------------- Constructors & Destructor
    E0();
};


//--------------------------------------------- Definition of the class E1
class E1 : public State {

public:
//--------------------------------------------------------- Public methods
    bool transition(Automaton &automate, Symbol *s) override;

//---------------------------------------------- Constructors & Destructor
    E1();
};


//--------------------------------------------- Definition of the class E2
class E2 : public State {

public:
//--------------------------------------------------------- Public methods
    bool transition(Automaton &automate, Symbol *s) override;

//---------------------------------------------- Constructors & Destructor
    E2();
};


//--------------------------------------------- Definition of the class E3
class E3 : public State {

public:
//--------------------------------------------------------- Public methods
    bool transition(Automaton &automate, Symbol *s) override;

//---------------------------------------------- Constructors & Destructor
    E3();
};


//--------------------------------------------- Definition of the class E4
class E4 : public State {

public:
//--------------------------------------------------------- Public methods
    bool transition(Automaton &automate, Symbol *s) override;

//---------------------------------------------- Constructors & Destructor
    E4();
};


//--------------------------------------------- Definition of the class E5
class E5 : public State {

public:
//--------------------------------------------------------- Public methods
    bool transition(Automaton &automate, Symbol *s) override;

//---------------------------------------------- Constructors & Destructor
    E5();
};


//--------------------------------------------- Definition of the class E6
class E6 : public State {

public:
//--------------------------------------------------------- Public methods
    bool transition(Automaton &automate, Symbol *s) override;

//---------------------------------------------- Constructors & Destructor
    E6();
};

//--------------------------------------------- Definition of the class E7
class E7 : public State {

public:
//--------------------------------------------------------- Public methods
    bool transition(Automaton &automate, Symbol *s) override;

//---------------------------------------------- Constructors & Destructor
    E7();
};


//--------------------------------------------- Definition of the class E8
class E8 : public State {

public:
//---------------------------------------------- Constructors & Destructor
    bool transition(Automaton &automate, Symbol *s) override;

//--------------------------------------------------------- Public methods
    E8();
};


//--------------------------------------------- Definition of the class E9
class E9 : public State {

public:
//--------------------------------------------------------- Public methods
    bool transition(Automaton &automate, Symbol *s) override;

//---------------------------------------------- Constructors & Destructor
    E9();
};


#endif //CALCULATORCOMPILER_STATE_H
