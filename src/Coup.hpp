#ifndef COUPS_HPP_
#define COUPS_HPP_
#include "Joueur.hpp"

class Coup{
public:
  Joueur joueur;
  int _px;
  int _py;


  Coup(Joueur j,int x, int y);
};

#endif
