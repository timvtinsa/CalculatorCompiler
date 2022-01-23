#include <iostream>
#include "Lexer.h"
#include "Automate.h"


int main(void) {

//----------- OLD MAIN ------------
//   string chaine("(1+34)*123");
//
//   Lexer l(chaine);
//
//   Symbole * s;
//   while(*(s=l.Consulter())!=FIN) {
//      s->Affiche();
//      cout<<endl;
//      l.Avancer();
//   }

//----------- NEW MAIN -----------
    string input;

    cout << "Entrez l'expression arithmétique :" << endl;
    cin >> input;
    Automate *automate = new Automate(input);
    automate->run();
    delete(automate);

   return 0;
}

