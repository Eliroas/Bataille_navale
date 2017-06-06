#include "Joueur.hpp"
#include "Coup.hpp"
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <time.h>


//Constructeur qui créer un coup
Coup::Coup(Joueur j,int x, int y):
  joueur(j),
  _px(x),
  _py(y)
{}
