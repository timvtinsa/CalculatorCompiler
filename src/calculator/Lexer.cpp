/*************************************************************************
                          Lexer.cpp  -  Implémentation
                             -------------------
*************************************************************************/

//--------------------------------------------------------- System include
#include <iostream>
//------------------------------------------------------- Personal include
#include "Lexer.h"

//------------------------------------------------- Lexer - Public methods
Symbol * Lexer::Consult() {
   if (!buffer) {

      if (head == flow.length())
          buffer = new Symbol(FIN, true);
      else
      {

         switch (flow[head]) {
            case '(':
                buffer = new Symbol(OPENPAR, true);
               head++;
               break;
            case ')':
                buffer = new Symbol(CLOSEPAR, true);
               head++;
               break;
            case '*':
                buffer = new Symbol(MULT, true);
               head++;
               break;
            case '+':
                buffer = new Symbol(PLUS, true );
               head++;
               break;
            default:
               if (flow[head] <= '9' && flow[head] >= '0') {
                  int resultat = flow[head] - '0';
                  int i=1;
                  while (flow[head + i] <= '9' && flow[head + i] >= '0') {
                     resultat = resultat*10+(flow[head + i] - '0');
                     i++;
                  }
                   head = head + i;
                   buffer = new EntierSimple(resultat);
               }
               else {
                   buffer = new Symbol(ERREUR, true);
               }
         }
      }
   }
   return buffer;
}

void Lexer::GoAhead() {
    buffer = nullptr;
}

void Lexer::putSymbol(Symbol *s) {
    buffer = s;
}

//-------------------------------------- Lexer - Constructors & Destructor
Lexer::Lexer(string s) : flow(move(s)), head(0), buffer(nullptr) {
#ifdef MAP
    cout << "Call to the Constructor of <Lexer>" << endl;
#endif
}

Lexer::~Lexer()
{
#ifdef MAP
    cout << "Call to the Destructor of <Lexer>" << endl;
#endif
    delete(buffer);
}

