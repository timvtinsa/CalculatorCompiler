/*************************************************************************
                     Automate  -  Réalisation de la classe
                             -------------------
*************************************************************************/

//---------- Réalisation de la classe <Automate> (fichier Automate.cpp) ------------


//-------------------------------------------------------- Include système
using namespace std;
#include <utility>
#include <iostream>
#include <regex>

//------------------------------------------------------ Include personnel
#include "CSVReader.h"

//------------------------------------------ CSVReader - Méthodes publiques

CSVRow CSVReader::readRow(int index) {
    return this->content[index];
}

CSVRow CSVReader::getHeader() const {
    return this->header;
}

//---------------------------------- Automate - Constructeurs - destructeur
CSVReader::CSVReader(string filename, char delimiter)
{
#ifdef MAP
    cout << "Appel au constructeur de <CSVReader>" << endl;
#endif
    this->filename = filename + ".csv";
    this->delimiter = delimiter;

    CSVRow row;
    string line, word;
    regex eol("\r");

    fstream file(this->filename, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();
            stringstream str(line);
            while(getline(str, word, delimiter))
            {
                string result = std::regex_replace(word, eol, "");
                row.push_back(result);
            }
            content.push_back(row);
        }
        this->header = content[0];
        content.erase(content.begin());
    }
    else
    {
        cout<<"Could not open the CSV file" << endl;
    }
}

CSVReader::~CSVReader()
{
#ifdef MAP
    cout << "Appel au destructeur de <CSVReader>" << endl;
#endif
//    delete (lexer);
//    while (!stateStack.empty()) {
//        delete (stateStack.top());
//        stateStack.pop();
//    }
//    while (!symbolStack.empty()) {
//        delete (symbolStack.top());
//        symbolStack.pop();
//    }
}

CSVContent CSVReader::getContent() const {
    return this->content;
}
