/*************************************************************************
                 TAutomate  -  Fichier de test de l'automate
                             -------------------
*************************************************************************/

//---------- Test du module <Automate> -------------------
#if ! defined ( CALCULATORCOMPILER_TAUTOMATE_H )
#define CALCULATORCOMPILER_TAUTOMATE_H

#include <calculator/Automate.h>
#include "utils/CSVReader.h"

// ---------------- Test unitaire de la méthode AddTask
TEST(TestAutomate, EvaluateExpression)
{
    CSVReader reader("../../test/expressions", ';');
    for (const CSVRow& row: reader.getContent())
    {
        string exprStr = row[0];
        string evalStr = row[1];
        auto * automateTest = new Automate(exprStr);
        int result = automateTest->run();
        delete(automateTest);
        cout << "Computed result : " << result << endl;
        cout << "Expected result : " << evalStr << endl;
        ASSERT_EQ(to_string(result),  evalStr);
    }
}

#endif // CALCULATORCOMPILER_TAUTOMATE_H