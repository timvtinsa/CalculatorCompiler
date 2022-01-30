/*************************************************************************
               Symbol.h  - Interface de la classe Symbol
                         -------------------
*************************************************************************/

//---------- Interface de la classe <Automaton> (fichier Automaton.h) ----------------
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

//---------------------------------------- Définition de la classe Symbol
class Symbol {
public:
//----------------------------------------------------- Méthodes publiques
    virtual void Affiche();

    virtual int eval();

    bool isTerminal() const { return terminal; }

//------------------------------------------------- Surcharge d'opérateurs
    operator int() const { return ident; }

//-------------------------------------------- Constructeurs - destructeur
    Symbol (const Symbol & aSymbole );
    // Mode d'emploi : Constructeur de copie

    Symbol(int i, bool t);
    // Mode d'emploi : Constructeur

    virtual ~Symbol();
    // Mode d'emploi : Destructeur

protected:
//----------------------------------------------------- Attributs protégés
    int ident;
    bool terminal;
};


//---------------------------------- Définition de la classe SymboleSimple
class EntierSimple : public Symbol {
public:
//----------------------------------------------------- Méthodes publiques
    virtual int eval();

//-------------------------------------------- Constructeurs - destructeur
    EntierSimple (const EntierSimple & aEntierSimple );
    // Mode d'emploi  : Constructeur de copie

    explicit EntierSimple(int val);

    ~EntierSimple() override;
    // Mode d'emploi : Destructeur

protected:
//----------------------------------------------------- Attributs protégés
    int valeur;
};
