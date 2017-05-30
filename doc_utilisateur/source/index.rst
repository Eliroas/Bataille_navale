.. Bataille_Navale documentation master file, created by
   sphinx-quickstart on Tue May 30 13:50:09 2017.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

============================================
Bienvenue sur la doc de la Bataille Navale !
============================================

Description
------------

.. toctree::
   :maxdepth: 2
	      
Bataille Navale est notre projet de fin d'étude en licence informatique.
	      
Il permet de jouer au celebre jeu de bateau contre l'ordinateur ou contre un autre joueur !

Récupérer les sources
---------------------

Le code source de la Bataille Navale se trouve sur github :

::
   
   $ git clone https://github.com/Eliroas/Bataille_navale

Compiler
--------

Bataille Navale utilise cmake. Pour compiler :

::

   $ cd Bataille_navale
   $ mkdir build
   $ cd build
   $ cmake ..
   $ make

Executer
--------

Ligne de commande pour executer le jeu préalablement compilé

::

   ./bataille.out
