#include <iostream>
#include <fstream>
#include  "Oueurj.hpp"
using namespace std;

Oueurj::Oueurj(int x, int y,int d): _Deplacable(x,y), nbDiams{d}, TP{1} {}

Oueurj::Oueurj(Oueurj J, int x, int y) : _Deplacable(x,y), nbDiams{J.getDiams()}, TP{J.getTP()} {}

void Oueurj::incrementeDiams(int i){
  nbDiams += i;
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

void Oueurj::setTP(int i){
  TP+=i;
}

void Oueurj::removeTP(){
  TP --;
}

unsigned int Oueurj::getTP(){
  return TP;
}

ofstream Oueurj::sauvegardeOueurj(string f){
  ofstream flux(f.c_str());
  flux << "save" << endl;
  flux << getDiams() << endl;
  flux << getTP() << endl;
  return flux;
}
