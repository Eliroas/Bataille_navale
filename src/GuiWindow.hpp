#ifndef GUIWINDOW_HPP_
#define GUIWINDOW_HPP_

#include <gtkmm.h>
#include <gtk/gtk.h>
#include <vector>

class GuiWindow {
	public:
		GuiWindow(int argc, char ** argv);
		void run();
                void on_button_options();
                void on_button_jouer();
                void on_button_clicked(Gtk::Button *);
                //virtual ~GuiWindow();
	private:
		Gtk::Main _kit;
		Gtk::Window _FenetrePrincipale;
                Gtk::HBox _boiteImage;
		Gtk::Image _img;
		Gtk::VButtonBox _boiteBoutonsV;
		Gtk::Button _boutonJouer;
		Gtk::Button _boutonOptions;
		Gtk::Button _boutonQuitter;
  
                Gtk::Window _FenetreOptions;
                Gtk::HBox _boiteMessage;
                Gtk::HButtonBox _boiteBoutons;
                Gtk::Button _boutonFacile;
                Gtk::Button _boutonNormal;

                Gtk::Window _FenetreJouer;
                Gtk::Label _difficulte;
                Gtk::VBox _boxJouer;
                Gtk::VBox _boxOrdi;
                //Gtk::Button _test;

                Gtk::Label _joueur;
		std::vector<Gtk::Button *> _Jbutton;
		std::vector<Gtk::HBox *> _Jboxes;

                Gtk::Label _sep1;
                Gtk::Label _sep2;
                Gtk::Label _sep3;
  
                Gtk::Label _ordi;
  		std::vector<Gtk::Button *> _Obutton;
		std::vector<Gtk::HBox *> _Oboxes;
		//Gtk::VBox vertical;
};

#endif
