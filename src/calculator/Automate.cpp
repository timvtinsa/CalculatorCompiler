/*************************************************************************
                     Automate  -  Réalisation de la classe
                             -------------------
*************************************************************************/

//---------- Réalisation de la classe <Automate> (fichier Automate.cpp) ------------


//-------------------------------------------------------- Include système
using namespace std;
#include <utility>
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Etat.h"
#include "Expression.h"
#include "Automate.h"


//------------------------------------------ Automate - Méthodes publiques

void Automate::decalage(Symbole *s, Etat *e) {
    symbolStack.push(s);
    stateStack.push(e);
    if (s->isTerminal()) {
        lexer->Avancer();
    }
}


void Automate::reduction(int n, Symbole *s) {
    SymbolStack aEnlever;

    for (int i = 0; i < n; i++) {
        delete (stateStack.top());
        stateStack.pop();
        aEnlever.push(symbolStack.top());
        symbolStack.pop();
    }

    Expression *expr = nullptr;
    if (n == 1)
    {
        expr = new Entier(aEnlever.top()->eval());
    }
    else if (n == 3)
    {
        if (*aEnlever.top() == OPENPAR)
        {
            delete(aEnlever.top());
            aEnlever.pop();
            expr = new Entier(aEnlever.top()->eval());
            delete(aEnlever.top());
            aEnlever.pop();
        } else
        {
            auto * operand1 = new Entier(aEnlever.top()->eval());
            delete(aEnlever.top());
            aEnlever.pop();
            int operatorSymbol = *aEnlever.top();
            delete(aEnlever.top());
            aEnlever.pop();
            auto * operand2 = new Entier((*aEnlever.top()).eval());
            expr = buildBinaryExpression(operand1, operand2, operatorSymbol);
        }
    }
    delete(aEnlever.top());
    aEnlever.pop();

    stateStack.top()->transition(*this, expr);
    lexer->putSymbol(s);
}

int Automate::run() {
    bool nextState = true;
    int resultat = -1;
    while (nextState) {
#ifdef STATES
        stateStack.top()->print();
#endif
        Symbole *s = lexer->Consulter();
        lexer->Avancer();
        nextState = stateStack.top()->transition(*this, s);
    }
    if (*symbolStack.top() != ERREUR) {
        resultat = (*symbolStack.top()).eval();
        cout << "Valid expression." << endl << "Evaluation result : " << resultat << endl;
    } else {
        cout << "Invalid expression : syntax error." << endl;
    }
    return resultat;
}

Expression *
Automate::buildBinaryExpression( Entier* operand1,  Entier* operand2, const int &operatorId) {
    switch (operatorId) {
        case PLUS:
            return new ExpressionPlus(operand1, operand2);
        case MULT:
            return new ExpressionMult(operand1,operand2);
        default:
            cout << "Erreur lors de la création l'expression binaire" << endl;
    }
    return nullptr;
}



//---------------------------------- Automate - Constructeurs - destructeur
Automate::Automate(string input)
{
    #ifdef MAP
        cout << "Appel au constructeur de <Automate>" << endl;
    #endif
    this->lexer = new Lexer(move(input));
    E0 * initState = new E0();
    stateStack.push(initState);
}

Automate::~Automate()
{
#ifdef MAP
    cout << "Appel au destructeur de <Automate>" << endl;
#endif
    delete (lexer);
    while (!stateStack.empty()) {
        delete (stateStack.top());
        stateStack.pop();
    }
    while (!symbolStack.empty()) {
        delete (symbolStack.top());
        symbolStack.pop();
    }
}



