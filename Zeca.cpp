#include <iostream>
#include  "Zeca.hpp"
using namespace std;


Zeca::Zeca(int x, int y, char e): X{x}, Y{y}, etat{e} {}

void Zeca::setEtat(char e){
  etat=e;
}

char Zeca::getEtat(){
  return etat;
}
