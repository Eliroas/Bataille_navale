#ifndef PLATEAU_HPP_
#define PLATEAU_HPP_

#include <vector>
#include "Bateau.hpp"
#include "Coup.hpp"
#include "Joueur.hpp"
#include "globales.hpp"

class Plateau{
public:
  std::vector<Case> plat_joueur1;
  std::vector<Case> plat_joueur2;
  int _taille;
  std::vector<Bateau*> flotte_j1;
  std::vector<Bateau*> flotte_j2;
  
  Plateau(int taille);
  void LancerPartie();
  void initialiser() ;
  int getTaille() const;
  void afficher_plateau_console();
  
  void PlacerBateau(Joueur j);

  bool verification_placement_bateau(int x, int y, int taille,
				     int decalage_x,int decalage_y,
				     std::vector<Case> C);


  void PlacerCoup(Coup c, int tour);
 

  int UpdateEtatBateau(Coup c,std::vector<Bateau*> B);

  
};

#endif


