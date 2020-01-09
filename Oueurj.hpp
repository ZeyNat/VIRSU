#include "Deplacable.hpp"
#include <iostream>
#ifndef OUEURJ
#define OUEURJ

class Oueurj : public _Deplacable{
  private:
    int nbDiams;
    unsigned int TP; //les teleports ramassés
    int vies;
  public:
    Oueurj(int x=0, int y=0, int d = 0, int v = 3);
    Oueurj(Oueurj j, int x, int y);
    void incrementeDiams(int i = 1);
    void decrementeDiams();
    int getDiams();
    void afficheDiams();
    bool hasTP();
    void addTP(int i = 2);
    void removeTP();
    unsigned int getTP();
    int getVies();
    void perdVie();
    void setVies(int i);
    std::ofstream sauvegardeOueurj(std::string f);
};
#endif
