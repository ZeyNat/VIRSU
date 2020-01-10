#ifndef ZECA
#define ZECA


class Zeca{
  private:
    //coordonnees
    int X;
    int Y;

    char etat; //oueurj = J / streumons = s / remus = X / diams = d / geurchars = * /teupors = p / vide =' '

  public:
    //constructeurs
    Zeca();
    Zeca(int x, int y, char e);

    //getteurs pour X et Y
    int getX();
    int getY();

    //gestion attribut etat
    void setEtat(char e);
    char getEtat();
};

#endif
