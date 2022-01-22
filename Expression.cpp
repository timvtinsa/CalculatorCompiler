/*************************************************************************
                       Expression.cpp  -  Implémentation
                             -------------------
*************************************************************************/
//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "Expression.h"

//----------------------------- Expression --- Constructeurs - destructeur

Expression::Expression(const Symbole &aSymbole, const Expression &anExpression) : Symbole(aSymbole)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Expression>" << endl;
#endif
}

Expression::~Expression()
{
#ifdef MAP
    cout << "Appel au destructeur de <Expression>" << endl;
#endif
}



//---------------------- ExpressionBinaire --- Constructeurs - destructeur
ExpressionBinaire::~ExpressionBinaire()
{
#ifdef MAP
    cout << "Appel au destructeur de <ExpressionBinaire>" << endl;
#endif
}

//------------------------------------ ExpressionBinaire - Méthodes publiques

int ExpressionBinaire::eval() {
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
    return this->operand1 + this->operand2;
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
    return this->operand1 * this->operand2;
}









