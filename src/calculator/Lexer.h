/*************************************************************************
               Lexer.h  - Interface de la classe Lexer
                         -------------------
*************************************************************************/

//---------- Interface de la classe <Lexer> (fichier Lexer.h) ----------------
#pragma once

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include <utility>
#include "Symbol.h"

//------------------------------------------ Définition de la classe Lexer
class Lexer {

public:

//-------------------------------------------- Constructeurs - destructeur
    Lexer(const Lexer &aLexer);

    explicit Lexer(string s) : flux(move(s)), tete(0), tampon(nullptr) {
        #ifdef MAP
                cout << "Appel au constructeur de <Lexer>" << endl;
        #endif
    }

    void putSymbol(Symbol *s);

    virtual ~Lexer();

//----------------------------------------------------- Méthodes publiques

    Symbol *Consulter();

    void Avancer();

protected:
    string flux;
    long unsigned int tete;
    Symbol *tampon;
};
