#ifndef MENUJOUER_HPP_
#define MENUJOUER_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

using namespace std;

class menuJouer{
public:
  menuJouer();
  void run();
private:
  sf::RenderWindow _jouerMenu;

  sf::Texture _imageFond;
  sf::Sprite _spriteFond;

  sf::Texture _imageGrille;
  sf::Sprite _spriteGrille;

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
