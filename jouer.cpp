#include <iostream>
#include <assert.h>   //pour tester nos fcts
#include <fstream>
#include "Teaupla.hpp"
#include "Oueurj.hpp"
#include "Streumon.hpp"

using namespace std;

/*Pour lancer une partie*/

int main(int argc, char **argv) {

  if(argc < 2) {
    cout << "Veuillez donner un fichier game" << endl;
    return 0;
  }

  cout << "BIENVENUE DANS LE VIRSU !!!" << endl << endl;

  /*chemin pour acceder aux fichiers de jeu*/
  string game = argv[1];
  game += ".game";

  //onverture du fichier .game et preparatifs a la lecture
  ifstream f;
  f.open(game);
  string line;
  bool encore = true;     //true si le oueurj souhaite continuer
  bool victoire = false;  //true si la partie est gagnee
  bool defaite = false;   //true si le oueurj sest fait febou (il peut lui rester des vies)
  Oueurj J;
  int lvl = 0; //numero teaupla


  //on verifie si cest une sauvegarde
  //si oui, importer les informations de la partie
  getline(f,line);
  if(line == "save"){
    getline(f,line);
    J.incrementeDiams(stoi (line));  //on recupere les diams
    getline(f,line);
    J.addTP(stoi (line)-1);  //les teleportations
    getline(f,line);
    J.setVies(stoi (line));  //les vies
    getline(f,line);
    lvl = stoi (line) -1;  //le niveau
  }

  //tant que lutilisateur souhaite continuer quil na pas perdu et quil na pas fini
  while(encore && getline(f,line)){
    lvl++; //on incremente le niveau si le Oueurj passe un teaupla

    //on reste dans le do while tant quon a pas perdu et quon a pas passer le teaupla
    do{
      //on cree le teaupla. On le recharge si le oueurj sest fait febou mais quil lui reste des vies
      Teaupla T(line,lvl);
      //on lance le jeu et on met a jour les boolens
      encore = T.deplaceOueurj(J);
      victoire = T.gagner(J);
      defaite = T.defaite();

      //on donne au oueurj 1 teleportation sil nen a plus et quil sest fait febou
      if (defaite && J.getTP() == 0) {J.addTP(1);}
    } while(defaite && J.getVies() > 0);
  }
  //la partie est terminee a partir dici


  //si le oueurj a gagne
  if(victoire){
    cout << endl << "Felicitations, vous avez gagné ! " << endl;
    //on calcule et affiche son score
    cout << "SCORE : " << J.getVies()*J.getDiams()*lvl + J.getTP() << endl;
    return 0;
  }

  //sauvegarde
  //on peut sauvearder si lutilisateur a decide darreter de jouer et quil na pas perdu
  if(J.getVies() > 0){
    string sauve;
    cout << "Souhaitez vous sauvegarder la partie ? (o/n)";
    cin >> sauve;
    if (sauve == "O" || sauve == "o"){
      cout << "Entrez le nom de sauvegarde : "; //on choisit un nom de sauvegarde
      cin >> sauve;

      //on cree le fichier de sauvegarde
      ofstream sauvegarde = J.sauvegardeOueurj(sauve+".game"); //les donnees du oueurj
      sauvegarde << lvl << endl; //le niveau
      sauvegarde << line << endl; //le teaupla actuel (il sera recharge du debut)
      while (getline(f,line)){
        sauvegarde << line << endl;  //les teauplas a venir
      }
    }
  }


  return 0;
}
