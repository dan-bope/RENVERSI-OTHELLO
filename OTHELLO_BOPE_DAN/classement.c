#include "type.h"
#include "menu.h"




void CLASSEMENT(){
  /*Les fichiers qu'on va utilisés*/
  FILE* fichier=NULL;
  FILE* fichier2=NULL;
  /*les varibales utilises*/
  int i,j;
  int x,y;
  int r;
  int tab[30];
  int tmp;
  MLV_Image *image;
  image = MLV_load_image( "retour.jpg" );
  for(i=0;i<30;i++)
    tab[i]=0;

  fichier=fopen("classement.cl","r+");
  fichier2=fopen("affichage.txt","r+");
  
  
  MLV_clear_window(MLV_COLOR_DARK_GREY);
  
  if(fichier==NULL || fichier2==NULL){
    MLV_draw_text(150,300,
		  "PROBLEME FICHIER",
		  MLV_COLOR_DARK_RED
		  );
  }
  
  else {
    //on met les valeurs du fichier dans un tableau
    for(i=0;i<12;i++){
      r=fscanf(fichier," %d",&tab[i]); 
      if(r!=1){
	fprintf(stderr,"erreur\n");
      }
      
      

      
      /*on trie le tableau*/
      
      for(j=12;j!=0;j--){
	for(i=0;i<j;i++){
	  if(tab[i]<tab[i+1]){
	    tmp=tab[i];
	    tab[i]=tab[i+1];
	    tab[i+1]=tmp;
	   
	  }
	}
      }
      

      // on recopie dans les fichiers ouvert les valeur triées
      for(i=0;i<12;i++)
	fprintf(fichier2," %d",tab[i]); 
      /*Seul les dix meilleurs sont recopier dans le fichier classement*/
      for(i=0;i<10;i++){
	fprintf(fichier," %d",tab[i]);
      }
      
    
      
     
      
      /*affiche les scores*/
      for(i=0;i<10;i++){      
	r=fscanf(fichier," %d",&tab[i]);
        
	if(r!=1)
	  fprintf(stderr,"erreur\n");
	
	MLV_draw_text(180,15,
		      "Le classement des 10 meilleurs joueurs:",
		      MLV_COLOR_DARK_RED
		      );
	MLV_draw_text(300,i*45+45,
		      "%d : %d",
		      MLV_COLOR_DARK_RED,
		      i+1,tab[i]
		      );
      }
    
      MLV_resize_image_with_proportions(image,175,250);
      MLV_draw_image(image,230,450);  
      MLV_actualise_window();
    
    
    
      /*Si on veut revenir au menu*/
      while(1){
	MLV_wait_mouse(&x,&y);
	if(x>=230 && y>=450 && x<=369 && y<=474)
	  MENU();
      
      }
    }
  }
  //fermeture des fichiers
  fclose(fichier2);
  fclose(fichier);
}
