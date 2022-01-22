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

//------------------------------------------- Symbole - Méthodes publiques
void Entier::Affiche() {
    Symbole::Affiche();
    cout<<"("<<valeur<<")";
}

//----------------------------------- Entier - Constructeurs - destructeur
Entier::Entier(const Symbole &aSymbole, const Entier &aEntier) : Symbole(aSymbole)
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Entier>" << endl;
    #endif
}

Entier::~Entier()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Entier>" << endl;
    #endif
}

