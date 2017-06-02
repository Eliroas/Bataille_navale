#ifndef PLATEAU_HPP_
#define PLATEAU_HPP_

#include <vector>
#include "Case.hpp"
#include "Bateau.hpp"

class Plateau{
public:
  std::vector<Case> plat_joueur1;
  std::vector<Case> plat_joueur2;
  int _taille;
  std::vector<Bateau*> flotte_j1;
  
  Plateau(int taille);
  
  void initialiser() ;
  int getTaille() const;
  void afficher_plateau_console();
  void PlacerBateau();
  bool verification_placement_bateau(int x, int y, int taille,int decalage_x,int decalage_y);
};


#endif


