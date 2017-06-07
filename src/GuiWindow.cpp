// Ligne de compilation:
// g++ GuiWindow.cpp -o Fenetre `pkg-config gtkmm-3.0 --cflags --libs`

#include "GuiWindow.hpp"

#include <iostream>
#include <gtkmm.h>
#include <gtkmm/button.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/container.h>
#include <gtkmm/buttonbox.h>


GuiWindow::GuiWindow(int argc, char ** argv) : _kit(argc, argv) {

  _FenetrePrincipale.set_title("Bataille Navale");
  _FenetrePrincipale.set_icon_from_file("../img/icone2.png");
  _img.set("../img/bataille2.jpg");
  _boiteImage.add(_img);
	   
  _boiteBoutonsV.pack_start(_boiteImage);
  _boutonJouer.set_label("Jouer");
  _boutonJouer.set_can_focus(false);
  _boutonJouer.signal_clicked().connect(sigc::mem_fun(*this, &GuiWindow::on_button_jouer));
  _boutonOptions.set_label("Options");
  _boutonOptions.set_can_focus(false);
  _boutonOptions.signal_clicked().connect(sigc::mem_fun(*this, &GuiWindow::on_button_options));
  _boutonQuitter.set_label("Quitter");
  _boutonQuitter.set_can_focus(false);
  _boutonQuitter.signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit));
  _boiteBoutonsV.pack_start(_boutonJouer);
  _boiteBoutonsV.pack_start(_boutonOptions);
  _boiteBoutonsV.pack_start(_boutonQuitter);
	   
  _FenetrePrincipale.add(_boiteBoutonsV);
  _FenetrePrincipale.show_all();
}





void GuiWindow::run() {
    _kit.run(_FenetrePrincipale);
}





void GuiWindow::on_button_options()
{
  _FenetreOptions.set_title("Options");
  // Modifier le titre de la fenetre
  _FenetreOptions.set_default_size(480,100);
  // Redimensionner la fenetre
  _FenetreOptions.set_icon_from_file("../img/icone2.png");
  _difficulte.set_label("Type de joueur:");
  _boiteMessage.add(_difficulte);
  // Ajout du message au conteneur

  _boutonFacile.set_label("Humain");
  _boutonFacile.set_can_focus(false);
  _boutonFacile.signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit));
  // Creation du bouton pour la difficulté Facile
  _boutonNormal.set_label("IA");
  _boutonNormal.set_can_focus(false);
  _boutonNormal.signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit));
   // Creation du bouton pour la difficulté Normale
  _boiteBoutons.pack_start(_boiteMessage);
  // Ajout du conteneur du message au conteneur des boutons
  _boiteBoutons.pack_start(_boutonFacile);
  // Ajout du bouton Facile au conteneur
  _boiteBoutons.pack_start(_boutonNormal);
  // Ajout du bouton Normal au conteneur
  _FenetreOptions.add(_boiteBoutons);
  // Ajout du conteneur a la fenetre
  
  _FenetreOptions.show_all();
  Gtk::Main::run(_FenetreOptions);
  // Affichage de la fenetre
}





void GuiWindow::on_button_jouer(){

  _FenetreJouer.set_title("Le Jeu");
  //_FenetreJouer.set_default_size(480,100);
  _FenetreJouer.set_icon_from_file("../img/icone2.png");

  _ordi.set_label("Ordinateur");
  
  for(int i = 0; i < 81; i++){
    _Obutton.push_back(new Gtk::Button());
  }
	
  for(int i = 0; i < 9; i++){
    _Oboxes.push_back(new Gtk::HBox);
  }

  //Set up frames
  for(int i = 0; i < 9; i++){
    for(int x = 0; x < 9; x++){
      _Oboxes[i]->add(*_Obutton[i*9 + x]);
      _Obutton[i*9 + x]->set_size_request(50, 50);
      _Obutton[i*9 + x]->signal_clicked().connect(sigc::bind<Gtk::Button*>
      (sigc::mem_fun(*this, &GuiWindow::on_button_clicked), _Obutton[i*9 + x]));
      _Obutton[i*9 + x]->show();
     }
     _Oboxes[i]->show();
     _boxOrdi.add(_ordi);
     _boxOrdi.add(*_Oboxes[i]);
  }

  _sep2.set_label("-------------------------------------------------------------------------------------------");
  _joueur.set_label("Joueur");
  _boxJouer.add(_boxOrdi);
  _boxJouer.add(_sep1);
  _boxJouer.add(_sep2);
  _boxJouer.add(_sep3);
  _boxJouer.add(_joueur);
  

  for(int i = 0; i < 81; i++){
    _Jbutton.push_back(new Gtk::Button());
  }

  
  
  for(int i = 0; i < 9; i++){
    _Jboxes.push_back(new Gtk::HBox);
  }

  //Set up frames
  for(int i = 0; i < 9; i++){
    for(int x = 0; x < 9; x++){
      _Jboxes[i]->add(*_Jbutton[i*9 + x]);
      _Jbutton[i*9 + x]->set_size_request(50, 50);
      //_Jbutton[i*9 + x]->signal_clicked().connect(sigc::bind<Gtk::Button*>
      //(sigc::mem_fun(*this, &GuiWindow::on_button_clicked), _Jbutton[i*9 + x]));
      _Jbutton[i*9 + x]->show();
     }
     _Jboxes[i]->show();
     _boxJouer.add(*_Jboxes[i]);
  }

  _FenetreJouer.add(_boxJouer);
  _FenetreJouer.show_all();
  _FenetreJouer.set_border_width(30);
  Gtk::Main::run(_FenetreJouer);
  
}

void GuiWindow::on_button_clicked(Gtk::Button *button){
  button->set_label("X");
  button->set_sensitive(false);
 }

int main(int argc, char* argv[]) {

  GuiWindow window(argc, argv);
  window.run();
  return 0;
} 
