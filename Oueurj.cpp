#include <iostream>
#include <fstream>
#include  "Oueurj.hpp"
using namespace std;

Oueurj::Oueurj(int x, int y,int d,int v): _Deplacable(x,y), nbDiams{d}, TP{1}, vies{v} {}

Oueurj::Oueurj(Oueurj J, int x, int y) : _Deplacable(x,y), nbDiams{J.getDiams()},
                                               TP{J.getTP()}, vies {J.getVies()}{}

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

void Oueurj::addTP(int i){
  TP+=i;
}

void Oueurj::removeTP(){
  TP --;
}

unsigned int Oueurj::getTP(){
  return TP;
}

int Oueurj::getVies(){
  return vies;
}

void Oueurj::perdVie(){
  vies--;
}

void Oueurj::setVies(int i){
  vies = i;
}


ofstream Oueurj::sauvegardeOueurj(string f){
  ofstream flux(f.c_str());
  flux << "save" << endl;
  flux << getDiams() << endl;
  flux << getTP() << endl;
  flux << getVies() << endl;
  return flux;
}
