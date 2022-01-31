#include <iostream>
#include "Lexer.h"
#include "Automaton.h"


int main(void) {
    string input;

    cout << "Enter the arithmetic expression :" << endl;
    cin >> input;
    auto *automate = new Automaton(input);
    automate->run();
    delete(automate);

   return 0;
}

