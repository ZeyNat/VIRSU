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
    unsigned int sizeX;
    unsigned int sizeY;
    vector<vector<Zeca> > tab;   //plateau des zecas. Attention il est a lenvers. cest tab[col][lig]
    vector<Streumon> streumons;
    vector<Streumon> construitStreumons();  //fct consstruction pour alleger constructeur
    vector<Zeca> teupors;
    unsigned int teuporsOuvertes;
    vector<Zeca> construitTeuports();


  public :
    Teaupla(string nomFichier);   // on construit avec un fichier texte
    unsigned int getMaxX();  //fcts tests
    unsigned int getMaxY();  //on pourra les enlever
    void affiche();   //plus tard on fera de la surcharge d'operateur

    vector<int> getCoordOueurj();   //on cree le oueurj en le cherchant sur le teaupla

    vector<Streumon> getStreumons();    // renvoie la liste des streumons

    vector<Zeca> getTeuports();

    bool posValide(int x, int y);   //Le Oueurj ne peut pas aller sur les reumus ni les teupors

    bool posSure(unsigned int x,unsigned int y); //Position securisée loin de Streumons

    /* Deplacement du Oueurj : Nord = 'z' / Nord-Est = 'e' / Nord-Ouest = 'a'
       Ouest = 'q' / Est = 'd' / Sud = 'x' / SudEst = 'c' / Sud-Ouest = 'w'
       quitter = 0 */

    bool deplaceOueurj(Oueurj& Jold);
    bool deplaceStreumons(Oueurj J);   //deplace les streumons vers le joueur J

    bool verifieDiams(int x, int y); //verifie si la zeca est un diams
    void updateDiams(); //mise à jour des diams ramassés par le oueurj

    void ouvreTeuport(); //une teuport s'ouvre lorsque Oueurj collecte un diams

    void afficheTeuport();

    bool verifieGeuchars(int x, int y);

    void teleportation(Oueurj* J);

    bool gagner(Oueurj J);


};

#endif
