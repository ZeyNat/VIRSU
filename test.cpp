#include <iostream>
#include <assert.h>   //pour tester nos fcts
#include "Teaupla.hpp"
#include "Oueurj.hpp"
using namespace std;



int main() {
  string teau = "/home/natacha/Documents/M1MIC/LOA/Projet/p1.txt";  //a modifier pour toi !
  Teaupla T(teau);
  T.affiche();
  //tests dimensions
  assert(T.getMaxX()==18);
  assert(T.getMaxY()==7);

  //Tests Oueurj
  Oueurj J = T.getOueurj();
  assert(J.getX()==6);
  assert(J.getY()==5);

  //Tests posValide
  assert(T.posValide(1,1));
  assert(!T.posValide(0,0));
  assert(!T.posValide(0,4));
  assert(!T.posValide(18,1));
  assert(!T.posValide(5,7));


  return 0;
}
