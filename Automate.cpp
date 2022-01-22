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

//----------------------------------------------------- Méthodes publiques

Automate::Automate(string input) {
    this->lexer = new Lexer(move(input));
    E0 * initState = new E0();
    stateStack.push(initState);
}

Automate::Automate(const Automate &Automate) { }

Automate::~Automate() { }

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
    stateStack.top()->transition(*this, s);

    int operand1 = *aEnlever.top();
    ExpressionBinaire * expr;

    if (n == 3) {
        if (operand1 == OPENPAR) {
            aEnlever.pop();
            operand1 = *aEnlever.top();
        } else {
            aEnlever.pop();
            int operatorSymbol = *aEnlever.top();
            aEnlever.pop();
            int operand2 = *aEnlever.top();
            switch (operatorSymbol) {
                case MULT:
                    expr = new ExpressionMult(operand1,operand2);
//                    operand1 = operand1 * operand2;
                break;
                case PLUS:
                    expr = new ExpressionPlus(operand1,operand2);
//                    operand1 = operand1 + operand2;
                break;
                default:
                    cout << "Erreur lors de l'évalutation de l'expression" << endl;
            }
        }
    }

    stateStack.top()->transition(*this, expr);
    lexer->putSymbol(s);
}

void Automate::run() {
    bool nextState = true;

    while (nextState) {
        Symbole *s = lexer->Consulter();
        lexer->Avancer();
        nextState = stateStack.top()->transition(*this, s);
    }
    if (*symbolStack.top() != ERREUR) {

        int resultat = symbolStack.top()->getValue();
        cout << "Syntaxe correct" << endl << "Résultat : " << resultat << endl;
    } else {
        cout << "Syntaxe non reconnu : caractere invalide" << endl;
    }
}


