/*************************************************************************
                          Symbol.cpp  -  Implémentation
                             -------------------
*************************************************************************/

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Symbol.h"

//------------------------------------------- Symbol - Méthodes publiques
void Symbol::Affiche()
{
    cout<<Etiquettes[ident];
}

int Symbol::eval() {
    return -1;
}


//---------------------------------- Symbol - Constructeurs - destructeur
Symbol::Symbol(int i, bool t) : ident(i), terminal(t) {
#ifdef MAP
    cout << "Appel au constructeur de <Symbol>" << endl;
#endif
}

Symbol::~Symbol()
{
#ifdef MAP
    cout << "Appel au destructeur de <Symbol>" << endl;
#endif
}

//------------------------------------------- EntierSimple - Méthodes publiques
int EntierSimple::eval() {
    return valeur;
}

//---------------------------- EntierSimple - Constructeurs - destructeur
EntierSimple::EntierSimple(int val) : Symbol(INT, true), valeur(val)
{
#ifdef MAP
    cout << "Appel au constructeur de <EntierSimple>" << endl;
#endif
}

EntierSimple::~EntierSimple() {
#ifdef MAP
    cout << "Appel au destructeur de <EntierSimple>" << endl;
#endif
}
