#include "menuDifficulte.hpp"
#include "menuOptions.hpp"

menuDifficulte::menuDifficulte(){
  //creation de la nouvelle fenetre
  _difficulteMenu.create(sf::VideoMode(900, 850), "Bataille Navale");

  //declaration des sprites
  _imageBataille.loadFromFile("../img/batailleChoix.png");
  _spriteBataille.setTexture(_imageBataille);
  _imageFond.loadFromFile("../img/metal4.png");
  _spriteFond.setTexture(_imageFond);
  _boutonFacile.loadFromFile("../img/boutonfacile.png");
  _spriteFacile.setTexture(_boutonFacile);
  _boutonNormal.loadFromFile("../img/boutonNormal.png");
  _spriteNormal.setTexture(_boutonNormal);

  // declaration des coordonnées des boutons
  _Fx = _boutonFacile.getSize().x;
  _Fy = _boutonFacile.getSize().y;
  _Nx = _boutonNormal.getSize().x;
  _Ny = _boutonNormal.getSize().y;
}

void menuDifficulte::run(){

  while(_difficulteMenu.isOpen()){
    while (_difficulteMenu.pollEvent(_event))
        {
	  //Pour permettre de fermer la fenetre
            if (_event.type == sf::Event::Closed)
                _difficulteMenu.close();

	    //Ouvre la fenetre Options si clique sur le bouton
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

	    //Ouvre la fenetre Options si clique sur le bouton
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


	// Positionnement et affichage des differents sprites de la fenetre
    	_spriteBataille.setPosition(sf::Vector2f(50,50));
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
 
