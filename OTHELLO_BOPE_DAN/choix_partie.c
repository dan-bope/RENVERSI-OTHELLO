#include "choix_partie.h"




void CHOIX_partie(){
  int x,y;
  MLV_Image *image;
  MLV_Image *image2; 
  MLV_Image *image3; 
  int width=650, height=520;
  int image_width, image_height;
  image = MLV_load_image( "fondmenu.jpg" );
  image2 = MLV_load_image( "1joueur.jpg" );
  image3 = MLV_load_image( "2joueurs.jpg" );
  MLV_resize_image_with_proportions( image, width, height);
  MLV_get_image_size(image, &image_width, &image_height);
  MLV_change_window_size(image_width, image_height);
  MLV_draw_image( image, 0, 0 );
  MLV_free_image( image );
    
  /*2 joueur*/
  MLV_resize_image_with_proportions(image3,175,250);
  MLV_draw_image(image3,240,100);  
  /* 1 joueur*/
  MLV_resize_image_with_proportions(image2,175,250);
  MLV_draw_image(image2,240,175);
  MLV_actualise_window();

  /*une boucle infini qui permet de pouvoir cliquez n'importe ou et autant de fois que l'on veut*/
  while(1){
    /*fonction qui attend un clique, avec ces coordonnées*/
    MLV_wait_mouse(&x,&y);
        
    /*2 joueurs*/
    if((x>=240 && y>=100) && (x<=389 && y<=135)){
      NOUVELLE_partie();        
    }
    /*1 joueur*/
    if((x>=240 && y>=176) && (x<=384 && y<=212)){
      NOUVELLE_PARTIE_AVEC_ordi();
    }
  }
}
