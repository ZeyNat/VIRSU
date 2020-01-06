#include <iostream>
#include  "Oueurj.hpp"
using namespace std;

Oueurj::Oueurj(int x, int y,int d): _Deplacable(x,y), nbDiams{d}, TP{0} {}


void Oueurj::incrementeDiams(){
  nbDiams++;
}


void Oueurj::decrementeDiams(){
  nbDiams--;
}

void Oueurj::afficheDiams(){
  cout<<"Diams : " << getDiams() << endl;
}

int Oueurj::getDiams(){
  return nbDiams;
}

bool Oueurj::hasTP(){
  return TP>0;
}

void Oueurj::setTP(){
  TP+=2;
}

void Oueurj::removeTP(){
  TP --;
}

unsigned int Oueurj::getTP(){
  return TP;
}
