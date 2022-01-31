/*************************************************************************
                       Expression.cpp  -  Implémentation
                             -------------------
*************************************************************************/

//--------------------------------------------------------- System include
#include <iostream>

//------------------------------------------------------- Personal include
#include "Expression.h"

//--- Implementation of the class <Expression> (file Expression.cpp) -----

//------------------------------- Expression --- Constructors & Destructor
Expression::Expression() : Symbol(EXPR, false) {
#ifdef MAP
    cout << "Call to the Constructor 1 of <Expression>" << endl;
#endif
}

Expression::Expression(Identificateurs id, bool isTerminal) : Symbol(id, isTerminal) {
#ifdef MAP
cout << "Call to the Constructor 2 of <Expression>" << endl;
#endif
}

Expression::~Expression()
{
#ifdef MAP
    cout << "Call to the Destructor of <Expression>" << endl;
#endif
}

//---- Implementation of the class <Entier> (file Expression.cpp) --------

//------------------------------------------------ Entier - Public methods
void Entier::Display() {
    Symbol::Display();
    cout<<"("<<valeur<<")";
}

int Entier::Eval() {
    return valeur;
}

//------------------------------------- Entier - Constructors & Destructor
Entier::Entier(int val) : Expression(), valeur(val)
{
#ifdef MAP
    cout << "Call to the Constructor of <Entier>" << endl;
#endif
}

Entier::~Entier()
{
#ifdef MAP
    cout << "Call to the Destructor of <Entier>" << endl;
#endif
}

//- Implementation of the class <BinaryExpression> (file Expression.cpp) -

//-------------------------------------- BinaryExpression - Public methods
int BinaryExpression::Eval() {
    return 0;
}

//------------------------- BinaryExpression --- Constructors & Destructor
BinaryExpression::BinaryExpression(Identificateurs opSymbol, Entier* opd1, Entier* opd2) : Expression(EXPR, false), operatorSymbole(opSymbol), operand1(opd1), operand2(opd2)
{
#ifdef MAP
    cout << "Call to the Constructor of <BinaryExpression>" << endl;
#endif
}

BinaryExpression::~BinaryExpression()
{
#ifdef MAP
    cout << "Call to the Destructor of <BinaryExpression>" << endl;
#endif
    delete(operand1);
    delete(operand2);
}

//-- Implementation of the class <ExpressionPlus> (file Expression.cpp) --

//---------------------------------------- ExpressionPlus - Public methods
int ExpressionPlus::Eval()
{
    return operand1->Eval() + operand2->Eval();
}

//--------------------------- ExpressionPlus --- Constructors & Destructor
ExpressionPlus::ExpressionPlus(Entier * opd1,  Entier * opd2) : BinaryExpression(PLUS, opd1, opd2)
{
#ifdef MAP
    cout << "Call to the Constructor of <ExpressionPlus>" << endl;
#endif
}

ExpressionPlus::~ExpressionPlus()
{
#ifdef MAP
    cout << "Call to the Destructor of <ExpressionPlus>" << endl;
#endif
}

//-- Implementation of the class <ExpressionMult> (file Expression.cpp) --

//---------------------------------------- ExpressionMult - Public methods
int ExpressionMult::Eval()
{
    return operand1->Eval() * operand2->Eval();
}

//--------------------------- ExpressionMult --- Constructors & Destructor
ExpressionMult::ExpressionMult(Entier * opd1, Entier * opd2) : BinaryExpression(MULT, opd1, opd2)
{
#ifdef MAP
    cout << "Call to the Constructor of <ExpressionMult>" << endl;
#endif
}

ExpressionMult::~ExpressionMult()
{
#ifdef MAP
    cout << "Call to the Destructor of <ExpressionMult>" << endl;
#endif
}











