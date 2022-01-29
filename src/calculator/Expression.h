/*************************************************************************
               Expression.h  - Interface de la classe Expression
                         -------------------
*************************************************************************/

//---------- Interface de la classe <Expression> (fichier Expresion.h) ----------------
#ifndef CALCULATORCOMPILER_EXPRESSION_H
#define CALCULATORCOMPILER_EXPRESSION_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include <vector>
#include "Symbole.h"

//------------------------------------- Définition de la classe Expression
class Expression : public Symbole {
public:
//-------------------------------------------- Constructeurs - destructeur
    Expression(const Symbole &aSymbole, const Expression &anExpression);
    // Mode d'emploi  : Constructeur de copie

    Expression() : Symbole(EXPR, false)
    {
#ifdef MAP
        cout << "Appel au constructeur de <Expression>" << endl;
#endif
    }
    // Mode d'emploi  : Constructeur

    Expression(Identificateurs id, bool isTerminal) : Symbole(id, isTerminal)
    {
#ifdef MAP
        cout << "Appel au constructeur de <Expression>" << endl;
#endif
    }

    ~Expression() override;
    // Mode d'emploi : Destructeur

//----------------------------------------------------- Méthodes publiques
    virtual int eval() = 0;
};

//---------------------------------------- Définition de la classe Entier
class Entier : public Expression {
public:
//-------------------------------------------- Constructeurs - destructeur
    Entier(const Symbole &sSymbole, const Entier &aEntier);
    // Mode d'emploi  : Constructeur de copie

    explicit Entier(int val) : Expression(), valeur(val)
    {
#ifdef MAP
        cout << "Appel au constructeur de <Entier>" << endl;
#endif
    }
    // Mode d'emploi  : Constructeur

    ~Entier() override;
    // Mode d'emploi : Destructeur

//----------------------------------------------------- Méthodes publiques
    virtual void Affiche();

    virtual int eval();

protected:
//----------------------------------------------------- Attributs protégés
    int valeur;
};


//------------------------------ Définition de la classe ExpressionBinaire
class ExpressionBinaire : public Expression {
public:
//-------------------------------------------- Constructeurs - destructeur
    ExpressionBinaire(const ExpressionBinaire &anExpressionBinaire);
    // Mode d'emploi  : Constructeur de copie

    ExpressionBinaire(Identificateurs opSymbol, Entier* opd1, Entier* opd2) : Expression(EXPR,false), operatorSymbole(opSymbol), operand1(opd1), operand2(opd2)
    {
#ifdef MAP
        cout << "Appel au constructeur de <ExpressionBinaire>" << endl;
#endif
    }
    // Mode d'emploi  : Constructeur

    ~ExpressionBinaire() override;
    // Mode d'emploi  : Destructeur

//----------------------------------------------------- Méthodes publiques
    virtual int eval() = 0;

protected:
    Identificateurs operatorSymbole;
    Entier* operand1;
    Entier* operand2;
};

//--------------------------------- Définition de la classe ExpressionPlus
class ExpressionPlus : public ExpressionBinaire {
public:
//-------------------------------------------- Constructeurs - destructeur
    ExpressionPlus(const ExpressionBinaire &anExpressionBinaire);
    // Mode d'emploi  : Constructeur de copie

    ExpressionPlus(Entier * opd1,  Entier * opd2) : ExpressionBinaire(PLUS, opd1, opd2)
    {
        #ifdef MAP
                cout << "Appel au constructeur de <ExpressionPlus>" << endl;
        #endif
    }
    // Mode d'emploi  : Constructeur

    ~ExpressionPlus() override;
    // Mode d'emploi  : Destructeur
//----------------------------------------------------- Méthodes publiques
    int eval() override;
};

//--------------------------------- Définition de la classe ExpressionMult
class ExpressionMult : public ExpressionBinaire {
public:
//-------------------------------------------- Constructeurs - destructeur
    ExpressionMult(const ExpressionMult &anExpressionMult);
    // Mode d'emploi  : Constructeur de copie

    ExpressionMult(Entier * opd1, Entier * opd2) : ExpressionBinaire(MULT, opd1, opd2)
    {
        #ifdef MAP
                cout << "Appel au constructeur de <ExpressionMult>" << endl;
        #endif
    }
    // Mode d'emploi  : Constructeur
    ~ExpressionMult() override;
//----------------------------------------------------- Méthodes publiques
    int eval() override;
};


#endif //CALCULATORCOMPILER_EXPRESSION_H
