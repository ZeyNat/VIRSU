#include<iostream>
#include <fstream>
#include <algorithm>
#include "Teaupla.hpp"
#include "Zeca.hpp"
#include "Oueurj.hpp"
using namespace std;

Teaupla::Teaupla(string nomFichier){
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


Oueurj Teaupla::getOueurj(){
  for (int i = 0;(unsigned int) i < sizeY; i++){
    for (int j = 0; (unsigned int) j < sizeX; j++){
      if(tab.at(i).at(j).getEtat() =='J'){
        return Oueurj(j,i);
      }
    }
  }
  return Oueurj(0,0);     //il faudrait une exception mais on verra plus tard
}

// pos non valide =  hors teaupla, reumu, teupor
bool Teaupla::posValide(int x, int y){
  if ((unsigned int) x < sizeX && (unsigned int) y < sizeY &&
      tab[y][x].getEtat()!='X' && tab[y][x].getEtat()!='-'){
    return true;
  }
  return false;
}


void Teaupla::deplaceOueurj(){ //deplacement du oueurj en fonction de l'entrée clavier
  Oueurj J = getOueurj();
  char mouv;
  cout<<"Jouer"<<endl;
  cin>>mouv;

  while(mouv!='0'){ //on demande au oueurj de joueur tant qu'il ne veut pas quitter (0 pour quitter la partie)
    int x = J.getX();
    int y = J.getY();
    affiche();

    //deplacement au Nord
    if(mouv=='z' && posValide(x,y-1)){
      tab[y][x].setEtat(' ');
      J.setLocalisation(x,y-1);
      cout<<"Nouvelle localisation de J est : (" << x << ", " << y-1 << ")" << endl; //pour tester
      tab[y-1][x].setEtat('J'); //mise à jour de la place du oueurj
      cout<<"Vous vous etes deplacer au Nord"<<endl;
    }

    //deplacement au Nord Est
    if(mouv=='e' && posValide(x+1,y-1)){
      tab[y][x].setEtat(' ');
      J.setLocalisation(x+1,y-1);
      cout<<"Nouvelle localisation de J est : (" << x+1 << ", " << y-1 << ")" << endl;
      tab[y-1][x+1].setEtat('J'); //mise à jour de la place du oueurj
      cout<<"Vous vous etes deplacer au Nord Est"<<endl;
    }

    //deplacement au Nord Ouest
    if(mouv=='a' && posValide(x-1,y-1)){
      tab[y][x].setEtat(' ');
      J.setLocalisation(x-1,y-1);
      cout<<"Nouvelle localisation de J est : (" << x-1 << ", " << y-1 << ")" << endl;
      tab[y-1][x-1].setEtat('J'); //mise à jour de la place du oueurj
      cout<<"Vous vous etes deplacer au Nord Ouest"<<endl;
    }

    //deplacement a l'Est
    if(mouv=='d' && posValide(x+1,y)){
      tab[y][x].setEtat(' ');
      J.setLocalisation(x+1,y);
      cout<<"Nouvelle localisation de J est : (" << x+1 << ", " << y << ")" << endl;
      tab[y][x+1].setEtat('J'); //mise à jour de la place du oueurj
      cout<<"Vous vous etes deplacer a l'Est"<<endl;
    }

    //deplacement a l'Ouest
    if(mouv=='q' && posValide(x-1,y)){
      tab[y][x].setEtat(' ');
      J.setLocalisation(x-1,y);
      cout<<"Nouvelle localisation de J est : (" << x-1 << ", " << y << ")" << endl;
      tab[y][x-1].setEtat('J'); //mise à jour de la place du oueurj
      cout<<"Vous vous etes deplacer a l'Ouest"<<endl;
    }

    //deplacement au Sud
    if(mouv=='x' && posValide(x,y+1)){
      tab[y][x].setEtat(' ');
      J.setLocalisation(x,y+1);
      cout<<"Nouvelle localisation de J est : (" << x << ", " << y+1 << ")" << endl;
      tab[y+1][x].setEtat('J'); //mise à jour de la place du oueurj
      cout<<"Vous vous etes deplacer au Sud"<<endl;
    }

    //deplacement au Sud Est
    if(mouv=='c' && posValide(x+1,y+1)){
      tab[y][x].setEtat(' ');
      J.setLocalisation(x+1,y+1);
      cout<<"Nouvelle localisation de J est : (" << x+1 << ", " << y+1 << ")" << endl;
      tab[y+1][x+1].setEtat('J'); //mise à jour de la place du oueurj
      cout<<"Vous vous etes deplacer au Sud Est"<<endl;
    }

    //deplacement au Sud Ouest
    if(mouv=='w' && posValide(x-1,y+1)){
      tab[y][x].setEtat(' ');
      J.setLocalisation(x-1,y+1);
      cout<<"Nouvelle localisation de J est : (" << x-1 << ", " << y+1 << ")" << endl;
      tab[y+1][x-1].setEtat('J'); //mise à jour de la place du oueurj
      cout<<"Vous vous etes deplacer au Sud Ouest"<<endl;
    }

    affiche();
    cout<<"Jouer"<<endl;
    cin>>mouv;
  }

}
