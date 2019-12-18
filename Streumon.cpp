#include<iostream>
#include "Streumon.hpp"
#include "Deplacable.hpp"
using namespace std;

//Streumon::Streumon() {}
Streumon::Streumon(int x,int y) : _Deplacable(x,y) , sousSesPieds{' '}{}

char Streumon::getSousSesPieds() {return sousSesPieds;}

void Streumon::setSousSesPieds(char c){ sousSesPieds = c;}
