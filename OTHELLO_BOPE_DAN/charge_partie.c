#include <stdlib.h>
#include <stdio.h>
#include "type.h"
#include "menu.h"
#include "jouer.h"
#include "affichage.h"
#include "nouvelle_partie.h"



/*Fonction qui recupere une sauvegarde et le met dans une structures, puis return cette structures pour pouvoir y jouer*/
/* Fonction qui recupere la partie sous forme de structures*/
Charger CHARGER_partie(){
  Charger charge;
  int i,j;
  FILE* fichier=NULL;
  int r;
  
  fichier=fopen("sauvegarde.sauv","r+");
  if(fichier==NULL){
    MLV_draw_text(400,400,
		  "ERREUR CHARGEMENT!!",
		  MLV_COLOR_RED
		  );
  }
  else{
    /* on recupere la matrice dans un tableau d'entier identique au plateau*/
    for(i=0;i<8;i++){
      for(j=0;j<8;j++){
	r=fscanf(fichier,"%d",&charge.plateau[i][j]);
        if(r!=1) fprintf(stderr,"erreur fscanf charger partie plateau");
      } 
    }
    
    /* on recupere le joueur pour le mettre dans un tableau d'une seule valeur, car on a soit 1 ou 2 pour le joueur*/
    r=fscanf(fichier,"%d",&charge.joueur[0]); 
    if(r!=1)  fprintf(stderr,"erreur fscanf charger partie joueur");

    fclose(fichier);
  }
  /*return la structures*/
  return charge;
}
