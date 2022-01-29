/*************************************************************************
                          Lexer.cpp  -  Implémentation
                             -------------------
*************************************************************************/

//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Lexer.h"

//--------------------------------------------- Lexer - Méthodes publiques
Symbole * Lexer::Consulter() {
   if (!tampon) {

      if (tete == flux.length())
         tampon = new Symbole(FIN, true);
      else
      {

         switch (flux[tete]) {
            case '(':
               tampon = new Symbole(OPENPAR, true);
               tete++;
               break;
            case ')':
               tampon = new Symbole(CLOSEPAR, true);
               tete++;
               break;
            case '*':
               tampon = new Symbole(MULT, true);
               tete++;
               break;
            case '+':
               tampon = new Symbole(PLUS, true );
               tete++;
               break;
            default:
               if (flux[tete]<='9' && flux[tete]>='0') {
                  int resultat = flux[tete]-'0';
                  int i=1;
                  while (flux[tete+i]<='9' && flux[tete+i]>='0') {
                     resultat = resultat*10+(flux[tete+i]-'0');
                     i++;
                  }
                  tete = tete+i;
                  tampon = new EntierSimple(resultat);
               }
               else {
                  tampon = new Symbole(ERREUR, true);
               }
         }
      }
   }
   return tampon;
}

void Lexer::Avancer() {
   tampon = nullptr;
}

void Lexer::putSymbol(Symbole *s) {
    tampon = s;
}

//------------------------------------ Lexer - Constructeurs - destructeur
Lexer::Lexer(const Lexer &aLexer)
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Lexer>" << endl;
    #endif
}

Lexer::~Lexer()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Lexer>" << endl;
    #endif
    delete(tampon);
}

