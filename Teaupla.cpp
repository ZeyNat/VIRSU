#include <iostream>
#include <fstream>
#include <time.h>
#include <algorithm>
#include "Teaupla.hpp"
#include "Zeca.hpp"
#include "Oueurj.hpp"
#include "Streumon.hpp"
using namespace std;

Teaupla::Teaupla(string nomFichier) : teuporsOuvertes{0} {
  ifstream f;
  f.open(nomFichier);
  string line;
  unsigned int i = 0;
  int maxX = 0;
  vector<Zeca> v;
    //lecture fichier et init des Zecas
  while(getline(f,line)){
    for (unsigned int j = 0; j < line.length(); j++){
      v.push_back(Zeca(i,j,line.at(j)));
    }
    maxX = max(maxX,(int)line.length());   //je prends le max des largeurs
    i++;
    tab.push_back(v);
    v.clear();
    }
  sizeY = i;   // on sauvegarde la taille du teaupla ca servira surement
  sizeX = (unsigned int) maxX;

  streumons = construitStreumons();
  teupors = construitTeuports();

  srand (time(NULL));
}




vector<Streumon> Teaupla::construitStreumons(){
  vector<Streumon> s;
  for (int i = 0;(unsigned int) i < sizeY; i++){
    for (int j = 0; (unsigned int) j < sizeX; j++){
      if(tab.at(i).at(j).getEtat() =='s'){
        s.push_back(Streumon(j,i));
      }
    }
  }
  return s;
}




vector<Zeca> Teaupla::construitTeuports(){
  vector<Zeca> t;
  for (int i = 0;(unsigned int) i < sizeY; i++){
    for (int j = 0; (unsigned int) j < sizeX; j++){
      if(tab.at(i).at(j).getEtat() =='-'){
        t.push_back(Zeca(i,j,'-'));
      }
    }
  }
  return t;
}




void Teaupla::affiche(){
  for (unsigned int i = 0 ; i < sizeY; i++){
    for (Zeca z : tab[i]){
      cout << z.getEtat();
    }
    cout << endl;
  }
}




unsigned int Teaupla::getMaxX(){ return sizeX;}

unsigned int Teaupla::getMaxY(){ return sizeY;}

vector<Streumon> Teaupla::getStreumons() {return streumons;}

vector<Zeca> Teaupla::getTeuports() {return teupors;}




vector<int> Teaupla::getCoordOueurj(){
  for (int i = 0;(unsigned int) i < sizeY; i++){
    for (int j = 0; (unsigned int) j < sizeX; j++){
      if(tab.at(i).at(j).getEtat() =='J'){
        return {j,i};
      }
    }
  }
  return{}  ;   //il faudrait une exception mais on verra plus tard
}




// pos non valide =  hors teaupla, reumu, teupor
bool Teaupla::posValide(int x, int y){
  if ((unsigned int) x < sizeX && (unsigned int) y < sizeY &&
      tab[y][x].getEtat()!='X' && tab[y][x].getEtat()!='-' && tab[y][x].getEtat()!='s'){
    return true;
  }
  return false;
}


// pos sure : pas de streumon juste a cote
bool Teaupla::posSure(unsigned int x, unsigned int y){
  unsigned int X = getMaxX();
  unsigned int Y = getMaxY();
  if (posValide(x,y)
        && tab[y][x-1].getEtat()!='s'
        && tab[y][x].getEtat()!='s'
        && tab[y][x+1].getEtat()!='s'

        && tab[y+1][x-1].getEtat()!='s'
        && tab[y+1][x].getEtat()!='s'
        && tab[y+1][x+1].getEtat()!='s'

        && tab[y-1][x-1].getEtat()!='s'
        && tab[y-1][x].getEtat()!='s'
        && tab[y-1][x+1].getEtat()!='s')

        {
          if (x+2 < X){
            if(tab[y-1][x+2].getEtat()=='s' && tab[y][x+2].getEtat()=='s' && tab[y+1][x+2].getEtat()=='s'){
              return false;

            }
            if (y >= 2){
              if(tab[y-2][x+2].getEtat() == 's'){
                return false;
              }
            }
            if (y+2 < Y){
              if(tab[y+2][x+2].getEtat()=='s'){
                return false;
              }
            }
          }
          if (x >= 2){
            if(tab[y-1][x-2].getEtat()=='s' || tab[y][x+2].getEtat()=='s' || tab[y+1][x+2].getEtat()=='s'){
              return false;
            }
            if (y >= 2){
              if(tab[y-2][x-2].getEtat() == 's'){
                return false;
              }
            }
            if (y+2 < Y){
              if(tab[y+2][x-2].getEtat()=='s'){
                return false;
              }
            }
          }
          if (y >= 2){
            cout << y << endl;
            if(tab[y-2][x-1].getEtat() =='s' || tab[y-2][x].getEtat() == 's' || tab[y-2][x+1].getEtat()=='s'){
              return false;
            }
          }
          if (y+2 < Y){
            if(tab[y+2][x-1].getEtat() =='s' || tab[y+2][x].getEtat() == 's' || tab[y+2][x+1].getEtat()=='s'){
              return false;
            }
          }

    return true;
  }
  return false;
}




