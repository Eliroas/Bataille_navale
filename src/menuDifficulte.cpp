#include "menuDifficulte.hpp"
#include "menuOptions.hpp"

menuDifficulte::menuDifficulte(){

  _difficulteMenu.create(sf::VideoMode(900, 850), "Bataille Navale");

  _imageBataille.loadFromFile("../img/batailleChoix.png");
  _spriteBataille.setTexture(_imageBataille);
  _imageFond.loadFromFile("../img/metal4.png");
  _spriteFond.setTexture(_imageFond);
  _boutonFacile.loadFromFile("../img/boutonfacile.png");
  _spriteFacile.setTexture(_boutonFacile);
  _boutonNormal.loadFromFile("../img/boutonNormal.png");
  _spriteNormal.setTexture(_boutonNormal);
  _Fx = _boutonFacile.getSize().x;
  _Fy = _boutonFacile.getSize().y;
  _Nx = _boutonNormal.getSize().x;
  _Ny = _boutonNormal.getSize().y;
}

void menuDifficulte::run(){

  while(_difficulteMenu.isOpen()){
    while (_difficulteMenu.pollEvent(_event))
        {
            if (_event.type == sf::Event::Closed)
                _difficulteMenu.close();


	    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
	      _localPosition = sf::Mouse::getPosition(_difficulteMenu);
	      if(_localPosition.x >= _spriteFacile.getPosition().x
		 && _localPosition.x <= _spriteFacile.getPosition().x+_Fx
		 && _localPosition.y >= _spriteFacile.getPosition().y
		 && _localPosition.y <= _spriteFacile.getPosition().y+_Fy){
		_difficulteMenu.close();
		menuOptions options;
		options.run();
		
	      }
	    }

	    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
	      _localPosition = sf::Mouse::getPosition(_difficulteMenu);
	      if(_localPosition.x >= _spriteNormal.getPosition().x
		 && _localPosition.x <= _spriteNormal.getPosition().x+_Nx
		 && _localPosition.y >= _spriteNormal.getPosition().y
		 && _localPosition.y <= _spriteNormal.getPosition().y+_Ny){
		_difficulteMenu.close();
		menuOptions options;
		options.run();
	      }
	    }

    
    	_spriteBataille.setPosition(sf::Vector2f(50,50));
	//affichage des images
	_difficulteMenu.draw(_spriteFond);
	_difficulteMenu.draw(_spriteBataille);
	_spriteFacile.setPosition(sf::Vector2f(30, 550));
	_difficulteMenu.draw(_spriteFacile);
	_spriteNormal.setPosition(sf::Vector2f(470, 550));
	_difficulteMenu.draw(_spriteNormal);
        _difficulteMenu.display();

    
  }
  }
}
 
//int main(){

//menuDifficulte main;
//main.run();
//return 0;

//}