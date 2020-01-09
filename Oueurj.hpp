#include "Deplacable.hpp"
#include <iostream>
#ifndef OUEURJ
#define OUEURJ

class Oueurj : public _Deplacable{
  private:
    int nbDiams;
    unsigned int TP; //les teleports ramassés
  public:
    Oueurj(int x=0, int y=0, int d = 0);
    Oueurj(Oueurj j, int x, int y);
    void incrementeDiams(int i = 1);
    void decrementeDiams();
    int getDiams();
    void afficheDiams();
    bool hasTP();
    void setTP(int i = 2);
    void removeTP();
    unsigned int getTP();
    std::ofstream sauvegardeOueurj(std::string f);
};
#endif
