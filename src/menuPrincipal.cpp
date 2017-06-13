#include "menuPrincipal.hpp"
#include "menuDifficulte.hpp"


menuPrincipal::menuPrincipal(){

  _mainMenu.create(sf::VideoMode(900, 850), "Bataille Navale");

  _imageBataille.loadFromFile("../img/bataille2.png");
  _spriteBataille.setTexture(_imageBataille);
  _imageFond.loadFromFile("../img/metal4.png");
  _spriteFond.setTexture(_imageFond);
  _boutonJouer.loadFromFile("../img/boutonJouer.png");
  _spriteJouer.setTexture(_boutonJouer);
  _boutonQuitter.loadFromFile("../img/boutonQuitter.png");
  _spriteQuitter.setTexture(_boutonQuitter);
  _Jx = _boutonJouer.getSize().x;
  _Jy = _boutonJouer.getSize().y;
  _Qx = _boutonQuitter.getSize().x;
  _Qy = _boutonQuitter.getSize().y;
}

void menuPrincipal::run(){

  while(_mainMenu.isOpen()){
     while (_mainMenu.pollEvent(_event))
        {
            if (_event.type == sf::Event::Closed)
                _mainMenu.close();


	    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
	      _localPosition = sf::Mouse::getPosition(_mainMenu);
	      if(_localPosition.x >= _spriteQuitter.getPosition().x
		 && _localPosition.x <= _spriteQuitter.getPosition().x+_Qx
		 && _localPosition.y >= _spriteQuitter.getPosition().y
		 && _localPosition.y <= _spriteQuitter.getPosition().y+_Qy){
		_mainMenu.close();
	      }
	    }

	    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
	      _localPosition = sf::Mouse::getPosition(_mainMenu);
	      if(_localPosition.x >= _spriteJouer.getPosition().x
		 && _localPosition.x <= _spriteJouer.getPosition().x+_Jx
		 && _localPosition.y >= _spriteJouer.getPosition().y
		 && _localPosition.y <= _spriteJouer.getPosition().y+_Jy){
		_mainMenu.close();
		menuDifficulte diff;
		diff.run();
	      }
	    }

    
    	_spriteBataille.setPosition(sf::Vector2f(50,50));
	//affichage des images
	_mainMenu.draw(_spriteFond);
	_mainMenu.draw(_spriteBataille);
	_spriteJouer.setPosition(sf::Vector2f(30, 550));
	_mainMenu.draw(_spriteJouer);
	_spriteQuitter.setPosition(sf::Vector2f(470, 550));
	_mainMenu.draw(_spriteQuitter);
        _mainMenu.display();

    
  }
  }
}
 
int main(){

  menuPrincipal main;
  main.run();
  return 0;

}
