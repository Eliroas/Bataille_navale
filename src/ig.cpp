// Ligne de compilation:
// g++ ig.cpp -o Fenetre `pkg-config gtkmm-3.0 --cflags --libs`

#include <iostream>
#include <gtkmm.h>
#include <gtkmm/button.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/container.h>
#include <gtkmm/buttonbox.h>
#include <vector>

void on_button_press(Gtk::Button *b){
  b->set_label("A");
}

void on_button_clicked_jouer()
{
  Gtk::Window fenetreJouer;
  fenetreJouer.set_title("Le Jeu");
  fenetreJouer.set_default_size(1080,720);
  fenetreJouer.set_icon_from_file("../img/icone2.png");

  Gtk::Table tableau(2, 2); //Création d'un tableau 

  /*
  std::vector <Gtk::Button> Grille;
  for(int i=1;i<82;i++){
    Grille[i].set_label(" ");
    Grille[i].set_can_focus(false);
  }
  */
  
  
  Gtk::Button bouton1(" ");
  //bouton1.signal_clicked().connect( sigc::ptr_fun(&on_button_press(&bouton1)) );
  Gtk::Button bouton2(" ");
  Gtk::Button bouton3(" ");
  Gtk::Button bouton4(" ");
  Gtk::Button bouton5(" ");
  Gtk::Button bouton6(" ");
  Gtk::Button bouton7(" ");
  Gtk::Button bouton8(" ");
  Gtk::Button bouton9(" ");
  Gtk::Button bouton10(" ");
  Gtk::Button bouton11(" ");
  Gtk::Button bouton12(" ");
  Gtk::Button bouton13(" ");
  Gtk::Button bouton14(" ");
  Gtk::Button bouton15(" ");
  Gtk::Button bouton16(" ");
  Gtk::Button bouton17(" ");
  Gtk::Button bouton18(" ");
  Gtk::Button bouton19(" ");
  Gtk::Button bouton20(" ");
  Gtk::Button bouton21(" ");
  Gtk::Button bouton22(" ");
  Gtk::Button bouton23(" ");
  Gtk::Button bouton24(" ");
  Gtk::Button bouton25(" ");
  Gtk::Button bouton26(" ");
  Gtk::Button bouton27(" ");
  Gtk::Button bouton28(" ");
  Gtk::Button bouton29(" ");
  Gtk::Button bouton30(" ");
  Gtk::Button bouton31(" ");
  Gtk::Button bouton32(" ");
  Gtk::Button bouton33(" ");
  Gtk::Button bouton34(" ");
  Gtk::Button bouton35(" ");
  Gtk::Button bouton36(" ");
  Gtk::Button bouton37(" ");
  Gtk::Button bouton38(" ");
  Gtk::Button bouton39(" ");
  Gtk::Button bouton40(" ");
  Gtk::Button bouton41(" ");
  Gtk::Button bouton42(" ");
  Gtk::Button bouton43(" ");
  Gtk::Button bouton44(" ");
  Gtk::Button bouton45(" ");
  Gtk::Button bouton46(" ");
  Gtk::Button bouton47(" ");
  Gtk::Button bouton48(" ");
  Gtk::Button bouton49(" ");
  Gtk::Button bouton50(" ");
  Gtk::Button bouton51(" ");
  Gtk::Button bouton52(" ");
  Gtk::Button bouton53(" ");
  Gtk::Button bouton54(" ");
  Gtk::Button bouton55(" ");
  Gtk::Button bouton56(" ");
  Gtk::Button bouton57(" ");
  Gtk::Button bouton58(" ");
  Gtk::Button bouton59(" ");
  Gtk::Button bouton60(" ");
  Gtk::Button bouton61(" ");
  Gtk::Button bouton62(" ");
  Gtk::Button bouton63(" ");
  Gtk::Button bouton64(" ");
  Gtk::Button bouton65(" ");
  Gtk::Button bouton66(" ");
  Gtk::Button bouton67(" ");
  Gtk::Button bouton68(" ");
  Gtk::Button bouton69(" ");
  Gtk::Button bouton70(" ");
  Gtk::Button bouton71(" ");
  Gtk::Button bouton72(" ");
  Gtk::Button bouton73(" ");
  Gtk::Button bouton74(" ");
  Gtk::Button bouton75(" ");
  Gtk::Button bouton76(" ");
  Gtk::Button bouton77(" ");
  Gtk::Button bouton78(" ");
  Gtk::Button bouton79(" ");
  Gtk::Button bouton80(" ");
  Gtk::Button bouton81(" ");
  
  bouton1.set_can_focus(false);
  bouton2.set_can_focus(false);
  bouton3.set_can_focus(false);
  bouton4.set_can_focus(false);
  bouton5.set_can_focus(false);
  bouton6.set_can_focus(false);
  bouton7.set_can_focus(false);
  bouton8.set_can_focus(false);
  bouton9.set_can_focus(false);
  bouton10.set_can_focus(false);
  bouton11.set_can_focus(false);
  bouton12.set_can_focus(false);
  bouton13.set_can_focus(false);
  bouton14.set_can_focus(false);
  bouton15.set_can_focus(false);
  bouton16.set_can_focus(false);
  bouton17.set_can_focus(false);
  bouton18.set_can_focus(false);
  bouton19.set_can_focus(false);
  bouton20.set_can_focus(false);
  bouton21.set_can_focus(false);
  bouton22.set_can_focus(false);
  bouton23.set_can_focus(false);
  bouton24.set_can_focus(false);
  bouton25.set_can_focus(false);
  bouton26.set_can_focus(false);
  bouton27.set_can_focus(false);
  bouton28.set_can_focus(false);
  bouton29.set_can_focus(false);
  bouton30.set_can_focus(false);
  bouton31.set_can_focus(false);
  bouton32.set_can_focus(false);
  bouton33.set_can_focus(false);
  bouton34.set_can_focus(false);
  bouton35.set_can_focus(false);
  bouton36.set_can_focus(false);
  bouton37.set_can_focus(false);
  bouton38.set_can_focus(false);
  bouton39.set_can_focus(false);
  bouton40.set_can_focus(false);
  bouton41.set_can_focus(false);
  bouton42.set_can_focus(false);
  bouton43.set_can_focus(false);
  bouton44.set_can_focus(false);
  bouton45.set_can_focus(false);
  bouton46.set_can_focus(false);
  bouton47.set_can_focus(false);
  bouton48.set_can_focus(false);
  bouton49.set_can_focus(false);
  bouton50.set_can_focus(false);
  bouton51.set_can_focus(false);
  bouton52.set_can_focus(false);
  bouton53.set_can_focus(false);
  bouton54.set_can_focus(false);
  bouton55.set_can_focus(false);
  bouton56.set_can_focus(false);
  bouton57.set_can_focus(false);
  bouton58.set_can_focus(false);
  bouton59.set_can_focus(false);
  bouton60.set_can_focus(false);
  bouton61.set_can_focus(false);
  bouton62.set_can_focus(false);
  bouton63.set_can_focus(false);
  bouton64.set_can_focus(false);
  bouton65.set_can_focus(false);
  bouton66.set_can_focus(false);
  bouton67.set_can_focus(false);
  bouton68.set_can_focus(false);
  bouton69.set_can_focus(false);
  bouton70.set_can_focus(false);
  bouton71.set_can_focus(false);
  bouton72.set_can_focus(false);
  bouton73.set_can_focus(false);
  bouton74.set_can_focus(false);
  bouton75.set_can_focus(false);
  bouton76.set_can_focus(false);
  bouton77.set_can_focus(false);
  bouton78.set_can_focus(false);
  bouton79.set_can_focus(false);
  bouton80.set_can_focus(false);
  bouton81.set_can_focus(false);
  

  tableau.attach(bouton1, 0, 1, 0, 1);
  tableau.attach(bouton2, 1, 2, 0, 1); 
  tableau.attach(bouton3, 2, 3, 0, 1);
  tableau.attach(bouton4, 3, 4, 0, 1);
  tableau.attach(bouton5, 4, 5, 0, 1);
  tableau.attach(bouton6, 5, 6, 0, 1);
  tableau.attach(bouton7, 6, 7, 0, 1);
  tableau.attach(bouton8, 7, 8, 0, 1);
  tableau.attach(bouton9, 8, 9, 0, 1);
  
  tableau.attach(bouton10, 0, 1, 1, 2);
  tableau.attach(bouton11, 1, 2, 1, 2); 
  tableau.attach(bouton12, 2, 3, 1, 2);
  tableau.attach(bouton13, 3, 4, 1, 2);
  tableau.attach(bouton14, 4, 5, 1, 2);
  tableau.attach(bouton15, 5, 6, 1, 2);
  tableau.attach(bouton16, 6, 7, 1, 2);
  tableau.attach(bouton17, 7, 8, 1, 2);
  tableau.attach(bouton18, 8, 9, 1, 2);
  
  tableau.attach(bouton19, 0, 1, 2, 3);
  tableau.attach(bouton20, 1, 2, 2, 3); 
  tableau.attach(bouton21, 2, 3, 2, 3);
  tableau.attach(bouton22, 3, 4, 2, 3);
  tableau.attach(bouton23, 4, 5, 2, 3);
  tableau.attach(bouton24, 5, 6, 2, 3);
  tableau.attach(bouton25, 6, 7, 2, 3);
  tableau.attach(bouton26, 7, 8, 2, 3);
  tableau.attach(bouton27, 8, 9, 2, 3);
  
  tableau.attach(bouton28, 0, 1, 3, 4);
  tableau.attach(bouton29, 1, 2, 3, 4); 
  tableau.attach(bouton30, 2, 3, 3, 4);
  tableau.attach(bouton31, 3, 4, 3, 4);
  tableau.attach(bouton32, 4, 5, 3, 4);
  tableau.attach(bouton33, 5, 6, 3, 4);
  tableau.attach(bouton34, 6, 7, 3, 4);
  tableau.attach(bouton35, 7, 8, 3, 4);
  tableau.attach(bouton36, 8, 9, 3, 4);
  
  tableau.attach(bouton37, 0, 1, 4, 5);
  tableau.attach(bouton38, 1, 2, 4, 5); 
  tableau.attach(bouton39, 2, 3, 4, 5);
  tableau.attach(bouton40, 3, 4, 4, 5);
  tableau.attach(bouton41, 4, 5, 4, 5);
  tableau.attach(bouton42, 5, 6, 4, 5);
  tableau.attach(bouton43, 6, 7, 4, 5);
  tableau.attach(bouton44, 7, 8, 4, 5);
  tableau.attach(bouton45, 8, 9, 4, 5);
  
  tableau.attach(bouton46, 0, 1, 5, 6);
  tableau.attach(bouton47, 1, 2, 5, 6); 
  tableau.attach(bouton48, 2, 3, 5, 6);
  tableau.attach(bouton49, 3, 4, 5, 6);
  tableau.attach(bouton50, 4, 5, 5, 6);
  tableau.attach(bouton51, 5, 6, 5, 6);
  tableau.attach(bouton52, 6, 7, 5, 6);
  tableau.attach(bouton53, 7, 8, 5, 6);
  tableau.attach(bouton54, 8, 9, 5, 6);
  
  tableau.attach(bouton55, 0, 1, 6, 7);
  tableau.attach(bouton56, 1, 2, 6, 7); 
  tableau.attach(bouton57, 2, 3, 6, 7);
  tableau.attach(bouton58, 3, 4, 6, 7);
  tableau.attach(bouton59, 4, 5, 6, 7);
  tableau.attach(bouton60, 5, 6, 6, 7);
  tableau.attach(bouton61, 6, 7, 6, 7);
  tableau.attach(bouton62, 7, 8, 6, 7);
  tableau.attach(bouton63, 8, 9, 6, 7);
  
  tableau.attach(bouton64, 0, 1, 7, 8);
  tableau.attach(bouton65, 1, 2, 7, 8); 
  tableau.attach(bouton66, 2, 3, 7, 8);
  tableau.attach(bouton67, 3, 4, 7, 8);
  tableau.attach(bouton68, 4, 5, 7, 8);
  tableau.attach(bouton69, 5, 6, 7, 8);
  tableau.attach(bouton70, 6, 7, 7, 8);
  tableau.attach(bouton71, 7, 8, 7, 8);
  tableau.attach(bouton72, 8, 9, 7, 8);
  
  tableau.attach(bouton73, 0, 1, 8, 9);
  tableau.attach(bouton74, 1, 2, 8, 9); 
  tableau.attach(bouton75, 2, 3, 8, 9);
  tableau.attach(bouton76, 3, 4, 8, 9);
  tableau.attach(bouton77, 4, 5, 8, 9);
  tableau.attach(bouton78, 5, 6, 8, 9);
  tableau.attach(bouton79, 6, 7, 8, 9);
  tableau.attach(bouton80, 7, 8, 8, 9);
  tableau.attach(bouton81, 8, 9, 8, 9);


  // fin 1er tableau

  Gtk::Table tableau2(2, 2); //Création du 2eme tableau 
  
  Gtk::Button bouton1a("X");
  Gtk::Button bouton2a("X");
  Gtk::Button bouton3a("X");
  Gtk::Button bouton4a("X");
  Gtk::Button bouton5a("X");
  Gtk::Button bouton6a("X");
  Gtk::Button bouton7a("X");
  Gtk::Button bouton8a("X");
  Gtk::Button bouton9a("X");
  Gtk::Button bouton10a("X");
  Gtk::Button bouton11a("X");
  Gtk::Button bouton12a("X");
  Gtk::Button bouton13a("X");
  Gtk::Button bouton14a("X");
  Gtk::Button bouton15a("X");
  Gtk::Button bouton16a("X");
  Gtk::Button bouton17a("X");
  Gtk::Button bouton18a("X");
  Gtk::Button bouton19a("X");
  Gtk::Button bouton20a("X");
  Gtk::Button bouton21a("X");
  Gtk::Button bouton22a("X");
  Gtk::Button bouton23a("X");
  Gtk::Button bouton24a("X");
  Gtk::Button bouton25a("X");
  Gtk::Button bouton26a("X");
  Gtk::Button bouton27a("X");
  Gtk::Button bouton28a("X");
  Gtk::Button bouton29a("X");
  Gtk::Button bouton30a("X");
  Gtk::Button bouton31a("X");
  Gtk::Button bouton32a("X");
  Gtk::Button bouton33a("X");
  Gtk::Button bouton34a("X");
  Gtk::Button bouton35a("X");
  Gtk::Button bouton36a("X");
  Gtk::Button bouton37a("X");
  Gtk::Button bouton38a("X");
  Gtk::Button bouton39a("X");
  Gtk::Button bouton40a("X");
  Gtk::Button bouton41a("X");
  Gtk::Button bouton42a("X");
  Gtk::Button bouton43a("X");
  Gtk::Button bouton44a("X");
  Gtk::Button bouton45a("X");
  Gtk::Button bouton46a("X");
  Gtk::Button bouton47a("X");
  Gtk::Button bouton48a("X");
  Gtk::Button bouton49a("X");
  Gtk::Button bouton50a("X");
  Gtk::Button bouton51a("X");
  Gtk::Button bouton52a("X");
  Gtk::Button bouton53a("X");
  Gtk::Button bouton54a("X");
  Gtk::Button bouton55a("X");
  Gtk::Button bouton56a("X");
  Gtk::Button bouton57a("X");
  Gtk::Button bouton58a("X");
  Gtk::Button bouton59a("X");
  Gtk::Button bouton60a("X");
  Gtk::Button bouton61a("X");
  Gtk::Button bouton62a("X");
  Gtk::Button bouton63a("X");
  Gtk::Button bouton64a("X");
  Gtk::Button bouton65a("X");
  Gtk::Button bouton66a("X");
  Gtk::Button bouton67a("X");
  Gtk::Button bouton68a("X");
  Gtk::Button bouton69a("X");
  Gtk::Button bouton70a("X");
  Gtk::Button bouton71a("X");
  Gtk::Button bouton72a("X");
  Gtk::Button bouton73a("X");
  Gtk::Button bouton74a("X");
  Gtk::Button bouton75a("X");
  Gtk::Button bouton76a("X");
  Gtk::Button bouton77a("X");
  Gtk::Button bouton78a("X");
  Gtk::Button bouton79a("X");
  Gtk::Button bouton80a("X");
  Gtk::Button bouton81a("X");
  
  
  bouton1a.set_can_focus(false);
  bouton2a.set_can_focus(false);
  bouton3a.set_can_focus(false);
  bouton4a.set_can_focus(false);
  bouton5a.set_can_focus(false);
  bouton6a.set_can_focus(false);
  bouton7a.set_can_focus(false);
  bouton8a.set_can_focus(false);
  bouton9a.set_can_focus(false);
  bouton10a.set_can_focus(false);
  bouton11a.set_can_focus(false);
  bouton12a.set_can_focus(false);
  bouton13a.set_can_focus(false);
  bouton14a.set_can_focus(false);
  bouton15a.set_can_focus(false);
  bouton16a.set_can_focus(false);
  bouton17a.set_can_focus(false);
  bouton18a.set_can_focus(false);
  bouton19a.set_can_focus(false);
  bouton20a.set_can_focus(false);
  bouton21a.set_can_focus(false);
  bouton22a.set_can_focus(false);
  bouton23a.set_can_focus(false);
  bouton24a.set_can_focus(false);
  bouton25a.set_can_focus(false);
  bouton26a.set_can_focus(false);
  bouton27a.set_can_focus(false);
  bouton28a.set_can_focus(false);
  bouton29a.set_can_focus(false);
  bouton30a.set_can_focus(false);
  bouton31a.set_can_focus(false);
  bouton32a.set_can_focus(false);
  bouton33a.set_can_focus(false);
  bouton34a.set_can_focus(false);
  bouton35a.set_can_focus(false);
  bouton36a.set_can_focus(false);
  bouton37a.set_can_focus(false);
  bouton38a.set_can_focus(false);
  bouton39a.set_can_focus(false);
  bouton40a.set_can_focus(false);
  bouton41a.set_can_focus(false);
  bouton42a.set_can_focus(false);
  bouton43a.set_can_focus(false);
  bouton44a.set_can_focus(false);
  bouton45a.set_can_focus(false);
  bouton46a.set_can_focus(false);
  bouton47a.set_can_focus(false);
  bouton48a.set_can_focus(false);
  bouton49a.set_can_focus(false);
  bouton50a.set_can_focus(false);
  bouton51a.set_can_focus(false);
  bouton52a.set_can_focus(false);
  bouton53a.set_can_focus(false);
  bouton54a.set_can_focus(false);
  bouton55a.set_can_focus(false);
  bouton56a.set_can_focus(false);
  bouton57a.set_can_focus(false);
  bouton58a.set_can_focus(false);
  bouton59a.set_can_focus(false);
  bouton60a.set_can_focus(false);
  bouton61a.set_can_focus(false);
  bouton62a.set_can_focus(false);
  bouton63a.set_can_focus(false);
  bouton64a.set_can_focus(false);
  bouton65a.set_can_focus(false);
  bouton66a.set_can_focus(false);
  bouton67a.set_can_focus(false);
  bouton68a.set_can_focus(false);
  bouton69a.set_can_focus(false);
  bouton70a.set_can_focus(false);
  bouton71a.set_can_focus(false);
  bouton72a.set_can_focus(false);
  bouton73a.set_can_focus(false);
  bouton74a.set_can_focus(false);
  bouton75a.set_can_focus(false);
  bouton76a.set_can_focus(false);
  bouton77a.set_can_focus(false);
  bouton78a.set_can_focus(false);
  bouton79a.set_can_focus(false);
  bouton80a.set_can_focus(false);
  bouton81a.set_can_focus(false);
  
  tableau2.attach(bouton1a, 0, 1, 0, 1);
  tableau2.attach(bouton2a, 1, 2, 0, 1); 
  tableau2.attach(bouton3a, 2, 3, 0, 1);
  tableau2.attach(bouton4a, 3, 4, 0, 1);
  tableau2.attach(bouton5a, 4, 5, 0, 1);
  tableau2.attach(bouton6a, 5, 6, 0, 1);
  tableau2.attach(bouton7a, 6, 7, 0, 1);
  tableau2.attach(bouton8a, 7, 8, 0, 1);
  tableau2.attach(bouton9a, 8, 9, 0, 1);
  
  tableau2.attach(bouton10a, 0, 1, 1, 2);
  tableau2.attach(bouton11a, 1, 2, 1, 2); 
  tableau2.attach(bouton12a, 2, 3, 1, 2);
  tableau2.attach(bouton13a, 3, 4, 1, 2);
  tableau2.attach(bouton14a, 4, 5, 1, 2);
  tableau2.attach(bouton15a, 5, 6, 1, 2);
  tableau2.attach(bouton16a, 6, 7, 1, 2);
  tableau2.attach(bouton17a, 7, 8, 1, 2);
  tableau2.attach(bouton18a, 8, 9, 1, 2);
  
  tableau2.attach(bouton19a, 0, 1, 2, 3);
  tableau2.attach(bouton20a, 1, 2, 2, 3); 
  tableau2.attach(bouton21a, 2, 3, 2, 3);
  tableau2.attach(bouton22a, 3, 4, 2, 3);
  tableau2.attach(bouton23a, 4, 5, 2, 3);
  tableau2.attach(bouton24a, 5, 6, 2, 3);
  tableau2.attach(bouton25a, 6, 7, 2, 3);
  tableau2.attach(bouton26a, 7, 8, 2, 3);
  tableau2.attach(bouton27a, 8, 9, 2, 3);
  
  tableau2.attach(bouton28a, 0, 1, 3, 4);
  tableau2.attach(bouton29a, 1, 2, 3, 4); 
  tableau2.attach(bouton30a, 2, 3, 3, 4);
  tableau2.attach(bouton31a, 3, 4, 3, 4);
  tableau2.attach(bouton32a, 4, 5, 3, 4);
  tableau2.attach(bouton33a, 5, 6, 3, 4);
  tableau2.attach(bouton34a, 6, 7, 3, 4);
  tableau2.attach(bouton35a, 7, 8, 3, 4);
  tableau2.attach(bouton36a, 8, 9, 3, 4);
  
  tableau2.attach(bouton37a, 0, 1, 4, 5);
  tableau2.attach(bouton38a, 1, 2, 4, 5); 
  tableau2.attach(bouton39a, 2, 3, 4, 5);
  tableau2.attach(bouton40a, 3, 4, 4, 5);
  tableau2.attach(bouton41a, 4, 5, 4, 5);
  tableau2.attach(bouton42a, 5, 6, 4, 5);
  tableau2.attach(bouton43a, 6, 7, 4, 5);
  tableau2.attach(bouton44a, 7, 8, 4, 5);
  tableau2.attach(bouton45a, 8, 9, 4, 5);
  
  tableau2.attach(bouton46a, 0, 1, 5, 6);
  tableau2.attach(bouton47a, 1, 2, 5, 6); 
  tableau2.attach(bouton48a, 2, 3, 5, 6);
  tableau2.attach(bouton49a, 3, 4, 5, 6);
  tableau2.attach(bouton50a, 4, 5, 5, 6);
  tableau2.attach(bouton51a, 5, 6, 5, 6);
  tableau2.attach(bouton52a, 6, 7, 5, 6);
  tableau2.attach(bouton53a, 7, 8, 5, 6);
  tableau2.attach(bouton54a, 8, 9, 5, 6);
  
  tableau2.attach(bouton55a, 0, 1, 6, 7);
  tableau2.attach(bouton56a, 1, 2, 6, 7); 
  tableau2.attach(bouton57a, 2, 3, 6, 7);
  tableau2.attach(bouton58a, 3, 4, 6, 7);
  tableau2.attach(bouton59a, 4, 5, 6, 7);
  tableau2.attach(bouton60a, 5, 6, 6, 7);
  tableau2.attach(bouton61a, 6, 7, 6, 7);
  tableau2.attach(bouton62a, 7, 8, 6, 7);
  tableau2.attach(bouton63a, 8, 9, 6, 7);
  
  tableau2.attach(bouton64a, 0, 1, 7, 8);
  tableau2.attach(bouton65a, 1, 2, 7, 8); 
  tableau2.attach(bouton66a, 2, 3, 7, 8);
  tableau2.attach(bouton67a, 3, 4, 7, 8);
  tableau2.attach(bouton68a, 4, 5, 7, 8);
  tableau2.attach(bouton69a, 5, 6, 7, 8);
  tableau2.attach(bouton70a, 6, 7, 7, 8);
  tableau2.attach(bouton71a, 7, 8, 7, 8);
  tableau2.attach(bouton72a, 8, 9, 7, 8);
  
  tableau2.attach(bouton73a, 0, 1, 8, 9);
  tableau2.attach(bouton74a, 1, 2, 8, 9); 
  tableau2.attach(bouton75a, 2, 3, 8, 9);
  tableau2.attach(bouton76a, 3, 4, 8, 9);
  tableau2.attach(bouton77a, 4, 5, 8, 9);
  tableau2.attach(bouton78a, 5, 6, 8, 9);
  tableau2.attach(bouton79a, 6, 7, 8, 9);
  tableau2.attach(bouton80a, 7, 8, 8, 9);
  tableau2.attach(bouton81a, 8, 9, 8, 9);

  //fin du tableau 2

  Gtk::HBox Grilles(false,10);
  Grilles.add(tableau);
  Grilles.add(tableau2);
  fenetreJouer.add(Grilles);

  tableau.set_border_width(50);
  tableau2.set_border_width(50);
  //fenetreJouer.set_border_width(50);

  fenetreJouer.show_all();
  Gtk::Main::run(fenetreJouer);
}
  

