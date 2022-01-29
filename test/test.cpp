/*************************************************************************
                 test.cpp  -  Fichier de test de l'automate
                             -------------------
*************************************************************************/

#include "gtest/gtest.h"
#include "../src/calculator/Automate.h"
#include "../src/utils/CSVReader.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(TestAutomate, EvaluateExpression)
{
    CSVReader reader("../test/expressions", ';');
    CSVContent content = reader.getContent();
    for (const CSVRow& row: content)
    {
        string exprStr = row[0];
        string evalStr = row[1];
        cout << "Expression : " << exprStr << endl;
        auto * automateTest = new Automate(exprStr);
        int result = automateTest->run();
        delete(automateTest);
        cout << "Expected result : " << evalStr << endl;
        ASSERT_EQ(to_string(result),  evalStr);
        cout << endl;
    }
    auto nbTest = content.size();
    cout << nbTest << " tests carried out with succes." << endl;
}