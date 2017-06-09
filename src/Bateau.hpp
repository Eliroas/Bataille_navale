#ifndef BATEAU_HPP_
#define BATEAU_HPP_

class Bateau{
public:
  int _x;
  int _y;
  int _longueur;
  int _dir;
  int _nbTouche;
  int _id;
  
  //l' attribut nbTouche verifie combien de fois il a été touché, une fois qu'elle est
  //egale a la longueur, le bateau est coulé ( supprimé du vector <bateau> )
  
  Bateau(int x, int y, int longueur, int dir, int id);

  int getAbscisse();
  int getOrdonnee();
  int getTaille();
  int getDir();

};

#endif

/*
On ne peut pas savoir quel bateau on a touché lorsqu'on joue un coup

Pour cela, on rajoute un id au bateau
et lorsqu'on a tiré, on parcourt la flotte du joueur adverse
et on repere quel bateau contient une case aux meme 
coordonnées que le coup.(grace a l'id
Puis on incrémente le nbtouche de ce bateau
et une fois que son nbtouche est egal a sa longueur
il est coulé ( supprimé du vector flotte )
une fois que flotte est vide, le jeu s'arrete

 */
