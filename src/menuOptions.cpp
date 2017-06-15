#include "menuOptions.hpp"
#include "menuJouer.hpp"

menuOptions::menuOptions(){
  //Creation de la nouvelle fenetre
  _optionsMenu.create(sf::VideoMode(900, 850), "Bataille Navale");

  //Declaration de ssprites et des images
  _imageOptions.loadFromFile("../img/batailleOptions.png");
  _spriteOptions.setTexture(_imageOptions);
  _imageFond.loadFromFile("../img/metal4.png");
  _spriteFond.setTexture(_imageFond);
  _boutonJvI.loadFromFile("../img/boutonJI.png");
  _spriteJvI.setTexture(_boutonJvI);
  _boutonIvI.loadFromFile("../img/boutonII.png");
  _spriteIvI.setTexture(_boutonIvI);

   // Recuperation de la taille de l'image
  _Vx = _boutonJvI.getSize().x;
  _Vy = _boutonJvI.getSize().y;
  _Ix = _boutonIvI.getSize().x;
  _Iy = _boutonIvI.getSize().y;
}

void menuOptions::run(){

  while(_optionsMenu.isOpen()){
     while (_optionsMenu.pollEvent(_event))
        {
	  //Permet de fermer la fenetre
            if (_event.type == sf::Event::Closed)
                _optionsMenu.close();

	    // Si clique sur le bouton Joueur vs IA, on ouvre la fenetre jouer
	    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
	      _localPosition = sf::Mouse::getPosition(_optionsMenu);
	      if(_localPosition.x >= _spriteJvI.getPosition().x
		 && _localPosition.x <= _spriteJvI.getPosition().x+_Vx
		 && _localPosition.y >= _spriteJvI.getPosition().y
		 && _localPosition.y <= _spriteJvI.getPosition().y+_Vy){
		_optionsMenu.close();
		menuJouer jouer;
		jouer.create();
		jouer.run();
	      }
	    }
	    // Si clique sur le bouton IA vs IA, on ouvre la fenetre jouer
	    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
	      _localPosition = sf::Mouse::getPosition(_optionsMenu);
	      if(_localPosition.x >= _spriteIvI.getPosition().x
		 && _localPosition.x <= _spriteIvI.getPosition().x+_Ix
		 && _localPosition.y >= _spriteIvI.getPosition().y
		 && _localPosition.y <= _spriteIvI.getPosition().y+_Iy){
		_optionsMenu.close();
		menuJouer jouer;
		jouer.create();
		jouer.run();
	      }
	    }


	 // Positionnement et affichage des sprites
    	_spriteOptions.setPosition(sf::Vector2f(50,50));
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
