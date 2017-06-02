#include <iostream>
#include <stdio.h>
#include <limits>
#include "Plateau.hpp"
#include "globales.hpp"

//Constructeur qui créer un plateau de jeu
Plateau::Plateau(int taille):
  plat_joueur1(taille*taille),
  plat_joueur2(taille*taille),
  _taille(taille),
  flotte_j1(5)
{}

//initialise le plateau ( toutes les cases sont vides )
void Plateau::initialiser(){
  int z=0;
  for(int j=0; j< getTaille(); j++){
    for(int k=0; k< getTaille(); k++){
      plat_joueur1[z]._x=j;
      plat_joueur1[z]._y=k;
      plat_joueur1[z]._state=VIDE;

      plat_joueur2[z]._x=j;
      plat_joueur2[z]._y=k;
      plat_joueur2[z]._state=VIDE;
      z++;
    }
  }
}

//accesseur qui retourne la taille du plateau
int Plateau::getTaille() const {
  return _taille;
}

//permet l'affichage console de l'état du plateau
void Plateau::afficher_plateau_console(){
  std::cout << "-------------------------------" << std::endl;
  std::cout << "-----------JOUEUR 2------------";
  std::cout << std::endl;
  std::cout << std::endl;
  
  for(int  i=0; i< getTaille();i++){
    for(int  j=0; j< getTaille();j++){
      switch (plat_joueur2[i]._state){
      case VIDE :
	std::cout << " V " ;
	break;
      case BATEAU :
	std::cout << " V " ;
	break;
      case RATE :
	std::cout << " R ";
	break;
      case TOUCHE :
	std::cout << " T ";
	break;
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << "-----------JOUEUR 1------------";
  std::cout << std::endl;
  std::cout << std::endl;
  
  for(int  i=0; i< getTaille()*getTaille();i++){
      switch (plat_joueur1[i]._state){
      case VIDE :
	std::cout << " V " ;
	break;
      case RATE :
	std::cout << " R ";
	break;
      case TOUCHE :
	std::cout << " T ";
	break;
      case BATEAU :
	std::cout << " B " ;
	break;
    }
      if(i%9==8){
	std::cout << std::endl;
      }
  }
}


//--Fonction pour placer les bateaux
void Plateau::PlacerBateau(){
  std::cout << std::endl;
  std::cout << "Placer vos cinq bateaux" << std::endl;
  
  for(int j=0; j<5 ; j++){
    int posX;
    int posY;
    int lon;
    int dir;

    //definit la taille du bateau
    switch (j){
    case 0 :
      lon=2;
      break;
    case 1 :
      lon=3;
      break;
    case 2 :
      lon=3;
      break;
    case 3 :
      lon=4;
      break;
    case 4 :
      lon=5;
      break;
    }
    
    std::cout << std::endl;
    std::cout << "Bateau n° " << j+1 <<" longueur : "<< lon <<  std::endl;
    bool placement_legitime=false;
    int decalage_x=0;
    int decalage_y=0;

    while(placement_legitime==false){
      //assigne la direction dans laquelle pointe le bateau
      std::cout << "Dans quel sens voulez vous placer le bateau n° " << j+1 << "? ( NORD, SUD, EST, OUEST ) :" << std::endl;
      
      std::string test;
      std::cin >> test;

      while(!(test== "SUD" || test== "NORD" || test=="EST" || test=="OUEST")){
	std::cout <<" saisir une direction valide (NORD,SUD,EST,OUEST) "<< std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin >> test;
      }

      if (test=="NORD"){
	dir=NORD;
      }
      if (test=="EST"){
	dir=EST;
      }
      if (test=="SUD"){
	dir=SUD;
      }
      if (test=="OUEST"){
	dir=OUEST;
      }

      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << " Abscisse : " ;
      std::cin >> posX;
      std::cout << std::endl;
      
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << " Ordonnée : ";
      std::cin >> posY;
      std::cout << std::endl;
      
      switch (dir){
      case NORD :
	decalage_x=0;
	decalage_y=-1;
	break;
      case EST :
	decalage_x=1;
	decalage_y=0;
	break;
      case SUD :
	decalage_x=0;

	decalage_y=1;
	break;
      case OUEST :
	decalage_x=-1;
	decalage_y=0;
	break;
      }
      
      placement_legitime = verification_placement_bateau(posX,posY,lon, decalage_x,decalage_y);
    }//fin du while

    
    std::cout << "Bateau n° " << j+1 << " a ete place en " << posX << " , " << posY <<
      " et s'etend jusqu'en " << posX + decalage_x*(lon-1) << " , " << posY + decalage_y*(lon-1) << std::endl;

    flotte_j1.push_back(new Bateau(posX,posY,lon,dir));
    
    for(int k=0; k<lon; k++){
      plat_joueur1[posX +   (posY*getTaille())  +   decalage_y*getTaille()*k  + decalage_x*k  ]._state = BATEAU;
    }
    
    
    afficher_plateau_console();
    
  }//fin du for =>passage a l'iteration suivante pour le bateau suivant
}


bool Plateau::verification_placement_bateau(int x, int y, int taille,int decalage_x, int decalage_y){
  for(int k=0;k<taille;k++){
    //on verifie si le bateau ne sort pas du plateau
    if((x+k*decalage_x) < 0 || (x+k*decalage_x) > getTaille() ||
	(y+k*decalage_y) < 0 || (y+k*decalage_y) > getTaille() ){
      std::cout << "Erreur vous sortez du plateau" << std::endl;
      return false;
    }
    if(plat_joueur1[  x +y*getTaille() +   decalage_y*getTaille()*k + decalage_x*k ]._state ==BATEAU){
      std::cout << "Erreur un bateau gêne le placement" << std::endl;
      return false;
    }
  }
  return true;
}


