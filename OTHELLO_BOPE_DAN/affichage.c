#include "affichage.h"
#include "jouer.h"
#include "menu.h"
#include "type.h"





/*dessin les traits sur la grille*/
void GRILLE_MLV(){
  int i;
  MLV_draw_line(1,1,400,1,MLV_COLOR_WHITE);
  for(i=1;i<=8;i++)
    MLV_draw_line(1,i*50,400,i*50,MLV_COLOR_WHITE);
    

  MLV_draw_line(1,400,1,1,MLV_COLOR_WHITE);
  for(i=1;i<=8;i++)
    MLV_draw_line(i*50,400,i*50,1,MLV_COLOR_WHITE);

  MLV_actualise_window();

}
/*Affichage du plateau */
void AFFICHER_matrice(plateau m,int joueur){
  int i,j;
  MLV_Image *image;
  MLV_Image *image2;
  MLV_Image *image3;
  MLV_Image *image4;
  int width=650, height=520;
  int image_width, image_height;
  image = MLV_load_image( "fondvert.jpg" );
  image2 = MLV_load_image( "sauvegarde.jpg" );
  image3 = MLV_load_image( "tour1.jpg" );
  image4 = MLV_load_image( "tour2.jpg" );
  MLV_resize_image_with_proportions( image, width, height);
  MLV_get_image_size(image, &image_width, &image_height);
  MLV_change_window_size(image_width, image_height);
  MLV_draw_image( image, 0, 0 );
  MLV_free_image( image );
  GRILLE_MLV();
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(m[i][j]==VIDE){  
      }
      if(m[i][j]==NOIR){
        MLV_draw_filled_circle(i*50+25,j*50+25,20,MLV_COLOR_BLACK);
      }
      if(m[i][j]==BLANC){
        MLV_draw_filled_circle(i*50+25,j*50+25,20,MLV_COLOR_WHITE);
      }
    }
  }

  /*bouton sauvegarde*/
  MLV_resize_image_with_proportions(image2,175,250);
  MLV_draw_image(image2,430,150);
  /*on affiche le tour d'un joueur*/
  if(joueur==1){
     /*tour du joueur 1*/
     MLV_resize_image_with_proportions(image3,150,150);
     MLV_draw_image(image3,150,430);
     MLV_draw_filled_circle(325,450,20,MLV_COLOR_BLACK);

  }
  else{
     MLV_resize_image_with_proportions(image4,150,150);
     MLV_draw_image(image4,150,430);
     MLV_draw_filled_circle(325,450,20,MLV_COLOR_WHITE);


  }
    
  MLV_actualise_window();   
}
