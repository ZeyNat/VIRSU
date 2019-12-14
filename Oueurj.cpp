#include <iostream>
#include  "Oueurj.hpp"
using namespace std;

Oueurj::Oueurj(int x, int y): X{x}, Y{y} {}

void Oueurj::setLocalisation(int x, int y){
  X=x;
  Y=y;
}


int Oueurj::getX(){
  return X;
}
int Oueurj::getY(){
  return Y;
}
