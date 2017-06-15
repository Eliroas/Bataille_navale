#ifndef GLOBALES_HPP_
#define GLOBALES_HPP_
#include <SFML/Graphics.hpp>

//on definit les types de joueurs possibles
#define HUMAIN 0
#define IA 1

//On definit les directions sous forme d'entier
#define NORD 0
#define EST 1
#define SUD 2
#define OUEST 3


//cet enum contient tout les etats possibles d'une case
enum etat {
  VIDE, RATE, TOUCHE, BATEAU, COULE
};

struct Case{
  int _x;
  int _y;
  etat _state;
};

struct Cases{

  int xi;
  int yi;
  int xf;
  int yf;
  etat state;
  
};

struct Bateaux{
  sf::RectangleShape _bateau;
};


extern int global_difficulte;
extern int global_difficulte_b;

extern bool succes_tir_j1;
extern bool succes_tir_j2;

#endif
