#include <iostream>
#include <assert.h>   //pour tester nos fcts
#include <fstream>
#include <sstream>
#include <string>
#include "Teaupla.hpp"
#include "Oueurj.hpp"
#include "Streumon.hpp"

using namespace std;



int main(int argc, char **argv) {

  if(argc < 2) {
    cout << "Veuillez donner un fichier game" << endl;
    return 0;
  }

  cout << "BIENVENUE DANS LE VIRSU !!!" << endl << endl;

  /*chemin pour acceder aux fichiers de jeu*/
  //string teau = "/home/zeneb/Documents/M1_MIC/LOA/PROJET/";
  string teau = "/home/natacha/Documents/M1MIC/LOA/Projet/";

  string game = teau + argv[1] + ".game";




  ifstream f;
  f.open(game);
  string line;
  bool encore = true;
  bool victoire = false;
  bool defaite = false;
  Oueurj J;
  int lvl = 0; //numero teaupla

  getline(f,line);
  if(line == "save"){
    getline(f,line);
    J.incrementeDiams(stoi (line));
    getline(f,line);
    J.setTP(stoi (line)-1);
    getline(f,line);
    lvl = stoi (line) -1;
  }


  while(encore && getline(f,line)){
    Teaupla T(teau+line);
    lvl++; //on incremente le niveau si le Oueurj passe un teaupla
    cout << " Niveau : " << lvl << endl;
    T.affiche();
    encore = T.deplaceOueurj(J);
    victoire = T.gagner(J);
    defaite = T.defaite();
  }

  if(victoire){
    cout << endl << "Felicitations, vous avez gagné ! " << endl;
    return 0;
  }

  //sauvegarde
  if(!defaite){
    string sauve;
    cout << "Souhaitez vous sauvegarder la partie ? (o/n)";
    cin >> sauve;
    if (sauve == "O" || sauve == "o"){
      cout << "Entrez le nom de sauvegarde : ";
      cin >> sauve;
      ofstream sauvegarde = J.sauvegardeOueurj(sauve+".game");
      sauvegarde << lvl << endl;
      sauvegarde << line << endl;
      while (getline(f,line)){
        sauvegarde << line << endl;
      }
    }
  }


  return 0;
}
