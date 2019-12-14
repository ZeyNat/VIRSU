#include<iostream>
#include <vector>
#include "Zeca.hpp"
using namespace std;

#ifndef TEAUPLA
#define TEAUPLA

class Teaupla {
  private :
    unsigned int sizeX;
    unsigned int sizeY;
    vector<vector<Zeca> > tab;   //plateau des zecas
  public :
    Teaupla(string nomFichier);   // on construit avec un fichier texte
    void affiche();   // pas ecrite, pour tester que c'est bien construit
};


#endif
