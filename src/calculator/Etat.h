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

//--------------------------------------------- Définition de la classe E0
class E0 : public Etat {

public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automate &automate, Symbole *s);

//-------------------------------------------- Constructeurs - destructeur
    E0();
};


//--------------------------------------------- Définition de la classe E1
class E1 : public Etat {

public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automate &automate, Symbole *s) override;

//-------------------------------------------- Constructeurs - destructeur
    E1();
};


//--------------------------------------------- Définition de la classe E2
class E2 : public Etat {

public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automate &automate, Symbole *s) override;

//-------------------------------------------- Constructeurs - destructeur
    E2();
};


//--------------------------------------------- Définition de la classe E3
class E3 : public Etat {

public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automate &automate, Symbole *s) override;

//-------------------------------------------- Constructeurs - destructeur
    E3();
};


//--------------------------------------------- Définition de la classe E4
class E4 : public Etat {

public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automate &automate, Symbole *s) override;

//-------------------------------------------- Constructeurs - destructeur
    E4();
};


//--------------------------------------------- Définition de la classe E5
class E5 : public Etat {

public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automate &automate, Symbole *s) override;

//-------------------------------------------- Constructeurs - destructeur
    E5();
};


//--------------------------------------------- Définition de la classe E6
class E6 : public Etat {

public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automate &automate, Symbole *s) override;

//-------------------------------------------- Constructeurs - destructeur
    E6();
};

//--------------------------------------------- Définition de la classe E7
class E7 : public Etat {

public:
//-------------------------------------------- Constructeurs - destructeur
    bool transition(Automate &automate, Symbole *s) override;

//----------------------------------------------------- Méthodes publiques
    E7();
};


//--------------------------------------------- Définition de la classe E8
class E8 : public Etat {

public:
//-------------------------------------------- Constructeurs - destructeur
    bool transition(Automate &automate, Symbole *s) override;

//----------------------------------------------------- Méthodes publiques
    E8();
};


//--------------------------------------------- Définition de la classe E9
class E9 : public Etat {

public:
//----------------------------------------------------- Méthodes publiques
    bool transition(Automate &automate, Symbole *s) override;

//-------------------------------------------- Constructeurs - destructeur
    E9();
};


#endif //CALCULATORCOMPILER_ETAT_H