bool Teaupla::verifieDiams(int x, int y){
  return (tab[y][x].getEtat()=='$');
}






bool Teaupla::verifieGeuchars(int x, int y){
  return (tab[y][x].getEtat()=='*');
}




void Teaupla::teleportation(Oueurj* J){

  int xrand;
  int yrand;
  int x = J->getX();
  int y = J->getY();
  do{
    xrand = rand()%(getMaxX());
    yrand = rand()%(getMaxY());
  } while(!posSure(xrand,yrand));
  tab[y][x].setEtat(' ');
  J->setLocalisation(xrand,yrand);
  tab[yrand][xrand].setEtat('J'); //mise à jour de la place du oueurj
  J->removeTP();
  cout<< "Vous vous etes TELEPORTES à la position (" << xrand <<',' << yrand << ")" << endl;

  if (verifieGeuchars(xrand,yrand)){
    J.setTP();  //on lui donne une TP
  }
  else{
      if (verifieDiams(xrand,yrand)){ //si le oueurj veut recuperer un diams
        J.incrementeDiams();
        ouvreTeuport();
      }
    }
}



bool Teaupla::deplaceOueurj(Oueurj& J){ //deplacement du oueurj en fonction de l'entrée clavier
  vector<int> coord = getCoordOueurj();
  J.setLocalisation(coord[0],coord[1]);
  bool perdu = false;
  char mouv;
  J.afficheDiams();
  cout << "Teleports : " << J.getTP() << endl;


  do{ //on demande au oueurj de joueur tant qu'il ne veut pas quitter (0 pour quitter la partie)
    cout<<"Jouer"<<endl;
    cin>>mouv;
    int x = J.getX();
    int y = J.getY();

    //deplacement au Nord
    if(mouv=='z' && posValide(x,y-1)){
        if (verifieGeuchars(x,y-1)){
          J.setTP();  //on lui donne une TP
        }
        else{
            if (verifieDiams(x,y-1)){ //si le oueurj veut recuperer un diams
              J.incrementeDiams();
              ouvreTeuport();
            }
          }
        tab[y][x].setEtat(' ');
        J.setLocalisation(x,y-1);
        //cout<<"Nouvelle localisation de J est : (" << x << ", " << y-1 << ")" << endl; //pour tester
        tab[y-1][x].setEtat('J'); //mise à jour de la place du oueurj
        //cout<<"Vous vous etes deplaces au Nord"<<endl;
    }


    //deplacement au Nord Est
    if(mouv=='e' && posValide(x+1,y-1)){

      if (verifieGeuchars(x+1,y-1)){
        J.setTP();  //on lui donne une TP
      }

      else{
        if (verifieDiams(x+1,y-1)){
          J.incrementeDiams();
          ouvreTeuport();
        }
      }
      tab[y][x].setEtat(' ');
      J.setLocalisation(x+1,y-1);
      //cout<<"Nouvelle localisation de J est : (" << x+1 << ", " << y-1 << ")" << endl;
      tab[y-1][x+1].setEtat('J'); //mise à jour de la place du oueurj
      //cout<<"Vous vous etes deplacer au Nord Est"<<endl;
    }


    //deplacement au Nord Ouest
    if(mouv=='a' && posValide(x-1,y-1)){

      if (verifieGeuchars(x-1,y-1)){
        J.setTP();  //on lui donne une TP
      }

      else{
        if (verifieDiams(x-1,y-1)){
          J.incrementeDiams();
          ouvreTeuport();
        }
      }
        tab[y][x].setEtat(' ');
        J.setLocalisation(x-1,y-1);
        //cout<<"Nouvelle localisation de J est : (" << x-1 << ", " << y-1 << ")" << endl;
        tab[y-1][x-1].setEtat('J'); //mise à jour de la place du oueurj
        //cout<<"Vous vous etes deplacer au Nord Ouest"<<endl;
    }

    //deplacement a l'Est
    if(mouv=='d' && posValide(x+1,y)){

      if (verifieGeuchars(x+1,y)){
        J.setTP();  //on lui donne une TP
      }

      else{
        if (verifieDiams(x+1,y)){
          J.incrementeDiams();
          ouvreTeuport();
        }
      }
        tab[y][x].setEtat(' ');
        J.setLocalisation(x+1,y);
        //cout<<"Nouvelle localisation de J est : (" << x+1 << ", " << y << ")" << endl;
        tab[y][x+1].setEtat('J'); //mise à jour de la place du oueurj
        //cout<<"Vous vous etes deplacer a l'Est"<<endl;
    }

    //deplacement a l'Ouest
    if(mouv=='q' && posValide(x-1,y)){

      if (verifieGeuchars(x-1,y)){
        J.setTP();  //on lui donne une TP
      }
      else{
        if (verifieDiams(x-1,y)){
          J.incrementeDiams();
          ouvreTeuport();
        }
      }
        tab[y][x].setEtat(' ');
        J.setLocalisation(x-1,y);
        //cout<<"Nouvelle localisation de J est : (" << x-1 << ", " << y << ")" << endl;
        tab[y][x-1].setEtat('J'); //mise à jour de la place du oueurj
        //cout<<"Vous vous etes deplacer a l'Ouest"<<endl;
    }

    //deplacement au Sud
    if(mouv=='x' && posValide(x,y+1)){

      if (verifieGeuchars(x,y+1)){
        J.setTP();  //on lui donne une TP
      }

      else{
        if (verifieDiams(x,y+1)){
          J.incrementeDiams();
          ouvreTeuport();
        }
      }
        tab[y][x].setEtat(' ');
        J.setLocalisation(x,y+1);
        //cout<<"Nouvelle localisation de J est : (" << x << ", " << y+1 << ")" << endl;
        tab[y+1][x].setEtat('J'); //mise à jour de la place du oueurj
        //cout<<"Vous vous etes deplacer au Sud"<<endl;
    }

    //deplacement au Sud Est
    if(mouv=='c' && posValide(x+1,y+1)){

      if (verifieGeuchars(x+1,y+1)){
        J.setTP();  //on lui donne une TP
      }
      else{
        if (verifieDiams(x+1,y+1)){
        J.incrementeDiams();
        ouvreTeuport();
        }
      }
        tab[y][x].setEtat(' ');
        J.setLocalisation(x+1,y+1);
        //cout<<"Nouvelle localisation de J est : (" << x+1 << ", " << y+1 << ")" << endl;
        tab[y+1][x+1].setEtat('J'); //mise à jour de la place du oueurj
        //cout<<"Vous vous etes deplacer au Sud Est"<<endl;
    }

    //deplacement au Sud Ouest
    if(mouv=='w' && posValide(x-1,y+1)){

      if (verifieGeuchars(x-1,y+1)){
        J.setTP();  //on lui donne une TP
      }
      else{
        if (verifieDiams(x-1,y+1)){
          J.incrementeDiams();
          ouvreTeuport();
        }
      }
        tab[y][x].setEtat(' ');
        J.setLocalisation(x-1,y+1);
        //cout<<"Nouvelle localisation de J est : (" << x-1 << ", " << y+1 << ")" << endl;
        tab[y+1][x-1].setEtat('J'); //mise à jour de la place du oueurj
        //cout<<"Vous vous etes deplacer au Sud Ouest"<<endl;
    }

    //Teleportation
    if(mouv=='s' && J.hasTP()){
      if (verifieGeuchars(x-1,y+1)){
        J.setTP();  //on lui donne une TP
      }
      else{
        if (verifieDiams(x-1,y+1)){
          J.incrementeDiams();
          ouvreTeuport();
        }
      }
        tab[y][x].setEtat(' ');
        teleportation(&J); //on teleporte
    }

    perdu = deplaceStreumons(J);

    affiche();
    J.afficheDiams();
    cout << "Teleports : " << J.getTP() << endl;
    //afficheTeuport();
    if(gagner(J)){
      cout<<"BRAVOOOOOOOO !!!"<<endl;
    }
  } while(mouv!='0' && !perdu && !gagner(J));

  if (perdu) {cout << "Perdu ! Le Oueurj sest fait febou par un streumon ! NOMNOMNOM !!!" << endl;}
  return gagner(J);
}



