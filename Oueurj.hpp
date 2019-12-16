#include "Deplacable.hpp"

#ifndef OUEURJ
#define OUEURJ

class Oueurj : public _Deplacable{
  private:
    //int X;
    //int Y;
    int nbDiams;
  public:
    Oueurj(int x, int y, int d = 0);
    //virtual void setLocalisation(int x, int y);
    //int getX();  //fcts de test
    //int getY();  //je sais pas si on les gardera

};
#endif
