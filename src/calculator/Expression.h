/*************************************************************************
                      Expression.h  - Interface
                         -------------------
*************************************************************************/

//---------- Interface of the class <Expression> (file Expresion.h) ----------------
#ifndef CALCULATORCOMPILER_EXPRESSION_H
#define CALCULATORCOMPILER_EXPRESSION_H

//--------------------------------------------------- Interfaces used
using namespace std;
#include <string>
#include <vector>
#include "Symbol.h"

//------------------------------------- Definition of the class Expression
class Expression : public Symbol {
public:
//---------------------------------------------- Constructors & Destructor
    Expression(const Symbol &aSymbole, const Expression &anExpression);
    // Copy Constructor

    Expression();
    // Constructor 1

    Expression(Identificateurs id, bool isTerminal);
    // Constructor 2

    ~Expression() override;
    // Destructor

//--------------------------------------------------------- Public methods
    virtual int Eval() = 0;
    // This pure virtual method is redefined by all types of expression
    // and allows to evaluate the expression which call the method.
};

//----------------------------------------- Definition of the class Entier
class Entier : public Expression {
public:
//---------------------------------------------- Constructors & Destructor
    Entier(const Symbol &sSymbole, const Entier &aEntier);
    // Copy Constructor

    explicit Entier(int val);
    // Constructor

    ~Entier() override;
    // Destructor

//--------------------------------------------------------- Public methods
    virtual void Display();
    // This method allows to Display the value of the object which call
    // the method.

    virtual int Eval();

protected:
//--------------------------------------------------- Protected attributes
    int valeur;
};


//------------------------------- Definition of the class BinaryExpression
class BinaryExpression : public Expression {
public:
//---------------------------------------------- Constructors & Destructor
    BinaryExpression(const BinaryExpression &aBinaryExpression);
    // Copy Constructor

    BinaryExpression(Identificateurs opSymbol, Entier* opd1, Entier* opd2);
    // Constructor

    ~BinaryExpression() override;
    // Destructor

//--------------------------------------------------------- Public methods
    virtual int Eval() = 0;

protected:
    Identificateurs operatorSymbole;
    Entier* operand1;
    Entier* operand2;
};

//--------------------------------- Definition of the class ExpressionPlus
class ExpressionPlus : public BinaryExpression {
public:
//---------------------------------------------- Constructors & Destructor
    ExpressionPlus(const BinaryExpression &aBinaryExpression);
    // Copy Constructor

    ExpressionPlus(Entier * opd1,  Entier * opd2);
    // Constructor

    ~ExpressionPlus() override;
    // Destructor
//--------------------------------------------------------- Public methods
    int Eval() override;
};

//--------------------------------- Definition of the class ExpressionMult
class ExpressionMult : public BinaryExpression {
public:
//---------------------------------------------- Constructors & Destructor
    ExpressionMult(const ExpressionMult &anExpressionMult);
    // Copy Constructor

    ExpressionMult(Entier * opd1, Entier * opd2);
    // Constructor
    ~ExpressionMult() override;
//--------------------------------------------------------- Public methods
    int Eval() override;
};


#endif //CALCULATORCOMPILER_EXPRESSION_H
