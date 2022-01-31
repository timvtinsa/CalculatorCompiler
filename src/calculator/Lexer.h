/*************************************************************************
                         Lexer.h  - Interface
                         -------------------
*************************************************************************/

//---------- Interface of the class <Lexer> (file Lexer.h) ---------------
#pragma once

//-------------------------------------------------------- Interfaces used
using namespace std;
#include <string>
#include <utility>
#include "Symbol.h"

//------------------------------------------ Definition of the class Lexer
class Lexer {

public:
//--------------------------------------------------------- Public methods
    Symbol * Consult();
    // This method allows to read a character of the arithmetic expression
    // given in input.

    void GoAhead();
    // This method allows to set the buffer to nullptr.

    void putSymbol(Symbol *s);
    // This method allows to put the symbol s into the buffer.

//---------------------------------------------- Constructors & Destructor
    Lexer(const Lexer &aLexer);
    // Copy Constructor

    explicit Lexer(string s);
    // Constructor

    virtual ~Lexer();
    // Destructor

protected:
//--------------------------------------------------- Protected attributes
    string flow;
    long unsigned int head;
    Symbol *buffer;
};
