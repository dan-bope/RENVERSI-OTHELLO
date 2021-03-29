#include "menu.h"
#include "regles_du_jeu.h"
#include "classement.h"
#include "charge_partie.h"
#include "type.h"
#include "nouvelle_partie.h"


/*Fonction qui affiche le menu*/
void MENU(){
  int x,y;
  MLV_Image *image;
  MLV_Image *image2;
  MLV_Image *image3;
  MLV_Image *image4;
  MLV_Image *image5;
  int width=650, height=520;
  int image_width, image_height;
  image = MLV_load_image( "fondmenu.jpg" );
  image2 = MLV_load_image( "nouvelle.jpg" );
  image3 = MLV_load_image( "charger.jpg" );
  image4 = MLV_load_image( "classement.jpg" );
  image5 = MLV_load_image( "regles.jpg" );
  MLV_resize_image_with_proportions( image, width, height);
  MLV_get_image_size(image, &image_width, &image_height);
  MLV_change_window_size(image_width, image_height);
  MLV_draw_image( image, 0, 0 );
  MLV_free_image( image );
   
  /*nouvelle partie*/
  MLV_resize_image_with_proportions(image2,175,175);
  MLV_draw_image(image2,240,100);
  /*charger partie*/
  MLV_resize_image_with_proportions(image3,175,175);
  MLV_draw_image(image3,240,175);
  /*classement*/
  MLV_resize_image_with_proportions(image4,175,175);
  MLV_draw_image(image4,240,250);
  /*regles du jeu*/  
  MLV_resize_image_with_proportions(image5,175,175);
  MLV_draw_image(image5,240,325);

  MLV_actualise_window();

  /*On clique selon les cas*/
  while(1){
    MLV_wait_mouse(&x,&y);
        
        
    if((x>=240 && y>=100) && (x<=389 && y<=135)){
      CHOIX_partie();        
    }
    if((x>=240 && y>=176) && (x<=384 && y<=212)){
	  
      NOUVELLE_PARTIE_AVEC_chargement();
	  
    }
    if((x>=240 && y>=251) && (x<=362 && y<=295)){
      CLASSEMENT();
    }     
    if(x>=240 && x<=372 && y>=325 && y<=366){
      REGLES_DU_jeu();
    }
  }
}


/*Deuxieme menu apres une partie terminer*/
void SECOND_menu(){
  int x,y;
  
  MLV_Image *image;
  MLV_Image *image2;
  MLV_Image *image3;
  MLV_Image *image4;
  MLV_Image *image5;
  int width=650, height=520;
  int image_width, image_height;
  image = MLV_load_image( "fondmenu.jpg" );
  image2 = MLV_load_image( "regles.jpg" );
  image3 = MLV_load_image( "classement.jpg" );
  image4 = MLV_load_image( "rejouer.jpg" );
  image5 = MLV_load_image( "quitter.jpg" );
  MLV_resize_image_with_proportions( image, width, height);
  MLV_get_image_size(image, &image_width, &image_height);
  MLV_change_window_size(image_width, image_height);
  MLV_draw_image( image, 0, 0 );
  MLV_free_image( image );
  /*rejouer*/
  MLV_resize_image_with_proportions(image4,175,175);
  MLV_draw_image(image4,240,100);
 /*classement*/
  MLV_resize_image_with_proportions(image3,175,175);
  MLV_draw_image(image3,240,175);
  /*regles du jeu*/  
  MLV_resize_image_with_proportions(image2,175,175);
  MLV_draw_image(image,240,250);
  /*quitter*/ 
  MLV_resize_image_with_proportions(image5,175,175);
  MLV_draw_image(image5,240,325);
  MLV_actualise_window();
  while(1){
    MLV_wait_mouse(&x,&y);
        
        
    if((x>=240 && y>=100) && (x<=389 && y<=135)){
      CHOIX_partie();        
    }
    if((x>=240 && y>=176) && (x<=384 && y<=212)){
      CLASSEMENT();
    }
    if((x>=240 && y>=251) && (x<=362 && y<=295)){
	  
      REGLES_DU_jeu();
    }     
    if(x>=240 && x<=372 && y>=325 && y<=366){
      MLV_free_window();
      exit(0);//preserve d'erreur de segmentation
    }
  }
}


void ACCUEIL(){
  int x,y;
  MLV_Image *image;
  MLV_Image *image2;
  int width=650, height=520;
  int image_width, image_height;
  
  image = MLV_load_image( "o.jpg" );
  image2 = MLV_load_image( "start.jpg" );
  MLV_resize_image_with_proportions( image, width, height);
  MLV_get_image_size(image, &image_width, &image_height);
  MLV_change_window_size(image_width, image_height);
  MLV_draw_image( image, 0, 0 );
  MLV_free_image( image );
  MLV_resize_image_with_proportions(image2,175,175);
  MLV_draw_image(image2,240,325);
  MLV_actualise_window();
  while(1){
    MLV_wait_mouse(&x,&y);
    if((x>=240 && y>=325) && (x<=372 && y<=366)){
	    MENU();
      }    
  }	
}

