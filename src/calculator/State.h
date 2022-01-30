/*************************************************************************
                      State  -  Interface de la classe State
                             -------------------
*************************************************************************/

//---------- Interface de la classe <State> (fichier State.h) et des classes Etats issues de la classe  ----------------
#pragma once

#ifndef CALCULATORCOMPILER_STATE_H
#define CALCULATORCOMPILER_STATE_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include "Automaton.h"
//------------------------------------------------------------------ Types


// Déclaration de la classe abstraite State
class State {

//----------------------------------------------------------------- PUBLIC
public:

//----------------------------------------------------- Méthodes publiques
    void print() const;

    virtual bool transition(Automaton &automate, Symbol *s) = 0;

//-------------------------------------------- Constructeurs - destructeur
    State ( const State & Etat );
    // Mode d'emploi : Constructeur de copie

    State(string name);
    // Mode d'emploi : Constructeur

    virtual ~State();
    // Mode d'emploi : Destructeur

//------------------------------------------------------------------ PROTEGE
protected:
    string name;
};


// Déclaration des différents états issus de la classe abstraite State

//--------------------------------------------- Définition de la classe E0
class E0 : public State {

public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automaton &automate, Symbol *s);

//-------------------------------------------- Constructeurs - destructeur
    E0();
};


//--------------------------------------------- Définition de la classe E1
class E1 : public State {

public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automaton &automate, Symbol *s) override;

//-------------------------------------------- Constructeurs - destructeur
    E1();
};


//--------------------------------------------- Définition de la classe E2
class E2 : public State {

public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automaton &automate, Symbol *s) override;

//-------------------------------------------- Constructeurs - destructeur
    E2();
};


//--------------------------------------------- Définition de la classe E3
class E3 : public State {

public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automaton &automate, Symbol *s) override;

//-------------------------------------------- Constructeurs - destructeur
    E3();
};


//--------------------------------------------- Définition de la classe E4
class E4 : public State {

public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automaton &automate, Symbol *s) override;

//-------------------------------------------- Constructeurs - destructeur
    E4();
};


//--------------------------------------------- Définition de la classe E5
class E5 : public State {

public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automaton &automate, Symbol *s) override;

//-------------------------------------------- Constructeurs - destructeur
    E5();
};


//--------------------------------------------- Définition de la classe E6
class E6 : public State {

public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automaton &automate, Symbol *s) override;

//-------------------------------------------- Constructeurs - destructeur
    E6();
};

//--------------------------------------------- Définition de la classe E7
class E7 : public State {

public:
//-------------------------------------------- Constructeurs - destructeur
    bool transition(Automaton &automate, Symbol *s) override;

//----------------------------------------------------- Méthodes publiques
    E7();
};


//--------------------------------------------- Définition de la classe E8
class E8 : public State {

public:
//-------------------------------------------- Constructeurs - destructeur
    bool transition(Automaton &automate, Symbol *s) override;

//----------------------------------------------------- Méthodes publiques
    E8();
};


//--------------------------------------------- Définition de la classe E9
class E9 : public State {

public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automaton &automate, Symbol *s) override;

//-------------------------------------------- Constructeurs - destructeur
    E9();
};


#endif //CALCULATORCOMPILER_STATE_H
