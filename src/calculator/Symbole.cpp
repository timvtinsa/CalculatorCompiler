/*************************************************************************
                          Symbole.cpp  -  Implémentation
                             -------------------
*************************************************************************/

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Symbole.h"

//------------------------------------------- Symbole - Méthodes publiques
void Symbole::Affiche()
{
    cout<<Etiquettes[ident];
}

int Symbole::eval() {
    return -1;
}


//---------------------------------- Symbole - Constructeurs - destructeur
Symbole::Symbole(int i, bool t) : ident(i), terminal(t) {
#ifdef MAP
    cout << "Appel au constructeur de <Symbole>" << endl;
#endif
}

Symbole::~Symbole()
{
#ifdef MAP
    cout << "Appel au destructeur de <Symbole>" << endl;
#endif
}

//------------------------------------------- EntierSimple - Méthodes publiques
int EntierSimple::eval() {
    return valeur;
}

//---------------------------- EntierSimple - Constructeurs - destructeur
EntierSimple::EntierSimple(int val) : Symbole(INT, true), valeur(val)
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
