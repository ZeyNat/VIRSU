#include <iostream>
#include <assert.h>   //pour tester nos fcts
#include "Teaupla.hpp"
#include "Oueurj.hpp"
#include "Streumon.hpp"
using namespace std;



int main() {
  string teau = "/home/zeneb/Documents/M1_MIC/LOA/PROJET/p1.txt";  //pour toi
  //string teau = "/home/natacha/Documents/M1MIC/LOA/Projet/p1.txt";  //pour moi
  Teaupla T(teau);
  T.affiche();
  //tests dimensions
  assert(T.getMaxX()==18);
  assert(T.getMaxY()==7);

  //Tests Oueurj
  Oueurj J = T.getOueurj();
  assert(J.getX()==6);
  assert(J.getY()==4);

  //Test STREUMON
  cout << T.getStreumons().size() << endl;
  assert(T.getStreumons().size()==2);

  //Tests posValide
  assert(T.posValide(1,1));
  assert(!T.posValide(0,0));
  assert(!T.posValide(0,4));
  assert(!T.posValide(18,1));
  assert(!T.posValide(5,7));

  T.deplaceOueurj();
  return 0;
}
