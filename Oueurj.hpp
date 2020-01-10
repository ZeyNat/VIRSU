#include "Deplacable.hpp"
#include <iostream>
#ifndef OUEURJ
#define OUEURJ
using namespace std;

class Oueurj : public _Deplacable{
  private:
    int nbDiams;  //nombre de diams amasses par le oueurj
    unsigned int TP; //les teleports ramassés
    int vies; //nombre de vies restantes, 0 = game over
  public:
    //constructeurs
    Oueurj(int x=0, int y=0, int d = 0, int v = 3);
    Oueurj(Oueurj j, int x, int y);

    //gestion des diams
    void incrementeDiams(int i = 1);
    void decrementeDiams();
    int getDiams();
    void afficheDiams();

    //gestion des TP
    bool hasTP();
    void addTP(int i = 2);
    void removeTP();
    unsigned int getTP();

    //gestion des vies
    int getVies();
    void perdVie();
    void setVies(int i);

    ofstream sauvegardeOueurj(string f); //sauvegarde
};
#endif
