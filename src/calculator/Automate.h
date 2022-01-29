/*************************************************************************
               Automate.h  - Interface de la classe Automate
                         -------------------
*************************************************************************/


//---------- Interface de la classe <Automate> (fichier Automate.h) ----------------
#ifndef CALCULATORCOMPILER_AUTOMATE_H
#define CALCULATORCOMPILER_AUTOMATE_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <stack>
#include "Symbole.h"
#include "Lexer.h"
#include "Expression.h"

class Etat;

//------------------------------------------------------------------ Types
typedef stack<Etat*> StateStack;
typedef stack<Symbole*> SymbolStack;

//--------------------------------------- Définition de la classe Automate
class Automate {
public:
//----------------------------------------------------- Méthodes publiques
    void reduction(int n, Symbole *s);

    void decalage(Symbole *s, Etat *e);

    int run();
//-------------------------------------------- Constructeurs - destructeur
    Automate ( const Automate & Automate );
    // Mode d'emploi  : Constructeur de copie

    explicit Automate(string chaine);
    // Mode d'emploi : Constructeur

    virtual ~Automate ( );
    // Mode d'emploi : Destructeur

protected:
//----------------------------------------------------- Méthodes protégées
    static Expression* buildBinaryExpression( Entier * operand1,  Entier * operand2, const int & operatorId );
//----------------------------------------------------- Attributs protégés
    StateStack stateStack;
    SymbolStack symbolStack;
    Lexer* lexer;

};


#endif //CALCULATORCOMPILER_AUTOMATE_H