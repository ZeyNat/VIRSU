#include<iostream>
#include <vector>
#include "Zeca.hpp"

#ifndef TEAUPLA
#define TEAUPLA

class Teaupla {
  private :
    unsigned int sizeX;
    unsigned int sizeY;
    std::vector<std::vector<Zeca>> tab;
  public :
    Teaupla(std::string nomFichier);
    void affiche();
};


#endif
