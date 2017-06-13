#ifndef MENUOPTIONS_HPP_
#define MENUOPTIONS_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

using namespace std;

class menuOptions{
 public:
  menuOptions();
  void run();
 private:
  sf::RenderWindow _optionsMenu;

  sf::Texture _imageOptions;
  sf::Sprite _spriteOptions;

  sf::Texture _imageFond;
  sf::Sprite _spriteFond;

  sf::Texture _boutonJvI;
  sf::Sprite _spriteJvI;
  float _Vx, _Vy;
  
  sf::Texture _boutonIvI;
  sf::Sprite _spriteIvI;
  float _Ix, _Iy;
  
  sf::Event _event;
  sf::Vector2i _localPosition;

  
};

#endif
