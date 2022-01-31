/*************************************************************************
                       CSVReader.h  - Interface
                         -------------------
*************************************************************************/


//--------- Interface of the class <Automaton> (file CSVReader.h) --------
#ifndef CALCULATORCOMPILER_CSVREADER_H
#define CALCULATORCOMPILER_CSVREADER_H

//-------------------------------------------------------- Interfaces used
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

//-------------------------------------- Definition of the class CSVReader
class CSVReader {

//----------------------------------------------------------------- PUBLIC
public:
//--------------------------------------------------------- Public methods
    CSVRow readRow(int index);
    // This method allows to read a specific row of the content of the
    // CSV file.

    CSVRow getHeader() const;
    // This method allows to read the header row of the CSV file.

    CSVContent getContent() const;
    // This method allows to get the content (attribute) of the CSV file.

//---------------------------------------------- Constructors & Destructor
    CSVReader ( const CSVReader & CSVReader );
    // Copy Constructor

    explicit CSVReader(string filename, char delimiter);
    // Constructor

    virtual ~CSVReader( );
    // Destructor

protected:
//--------------------------------------------------- Protected attributes
    CSVRow header;
    CSVContent content;
    string filename;
    char delimiter;

};


#endif //CALCULATORCOMPILER_CSVREADER_H
