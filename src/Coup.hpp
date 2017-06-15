#ifndef COUPS_HPP_
#define COUPS_HPP_
#include "globales.hpp"
#include "Joueur.hpp"
#include <math.h>

class Coup{
public:
  Joueur joueur;
  int _px;
  int _py;

  Coup(Joueur j,int x, int y);
  bool LegalCoup(std::vector<Case> grille);
  void CreerCoup(Joueur j ,Coup* origine,Coup* repere, int* dir_x, int* dir_y,
		 bool* chasse ,std::vector<Case> grille);

  void PlacementHumain(std::vector<Case> grille); 
  void strategieAveugleSourd(std::vector<Case> grille);

  void strategieAveugle(Coup* origine,Coup* repere, int* dir_x, int* dir_y,
			bool* chasse ,std::vector<Case> grille);
};

#endif


