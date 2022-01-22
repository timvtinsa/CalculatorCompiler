/*************************************************************************
               Symbole.h  - Interface de la classe Symbole
                         -------------------
*************************************************************************/

//---------- Interface de la classe <Automate> (fichier Automate.h) ----------------
#pragma once

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>

//------------------------------------------------------------- Constantes
const string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR"};

//------------------------------------------------------------------ Types
enum Identificateurs {
    OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR
};

//---------------------------------------- Définition de la classe Symbole
class Symbole {
public:
//----------------------------------------------------- Méthodes publiques
    virtual void Affiche();

    bool isTerminal() const { return terminal; }

//------------------------------------------------- Surcharge d'opérateurs
    operator int() const { return ident; }

//-------------------------------------------- Constructeurs - destructeur
    Symbole (const Symbole & aSymbole );
    // Mode d'emploi  : Constructeur de copie

    Symbole(int i, bool t) : ident(i), terminal(t)
    // Mode d'emploi : Constructeur
    {
        #ifdef MAP
            cout << "Appel au constructeur de <Symbole>" << endl;
        #endif
    };

    virtual ~Symbole();
    // Mode d'emploi : Destructeur

protected:
//----------------------------------------------------- Attributs protégés
    int ident;
    bool terminal;
};


//---------------------------------------- Définition de la classe Entier
class Entier : public Symbole {
public:
//-------------------------------------------- Constructeurs - destructeur
    Entier(const Symbole &sSymbole, const Entier &aEntier);
    // Mode d'emploi  : Constructeur de copie

    explicit Entier(int val) : Symbole(INT, false), valeur(val)
    {
        #ifdef MAP
                cout << "Appel au constructeur de <Entier>" << endl;
        #endif
    }
    // Mode d'emploi  : Constructeur

    virtual ~Entier();
    // Mode d'emploi : Destructeur

//----------------------------------------------------- Méthodes publiques
    virtual void Affiche();

protected:
//----------------------------------------------------- Attributs protégés
    int valeur;
};
