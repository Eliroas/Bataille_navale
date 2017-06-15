#ifndef MENUJOUER_HPP_
#define MENUJOUER_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "globales.hpp"


#define z 450

using namespace std;

class menuJouer{
public:
  menuJouer();
  void run();
  void create();
private:
  sf::RenderWindow _jouerMenu;

  sf::Texture _imageFond;
  sf::Sprite _spriteFond;

  sf::Texture _imageGrille;
  sf::Sprite _spriteGrille;
  std::vector <Cases> _Grille;
  std::vector <Bateaux> _Boats;

  sf::RectangleShape _rect;
  sf::RectangleShape _bateau1;
  sf::RectangleShape _bateau2;
  sf::RectangleShape _bateau3;
  sf::RectangleShape _bateau4;
  sf::RectangleShape _bateau5;
  
  sf::Texture _imageValider;
  sf::Sprite _spriteValider;
  float _Vx, _Vy;

  sf::Texture _imageFleches;
  sf::Sprite _spriteFleches;

  sf::Texture _imageInstructions;
  sf::Sprite _spriteInstructions;
  
  sf::Event _event;
  sf::Vector2i _localPosition;
};

#endif
