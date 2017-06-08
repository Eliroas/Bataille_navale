#ifndef PLATEAU_HPP_
#define PLATEAU_HPP_

#include <vector>
#include "Case.hpp"
#include "Bateau.hpp"
#include "Coup.hpp"

class Plateau{
public:
  std::vector<Case> plat_joueur1;
  std::vector<Case> plat_joueur2;
  int _taille;
  std::vector<Bateau*> flotte_j1;
  std::vector<Bateau*> flotte_j2;
  
  Plateau(int taille);
  
  void initialiser() ;
  int getTaille() const;
  void afficher_plateau_console();
  
  void PlacerBateau(Joueur j1);
  bool verification_placement_bateau(int x, int y, int taille,
				     int decalage_x,int decalage_y,
				     std::vector<Case> C);
  //void afficher_flotte(std::vector<Bateau*>flotte);

  Coup CreerCoup(Joueur j);
  void PlacerCoup(Coup c, int tour);
  void LancerPartie();

  void PlacementHumain(int *posX, int *posY);
  void strategieAveugleSourd(int *posX,int *posY, int id);
  void strategieAveugle(int *posX,int *posY, int id);

  int UpdateEtatBateau(Coup c,std::vector<Bateau*> B);

};


#endif


