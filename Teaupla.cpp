#include<iostream>
#include <fstream>
#include <algorithm>
#include "Teaupla.hpp"
#include "Zeca.hpp"
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
