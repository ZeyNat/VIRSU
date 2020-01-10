#include <iostream>
#include <vector>
#include "Deplacable.hpp"
using namespace std;

#ifndef STREUMON
#define STREUMON


class Streumon : public _Deplacable {
  private :
    char sousSesPieds;  //garde en memoire le contenu de la zeca
  public :
    //constructeurs
    Streumon();
    Streumon(int x,int y);

    //gestion attribut sousSesPieds
    char getSousSesPieds();
    void setSousSesPieds(char c);
};


#endif
