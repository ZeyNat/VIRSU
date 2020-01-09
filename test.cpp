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
    J.addTP(stoi (line)-1);
    getline(f,line);
    J.setVies(stoi (line));
    getline(f,line);
    lvl = stoi (line) -1;
  }


  while(encore && getline(f,line)){
    lvl++; //on incremente le niveau si le Oueurj passe un teaupla
    do{
      Teaupla T(teau+line);
      cout << " Niveau : " << lvl << endl;
      T.affiche();
      encore = T.deplaceOueurj(J);
      victoire = T.gagner(J);
      defaite = T.defaite();
      if (defaite && J.getTP() == 0) {J.addTP(1);}
    } while(defaite && J.getVies() > 0);
  }

  if(victoire){
    cout << endl << "Felicitations, vous avez gagné ! " << endl;
    cout << "SCORE : " << J.getVies()*(J.getDiams()+J.getTP()) << endl;
    return 0;
  }

  //sauvegarde
  if(J.getVies() != 0){
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
