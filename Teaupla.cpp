#include<iostream>
#include <fstream>
#include <algorithm>
#include "Teaupla.hpp"
#include "Zeca.hpp"
#include "Oueurj.hpp"
using namespace std;

Teaupla::Teaupla(string nomFichier){
  ifstream f;
  f.open(nomFichier);
  string line;
  unsigned int i = 0;
  int maxX = 0;
  vector<Zeca> v;
    //lecture fichier et init des Zecas
    while(getline(f,line)){
      for (unsigned int j = 0; j < line.length(); j++){
        v.push_back(Zeca(i,j,line.at(j)));
      }
      maxX = max(maxX,(int)line.length());   //je prends le max des largeurs
      i++;
      tab.push_back(v);
      v.clear();
    }
    sizeY = i;   // on sauvegarde la taille du teaupla ca servira surement
    sizeX = (unsigned int) maxX;

}



void Teaupla::affiche(){
  for (unsigned int i = 0 ; i < sizeY; i++){
    for (Zeca z : tab[i]){
      cout << z.getEtat();
    }
    cout << endl;
  }
}

unsigned int Teaupla::getMaxX(){ return sizeX;}
unsigned int Teaupla::getMaxY(){ return sizeY;}


Oueurj Teaupla::getOueurj(){
  for (int i = 0;(unsigned int) i < sizeY; i++){
    for (int j = 0; (unsigned int) j < sizeX; j++){
      if(tab.at(i).at(j).getEtat() =='J'){
        return Oueurj(j,i);
      }
    }
  }
  return Oueurj(0,0);     //il faudrait une exception mais on verra plus tard
}

// pos non valide =  hors teaupla, reumu, teupor
bool Teaupla::posValide(int x, int y){
  if ((unsigned int) x < sizeX && (unsigned int) y < sizeY &&
      tab[y][x].getEtat()!='X' && tab[y][x].getEtat()!='-'){
    return true;
  }
  return false;
}
