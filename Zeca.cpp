#include <iostream>
#include  "Zeca.hpp"
using namespace std;


/*Constructeur*/
Zeca::Zeca(int x, int y, char e): X{x}, Y{y}, etat{e} {}


/*Getteurs*/

int Zeca::getX(){
  return X;
}

int Zeca::getY(){
  return Y;
}


/*Gestion etat*/

void Zeca::setEtat(char e){
  etat=e;
}

char Zeca::getEtat(){
  return etat;
}
