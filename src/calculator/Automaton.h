/*************************************************************************
               Automaton.h  - Interface de la classe Automaton
                         -------------------
*************************************************************************/


//---------- Interface de la classe <Automaton> (fichier Automaton.h) ----------------
#ifndef CALCULATORCOMPILER_AUTOMATON_H
#define CALCULATORCOMPILER_AUTOMATON_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <stack>
#include "Symbol.h"
#include "Lexer.h"
#include "Expression.h"

class State;

//------------------------------------------------------------------ Types
typedef stack<State*> StateStack;
typedef stack<Symbol*> SymbolStack;

//--------------------------------------- Définition de la classe Automaton
class Automaton {
public:
//----------------------------------------------------- Méthodes publiques
    void reduction(int n, Symbol *s);

    void decalage(Symbol *s, State *e);

    int run();
//-------------------------------------------- Constructeurs - destructeur
    Automaton ( const Automaton & Automate );
    // Mode d'emploi  : Constructeur de copie

    explicit Automaton(string chaine);
    // Mode d'emploi : Constructeur

    virtual ~Automaton ( );
    // Mode d'emploi : Destructeur

protected:
//----------------------------------------------------- Méthodes protégées
    static Expression* buildBinaryExpression( Entier * operand1,  Entier * operand2, const int & operatorId );
//----------------------------------------------------- Attributs protégés
    StateStack stateStack;
    SymbolStack symbolStack;
    Lexer* lexer;

};


#endif //CALCULATORCOMPILER_AUTOMATON_H
