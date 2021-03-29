#include "nouvelle_partie.h"
#include "menu.h"
#include "charge_partie.h"
#include "type.h"
#include "regles_du_jeu.h"
#include "classement.h"


/*Fonction qui permet de faire derouler un jeu*/
void NOUVELLE_partie(){
  plateau m;
  int lig, col, joueur = 1;
    
    

  //initialisation du plateau avec les valeurs de depart
  INIT_plateau (m);

  /* Deroulement d'une partie tant que le jeu n'est pas fini on boucle */
  while (PARTIE_terminee (m,joueur)!=1) {
    AFFICHER_matrice (m,joueur);
    LIRE_coup (m, &lig, &col, joueur);
    JOUER_coup (m, lig, col, joueur);
        
       
    if (PEUT_jouer(m, JOUEUR_suivant(joueur)))
      joueur = JOUEUR_suivant (joueur);
    else if (PARTIE_terminee (m,joueur)==0){
            
      MLV_draw_text(420,420,
		    "Le joueur %d passe son tour",
		    MLV_COLOR_RED,
		    JOUEUR_suivant(joueur)
		    );
      MLV_actualise_window();
      MLV_wait_seconds(2);//pour avoir le temps de voir le message sur la fenetre

    }
  }
    
  // second_menu();

   
}


/*Fonction identique a lire_coup sauf que cette fois on fait un random a l'interieur*/
void LIRE_COUP_ordi(plateau m, int *lig, int *col, int joueur){
  int x,y;
  //il faut tout les coups, si l'un est valide il sort de la boucle et les pointeurs lignes et colonnes sont a la dernieres valeurs
  while (!COUP_valide (m, *lig, *col, joueur)) {
    x=rand()%9;//entre 0 et 7 
    y=rand()%9;
    *lig=x;
    *col=y;
  }
}   


void NOUVELLE_PARTIE_AVEC_ordi(){
  plateau m;
  int lig, col, joueur = 1;
  INIT_plateau (m);
  /* Deroulement d'une partie */
  while (PARTIE_terminee (m,joueur)!=1) {
    AFFICHER_matrice (m,joueur);
    //seul difference avec le cas HvsH si joueur ==1 alors humain donc la souris sinon ordinateur donc random	
    if(joueur ==1){
      LIRE_coup (m, &lig, &col, joueur);
    }
    else {
      LIRE_COUP_ordi(m,&lig,&col,joueur);
    }
    JOUER_coup (m, lig, col, joueur);
    AFFICHER_matrice (m,joueur);
       
    if (PEUT_jouer(m, JOUEUR_suivant(joueur)))
      joueur = JOUEUR_suivant (joueur);
    else if (PARTIE_terminee (m,joueur)==0){
            
      MLV_draw_text(420,420,
		    "Le joueur %d passe son tour",
		    MLV_COLOR_RED,
		    JOUEUR_suivant(joueur)
		    );
      MLV_actualise_window();
      MLV_wait_seconds(2);

    }
  }
}

/*fonction speaciale pour le chargement*/
void NOUVELLE_PARTIE_AVEC_chargement(){
  plateau m;
  int joueur;
  int col,lig;
  Charger charge;
  int i,j;

  /*initialise le plateau et le joueur*/
  charge=CHARGER_partie();
  /*recupere le plateau*/
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      m[i][j]=charge.plateau[i][j];
    }
  }

  // recupere le joueur

  joueur=charge.joueur[0];
 
 
 
  
  /*Identique aux autres*/
  while (PARTIE_terminee (m,joueur)!=1) {
    AFFICHER_matrice (m,joueur);
    LIRE_coup (m, &lig, &col, joueur);
    JOUER_coup (m, lig, col, joueur);
    AFFICHER_matrice (m,joueur);
	
       
    if (PEUT_jouer(m, JOUEUR_suivant(joueur)))
      joueur = JOUEUR_suivant (joueur);
    else if (PARTIE_terminee (m,joueur)==0){
            
      MLV_draw_text(420,420,
		    "Le joueur %d passe son tour",
		    MLV_COLOR_RED,
		    JOUEUR_suivant(joueur)
		    );
      MLV_actualise_window();
      MLV_wait_seconds(2);

    }
  }
}