void on_button_clicked_options()
{
  Gtk::Window fenetreOption;
  // Creation de la fenetre des options
  fenetreOption.set_title("Options");
  // Modifier le titre de la fenetre
  fenetreOption.set_default_size(480,100);
  // Redimensionner la fenetre
  fenetreOption.set_icon_from_file("../img/icone2.png");
  Gtk::HBox boiteMessage(false,10);
  // Creation du conteneur du message
  Gtk::Label message("Choix de la difficulté:");
  // Creation du message
  boiteMessage.add(message);
  // Ajout du message au conteneur

  Gtk::HButtonBox boiteBoutons(Gtk::BUTTONBOX_CENTER, 25);
  // Creation du conteneur des boutons
  Gtk::Button boutonFacile("Facile");
  boutonFacile.set_can_focus(false);
  boutonFacile.signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit));
  // Creation du bouton pour la difficulté Facile
  Gtk::Button boutonNormal("Normal");
  boutonNormal.set_can_focus(false);
  boutonNormal.signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit));
   // Creation du bouton pour la difficulté Normale
  boiteBoutons.pack_start(boiteMessage);
  // Ajout du conteneur du message au conteneur des boutons
  boiteBoutons.pack_start(boutonFacile);
  // Ajout du bouton Facile au conteneur
  boiteBoutons.pack_start(boutonNormal);
  // Ajout du bouton Normal au conteneur
  fenetreOption.add(boiteBoutons);
  // Ajout du conteneur a la fenetre
  
  fenetreOption.show_all();
  Gtk::Main::run(fenetreOption);
  // Affichage de la fenetre
}




