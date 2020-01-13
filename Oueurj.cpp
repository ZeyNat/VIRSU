#include <iostream>
#include <fstream>
#include  "Oueurj.hpp"
using namespace std;

/*Constructeur*/
Oueurj::Oueurj(int x, int y,int d,int v): _Deplacable(x,y), nbDiams{d}, TP{1}, vies{v} {}


/*Gestion des diams*/

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



/*Gestion teleportation*/

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



/*Gestion des vies*/

int Oueurj::getVies(){
  return vies;
}

void Oueurj::perdVie(){
  vies--;
}

void Oueurj::setVies(int i){
  vies = i;
}



/*Sauvegarde donnes oueurj*/
//cree le fichier de sauvegarde
ofstream Oueurj::sauvegardeOueurj(string f){
  ofstream flux(f.c_str());  //on cree le fichier
  flux << "save" << endl;  //on marque le fichier comme une sauvegarde
  flux << getDiams() << endl; //on sauvegarde les diams
  flux << getTP() << endl;  //le nombre de teleportations
  flux << getVies() << endl;  //le nombre de vies
  return flux;  //on revoie le flux
}
