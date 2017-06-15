#ifndef PLATEAU_HPP_
#define PLATEAU_HPP_

#include <vector>
#include "Bateau.hpp"
#include "Coup.hpp"

/* ils sont appelés dans coup.hpp
#include "Joueur.hpp"
#include "globales.hpp"
*/

class Plateau{
public:
  std::vector<Case> plat_joueur1;
  std::vector<Case> plat_joueur2;
  int _taille;
  std::vector<Bateau*> flotte_j1;
  std::vector<Bateau*> flotte_j2;
  
  Plateau(int taille);
  void LancerPartie();
  void initialiser();

  bool conditionVictoire();
  int getTaille() const;
  void afficher_plateau_console();
  
  void PlacerBateau(Joueur j);

  bool verification_placement_bateau(int x, int y, int taille,
				     int decalage_x,int decalage_y,
				     std::vector<Case> C);


  void PlacerCoup(Coup c);
  int UpdateEtatBateau(Coup c);

  Coup getMoveMinMax();
  float getMoveMinMaxAux(Joueur j, int depth, int depthmax, Coup &m);
  
  float Eval(Coup c);
  std::vector<Coup> coupJouables(Joueur j);
  void doMove(Joueur j,Coup m);
  
};


extern Coup coup_origine_j1;
extern Coup coup_repere_j1;
extern int sav_dirXj1;
extern int sav_dirYj1;
  
extern Coup coup_repere_j2;
extern Coup coup_origine_j2;
extern int sav_dirXj2;
extern int sav_dirYj2;

extern bool mode_chasse_j1;
extern bool mode_chasse_j2;

#endif


