#include <iostream>
#include <assert.h>   //pour tester nos fcts
#include <fstream>
#include "Teaupla.hpp"
#include "Oueurj.hpp"
#include "Streumon.hpp"
using namespace std;



int main(int argc, char **argv) {
  //string teau = "/home/zeneb/Documents/M1_MIC/LOA/PROJET/b.board";  //pour moi haha
  string teau = "/home/natacha/Documents/M1MIC/LOA/Projet/";  //pour toi hihi ;)
  string game = teau + argv[1] + ".game";

  int lvl = 1;

  ifstream f;
  f.open(game);
  string line;
  bool encore = true;
  Oueurj J;
  while(getline(f,line) && encore){
    Teaupla T(teau+line);
    cout << " Niveau : " << lvl << endl;
    T.affiche();
    encore = T.deplaceOueurj(&J);
    lvl++;
}

  return 0;
}
