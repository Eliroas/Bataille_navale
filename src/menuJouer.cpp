// g++ -c menuPrincipal.cpp menuDifficulte.cpp menuOptions.cpp menuJouer.cpp
// g++ -o Menu menuPrincipal.o menuDifficulte.o menuOptions.o menuJouer.o -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

#include "menuJouer.hpp"
#include "Case.hpp"
#include <iostream>
#include <vector>

menuJouer::menuJouer(){
  _jouerMenu.create(sf::VideoMode(900,850), "Bataille Navale");
  _imageFond.loadFromFile("../img/metal4.png");
  _spriteFond.setTexture(_imageFond);
  _imageGrille.loadFromFile("../img/grille.png");
  _spriteGrille.setTexture(_imageGrille);
  _spriteGrille.setPosition(sf::Vector2f(125,50));
  
  _rect.setSize(sf::Vector2f(50,50));
  _rect.setFillColor(sf::Color(110, 110, 110));
  _rect.setPosition(sf::Vector2f(-100,-100));
  
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
  int courant=0;
  string dir;
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
		  courant+=1;
		  std::cout << courant << std::endl;
		  if(courant>4){
		    _jouerMenu.close();
////////////////////////////////////////////////////////////////////////////////

		    sf::RenderWindow _plateauMenu;
		    _plateauMenu.create(sf::VideoMode(1200,720), "Bataille Navale");

		    sf::Texture _imageGrille2;
		    _imageGrille2.loadFromFile("../img/grille.png");
		    sf::Sprite _spriteGrille2;
		    _spriteGrille2.setTexture(_imageGrille2);

		    sf::Texture _imageSeparateur;
		     _imageSeparateur.loadFromFile("../img/separateur.png");
		    sf::Sprite _spriteSeparateur;
		    _spriteSeparateur.setTexture(_imageSeparateur);

		    while(_plateauMenu.isOpen()){
		      while (_plateauMenu.pollEvent(_event))
			{
			  if (_event.type == sf::Event::Closed)
			    _plateauMenu.close();
    
			  _plateauMenu.draw(_spriteFond);
			  _spriteGrille.setPosition(sf::Vector2f(125,50));
			  _plateauMenu.draw(_spriteGrille);
			  _plateauMenu.draw(menuJouer::_Boats[0]._bateau);
			  _plateauMenu.draw(menuJouer::_Boats[1]._bateau);
			  _plateauMenu.draw(menuJouer::_Boats[2]._bateau);
			  _plateauMenu.draw(menuJouer::_Boats[3]._bateau);
			  _plateauMenu.draw(menuJouer::_Boats[4]._bateau);
			  _spriteGrille2.setPosition(sf::Vector2f(625,50));
			  _plateauMenu.draw(_spriteGrille2);
			  _spriteSeparateur.setPosition(sf::Vector2f(495,-300));
			  _plateauMenu.draw(_spriteSeparateur);
			  _plateauMenu.display();

			}
		    }

//////////////////////////////////////////////////////////////////////////////// 
		  }
		  
	      }
      }

      _jouerMenu.draw(_spriteFond);
      //_spriteGrille.setPosition(sf::Vector2f(125,40));
      _jouerMenu.draw(_spriteGrille);
      _jouerMenu.draw(_Boats[0]._bateau);
      _jouerMenu.draw(_Boats[1]._bateau);
      _jouerMenu.draw(_Boats[2]._bateau);
      _jouerMenu.draw(_Boats[3]._bateau);
      _jouerMenu.draw(_Boats[4]._bateau);
      _spriteFleches.setPosition(sf::Vector2f(50,550));
      _jouerMenu.draw(_spriteFleches);
      _spriteValider.setPosition(sf::Vector2f(640,220));
      _jouerMenu.draw(_spriteValider);
      _spriteInstructions.setPosition(sf::Vector2f(450,560));
      _jouerMenu.draw(_spriteInstructions);
      _jouerMenu.display();
      
      if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
	for(unsigned int l=0;l<_Grille.size();l++){
	  _localPosition = sf::Mouse::getPosition(_jouerMenu);
	  if(_localPosition.x >= _Grille[l].xi
	     && _localPosition.x <= _Grille[l].xf
	     && _localPosition.y >= _Grille[l].yi
	     && _localPosition.y <= _Grille[l].yf){
	    std::cout << "Case [" << l << "] clicked" << std::endl;

	    if(courant==0){

	    if(dir=="NORD"){
	      _Boats[courant]._bateau.setSize(sf::Vector2f(50,100));
	      _Boats[courant]._bateau.setPosition(sf::Vector2f(_Grille[l-9].xi,_Grille[l-9].yi));
	      _Grille[l].state=BATEAU;
	      _Grille[l-9].state=BATEAU;
	    }

	    if(dir=="SUD"){
	      _Boats[courant]._bateau.setSize(sf::Vector2f(50,100));
	      _Boats[courant]._bateau.setPosition(sf::Vector2f(_Grille[l].xi,_Grille[l].yi));
	      _Grille[l].state=BATEAU;
	      _Grille[l+9].state=BATEAU;
	    }

	    if(dir=="OUEST"){
	      _Boats[courant]._bateau.setSize(sf::Vector2f(100,50));
	      _Boats[courant]._bateau.setPosition(sf::Vector2f(_Grille[l-1].xi,_Grille[l-1].yi));
	      _Grille[l].state=BATEAU;
	      _Grille[l-1].state=BATEAU;
	    }

	    if(dir=="EST"){
	      _Boats[courant]._bateau.setSize(sf::Vector2f(100,50));
	      _Boats[courant]._bateau.setPosition(sf::Vector2f(_Grille[l].xi,_Grille[l].yi));
	      _Grille[l].state=BATEAU;
	      _Grille[l+1].state=BATEAU;
	    }

	    }

	    if(courant==1 || courant==2){

	    if(dir=="NORD"){
	      _Boats[courant]._bateau.setSize(sf::Vector2f(50,150));
	      _Boats[courant]._bateau.setPosition(sf::Vector2f(_Grille[l-18].xi,_Grille[l-18].yi));
	      _Grille[l].state=BATEAU;
	      _Grille[l-9].state=BATEAU;
	      _Grille[l-18].state=BATEAU;
	    }

	    if(dir=="SUD"){
	      _Boats[courant]._bateau.setSize(sf::Vector2f(50,150));
	      _Boats[courant]._bateau.setPosition(sf::Vector2f(_Grille[l].xi,_Grille[l].yi));
	      _Grille[l].state=BATEAU;
	      _Grille[l+9].state=BATEAU;
	      _Grille[l+18].state=BATEAU;
	    }

	    if(dir=="OUEST"){
	      _Boats[courant]._bateau.setSize(sf::Vector2f(150,50));
	      _Boats[courant]._bateau.setPosition(sf::Vector2f(_Grille[l-2].xi,_Grille[l-2].yi));
	      _Grille[l].state=BATEAU;
	      _Grille[l-1].state=BATEAU;
	      _Grille[l-2].state=BATEAU;
	    }

	    if(dir=="EST"){
	      _Boats[courant]._bateau.setSize(sf::Vector2f(150,50));
	      _Boats[courant]._bateau.setPosition(sf::Vector2f(_Grille[l].xi,_Grille[l].yi));
	      _Grille[l].state=BATEAU;
	      _Grille[l+1].state=BATEAU;
	      _Grille[l+2].state=BATEAU;
	    }

	    }

	    if(courant==3){

	    if(dir=="NORD"){
	      _Boats[courant]._bateau.setSize(sf::Vector2f(50,200));
	      _Boats[courant]._bateau.setPosition(sf::Vector2f(_Grille[l-27].xi,_Grille[l-27].yi));
	      _Grille[l].state=BATEAU;
	      _Grille[l-9].state=BATEAU;
	      _Grille[l-18].state=BATEAU;
	      _Grille[l-27].state=BATEAU;
	    }

	    if(dir=="SUD"){
	      _Boats[courant]._bateau.setSize(sf::Vector2f(50,200));
	      _Boats[courant]._bateau.setPosition(sf::Vector2f(_Grille[l].xi,_Grille[l].yi));
	      _Grille[l].state=BATEAU;
	      _Grille[l+9].state=BATEAU;
	      _Grille[l+18].state=BATEAU;
	      _Grille[l+27].state=BATEAU;
	    }

	    if(dir=="OUEST"){
	      _Boats[courant]._bateau.setSize(sf::Vector2f(200,50));
	      _Boats[courant]._bateau.setPosition(sf::Vector2f(_Grille[l-3].xi,_Grille[l-3].yi));
	      _Grille[l].state=BATEAU;
	      _Grille[l-1].state=BATEAU;
	      _Grille[l-2].state=BATEAU;
	      _Grille[l-3].state=BATEAU;
	    }

	    if(dir=="EST"){
	      _Boats[courant]._bateau.setSize(sf::Vector2f(200,50));
	      _Boats[courant]._bateau.setPosition(sf::Vector2f(_Grille[l].xi,_Grille[l].yi));
	      _Grille[l].state=BATEAU;
	      _Grille[l+1].state=BATEAU;
	      _Grille[l+2].state=BATEAU;
	      _Grille[l+3].state=BATEAU;
	    }

	    }

	    if(courant==4){

	    if(dir=="NORD"){
	      _Boats[courant]._bateau.setSize(sf::Vector2f(50,250));
	      _Boats[courant]._bateau.setPosition(sf::Vector2f(_Grille[l-36].xi,_Grille[l-36].yi));
	      _Grille[l].state=BATEAU;
	      _Grille[l-9].state=BATEAU;
	      _Grille[l-18].state=BATEAU;
	      _Grille[l-27].state=BATEAU;
	      _Grille[l-36].state=BATEAU;
	    }

	    if(dir=="SUD"){
	      _Boats[courant]._bateau.setSize(sf::Vector2f(50,250));
	      _Boats[courant]._bateau.setPosition(sf::Vector2f(_Grille[l].xi,_Grille[l].yi));
	      _Grille[l].state=BATEAU;
	      _Grille[l+9].state=BATEAU;
	      _Grille[l+18].state=BATEAU;
	      _Grille[l+27].state=BATEAU;
	      _Grille[l+36].state=BATEAU;
	    }

	    if(dir=="OUEST"){
	      _Boats[courant]._bateau.setSize(sf::Vector2f(250,50));
	      _Boats[courant]._bateau.setPosition(sf::Vector2f(_Grille[l-4].xi,_Grille[l-4].yi));
	      _Grille[l].state=BATEAU;
	      _Grille[l-1].state=BATEAU;
	      _Grille[l-2].state=BATEAU;
	      _Grille[l-3].state=BATEAU;
	      _Grille[l-4].state=BATEAU;
	    }

	    if(dir=="EST"){
	      _Boats[courant]._bateau.setSize(sf::Vector2f(250,50));
	      _Boats[courant]._bateau.setPosition(sf::Vector2f(_Grille[l].xi,_Grille[l].yi));
	      _Grille[l].state=BATEAU;
	      _Grille[l+1].state=BATEAU;
	      _Grille[l+2].state=BATEAU;
	      _Grille[l+3].state=BATEAU;
	      _Grille[l+4].state=BATEAU;
	    }

	    }
	    
	    std::cout << "Bateau " << courant << std::endl;

	    std::cout << "Case :" << l << std::endl;
	    std::cout << "xi: " << _Grille[l].xi << std::endl;
	    std::cout << "yi: " << _Grille[l].yi << std::endl;
	    std::cout << "xf: " << _Grille[l].xf << std::endl;
	    std::cout << "yf: " << _Grille[l].yf << std::endl;
	    std::cout << "state " << _Grille[l].state << std::endl;
	    std::cout << std::endl;
	    
	  }
	}
      }
      
      //string dir;
      
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
	  dir = "OUEST";
	  std::cout << "direction :" << dir << std::endl;
	}

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
	  dir = "EST";
	  std::cout << "direction :" << dir << std::endl;
	}

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
	  dir = "NORD";
	  std::cout << "direction :" << dir << std::endl;
	}

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
	  dir = "SUD";
	  std::cout << "direction :" << dir << std::endl;
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
      c.state=VIDE;
      _Grille.push_back(c);
      c.xi+=z/9;
      c.xf+=z/9;
    }
  c.yi+=z/9;
  c.yf+=z/9;
  }

  Bateaux b;
  b._bateau.setSize(sf::Vector2f(50,50));
  b._bateau.setFillColor(sf::Color(110, 110, 110));
  b._bateau.setPosition(sf::Vector2f(-100,-100));
  _Boats.push_back(b);
  _Boats.push_back(b);
  _Boats.push_back(b);
  _Boats.push_back(b);
  _Boats.push_back(b);
  
  for (unsigned int k=0;k<_Grille.size();k++){

    std::cout << "Case :" << k << std::endl;
    std::cout << "xi: " << _Grille[k].xi << std::endl;
    std::cout << "yi: " << _Grille[k].yi << std::endl;
    std::cout << "xf: " << _Grille[k].xf << std::endl;
    std::cout << "yf: " << _Grille[k].yf << std::endl;
    std::cout << "state " << _Grille[k].state << std::endl;
    std::cout << std::endl;
    }
  
}
