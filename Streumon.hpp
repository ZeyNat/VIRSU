#include<iostream>
#include <vector>
#include "Deplacable.hpp"
using namespace std;

#ifndef STREUMON
#define STREUMON

class Streumon : public _Deplacable {
  private :
    char sousSesPieds;
  public :
    Streumon();
    Streumon(int x,int y);
    char getSousSesPieds();
    void setSousSesPieds(char c);
};


#endif
