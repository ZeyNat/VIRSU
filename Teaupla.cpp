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
  int maxY = 0;
    while(getline(f,line)){
      for (unsigned int j = 0; j < line.length(); j++){
        tab[i].push_back(Zeca(i,j,line.at(j)));
      }
      maxY = max(maxY,(int)line.length());
      i++;
    }
    sizeX = i+1;
    sizeY = (unsigned int) maxY + 1;
}
