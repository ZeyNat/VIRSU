#include <iostream>
#include <assert.h>   //pour tester nos fcts
#include "Teaupla.hpp"
#include "Oueurj.hpp"
#include "Streumon.hpp"
using namespace std;



int main() {
  //string teau = "/home/zeneb/Documents/M1_MIC/LOA/PROJET/b.board";  //pour moi haha
  string teau = "/home/natacha/Documents/M1MIC/LOA/Projet/b.board";  //pour toi hihi ;)
  Teaupla T(teau);
  T.affiche();

/*  assert(T.posSure(1,1));
  cout << "ok 1 1" << endl;
  assert(T.posSure(24,11));
  cout << "ok 8 10" << endl;
  assert(T.posSure(1,11));
  cout << "ok 1 10" << endl;
  assert(T.posSure(24,1));
  cout << "ok 8 1" << endl;
  assert(T.posSure(1,3));

  assert(T.posSure(24,5));

  assert(T.posSure(5,1));

  assert(T.posSure(5,11));
  */
  
  /*
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
  Streumon s1(5,5);
  assert(s1.getX()==5 && s1.getY()==5);
  s1.setLocalisation(6,6);
  assert(s1.getX() == 6 && s1.getY() == 6);

  //Test TEUPORTS
  cout << T.getTeuports().size() << endl;
  assert(T.getTeuports().size()==2);

  //Tests posValide
  assert(T.posValide(1,1));
  assert(!T.posValide(0,0));
  assert(!T.posValide(0,4));
  assert(!T.posValide(18,1));
  assert(!T.posValide(5,7));
  */


  T.deplaceOueurj();

  return 0;
}
