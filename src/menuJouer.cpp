#include "menuJouer.hpp"
#include "Case.hpp"
#include "Plateau.hpp"
#include <iostream>
#include <vector>

menuJouer::menuJouer(){
  _jouerMenu.create(sf::VideoMode(900,850), "Bataille Navale");
  
  _imageFond.loadFromFile("../img/metal4.png");
  _spriteFond.setTexture(_imageFond);
  _imageGrille.loadFromFile("../img/grille.png");
  _spriteGrille.setTexture(_imageGrille);
  _spriteGrille.setPosition(sf::Vector2f(125,50));
  _imageValider.loadFromFile("../img/boutonValider.png");
  _spriteValider.setTexture(_imageValider);
  _imageFleches.loadFromFile("../img/touche.png");
  _spriteFleches.setTexture(_imageFleches);
  _imageInstructions.loadFromFile("../img/Instruction.png");
  _spriteInstructions.setTexture(_imageInstructions);
  _Vx = _imageValider.getSize().x;
  _Vy = _imageValider.getSize().y;
}

void menuJouer::run(){
  
  while(_jouerMenu.isOpen()){

    while(_jouerMenu.pollEvent(_event)){

      if(_event.type == sf::Event::Closed)
	_jouerMenu.close();

      if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
	      _localPosition = sf::Mouse::getPosition(_jouerMenu);
	      if(_localPosition.x >= _spriteValider.getPosition().x
		 && _localPosition.x <= _spriteValider.getPosition().x+_Vx
		 && _localPosition.y >= _spriteValider.getPosition().y
		 && _localPosition.y <= _spriteValider.getPosition().y+_Vy){
		_jouerMenu.close();
	      }
      }

      _jouerMenu.draw(_spriteFond);
      //_spriteGrille.setPosition(sf::Vector2f(125,40));
      _jouerMenu.draw(_spriteGrille);
      _spriteFleches.setPosition(sf::Vector2f(50,550));
      _jouerMenu.draw(_spriteFleches);
      _spriteValider.setPosition(sf::Vector2f(640,220));
      _jouerMenu.draw(_spriteValider);
      _spriteInstructions.setPosition(sf::Vector2f(450,560));
      _jouerMenu.draw(_spriteInstructions);
      _jouerMenu.display();


      //orientation des bateaux si pression des fleches du clavier
      string dir;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
	  dir="OUEST";
	  std::cout<<"Le bateau va vers : "<< dir <<std::endl;
	}

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
	  dir="EST";
	  std::cout<<"Le bateau va vers : "<< dir <<std::endl;
	}

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
	  dir="NORD";
	  std::cout<<"Le bateau va vers : "<< dir <<std::endl;
	}

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
	  dir="SUD";
	  std::cout<<"Le bateau va vers : "<< dir <<std::endl;
	}
      
      
      if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
	for(unsigned int l=0;l<_Grille.size();l++){
	  _localPosition = sf::Mouse::getPosition(_jouerMenu);
	  if(_localPosition.x >= _Grille[l].xi
	     && _localPosition.x <= _Grille[l].xf
	     && _localPosition.y >= _Grille[l].yi
	     && _localPosition.y <= _Grille[l].yf){
	    std::cout << "Case [" << l << "] clicked" << std::endl;
	  }
	}
      }
    }
  }
}

void menuJouer::create(){
  Cases c;
  c.yi=_spriteGrille.getPosition().y;
  c.yf=_spriteGrille.getPosition().y+(z/9);
  for(int i=0;i<9;i++){
    c.xi=_spriteGrille.getPosition().x;
    c.xf=_spriteGrille.getPosition().x+(z/9);
    for(int j=0;j<9;j++){
      _Grille.push_back(c);
      c.xi+=z/9;
      c.xf+=z/9;
    }
  c.yi+=z/9;
  c.yf+=z/9;
  }

  for (unsigned int k=0;k<_Grille.size();k++){

    std::cout << "Case :" << k << std::endl;
    std::cout << "xi: " << _Grille[k].xi << std::endl;
    std::cout << "yi: " << _Grille[k].yi << std::endl;
    std::cout << "xf: " << _Grille[k].xf << std::endl;
    std::cout << "yf: " << _Grille[k].yf << std::endl;
    std::cout << std::endl;
    }
  
}
