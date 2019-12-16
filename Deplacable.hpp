#include<iostream>

#ifndef DEPLACABLE
#define DEPLACABLE

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
    int X;
    int Y;
  public :
    _Deplacable(int x,int y) : X{x},Y{y} {}
    virtual int getX() {return X;}
    virtual int getY() {return Y;}
    virtual void setLocalisation(int x,int y) {X = x; Y = y;}
};

#endif
