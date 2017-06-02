#include "Bateau.hpp"
#include "globales.hpp"

Bateau::Bateau(int x,int y, int longueur, int dir):
  _x(x),
  _y(y),
  _longueur(longueur),
  _dir(dir),
  _nbTouche(0)
{}

int Bateau::getAbscisse(){
  return _x;
}

int Bateau::getOrdonnee(){
  return _y;
}

int Bateau::getTaille(){
  return _longueur;
}

int Bateau::getDir(){
  return _dir;
}