//ouvre une porte aleatoirement
void Teaupla::ouvreTeuport(){
    if(teupors.size() == teuporsOuvertes)  {return;}
    int i;
    do{
      i=rand()%(getTeuports().size());
    } while(teupors.at(i).getEtat()!='-');
    cout<<"OULALAAAA"<<endl;
    teupors.at(i).setEtat('+');
    tab[teupors.at(i).getX()][teupors.at(i).getY()].setEtat('+');
    teuporsOuvertes++;
}


//return true si un streumon a foubé le oueurj.
bool Teaupla::deplaceStreumons(Oueurj J){
  int xJ = J.getX();
  int yJ = J.getY();
  int x,y;
  bool dep;

  for (int i = 0; (unsigned int) i < streumons.size(); i++){
    dep = false;
    x = streumons.at(i).getX();
    y = streumons.at(i).getY();
    tab[y][x].setEtat(streumons.at(i).getSousSesPieds());

    //SE
    if (x < xJ && y < yJ && posValide(x+1,y+1) && !dep){
      //cout << "SE" << endl;
      streumons.at(i).setLocalisation(x+1,y+1);
      streumons.at(i).setSousSesPieds(tab[y+1][x+1].getEtat());
      tab[y+1][x+1].setEtat('s');
      dep = true;
    }

    //NE
    if (x < xJ && y > yJ && posValide(x+1,y-1) && !dep){
      //cout << "NE" << endl;
      streumons.at(i).setLocalisation(x+1,y-1);
      streumons.at(i).setSousSesPieds(tab[y-1][x+1].getEtat());
      tab[y-1][x+1].setEtat('s');
      dep = true;
    }

    //SO
    if(x > xJ && y < yJ && posValide(x-1,y+1) && !dep){
      //cout << "SO" << endl;
      streumons.at(i).setLocalisation(x-1,y+1);
      streumons.at(i).setSousSesPieds(tab[y+1][x-1].getEtat());
      tab[y+1][x-1].setEtat('s');
      dep = true;
    }

    //NO
    if(x > xJ && y > yJ && posValide(x-1,y-1) && !dep){
      //cout << "NO" << endl;
      streumons.at(i).setLocalisation(x-1,y-1);
      streumons.at(i).setSousSesPieds(tab[y-1][x-1].getEtat());
      tab[y-1][x-1].setEtat('s');
      dep = true;
    }

    //O
    if (x > xJ && posValide(x-1,y) && !dep){
      //cout << "O" << endl;
      streumons.at(i).setLocalisation(x-1,y);
      streumons.at(i).setSousSesPieds(tab[y][x-1].getEtat());
      tab[y][x-1].setEtat('s');
      dep = true;
    }

    //E
    if (x < xJ && posValide(x+1,y) && !dep){
      //cout << "E" << endl;
      streumons.at(i).setLocalisation(x+1,y);
      streumons.at(i).setSousSesPieds(tab[y][x+1].getEtat());
      tab[y][x+1].setEtat('s');
      dep = true;
    }

    //N
    if (y > yJ && posValide(x,y-1) && !dep){
      //cout << "N" << endl;
      streumons.at(i).setLocalisation(x,y-1);
      streumons.at(i).setSousSesPieds(tab[y-1][x].getEtat());
      tab[y-1][x].setEtat('s');
      dep = true;
    }

    //S
    if(y < yJ && posValide(x,y+1) && !dep){
      //cout << "S" << endl;
      streumons.at(i).setLocalisation(x,y+1);
      streumons.at(i).setSousSesPieds(tab[y+1][x].getEtat());
      tab[y+1][x].setEtat('s');
      dep = true;
    }
    if (!dep) {
      tab[y][x].setEtat('s');
    }

    if(streumons.at(i).getX() == xJ && streumons.at(i).getY() == yJ){
      return true;
    }
  }
  return false;
}



void Teaupla::afficheTeuport(){
  cout<<"****************"<<endl;
  cout<< "Teuport : " <<endl;
  for (unsigned int z=0; z<teupors.size(); z++){
    cout<<teupors[z].getEtat()<<endl;
  }
  cout<<"****************"<<endl;
}



bool Teaupla::gagner(Oueurj J){
  for (unsigned int z=0; z<teupors.size(); z++){
    if (teupors[z].getEtat()=='+' && teupors[z].getY()==J.getX() && teupors[z].getX()==J.getY()){
      return true;
    }
  }
  return false;
}
