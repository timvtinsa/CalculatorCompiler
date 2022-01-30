/*************************************************************************
               Automaton.h  - Interface de la classe Automaton
                         -------------------
*************************************************************************/


//---------- Interface de la classe <Automaton> (fichier Automaton.h) ----------------
#ifndef CALCULATORCOMPILER_CSVREADER_H
#define CALCULATORCOMPILER_CSVREADER_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <stack>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

//------------------------------------------------------------------ Types
typedef vector<string> CSVRow;
typedef vector<CSVRow> CSVContent;

//--------------------------------------- Définition de la classe Automaton
class CSVReader {
public:
//----------------------------------------------------- Méthodes publiques
    CSVRow readRow(int index);

    CSVRow getHeader() const;

    CSVContent getContent() const;
//-------------------------------------------- Constructeurs - destructeur
    CSVReader ( const CSVReader & CSVReader );
    // Mode d'emploi  : Constructeur de copie

    explicit CSVReader(string filename, char delimiter);
    // Mode d'emploi : Constructeur

    virtual ~CSVReader( );
    // Mode d'emploi : Destructeur

protected:
//----------------------------------------------------- Méthodes protégées
//    static Expression* buildBinaryExpression( Entier * operand1,  Entier * operand2, const int & operatorId );
//----------------------------------------------------- Attributs protégés
    CSVRow header;
    CSVContent content;
    string filename;
    char delimiter;

};


#endif //CALCULATORCOMPILER_CSVREADER_H
