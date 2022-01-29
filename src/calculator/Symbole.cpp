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
Symbole::Symbole(const Symbole & aSymbole)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Symbole>" << endl;
#endif
}

Symbole::~Symbole()
{
#ifdef MAP
    cout << "Appel au destructeur de <Symbole>" << endl;
#endif
}


//---------------------------- SymboleSimple - Constructeurs - destructeur

EntierSimple::~EntierSimple() {
#ifdef MAP
    cout << "Appel au destructeur de <EntierSimple>" << endl;
#endif
}

int EntierSimple::eval() {
    return valeur;
}
