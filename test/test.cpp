/*************************************************************************
                 test.cpp  -  file de test de l'automate
                             -------------------
*************************************************************************/

#include "gtest/gtest.h"
#include "../src/calculator/Automaton.h"
#include "../src/utils/CSVReader.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// The following test takes one by one the lines of the CSV file
// 'expressions.csv' (one line = one expression to test & its result)
// and give the corresponding expression in input of the analyzer.
// If the result of the evaluation of the expression is the same
// as the result provided in the CSV file, then the test is OK for
// this expression. The CSV file contains 1000 lines which corresponds
// to 1000 expressions to test. If one of the evaluations is wrong
// then the test fails.
// NB : The test also include invalid expressions with syntax error which
// have to be detected by the analyzer.


TEST(TestAutomaton, EvaluateExpression)
{
    CSVReader reader("../test/expressions", ';');
    CSVContent content = reader.getContent();
    for (const CSVRow& row: content)
    {
        string exprStr = row[0];
        string evalStr = row[1];
        cout << "Expression : " << exprStr << endl;
        auto * automateTest = new Automaton(exprStr);
        int result = automateTest->run();
        delete(automateTest);
        cout << "Expected result : " << evalStr << endl;
        ASSERT_EQ(to_string(result),  evalStr);
        cout << endl;
    }
    auto nbTest = content.size();
    cout << nbTest << " tests carried out with success." << endl;
}