#include <iostream>
#include <time.h>
#include <fstream>
#include "board.hpp"
using namespace std;

/*Programme de creation dun .game*/

int main(int argc, char **argv){
  srand (time(NULL));  //on veut des boards aleatoires
  string nom = argv[1];
  string nomGame = nom + ".game";
  int nbTeauplas = (int) *argv[2] -48;   //le nombre de boards dans le game
  ofstream flux (nomGame.c_str());  //on cree le fichier
  string nomBoard;
  char num = '1';

  flux << "NS" << endl;   //Ce nest pas une sauvegarde

  //on cree les boards et on ajoute leur nom au fichier .game
  for (int i = 1; i <= nbTeauplas; i++){
    nomBoard = nom;
    nomBoard += num;
    nomBoard += ".board";
    num++;
    createBoard(nomBoard);
    flux << nomBoard << endl;
  }

  cout << "Fichier game cree" << endl; //tout est ok

  return 0;
}
