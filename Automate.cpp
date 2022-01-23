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
            aEnlever.pop();
            expr = new Entier(aEnlever.top()->eval());
        } else
        {
            auto * operand1 = new Entier(aEnlever.top()->eval());
            aEnlever.pop();
            int operatorSymbol = *aEnlever.top();
            aEnlever.pop();
            auto * operand2 = new Entier((*aEnlever.top()).eval());
            switch (operatorSymbol) {
                case MULT:
                    expr = new ExpressionMult(*operand1,*operand2);
//                    operand1 = operand1 * operand2;
                    break;
                case PLUS:
                    expr = new ExpressionPlus(*operand1,*operand2);
//                    operand1 = operand1 + operand2;
                    break;
                default:
                    cout << "Erreur lors de la création l'expression binaire" << endl;
            }
        }
    }

    stateStack.top()->transition(*this, expr);
    lexer->putSymbol(s);
}

void Automate::run() {
    bool nextState = true;

    while (nextState) {
        stateStack.top()->print();
        Symbole *s = lexer->Consulter();
        lexer->Avancer();
        nextState = stateStack.top()->transition(*this, s);
    }
    if (*symbolStack.top() != ERREUR) {
        int resultat = (*symbolStack.top()).eval();
        cout << "Syntaxe correct" << endl << "Résultat : " << resultat << endl;
    } else {
        cout << "Syntaxe non reconnu : caractere invalide" << endl;
    }
}



//---------------------------------- Symbole - Constructeurs - destructeur
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

