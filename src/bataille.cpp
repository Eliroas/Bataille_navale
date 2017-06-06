#include <iostream>
#include <vector>
#include "Plateau.hpp"


int main(){
  std::cout << "Bataille Navale " << std::endl;
  int taille=9;
  Plateau pl(taille);
  pl.initialiser();
  pl.afficher_plateau_console();

  pl.PlacerBateau();
  
  return 0;
}
