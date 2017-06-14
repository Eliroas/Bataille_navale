#ifndef MENUDIFFICULTE_HPP_
#define MENUDIFFICULTE_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

using namespace std;

class menuDifficulte{
 public:
  menuDifficulte();
  void run();
 private:
  sf::RenderWindow _difficulteMenu;

  sf::Texture _imageBataille;
  sf::Sprite _spriteBataille;

  sf::Texture _imageFond;
  sf::Sprite _spriteFond;

  sf::Texture _boutonFacile;
  sf::Sprite _spriteFacile;
  float _Fx, _Fy;
  
  sf::Texture _boutonNormal;
  sf::Sprite _spriteNormal;
  float _Nx, _Ny;
  
  sf::Event _event;
  sf::Vector2i _localPosition;

  
};

#endif
