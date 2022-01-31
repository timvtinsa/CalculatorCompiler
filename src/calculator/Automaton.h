/*************************************************************************
                       Automaton.h  - Interface
                         -------------------
*************************************************************************/


//------- Interface of the class <Automaton> (file Automaton.h) ----------
#ifndef CALCULATORCOMPILER_AUTOMATON_H
#define CALCULATORCOMPILER_AUTOMATON_H

//-------------------------------------------------------- Interfaces used
using namespace std;
#include <stack>
#include "Symbol.h"
#include "Lexer.h"
#include "Expression.h"

class State;

//------------------------------------------------------------------ Types
typedef stack<State*> StateStack;
typedef stack<Symbol*> SymbolStack;

//-------------------------------------- Definition of the class Automaton
class Automaton {
public:
//--------------------------------------------------------- Public methods
    void reduction(int n, Symbol *s);
    // This method allows the automaton to do a "reduction" of n symbols
    // from the symbol s.

    void shift(Symbol *s, State *e);
    // This method allows the automaton to do a "shift" of a symbole s
    // from the state e.

    int run();
//---------------------------------------------- Constructors & Destructor
    Automaton ( const Automaton & Automate );
    // Copy Constructor

    explicit Automaton(string chaine);
    // Constructor

    virtual ~Automaton ( );
    // Destructor

protected:
//------------------------------------------------------ Protected methods
    static Expression* buildBinaryExpression( Entier * operand1,  Entier * operand2, const int & operatorId );
//--------------------------------------------------- Protected attributes
    StateStack stateStack;
    SymbolStack symbolStack;
    Lexer* lexer;

};

#endif //CALCULATORCOMPILER_AUTOMATON_H
