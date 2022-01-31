/*************************************************************************
                        Symbol.h  - Interface
                         -------------------
*************************************************************************/

//---------- Interface of the class <Automaton> (file Automaton.h) -------
#pragma once

//-------------------------------------------------------- Interfaces used
using namespace std;
#include <string>

//-------------------------------------------------------------- Constants
const string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR"};

//------------------------------------------------------------------ Types
enum Identificateurs {
    OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR
};

//----------------------------------------- Definition of the class Symbol
class Symbol {
public:
//--------------------------------------------------------- Public methods
    virtual void Display();
    // This method allows to Display a Symbole

    virtual int Eval();

    bool IsTerminal() const { return terminal; }
    // This method allows to know if the symbol which call the method is
    // terminal. It is important to know if the symbol is a terminalor not
    // in order to trigger the reading cursor during a shift operation.

//---------------------------------------------------- Operator overloaded
    operator int() const { return ident; }
    // Overloading the operator int() allows to cast implicitly a symbol
    // into an integer, to get its identifier. This is convenient for the
    // implementation of the transition methods.

//---------------------------------------------- Constructors & Destructor
    Symbol (const Symbol & aSymbole );
    // Copy Constructor

    Symbol(int i, bool t);
    // Constructor

    virtual ~Symbol();
    // Destructor

protected:
//--------------------------------------------------- Protected attributes
    int ident;
    bool terminal;
};


//---------------------------------- Definition of the class SymboleSimple
class EntierSimple : public Symbol {
public:
//--------------------------------------------------------- Public methods
    virtual int Eval();

//---------------------------------------------- Constructors & Destructor
    EntierSimple (const EntierSimple & aEntierSimple );
    // Copy Constructor

    explicit EntierSimple(int val);
    // Constructor

    ~EntierSimple() override;
    // Destructor

protected:
//--------------------------------------------------- Protected attributes
    int valeur;
};
