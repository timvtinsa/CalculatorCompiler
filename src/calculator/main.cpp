#include <iostream>
#include "Lexer.h"
#include "Automaton.h"


int main(void) {

//----------- OLD MAIN ------------
//   string chaine("(1+34)*123");
//
//   Lexer l(chaine);
//
//   Symbol * s;
//   while(*(s=l.Consulter())!=FIN) {
//      s->Affiche();
//      cout<<endl;
//      l.Avancer();
//   }

//----------- NEW MAIN -----------
    string input;

    cout << "Enter the arithmetic expression :" << endl;
    cin >> input;
    auto *automate = new Automaton(input);
    automate->run();
    delete(automate);

   return 0;
}

