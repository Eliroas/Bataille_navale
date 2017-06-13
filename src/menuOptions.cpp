#include "menuOptions.hpp"
#include "menuJouer.hpp"

menuOptions::menuOptions(){

  _optionsMenu.create(sf::VideoMode(900, 850), "Bataille Navale");

  _imageOptions.loadFromFile("../img/batailleOptions.png");
  _spriteOptions.setTexture(_imageOptions);
  _imageFond.loadFromFile("../img/metal4.png");
  _spriteFond.setTexture(_imageFond);
  _boutonJvI.loadFromFile("../img/boutonJI.png");
  _spriteJvI.setTexture(_boutonJvI);
  _boutonIvI.loadFromFile("../img/boutonII.png");
  _spriteIvI.setTexture(_boutonIvI);
  _Vx = _boutonJvI.getSize().x;
  _Vy = _boutonJvI.getSize().y;
  _Ix = _boutonIvI.getSize().x;
  _Iy = _boutonIvI.getSize().y;
}

void menuOptions::run(){

  while(_optionsMenu.isOpen()){
     while (_optionsMenu.pollEvent(_event))
        {
            if (_event.type == sf::Event::Closed)
                _optionsMenu.close();


	    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
	      _localPosition = sf::Mouse::getPosition(_optionsMenu);
	      if(_localPosition.x >= _spriteJvI.getPosition().x
		 && _localPosition.x <= _spriteJvI.getPosition().x+_Vx
		 && _localPosition.y >= _spriteJvI.getPosition().y
		 && _localPosition.y <= _spriteJvI.getPosition().y+_Vy){
		_optionsMenu.close();
		menuJouer jouer;
		jouer.run();
	      }
	    }

	    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
	      _localPosition = sf::Mouse::getPosition(_optionsMenu);
	      if(_localPosition.x >= _spriteIvI.getPosition().x
		 && _localPosition.x <= _spriteIvI.getPosition().x+_Ix
		 && _localPosition.y >= _spriteIvI.getPosition().y
		 && _localPosition.y <= _spriteIvI.getPosition().y+_Iy){
		_optionsMenu.close();
		menuJouer jouer;
		jouer.run();
	      }
	    }

    
    	_spriteOptions.setPosition(sf::Vector2f(50,50));
	//affichage des images
	_optionsMenu.draw(_spriteFond);
	_optionsMenu.draw(_spriteOptions);
	_spriteJvI.setPosition(sf::Vector2f(30, 550));
	_optionsMenu.draw(_spriteJvI);
	_spriteIvI.setPosition(sf::Vector2f(470, 550));
	_optionsMenu.draw(_spriteIvI);
        _optionsMenu.display();

    
  }
  }
}
 
//int main(){

//menuOptions main;
//main.run();
//return 0;

//}
