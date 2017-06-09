#ifndef GLOBALES_HPP_
#define GLOBALES_HPP_

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


extern int global_difficulte;

extern bool succes_tir_j1;
extern bool succes_tir_j2;

#endif
