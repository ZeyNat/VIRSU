#include<iostream>
#include <vector>
#include "Zeca.hpp"
#include "Oueurj.hpp"
#include "Streumon.hpp"
using namespace std;

#ifndef TEAUPLA
#define TEAUPLA

class Teaupla {

  private :
    //taille teaupla
    unsigned int sizeX;
    unsigned int sizeY;

    int lvl; //le niveau correspondant au teaupla

    vector<vector<Zeca>> tab;   //plateau des zecas. Attention il est a lenvers. cest tab[col][lig]

    //les streumons
    vector<Streumon> streumons; //tableau de streumons
    vector<Streumon> construitStreumons();  //fct construction pour alleger constructeur

    //les teupors
    vector<Zeca> teupors; //tableau de teupors
    unsigned int teuporsOuvertes; //nb de teupors ouvertes
    vector<Zeca> construitTeuports(); //fct de construction

    bool perdu; //les streumons ont ils febou le oueurj


  public :
    Teaupla(string nomFichier, int l);   // on construit avec un fichier texte

    //getters de tailles de teaupla
    unsigned int getMaxX();
    unsigned int getMaxY();

    void affiche();   //plus tard on fera de la surcharge d'operateur

    vector<int> getCoordOueurj();  //renvoie coordonnees du oueurj sur le teaupla
    vector<Streumon> getStreumons();    // renvoie la liste des streumons
    vector<Zeca> getTeuports();  //renvoie la liste des teupors

    bool posValide(int x, int y);   //pas un reumu ni une teupors ni un streumons
    bool posSure(unsigned int x,unsigned int y); //Position securisée loin de Streumons

    /* Deplacement du Oueurj : Nord = 'z' / Nord-Est = 'e' / Nord-Ouest = 'a'
       Ouest = 'q' / Est = 'd' / Sud = 'x' / SudEst = 'c' / Sud-Ouest = 'w'
       quitter = 0 */

    bool deplaceOueurj(Oueurj& Jold);
    bool deplaceStreumons(Oueurj J);   //deplace les streumons vers le joueur J
    void teleportation(Oueurj* J); //teleporte le oueurj a une posSure

    bool verifieDiams(int x, int y); //verifie si la zeca a un diams

    bool verifieGeuchars(int x, int y); //verifie si la zeca a un geurchar

    void ouvreTeuport(); //ouvre une teupor au hasard

    bool gagner(Oueurj J); //estce que le oueurj est sur une teupor ouverte
    bool defaite(); //renvoie la valeur de perdu


};

#endif
