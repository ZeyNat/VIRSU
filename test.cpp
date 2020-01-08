#include <iostream>
#include <assert.h>   //pour tester nos fcts
#include <fstream>
#include "Teaupla.hpp"
#include "Oueurj.hpp"
#include "Streumon.hpp"
using namespace std;



int main(int argc, char **argv) {

  if(argc < 2) {
    cout << "Veuillez donner un fichier game" << endl;
    return 0;
  }


  string teau = "/home/zeneb/Documents/M1_MIC/LOA/PROJET/";
  //string teau = "/home/natacha/Documents/M1MIC/LOA/Projet/";
  string game = teau + argv[1] + ".game";

  int lvl = 1; //niveau du Oueurj

  ifstream f;
  f.open(game);
  string line;
  bool encore = true;
  Oueurj J;
  while(getline(f,line) && encore){
    Teaupla T(teau+line);
    cout << " Niveau : " << lvl << endl;
    T.affiche();
    encore = T.deplaceOueurj(J);
    lvl++; //on incremente le niveau si le Oueurj gagne la partie
}

  return 0;
}
