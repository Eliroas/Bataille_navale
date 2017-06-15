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
