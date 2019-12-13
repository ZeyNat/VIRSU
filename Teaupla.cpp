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
    //lecture fichier et init des Zecas
    while(getline(f,line)){
      for (unsigned int j = 0; j < line.length(); j++){
        tab[i].push_back(Zeca(i,j,line.at(j)));
      }
      maxX = max(maxX,(int)line.length());   //je prends le max des largeurs
      i++;
    }
    sizeY = i+1;   // on sauvegarde la taille du platea ca servira surement
    sizeX = (unsigned int) maxX + 1;
}
