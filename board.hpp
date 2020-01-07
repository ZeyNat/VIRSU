#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

const unsigned int MAX_X_len = 27;
const unsigned int MAX_Y_len = 13;

const unsigned int MIN_X_len = 9;
const unsigned int MIN_Y_len = 7;

const unsigned int grandeGrille = 30;

const unsigned int maxStreumons = 3;
const unsigned int maxTeupors = 3;
const unsigned int maxGeurchars = 3;



vector<vector<char> > constructionGrille(unsigned int X, unsigned int Y){
  vector<char> ligne;
  vector<vector<char> > res;
  for (unsigned int i = 0; i < Y; i++){
    for (unsigned int j = 0; j < X; j++){
      ligne.push_back(' ');
    }
    res.push_back(ligne);
    ligne.clear();
  }
  return res;
}

bool posValide(vector<vector<char> > grille,unsigned int x,unsigned int y){
  return grille[x][y] == ' ';
}


void constructionReumus(vector<vector<char> > & grille){
  unsigned int X = grille.size();
  unsigned int Y = grille[0].size();
  for (unsigned int i = 0; i < X; i++){
    for (unsigned int j = 0; j < Y; j++){
      if (i == 0 or i == X-1 or j == 0 or j == Y-1){
        grille[i][j] = 'X';
      }
    }
  }
}



void ajoutTruc(vector<vector<char> > &grille, char c, int nb){
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

void affiche(vector<vector<char> > grille){
  for (unsigned int i = 0; i < grille.size(); i++){
    for (unsigned int j = 0; j < grille[0].size(); j++){
      cout << grille[i][j];
    }
    cout << endl;
  }
}

void ajoutTeupors(vector<vector<char> > &grille, unsigned int nbTeupors){
  unsigned int xTeupor;
  unsigned int yTeupor;
  for (unsigned int i = 0; i < nbTeupors; i++){
    do{
      xTeupor = rand()%(grille.size());
      yTeupor = rand()%(grille[0].size());
    } while(!((xTeupor == 0 or xTeupor == grille.size()-1) xor
            (yTeupor == 0 or yTeupor==grille[0].size())));
    grille[xTeupor][yTeupor] = '-';
  }
}


// pos sure : pas de streumon juste a cote
bool posSure(vector<vector<char> > grille, unsigned int x, unsigned int y){
  unsigned int X = grille.size();
  unsigned int Y = grille[0].size();
  if (posValide(grille,x,y)
        && grille[x][y-1]!='s'
        && grille[x][y]!='s'
        && grille[x][y+1]!='s'

        && grille[x+1][y-1]!='s'
        && grille[x+1][y]!='s'
        && grille[x+1][y+1]!='s'

        && grille[x-1][y-1]!='s'
        && grille[x-1][y]!='s'
        && grille[x-1][y+1]!='s')

        {
          if (y+2 < Y){
            if(grille[x-1][y+2]=='s' && grille[x][y+2]=='s' && grille[x+1][y+2]=='s'){
              return false;

            }
            if (x >= 2){
              if(grille[x-2][y+2] == 's'){
                return false;
              }
            }
            if (x+2 < X){
              if(grille[x+2][y+2]=='s'){
                return false;
              }
            }
          }
          if (y >= 2){
            if(grille[x-1][y-2]=='s' || grille[x][y+2]=='s' || grille[x+1][y+2]=='s'){
              return false;
            }
            if (x >= 2){
              if(grille[x-2][y-2] == 's'){
                return false;
              }
            }
            if (x+2 < X){
              if(grille[x+2][y-2]=='s'){
                return false;
              }
            }
          }
          if (x >= 2){
            if(grille[x-2][y-1] =='s' || grille[x-2][y] == 's' || grille[x-2][y+1]=='s'){
              return false;
            }
          }
          if (x+2 < X){
            if(grille[x+2][y-1] =='s' || grille[x+2][y] == 's' || grille[x+2][y+1]=='s'){
              return false;
            }
          }

    return true;
  }
  return false;
}



void ajoutOueurj(vector<vector<char> > &grille){
  unsigned int xOueurj;
  unsigned int yOueurj;
  do {
      xOueurj= rand()%grille.size();
      yOueurj = rand()%grille[0].size();
  } while (!posValide(grille,xOueurj,yOueurj) || !posSure(grille,xOueurj,yOueurj));
  grille[xOueurj][yOueurj] = 'J';

}



void ecriture(vector<vector<char> > grille,ofstream &flux){
  for (unsigned int i = 0; i < grille.size(); i++){
    for (unsigned int j = 0; j < grille[0].size(); j++){
      flux << grille[i][j];
    }
    flux << endl;
  }
}




void createBoard(string nom) {


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


    vector<vector<char> > grille = constructionGrille(X,Y);
    constructionReumus(grille);
    ajoutTeupors(grille,nbTeupors);
    ajoutTruc(grille,'$',nbTeupors);
    ajoutTruc(grille,'*',nbGeurchars);
    ajoutTruc(grille,'s',nbStreumon);
    ajoutOueurj(grille);

    ofstream flux(nom.c_str());

    ecriture(grille,flux);


}
