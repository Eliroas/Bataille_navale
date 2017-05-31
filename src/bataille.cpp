#include <iostream>

#include "Plateau.hpp"

int main(){
  std::cout << "Hello World" << std::endl;

  Plateau pl(9);
  pl.initialiser();
  pl.afficher_plateau_console();
}
