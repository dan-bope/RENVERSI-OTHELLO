#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "type.h"
#include "menu.h"



/*sauvegarde de la partie*/
void SAUVEGARDER(plateau m, int joueur){
  MLV_Image *image;
  MLV_Image *image1;
  image1 = MLV_load_image( "retour.jpg" );
  int width=650, height=520;
  int image_width, image_height;
 
  FILE* fichier=NULL;
  int i,j;
  int x,y;
  image = MLV_load_image( "fondmenu.jpg" );
  MLV_resize_image_with_proportions( image, width, height);
  MLV_get_image_size(image, &image_width, &image_height);
  MLV_change_window_size(image_width, image_height);
  MLV_draw_image( image, 0, 0 );
  MLV_free_image( image );
  MLV_actualise_window();
  //on ouvre le fichier en mode lecture ecriture mais on supprime tout avant
  fichier=fopen("sauvegarde.sauv","w+");

    
  if(fichier==NULL){
    MLV_draw_text(230,400,
		  "ERREUR SAUVEGARDE!!",
		  MLV_COLOR_RED);
    MLV_actualise_window();
  }
  else {
    //pour avoir une representation plus facile a lire de la matrice
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){

	fprintf(fichier,"%d ",m[i][j]);

	
      }
      fprintf(fichier,"\n");
    }
    //on copie le joueur
    fprintf(fichier,"%d",joueur);
    fclose(fichier);//fermeture du fichier
    
    
    /*retour menu*/
    MLV_resize_image_with_proportions(image1,175,250);
    MLV_draw_image(image1,230,450);  
    MLV_actualise_window();

    /*Dans le cas ou l'on veut revenir dans le menu*/  
    while(1){
      MLV_wait_mouse(&x,&y);
      if(x>=230 && y>=450 && x<=369 && y<=474){
	
	MENU();
      }
    }
    
  }
  
}
