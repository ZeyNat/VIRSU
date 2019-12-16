#include<iostream>
#include <vector>
#include "Deplacable.hpp"
using namespace std;

#ifndef STREUMON
#define STREUMON

class Streumon : public _Deplacable {
  public :
    Streumon();
    Streumon(int x,int y);
};



#endif
