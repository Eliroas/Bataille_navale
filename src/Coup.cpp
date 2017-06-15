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

void Coup::CreerCoup(Joueur j, Coup* origine,Coup* repere, int* dir_x, int* dir_y,
		     bool* chasse ,std::vector<Case> grille){
  joueur=j;
  switch(j._type){
  case HUMAIN :
    PlacementHumain(grille);
    break;
  case IA :
    switch (global_difficulte){
    case 0 :
      strategieAveugleSourd(grille);
      break;
    case 1 :
      strategieAveugle(origine,repere,dir_x,dir_y,chasse,grille);
      break;
    case 2 :
      strategieAveugleSourd(grille);
      break;
    }
  }
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
    _px = floor(rand()%9);
    _py = floor(rand()%9);
  }
  while(!LegalCoup(grille));    
}


void Coup::strategieAveugle(Coup* origine,Coup* repere, int* dir_x, int* dir_y,
			    bool* chasse ,std::vector<Case> grille){
  std::cout << "Strategie aveugle mais qui entend ! " << std::endl;

  //VERIFICATION
  std::cout << "coup origine joueur = " << origine->joueur._id  << " " << origine->_px << " " << origine->_py  << std::endl;

  std::cout << "coup prec joueur = " << repere->joueur._id  << " " << repere->_px << " " << repere->_py  << std::endl;

  std::cout << "direction x et y = " << *dir_x  << " " << *dir_y << " "  << std::endl;
  
  srand (time(NULL));
  // On tire au hasard et dès qu'on touche, on tire aux alentours jusqu'a le couler
  //Puis on reprend les tirs au hasard
  int tentative=0;

  if(*chasse==true){
    // si on rentre dans le mode chasse, on
    //tire d'abord une case autour aléatoirement
    do{
	do{
	  *dir_x = -1 + floor(rand()%3);
	  *dir_y = -1 + floor(rand()%3);
	}
	while((*dir_x + *dir_y) %2 ==0);
      _px = repere->_px + *dir_x;
      _py = repere->_py + *dir_y;
      tentative++;
    }
    while(!LegalCoup(grille) && tentative<100);
    
    if(tentative>=100){
      *repere = *origine;
      tentative=0;
    
      do{
	do{
	  *dir_x = -1 + floor(rand()%3);
	  *dir_y = -1 + floor(rand()%3);
	}
	while((*dir_x + *dir_y) %2 ==0);
	_px = origine->_px - *dir_x;
	_py = origine->_py - *dir_y;
	tentative++;
      }
      while(!LegalCoup(grille) && tentative<200);
    }
    if(tentative>=200){
      std::cout << "On sort du mode chasse" << std::endl;
      strategieAveugleSourd(grille);
      *chasse=false;
      repere->_px=_px;
      repere->_py=_py;
      repere->joueur=joueur;
    }
  }
 else{
   strategieAveugleSourd(grille);
 }
}

//PROBLEME,
/*
une fois qu'il touche, il ne tire plus d'apres l'affichage
 */



//--------------------
/*
Pour tirer autour, il faut garder en mémoire le dernier coup qui a
touché. Or, le dernier coup est le coup adverse, donc il faut sauver en
mémoire le dernier coup du j1 ET du j2 pour les reprendre dans la fonction
ci dessus
*/


//--------------------------------------------------------------------------------------









/*
float Position::getMoveMinMaxAux(Couleur j, int depth, int depthmax, Move &m) {
  if(depth == depthmax){
    return eval(j);
  }
    float meilleur_score;
    Move meilleur_coup;
    Position p(*this);
    vector<Move> jouables1 = p.coupsJouables();

    if(depth%2==0){
      meilleur_score = -6666;//-inf
    }else{
      meilleur_score = 6666;//inf
    }
    for(int i=0;i<jouables1.size();i++){
      p.doMove(jouables1[i]);
      p.prochainJoueur();
      float score = getMoveMinMaxAux(j, depth+1, depthmax, m);
      if(depth%2==0){
	if(score > meilleur_score){
	  meilleur_score = score;
	  meilleur_coup = jouables1[i];
	} else {
	  break;
	}
      }
      else {
      meilleur_score = +6666;
      for(int i=0;i<jouables1.size();i++){
      p.doMove(jouables1[i]);
      p.prochainJoueur();
      float score = getMoveMinMaxAux(j, depth+1, depthmax, m);
      //annuler le coup;
      if(score < meilleur_score) {
      meilleur_score=  score;
       meilleur_coup = jouables1[i];
       } else {
       break;
       }
       }
    }
    m = meilleur_coup;
    return meilleur_score;
    }
}
*/


