#include<iostream>

#ifndef DEPLACABLE
#define DEPLACABLE

/*Interface commune aux classes Oueurj et Streumon*/

class Deplacable{
  public :
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual void setLocalisation(int x,int y) = 0;
};

#endif



#ifndef _DEPLACABLE
#define _DEPLACABLE

class _Deplacable : public Deplacable{
  protected :
    //position
    int X;
    int Y;
  public :
    //constructeur
    _Deplacable(int x,int y) : X{x},Y{y} {}

    //getteurs de position
    virtual int getX() {return X;}
    virtual int getY() {return Y;}

    //changer la position
    virtual void setLocalisation(int x,int y) {X = x; Y = y;}
};

#endif
