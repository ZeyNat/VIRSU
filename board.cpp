#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
using namespace std;

const unsigned int MAX_X_len = 27;
const unsigned int MAX_Y_len = 13;

const unsigned int MIN_X_len = 9;
const unsigned int MIN_Y_len = 7;

const unsigned int grandeGrille = 30;

const unsigned int maxStreumons = 3;
const unsigned int maxTeupors = 3;
const unsigned int maxGeurchars = 3;



vector<vector<char>> constructionGrille(unsigned int X, unsigned int Y){
  vector<char> ligne;
  vector<vector<char>> res;
  for (unsigned int i = 0; i < Y; i++){
    for (unsigned int j = 0; j < X; j++){
      ligne.push_back(' ');
    }
    res.push_back(ligne);
    ligne.clear();
  }
  return res;
}

bool posValide(vector<vector<char>> grille,unsigned int x,unsigned int y){
  return grille[x][y] == ' ';
}


void constructionReumus(vector<vector<char>> & grille){
  int X = grille.size();
  int Y = grille[0].size();
  for (unsigned int i = 0; i < X; i++){
    for (unsigned int j = 0; j < Y; j++){
      if (i == 0 or i == X-1 or j == 0 or j == Y-1){
        grille[i][j] = 'X';
      }
    }
  }
}



void ajoutTruc(vector<vector<char>> &grille, char c, int nb){
  unsigned int xTruc;
  unsigned int yTruc;
  for (int i = 0; i < nb; i++){
    do {
      xTruc = rand()%grille.size();
      yTruc = rand()%grille[0].size();
    } while (!posValide(grille,xTruc,yTruc));
    grille[xTruc][yTruc] = c;
  }
}

void affiche(vector<vector<char>> grille){
  for (unsigned int i = 0; i < grille.size(); i++){
    for (unsigned int j = 0; j < grille[0].size(); j++){
      cout << grille[i][j];
    }
    cout << endl;
  }
}

void ajoutTeupors(vector<vector<char>> &grille, unsigned int nbTeupors){
  unsigned int xTeupor;
  unsigned int yTeupor;
  unsigned int xDiams;
  unsigned int yDiams;
  for (unsigned int i = 0; i < nbTeupors; i++){
    do{
      xTeupor = rand()%(grille.size());
      yTeupor = rand()%(grille[0].size());
    } while(!((xTeupor == 0 or xTeupor == grille.size()-1) xor
            (yTeupor == 0 or yTeupor==grille[0].size())));
    grille[xTeupor][yTeupor] = '-';
  }
}


void ecriture(vector<vector<char>> grille,ofstream &flux){
  for (unsigned int i = 0; i < grille.size(); i++){
    for (unsigned int j = 0; j < grille[0].size(); j++){
      flux << grille[i][j];
    }
    flux << endl;
  }
}




int main() {
    string nom = "b.board";
    srand (time(NULL));

    unsigned int X = rand()%(MAX_X_len-MIN_X_len) + MIN_X_len + 1;
    unsigned int Y = rand()%(MAX_Y_len-MIN_Y_len) + MIN_Y_len + 1;

    unsigned int nbStreumon = rand()%maxStreumons +1;
    unsigned int nbTeupors = rand()%maxTeupors +1;
    unsigned int nbGeurchars = rand()%maxGeurchars +1;

    if (X+Y >= grandeGrille){
      nbStreumon ++;
      nbTeupors ++;
      nbGeurchars ++;
    }


    cout << X << ' ' << Y << endl;

    vector<vector<char>> grille = constructionGrille(X,Y);
    constructionReumus(grille);
    ajoutTruc(grille,'J',1);
    ajoutTeupors(grille,nbTeupors);
    ajoutTruc(grille,'$',nbTeupors);
    ajoutTruc(grille,'*',nbGeurchars);
    ajoutTruc(grille,'s',nbStreumon);

    affiche(grille);

    ofstream flux(nom.c_str());

    ecriture(grille,flux);


}
