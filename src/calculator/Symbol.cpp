/*************************************************************************
                          Symbol.cpp  -  Implémentation
                             -------------------
*************************************************************************/

//--------------------------------------------------------- System include
#include <iostream>

//------------------------------------------------------- Personal include
#include "Symbol.h"

//--------- Implementation of the class <Symbol> (file State.cpp) --------

//------------------------------------------------ Symbol - Public methods
void Symbol::Display()
{
    cout<<Etiquettes[ident];
}

int Symbol::Eval() {
    return -1;
}


//------------------------------------- Symbol - Constructors & Destructor
Symbol::Symbol(int i, bool t) : ident(i), terminal(t) {
#ifdef MAP
    cout << "Call to the Constructor of <Symbol>" << endl;
#endif
}

Symbol::~Symbol()
{
#ifdef MAP
    cout << "Call to the Destructor of <Symbol>" << endl;
#endif
}

//------ Implementation of the class <EntierSimple> (file State.cpp) -----

//------------------------------------------ EntierSimple - Public methods
int EntierSimple::Eval() {
    return valeur;
}

//------------------------------- EntierSimple - Constructors & Destructor
EntierSimple::EntierSimple(int val) : Symbol(INT, true), valeur(val)
{
#ifdef MAP
    cout << "Call to the Constructor of <EntierSimple>" << endl;
#endif
}

EntierSimple::~EntierSimple() {
#ifdef MAP
    cout << "Call to the Destructor of <EntierSimple>" << endl;
#endif
}
