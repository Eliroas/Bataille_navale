#include "menuJouer.hpp"

menuJouer::menuJouer(){
  _jouerMenu.create(sf::VideoMode(900,850), "Bataille Navale");
  
  _imageFond.loadFromFile("../img/metal4.png");
  _spriteFond.setTexture(_imageFond);
  _imageGrille.loadFromFile("../img/grille.png");
  _spriteGrille.setTexture(_imageGrille);
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
      _spriteGrille.setPosition(sf::Vector2f(125,40));
      _jouerMenu.draw(_spriteGrille);
      _spriteFleches.setPosition(sf::Vector2f(50,550));
      _jouerMenu.draw(_spriteFleches);
      _spriteValider.setPosition(sf::Vector2f(640,220));
      _jouerMenu.draw(_spriteValider);
      _spriteInstructions.setPosition(sf::Vector2f(450,560));
      _jouerMenu.draw(_spriteInstructions);
      _jouerMenu.display();

    }
    
  }

}

//int main (){

//menuJouer main;
//main.run();
//return 0;

//}
