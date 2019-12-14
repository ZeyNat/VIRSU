#include<iostream>
#include <vector>
#include "Zeca.hpp"
#include "Oueurj.hpp"
using namespace std;

#ifndef TEAUPLA
#define TEAUPLA

class Teaupla {
  private :
    unsigned int sizeX;
    unsigned int sizeY;
    vector<vector<Zeca> > tab;   //plateau des zecas. Attention il est a lenvers. cest tab[col][lig]
  public :
    Teaupla(string nomFichier);   // on construit avec un fichier texte
    unsigned int getMaxX();  //fcts tests
    unsigned int getMaxY();  //on pourra les enlever
    void affiche();   //plus tard on fera de la surcharge d'operateur
    Oueurj getOueurj();   //on cree le oueurj en le cherchant sur le teaupla
    bool posValide(int x, int y);   //Le Oueurj ne peut pas aller sur les reumus ni les teupors

    /* Deplacement du Oueurj : Nord = 'z' / Nord-Est = 'e' / Nord-Ouest = 'a'
       Ouest = 'q' / Est = 'd' / Sud = 'x' / SudEst = 'c' / Sud-Ouest = 'w'
       quitter = 0 */
    void deplaceOueurj();

};


#endif
