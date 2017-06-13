#ifndef MENUPRINCIPAL_HPP_
#define MENUPRINCIPAL_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

using namespace std;

class menuPrincipal{
 public:
  menuPrincipal();
  void run();
 private:
  sf::RenderWindow _mainMenu;
  
  sf::Texture _imageBataille;
  sf::Sprite _spriteBataille;

  sf::Texture _imageFond;
  sf::Sprite _spriteFond;

  sf::Texture _boutonJouer;
  sf::Sprite _spriteJouer;
  float _Jx, _Jy;
  
  sf::Texture _boutonQuitter;
  sf::Sprite _spriteQuitter;
  float _Qx, _Qy;
  
  sf::Event _event;
  sf::Vector2i _localPosition;

  
};

#endif
