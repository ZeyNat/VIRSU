#include "Deplacable.hpp"

#ifndef OUEURJ
#define OUEURJ

class Oueurj : public _Deplacable{
  private:
    int nbDiams;
    unsigned int TP;
  public:
    Oueurj(int x=0, int y=0, int d = 0);
    Oueurj(Oueurj j, int x, int y);
    void incrementeDiams();
    void decrementeDiams();
    int getDiams();
    void afficheDiams(); //affiche les Diams que possède le oueurj
    bool hasTP();
    void setTP();
    void removeTP();
    unsigned int getTP();
};
#endif
