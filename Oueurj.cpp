#include <iostream>
#include  "Oueurj.hpp"
using namespace std;

Oueurj::Oueurj(int x, int y,int d): _Deplacable(x,y), nbDiams{d} {}


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
