#ifndef PLATEAU_HPP_
#define PLATEAU_HPP_

#include <vector>
#include "globales.hpp"
#include "Case.hpp"

class Plateau{
public:
  std::vector<Case> plat_joueur1;
  std::vector<Case> plat_joueur2;
  int _taille;
  
  Plateau(int taille);
  
  void initialiser() ;
  int getTaille() const;
  void afficher_plateau_console();
};

#endif


