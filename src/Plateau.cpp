#include <iostream>
#include <stdio.h>
#include <limits>
#include "Plateau.hpp"
#include <math.h>
#include <time.h>


int global_difficulte=0; // 0 OU 1 -> DIFFICULTE

//retient le coup précédent du joueur (true si touché)
bool succes_tir_j1 = false;
bool succes_tir_j2 = false;


//Constructeur qui créer un plateau de jeu
Plateau::Plateau(int taille):
  plat_joueur1(taille*taille),
  plat_joueur2(taille*taille),
  _taille(taille),
  flotte_j1(5),
  flotte_j2(5)
{}

void Plateau::LancerPartie(){
  initialiser();
  
  std::cout << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << "----------DEMARRAGE DU JEU------------" << std::endl;
  std::cout << std::endl;


  //---CREATION DE JOUEURS
  std::cout <<  "HUMAIN : " << HUMAIN << " IA : " << IA << std::endl;
  int type_j1;
  std::cout << "Le premier joueur est un HUMAIN  ou une IA : " << std::endl;

  std::string type;
  std::cin >> type;

  while(!(type== "IA" || type== "HUMAIN")){
    std::cout <<"Saisir un type valide (IA,HUMAIN) "<< std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> type;
  }

  if (type=="HUMAIN"){
    type_j1=HUMAIN;
  }
  if (type=="IA"){
    type_j1=IA;
  }

  Joueur j1(0,type_j1);
  Joueur j2(1,IA);
  afficher_plateau_console();
  PlacerBateau(j1);
  PlacerBateau(j2);

  //retient les coordonnées coup précédent
  
  /*
  Coup coup_prec_j1(j1,0,0);
  Coup coup_prec_j2(j2,0,1);

  //retient le premier touché
  Coup succes_origine_j1(j1,0,0);
  Coup succes_origine_j2(j2,0,1);
  */

  
  //----FIN CREATION DES JOUEURS ET DU PLACEMENT DE LEURS BATEAUX
  //performance de l'ia

  //----DEMARRAGE DU JEU
  //bool verifierVictoire=false;
  int tour=0;
  std::cout << std::endl;
  std::cout << std::endl;
  while(flotte_j1.size() != 0 && flotte_j2.size() !=0 ){
    if(tour%2==0){
      std::cout << "Coup du joueur 1 : " << std::endl;
      Coup c = c.CreerCoup(j1,plat_joueur2);
      PlacerCoup(c,0);
      int indice = UpdateEtatBateau(c,flotte_j2);
      //on enregistre le coup precedent
      //coup_prec_j1 = c;
      if(indice >=0){
	flotte_j2[indice]->_nbTouche++;
	if(flotte_j2[indice]->_nbTouche >= flotte_j2[indice]->_longueur){
	  std::cout << "On A COULE UN BATEAU" << std::endl;
	  succes_tir_j1=false;
	  int decal_x;
	  int decal_y;
	  switch(flotte_j2[indice]->_dir){
	  case NORD :
	    decal_x=0;
	    decal_y=-1;
	    break;
	  case SUD :
	    decal_x=0;
	    decal_y=1;
	    break;
	  case EST :
	    decal_x = 1;
	    decal_y=0;
	    break;
	  case OUEST :
	    decal_x=-1;
	    decal_y=0;
	    break;
	  }
	  for(int r=0; r<flotte_j2[indice]->_longueur; r++){
	    plat_joueur2[ flotte_j2[indice]->_x + flotte_j2[indice]->_y*getTaille()
			  + decal_x*r + decal_y*r*getTaille()]._state=COULE;
	  }
	  flotte_j2.erase(flotte_j2.begin() + indice);
	}
      }
    }
    else{
      std::cout << "Coup du joueur 2 : " << std::endl;
      Coup c = c.CreerCoup(j2,plat_joueur1);
      PlacerCoup(c,1);
      //On enregistre le coup precedent
      //coup_prec_j2 = c;
      int indice = UpdateEtatBateau(c,flotte_j1);
      if(indice >=0){
	flotte_j1[indice]->_nbTouche++;
	if(flotte_j1[indice]->_nbTouche >= flotte_j1[indice]->_longueur){
	  std::cout << "On A COULE UN BATEAU" << std::endl;
	  succes_tir_j2=false;
	  //on lache prise qu'une fois le bateau coulé
	  int decal_x;
	  int decal_y;
	  switch(flotte_j1[indice]->_dir){
	  case NORD :
	    decal_x=0;
	    decal_y=-1;
	    break;
	  case SUD :
	    decal_x=0;
	    decal_y=1;
	    break;
	  case EST :
	    decal_x = 1;
	    decal_y=0;
	    break;
	  case OUEST :
	    decal_x=-1;
	    decal_y=0;
	    break;
	  }
	  for(int r=0; r<flotte_j1[indice]->_longueur; r++){
	    plat_joueur1[ flotte_j1[indice]->_x + flotte_j1[indice]->_y*getTaille()
			  + decal_x*r + decal_y*r*getTaille()]._state=COULE;
	  }
	  flotte_j1.erase(flotte_j1.begin() + indice);
	}
      }
    }
    
    tour++;
    tour%=2;
    afficher_plateau_console();
    
    }
  std::cout << "TERMINE " << std::endl;
  if(flotte_j1.size()==0){
    std::cout << "Le joueur 2 a gagné !" << std::endl;
  }
  else{
    std::cout << "Le joueur 1 a gagné ! " <<std::endl;
  }
}


