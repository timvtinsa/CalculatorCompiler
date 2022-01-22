/*************************************************************************
                      Etat  -  Interface de la classe Etat
                             -------------------
*************************************************************************/

//---------- Interface de la classe <Etat> (fichier Etat.h) et des classes Etats issues de la classe  ----------------
#pragma once

#ifndef CALCULATORCOMPILER_ETAT_H
#define CALCULATORCOMPILER_ETAT_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include "Automate.h"
//------------------------------------------------------------------ Types


// Déclaration de la classe abstraite Etat
class Etat {

//----------------------------------------------------------------- PUBLIC
public:

//----------------------------------------------------- Méthodes publiques
    void print() const;

    virtual bool transition(Automate &automate, Symbole *s) = 0;

//-------------------------------------------- Constructeurs - destructeur
    Etat ( const Etat & Etat );
    // Mode d'emploi : Constructeur de copie

    Etat(string name);
    // Mode d'emploi : Constructeur

    virtual ~Etat();
    // Mode d'emploi : Destructeur

//------------------------------------------------------------------ PROTEGE
protected:
    string name;
};


// Déclaration des différents états issus de la classe abstraite Etat

// Déclaration de la classe correspondant à l'état E0
class E0 : public Etat {

//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automate &automate, Symbole *s);

//-------------------------------------------- Constructeurs - destructeur
    E0();
};


// Déclaration de la classe correspondant à l'état E1
class E1 : public Etat {

public:
    E1();

    bool transition(Automate &automate, Symbole *s) override;
};

class E2 : public Etat {

public:

    E2();

    bool transition(Automate &automate, Symbole *s) override;
};

class E3 : public Etat {

public:

    E3();

    bool transition(Automate &automate, Symbole *s) override;
};

class E4 : public Etat {

public:

    E4();

    bool transition(Automate &automate, Symbole *s) override;
};

class E5 : public Etat {

public:

    E5();

    bool transition(Automate &automate, Symbole *s) override;
};

class E6 : public Etat {

public:

    E6();

    bool transition(Automate &automate, Symbole *s) override;
};

class E7 : public Etat {

public:

    E7();

    bool transition(Automate &automate, Symbole *s) override;
};

class E8 : public Etat {

public:

    E8();

    bool transition(Automate &automate, Symbole *s) override;
};

class E9 : public Etat {

public:

    E9();

    bool transition(Automate &automate, Symbole *s) override;
};


#endif //CALCULATORCOMPILER_ETAT_H
