/*************************************************************************
                       Expression.cpp  -  Implémentation
                             -------------------
*************************************************************************/
//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Expression.h"

//----------------------------- Expression --- Constructeurs - destructeur
Expression::~Expression()
{
#ifdef MAP
    cout << "Appel au destructeur de <Expression>" << endl;
#endif
}

//------------------------------------------- Symbol - Méthodes publiques
void Entier::Affiche() {
    Symbol::Affiche();
    cout<<"("<<valeur<<")";
}

int Entier::eval() {
    return valeur;
}

//----------------------------------- Entier - Constructeurs - destructeur
Entier::~Entier()
{
#ifdef MAP
    cout << "Appel au destructeur de <Entier>" << endl;
#endif
}



//---------------------- BinaryExpression --- Constructeurs - destructeur
BinaryExpression::~BinaryExpression()
{
#ifdef MAP
    cout << "Appel au destructeur de <BinaryExpression>" << endl;
#endif
    delete(operand1);
    delete(operand2);
}

//------------------------------------ BinaryExpression - Méthodes publiques

int BinaryExpression::eval() {
    return 0;
}



//------------------------- ExpressionPlus --- Constructeurs - destructeur
ExpressionPlus::~ExpressionPlus()
{
#ifdef MAP
    cout << "Appel au destructeur de <ExpressionPlus>" << endl;
#endif
}

//------------------------------------ ExpressionPlus - Méthodes publiques
int ExpressionPlus::eval()
{
    return operand1->eval() + operand2->eval();
}

//------------------------- ExpressionMult --- Constructeurs - destructeur
ExpressionMult::~ExpressionMult()
{
#ifdef MAP
    cout << "Appel au destructeur de <ExpressionMult>" << endl;
#endif
}

//------------------------------------ ExpressionMult - Méthodes publiques
int ExpressionMult::eval()
{
    return operand1->eval() * operand2->eval();
}