void Plateau::PlacerCoup(Coup c,int tour){
  if(tour%2==0){
    if(plat_joueur2[c._px + c._py*getTaille()]._state == BATEAU){
      plat_joueur2[c._px + c._py*getTaille()]._state = TOUCHE;
      succes_tir_j1=true;
    }
    else{
      plat_joueur2[c._px + c._py*getTaille()]._state = RATE;
    }
  }
  else{
    if(plat_joueur1[c._px + c._py*getTaille()]._state == BATEAU){
      plat_joueur1[c._px + c._py*getTaille()]._state = TOUCHE;
      succes_tir_j2=true;
    }
    else{
      if(plat_joueur1[c._px + c._py*getTaille()]._state == VIDE){
	plat_joueur1[c._px + c._py*getTaille()]._state = RATE;
      }
    }
  }
}


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

int Plateau::UpdateEtatBateau(Coup c,std::vector<Bateau*> B){
  for(unsigned int i=0; i<B.size() ; i++){
    int decal_x=0;
    int decal_y=0;
    switch(B[i]->_dir){
    case NORD :
      decal_x=0;
      decal_y=-1;
      break;
    case SUD :
      decal_x=0;
      decal_y=1;
      break;
    case EST :
      decal_x = 1;
      decal_y=0;
      break;
    case OUEST :
      decal_x=-1;
      decal_y=0;
      break;
    }
    
    for(int j=0;j<B[i]->_longueur ; j++){
      //Il verifie toujours la meme case ( utiliser decalage x
      if(B[i]->_x + decal_x*j == c._px && B[i]->_y +decal_y*j == c._py){
	return i;
      }
    }
  }
  return -1;
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
  
  for(int  i=0; i< getTaille()*getTaille();i++){
    switch (plat_joueur2[i]._state){
    case VIDE :
      std::cout << " . " ;
      break;
    case RATE :
      std::cout << " R ";
      break;
    case TOUCHE :
      std::cout << " T ";
      break;
    case BATEAU :
      std::cout << " B " ; // On met a V pour cacher les bateaux ennemis
      break;
    case COULE :
      std::cout << " C " ;
      break;
    }
    if(i%getTaille()==getTaille()-1){
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << "-----------JOUEUR 1------------";
  std::cout << std::endl;
  std::cout << std::endl;
  
  for(int  i=0; i< getTaille()*getTaille();i++){
      switch (plat_joueur1[i]._state){
       case VIDE :
       	std::cout << " . " ;
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
      case COULE :
	std::cout << " C " ;
	break;	
    }
      if(i%getTaille()==getTaille()-1){
	std::cout << std::endl;
      }
  }
}

//-----PLACER LES BATEAUX

//--Fonction pour placer les bateaux
void Plateau::PlacerBateau(Joueur joueur){
  std::cout << std::endl;
  std::cout << "Placement des cinq bateaux" << std::endl;
  srand (time(NULL)*(joueur._id+1)); // pour eviter de generer le meme
  //plateau pourj1 et j2 en IA VS IA
  
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

    if(joueur._type==HUMAIN){ 
      while(placement_legitime==false){
	//assigne la direction dans laquelle pointe le bateau
	std::cout << "Dans quel sens voulez vous placer le bateau n° " << j+1 << "? ( NORD, SUD, EST, OUEST ) :" << std::endl;
      
	std::string test;
	std::cin >> test;

	while(!(test== "SUD" || test== "NORD" || test=="EST" || test=="OUEST")){
	  std::cout <<"Saisir une direction valide (NORD,SUD,EST,OUEST) " << std::endl;
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
	placement_legitime = verification_placement_bateau(posX,posY,lon,
							   decalage_x,decalage_y,
							   plat_joueur1);
      }//fin du while
   }
    else{ // SI non humain
     while(placement_legitime==false){
       dir=floor(rand()%4);
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
       posX=floor(rand()%9);
       posY=floor(rand()%9);

       if(joueur._id==0){
	 placement_legitime = verification_placement_bateau(posX,posY,lon,
							    decalage_x,decalage_y,
							  plat_joueur1);
       }
       else{
	 placement_legitime = verification_placement_bateau(posX,posY,lon,
							    decalage_x,decalage_y,
							  plat_joueur2);
       }
     }
   }
    
    std::cout << "Bateau n° " << j+1 << " a ete place en " << posX << " , " << posY <<
      " et s'etend jusqu'en " << posX + decalage_x*(lon-1) << " , " << posY + decalage_y*(lon-1) << std::endl;

    if(joueur._id==0){
      flotte_j1[j]= new Bateau(posX,posY,lon,dir,j);
      for(int k=0; k<lon; k++){
	plat_joueur1[posX +   (posY*getTaille())  +   decalage_y*getTaille()*k  + decalage_x*k  ]._state = BATEAU;
      }
    }
    else{
      flotte_j2[j]= new Bateau(posX,posY,lon,dir,j);
      for(int k=0; k<lon; k++){
	plat_joueur2[posX +   (posY*getTaille())  +   decalage_y*getTaille()*k  + decalage_x*k  ]._state = BATEAU;
      }
    }
    
  
    afficher_plateau_console();

  }//fin du for =>passage a l'iteration suivante pour le bateau suivant

  //---FIN DU PLACEMENT DE LA FLOTTE DU JOUEUR 1
}


bool Plateau::verification_placement_bateau(int x, int y, int taille,
					    int decalage_x, int decalage_y,
					    std::vector<Case> C){
  for(int k=0;k<taille;k++){
    //on verifie si le bateau ne sort pas du plateau
    if((x+k*decalage_x) < 0 || (x+k*decalage_x) >= getTaille() ||
       (y+k*decalage_y) < 0 || (y+k*decalage_y) >= getTaille() ){
      std::cout << "Erreur vous sortez du plateau" << std::endl;
      return false;
    }
    if(C[  x +y*getTaille() +   decalage_y*getTaille()*k + decalage_x*k ]._state ==BATEAU){
      std::cout << "Erreur un bateau gêne le placement" << std::endl;
      return false;
    }
  }
  return true;
}