int main(int argc, char* argv[]) {
  
  Gtk::Main kit(argc, argv);
  //Initialise gtkmm et regarde dans les arguments du programme.
  Gtk::Window fenetre;
  //Création de la fenêtre.
  fenetre.set_title("Bataille Navale !");
  //Modifier le titre de la fenêtre.
  fenetre.set_default_size(1080,720);
  //redimmensionner la fenetre

  Gtk::HBox boiteImage(false,10);
  Gtk::Image image("../img/bataille2.jpg");
  //Création d'une image à partir d'un fichier.
  boiteImage.add(image);

  // creation de la boite des boutons
  Gtk::VButtonBox boiteBoutonsV(Gtk::BUTTONBOX_CENTER, 50);
    Gtk::Button boutonJouer("Jouer");
    boutonJouer.set_can_focus(false);
    boutonJouer.signal_clicked().connect(sigc::ptr_fun(&on_button_clicked_jouer));
    Gtk::Button boutonOptions("Options");
    boutonOptions.set_can_focus(false);
    boutonOptions.signal_clicked().connect(sigc::ptr_fun(&on_button_clicked_options));
    Gtk::Button boutonFermer("Quitter");
    boutonFermer.set_can_focus(false);
    boutonFermer.signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit));
    //Connexion du signal clicked() à la fonction Gtk::Main::quit() qui ferme le programme.
    
    //Ajout de boutons à la boîte.
    //boiteBoutonsV.pack_start(boiteV);
    boiteBoutonsV.pack_start(boiteImage);
    boiteBoutonsV.pack_start(boutonJouer);
    boiteBoutonsV.pack_start(boutonOptions);
    boiteBoutonsV.pack_start(boutonFermer);

    fenetre.add(boiteBoutonsV);
    //Ajout de la boîte à la fenêtre.
    fenetre.show_all(); 

  
  fenetre.set_icon_from_file("../img/icone2.png");
  //icone du jeu

  
  fenetre.set_border_width(10);
  //Ajouter une bordure (invisible) de 10px à la fenêtre.
  
  Gtk::Main::run(fenetre);
  //Affiche la fenêtre et démarre la boucle, qui se terminera lorsqu'on fermera le programme.
  
  return 0;
} 
