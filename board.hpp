#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

//taille maximale de teaupla
const unsigned int MAX_X_len = 27;
const unsigned int MAX_Y_len = 13;

//taille minimale de teaupla
const unsigned int MIN_X_len = 9;
const unsigned int MIN_Y_len = 7;

const unsigned int grandeGrille = 30; //a partir de quand le teaupla est dit grand

//max pour chaque element
const unsigned int maxStreumons = 3;
const unsigned int maxTeupors = 3;
const unsigned int maxGeurchars = 3;


/*Fonction de construction du teaupla
 *construit un teaupla de taille aleatoire
 *dont toutes les zecas ont un contenu vide
 */
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

//Une position est dite valide si la zeca est vide
bool posValide(vector<vector<char> > grille,unsigned int x,unsigned int y){
  return grille[x][y] == ' ';
}

/*Fonction de construction des reumus
 *ajoute a un teaupla vide des reumus sur les bords
 */
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


/*Fonction dajout
 *ajoute un diams, un streumon ou un geurchars
 *caracterise par un char
 */
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


/*Fonction daffichage pour tester*/
void affiche(vector<vector<char> > grille){
  for (unsigned int i = 0; i < grille.size(); i++){
    for (unsigned int j = 0; j < grille[0].size(); j++){
      cout << grille[i][j];
    }
    cout << endl;
  }
}

/*Fonction dajout des teupors*/
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


/* Renvoie si la posotion est sure ou non
 * une position est dite sure
 * sil ny a pas de streumon dans un rayon de deux zecas
 */
bool posSure(vector<vector<char> > grille, unsigned int x, unsigned int y){
  unsigned int X = grille.size();
  unsigned int Y = grille[0].size();
  //rayon 1
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
          //rayon 2
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


/*Fonction dajout du oueurj a une posSure*/
void ajoutOueurj(vector<vector<char> > &grille){
  unsigned int xOueurj;
  unsigned int yOueurj;
  do {
      xOueurj= rand()%grille.size();
      yOueurj = rand()%grille[0].size();
  } while (!posValide(grille,xOueurj,yOueurj) || !posSure(grille,xOueurj,yOueurj));
  grille[xOueurj][yOueurj] = 'J';

}


/*Fonction decriture
 *recopie une grille donnee dans un fichier texte donne
 */
void ecriture(vector<vector<char> > grille,ofstream &flux){
  for (unsigned int i = 0; i < grille.size(); i++){
    for (unsigned int j = 0; j < grille[0].size(); j++){
      flux << grille[i][j];
    }
    flux << endl;
  }
}



/* Fonction de creation dun board
 * utilise les fonctions precedentes pour creer un teaupla complet
 * puis le recopie dans un fichier texte
 * dont le nom est donne en parametre
 */
void createBoard(string nom) {

  //On tire aleatoirement la taille du board
  unsigned int X = rand()%(MAX_X_len-MIN_X_len) + MIN_X_len + 1;
  unsigned int Y = rand()%(MAX_Y_len-MIN_Y_len) + MIN_Y_len + 1;

  //on tire aleatoirement le nombre de streumon,teupors et geurchars
  unsigned int nbStreumon = rand()%maxStreumons +1;
  unsigned int nbTeupors = rand()%maxTeupors +1;
  unsigned int nbGeurchars = rand()%maxGeurchars +1;

  //si la grille est grande, on augmente tout de 1
  if (X+Y >= grandeGrille){
    nbStreumon ++;
    nbTeupors ++;
    nbGeurchars ++;
  }

  //construction
  vector<vector<char> > grille = constructionGrille(X,Y); //la grille vide
  constructionReumus(grille);                             //les reumus
  ajoutTeupors(grille,nbTeupors);                         //les teupors
  ajoutTruc(grille,'d',nbTeupors);                        //les diams
  ajoutTruc(grille,'*',nbGeurchars);                      //les geurchars
  ajoutTruc(grille,'s',nbStreumon);                       //les streumons
  ajoutOueurj(grille);                                    //le oueurj

  ofstream flux(nom.c_str()); //on cree le fichier

  ecriture(grille,flux); //on recopie la grille


}
