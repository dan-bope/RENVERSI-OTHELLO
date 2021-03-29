#include "regles_du_jeu.h"
void REGLES_DU_jeu(){

  int x,y;
  int interligne =10;
  MLV_Image *image;
  int width=650, height=520;
  int image_width, image_height;
  image = MLV_load_image( "a3.jpg" );
  /*NETTOIE LA FENETRE MENU POUR AFFICHER LES REGLES DU JEU*/
  //MLV_clear_window(MLV_COLOR_DARK_GREY);
  MLV_resize_image_with_proportions( image, width, height);
  MLV_get_image_size(image, &image_width, &image_height);
  MLV_change_window_size(image_width, image_height);
  MLV_draw_image( image, 0, 0 );
  MLV_free_image( image );
  //MLV_draw_text(230,75/2,"REGLES DU JEU",MLV_COLOR_BLACK);
  MLV_draw_adapted_text_box(0,75,
			    "Il se joue sur un plateau de 64 cases (othellier). Le jeu disposent de 64 pions bicolores, \nnoirs d'un côté et blancs de l'autre.Le but du jeu est d'avoir plus de pions que son \nadversaire à la fin de la partie. Celle-ci se termine lorsque aucun des deux joueurs ne \npeut plus jouer de coup qui soit légal. Au début de la partie, deux pions noirs sont placés \nen e4 et d5 et deux pions blancs sont placés en d4 et e5. Contrairement au dames ou au \néchecs, le joueur ayant les pions Noir commence toujours !Le joueur qui a le trait doit\n poser un pion de sa couleur sur une case vide de l'othellier qui soit adjacente à un pion \nadverse. Pour que le coup soit légal, le pion posé doit encadrer un ou plusieurs pions \nadverses avec un autre pion allié déjà placé sur l'othellier. Pour chaque direction,\n il retourne les pions qu'il vient d'encadrer du côté de ça couleur. Si, le joueur ayant le \ntrait ne peut pas poser de pion suivant les règles, il devra passer son tour par défaut.\n En revanche, s'il peut réaliser un coup qui soit légal, il ne pourra pas passer son tour",
			    interligne,
			    MLV_COLOR_DARK_GREY,
			    MLV_COLOR_BLACK,
			    MLV_COLOR_DARK_GREY,
			    MLV_TEXT_LEFT
			    );
    
    
 
  MLV_draw_adapted_text_box(230,450,
			    "RETOUR AU MENU",
			    interligne-5,
			    MLV_COLOR_BLACK,
			    MLV_COLOR_DARK_GREEN,
			    MLV_COLOR_DARK_GREY,
			    MLV_TEXT_CENTER
			    );
  MLV_actualise_window();



      
  while(1){
    MLV_wait_mouse(&x,&y);
    if(x>=230 && y>=450 && x<=369 && y<=474){
         
      MENU();
    }
  }
}

