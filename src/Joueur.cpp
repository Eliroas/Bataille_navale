#include "Joueur.hpp"
#include "globales.hpp"

Joueur::Joueur(int id,int type):
  _id(id),
  _type(type)
{}

int Joueur::getId(){
  return _id;
}
