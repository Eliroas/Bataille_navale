#include <iostream>
#include <limits>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Coup.hpp"


//Constructeur qui créer un coup
Coup::Coup(Joueur j,int x, int y):
  joueur(j),
  _px(x),
  _py(y)
{}

//OK
bool Coup::LegalCoup( std::vector<Case> grille){
  int taille = sqrt(grille.size());
  if(_px<0 || _px>=taille || _py <0 || _py >= taille ||
     grille[_px + (_py* taille )]._state == RATE ||
     grille[_px + (_py*taille)]._state == TOUCHE ||
     grille[_px + (_py*taille)]._state == COULE
	  ){
    return false;
  }
  return true;
}

Coup Coup::CreerCoup(Joueur j ,std::vector<Case> grille){
  int posX=0;
  int posY=0;

  Coup c(j,posX,posY);

  switch(j._type){
  case HUMAIN :
      c.PlacementHumain(grille);
    break;
  case IA :
    switch (global_difficulte){
    case 0 :
      c.strategieAveugleSourd(grille);
      break;
    case 1 :
      strategieAveugle(grille);
      break;
    }
    break;
  }

  
  return c;
}


void Coup::PlacementHumain(std::vector<Case> grille){
  std::cout<<"Saisissez la position de votre tir :"<< std::endl;
    
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Abscisse : " ;
    std::cin >> _px;
    std::cout << std::endl;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ordonnée : " ;
    std::cin >> _py;
    std::cout << std::endl;

    while(!LegalCoup(grille)){
      std::cout << "Erreur, coordonnées non valides. Vous tirez en dehors du plateau ou tirez sur une case déjà visée" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << " Abscisse : " ;
      std::cin >> _px;
      std::cout << std::endl;

      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << " Ordonnée : " ;
      std::cin >> _py;
      std::cout << std::endl;
      }
    
    // en dehors du plateau
    // sur une case deja tirée
}


void Coup::strategieAveugleSourd(std::vector<Case> grille){
  std::cout << "Strategie aveugle et sourd ! " << std::endl;
  srand (time(NULL));

  do{
    _px = rand() % 9;
    _py = rand() % 9;
  }
  while(grille[_px + (_py*sqrt(grille.size()))]._state == RATE ||
	grille[_px + (_py*sqrt(grille.size()))]._state == TOUCHE ||
	grille[_px + (_py*sqrt(grille.size()))]._state == COULE);    
}


void Coup::strategieAveugle(std::vector<Case> grille){
  std::cout << "Strategie aveugle mais qui entend ! " << std::endl;
  srand (time(NULL));
  // On tire au hasard et dès qu'on touche, on tire aux alentours jusqu'a le couler
  //Puis on reprend les tirs au hasard
  //bool legal=false;
  //int tir_rand;
  /*
  if(id==0){ // joueur 1
    if(succes_tir_j1){
      
      do {
	tir_rand=floor(rand()%4);
	switch(tir_rand){
	case NORD:
	  *posX=coup_prec_j1._px;
	  *posY=coup_prec_j1._py-1;
	  break;
	case EST:
	  *posX=coup_prec_j1._px+1;
	  *posY=coup_prec_j1._py;
	  break;
	case SUD:
	  *posX=coup_prec_j1._px;
	  *posY=coup_prec_j1._py+1;
	  break;
	case OUEST:
	  *posX=coup_prec_j1._px-1;
	  *posY=coup_prec_j1._py;
	  break;
	}
      }
      while (!LegalCoup(*posX, *posY));
      
    }
    else{
      strategieAveugleSourd(posX,posY,id,grille);
    }
  }
  else{
    if(succes_tir_j2){
      //essayer de tirer autour
    }
    else{
      strategieAveugleSourd(posX,posY,id,grille);
    }
  }
  */
}

//--------------------
/*
Pour tirer autour, il faut garder en mémoire le dernier coup qui a
touché. Or, le dernier coup est le coup adverse, donc il faut sauver en
mémoire le dernier coup du j1 ET du j2 pour les reprendre dans la fonction
ci dessus
*/
