/*************************************************************************
                        CSVReader  -  Implementation
                             -------------------
*************************************************************************/

//---- Implementation of the class <Automaton> (file Automaton.cpp) ------


//--------------------------------------------------------- System include
using namespace std;
#include <utility>
#include <iostream>
#include <regex>

//------------------------------------------------------- Personal include
#include "CSVReader.h"

//--------------------------------------------- CSVReader - Public methods

CSVRow CSVReader::readRow(int index) {
    return this->content[index];
}

CSVRow CSVReader::getHeader() const {
    return this->header;
}

CSVContent CSVReader::getContent() const {
    return this->content;
}

//---------------------------------- CSVReader - Constructors & Destructor
CSVReader::CSVReader(string filename, char delimiter)
{
#ifdef MAP
    cout << "Call to the Constructor of <CSVReader>" << endl;
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
    cout << "Call to the Destructor of <CSVReader>" << endl;
#endif
}


