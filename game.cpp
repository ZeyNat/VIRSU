#include <iostream>
#include <time.h>
#include <fstream>
#include "board.hpp"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main(int argc, char **argv){
  srand (time(NULL));
  string nom = argv[1];
  nom += ".game";
  int nbTeauplas = (int) *argv[2] -48;
  ofstream flux (nom.c_str());
  string nomBoard;
  char num = '1';

  flux << "NS" << endl;   //Ce nest pas une sauvegarde
  for (int i = 1; i <= nbTeauplas; i++){
    nomBoard = "b";
    nomBoard += num;
    nomBoard += ".board";
    num++;
    cout << nomBoard << endl;
    createBoard(nomBoard);
    flux << nomBoard << endl;
  }
}
