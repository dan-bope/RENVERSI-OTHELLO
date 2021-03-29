#include "jouer.h"
#include "affichage.h"
#include "sauvegarde.h"
#include "classement.h"
#include "menu.h"



/*initialise le tableau*/
void INIT_plateau(plateau m) {
  int i, j;

  /* On met tout a vide */
  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      m[i][j] = VIDE;

  /* On place les 4 premiers pions */
  m[N/2-1][N/2-1] = BLANC;
  m[N/2-1][N/2] = NOIR;
  m[N/2][N/2-1] = NOIR;
  m[N/2][N/2] = BLANC;
}
/* Fonction pour verifier qu'une case existe */
int CASE_existe (int lig, int col) {
  return ((col >= 0) && (col < N) && (lig >= 0) && (lig < N));
}

/* Fonction pour verifier qu'un coup est valide , c'est a dire si on encandre bien bien un pion adv entre deux autres pions de notre couleur*/
int COUP_valide (plateau m, int lig, int col, int joueur) {
  int i, j, ok;
  int cj, ca;

  /* On definit la couleur du joueur et celle de l'adversaire */
  if (joueur == 1) {
    cj = NOIR;
    ca = BLANC;
  } else {
    cj = BLANC;
    ca = NOIR;
  }

  /*Si la case n'est pas valide (inexiste) ou n'est pas vide alors on return 0*/
  if (!CASE_existe(lig, col) || m[lig][col] != VIDE)
    return 0;

  /* Vertical vers le haut on bloque la colonne on regarde s'il y a existance entre notre pion et un autre pion sur la meme colonne lais a une ligne plus haut */
  i = lig - 1;
  ok = 0;
  while (CASE_existe(i, col) && m[i][col] == ca) {
    i--;
    ok = 1;
  }
  if (CASE_existe(i, col) && m[i][col] == cj && ok == 1)
    return 1;

  /* Vertical vers le bas, idem qu'en haut met cette fois on regarde si on peut entoure vers le bas  */
  i = lig + 1;
  ok = 0;
  while (CASE_existe(i, col) && m[i][col] == ca) {
    i++;
    ok = 1;
  }
  if (CASE_existe(i, col) && m[i][col] == cj && ok == 1)
    return 1;

  /* Horizontal vers la gauche, cette fois on bloque la ligne et on regarde si on peut entourer en faisant varier la valeur de la colonne , vers la gauche */
  j = col - 1;
  ok = 0;
  while (CASE_existe(lig, j) && m[lig][j] == ca) {
    j--;
    ok = 1;
  }
  if (CASE_existe(lig, j) && m[lig][j] == cj && ok == 1)
    return 1;

  /* Horizontal vers la droite cette fois on bloque la ligne et on regarde si on peut entourer en faisant varier la valeur de la colonne , vers la droite  */
  j = col + 1;
  ok = 0;
  while (CASE_existe(lig, j) && m[lig][j] == ca) {
    j++;
    ok = 1;
  }
  if (CASE_existe(lig, j) && m[lig][j] == cj && ok == 1)
    return 1;

  /* Diagonal \ vers le haut on regarde si l'on bloque un pion entre le coup jouer et un pion de position en haut de position nord nord-ouest soit la diagonale*/
  i = lig - 1;
  j = col - 1;
  ok = 0;
  while (CASE_existe(i, j) && m[i][j] == ca) {
    i--;
    j--;
    ok = 1;
  }
  if (CASE_existe(i, j) && m[i][j] == cj && ok == 1)
    return 1;

  /* Diagonal \ vers le bas la meme diagonale avec cette fois si on descdend */
  i = lig + 1;
  j = col + 1;
  ok = 0;
  while (CASE_existe(i, j) && m[i][j] == ca) {
    i++;
    j++;
    ok = 1;
  }
  if (CASE_existe(i, j) && m[i][j] == cj && ok == 1)
    return 1;

  /* Diagonal / (sud-ouest vers nord-est)vers le haut on verifie l'autre diagonale pour verifier si on peut bloquer un pion vers le haut */
  i = lig - 1;
  j = col + 1;
  ok = 0;
  while (CASE_existe(i, j) && m[i][j] == ca) {
    i--;
    j++;
    ok = 1;
  }
  if (CASE_existe(i, j) && m[i][j] == cj && ok == 1)
    return 1;

  /* Diagonal / vers le bas la meme diagonale vers le bas  */
  i = lig + 1;
  j = col - 1;
  ok = 0;
  while (CASE_existe(i, j) && m[i][j] == ca) {
    i++;
    j--;
    ok = 1;
  }
  if (CASE_existe(i, j) && m[i][j] == cj && ok == 1)
    return 1;

  /* Si apres verification on ne peut toujours pas encadrer un pion alors on return 0*/
  return 0;
}

/* Fonction qui determine si un joueur peut encore jouer */
int PEUT_jouer (plateau m, int joueur) {
  int i, j;
  /*on boucle sur tout le plateau et on regarde s'il y a une case au moins ou peut jouer*/
  for (i=0; i<N; i++){
    for (j=0; j<N; j++){
      if (COUP_valide(m, i, j, joueur)){
	return 1; /* Le joueur peut encore jouer */
      }
    }
  }
  /* Le joueur ne peut plus jouer */
  return 0;
}

/* Renvoie le numero du joueur suivant */
int JOUEUR_suivant (int joueur) {
  return (joueur %2 + 1);
  /* Si joueur 1 alors 1mod2 = 1, et 1+1 = 2 donc joueur 2
     Si joueur 2 alors 2mod 2=0 et 0+1=1 donc joueur 1*/
}



/*Fonction qui prend en argument un pointeur ligne et colonne qui permette de modifier directement la valeur de ligne et colonne*/
void LIRE_coup(plateau m, int *lig, int *col, int joueur){
  int x,y;
  /*Tant que le coup n'est pas valide alors on recherche un clique dans le plateau*/
  while (!COUP_valide (m, *lig, *col, joueur)) {
    MLV_wait_mouse(&x,&y);
    /*Si le clique est sur le rectangle sauvegarde alors on sauvegarde et on sort du jeu*/
    if(x>=431 && y>=151 && x<=533 && y<=176 ){
     
      SAUVEGARDER(m,joueur);
	  
    }
  
    /*Dans le cas ou l'on veut revenir dans le menu*/  
    /*Sinon si on divise la valeur de x et y par 50 qui la taille de carrée de grille pour obtenir la division entiere qui va se convertir a un nombre compris entre 0 et 7*/
    else{
      *lig=x/50;
      *col=y/50;
    }
  }   
}

/*Fonction permettant de savoir si la partie est terminer*/
int PARTIE_terminee (plateau m,int joueur) {
  int i, j, nb_noir=0, nb_blanc=0, cpt=0;
  FILE* fichier=NULL;
   
    
  /* On compte les pions noirs et les blancs */
  nb_noir = 0;
  nb_blanc = 0;
  for (i=0; i<N; i++) {
    for (j=0; j<N; j++) {
      if (m[i][j] == VIDE && (PEUT_jouer(m, 1) || PEUT_jouer(m, 2))) {
	return 0; /* La partie n'est pas finie */
      } 
      else {
	if (m[i][j] == NOIR) nb_noir++;
	else 
	  if (m[i][j] == BLANC) nb_blanc++;
      }
    }
  }
  /*Pour le cas si le jeu se termine, alors que le plateau n'est pas plein*/
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(nb_noir > nb_blanc && m[i][j]==VIDE){
	nb_noir ++;
      }
      if(nb_blanc > nb_noir && m[i][j]==VIDE){
	nb_blanc++;
      }
    }
  }
    

    

  /* On range les pions par couleur et on affiche la grille */
    
  for (i=0; i<N; i++)
    for (j=0; j<N; j++) {
      if (cpt < nb_noir)
	m[i][j] = NOIR;
      else if ((cpt >= nb_noir) && (cpt < nb_noir + nb_blanc -1))
	m[i][j] = BLANC;
      else m[i][j] = VIDE;
      cpt++;
    }
    

  AFFICHER_matrice(m,joueur);


  /* La partie est terminee, on affiche le gagnant */
  if (nb_noir > nb_blanc){
        
    MLV_draw_text(420,420,
		  "Le joueur 1 a gagné %d à %d",
		  MLV_COLOR_BLACK,
		  nb_noir,nb_blanc
		  );
    MLV_actualise_window();
    MLV_wait_seconds(5);
    //on place les deux scores dans classement.cl	
    fichier=fopen("classement.cl","r+");
    fprintf(fichier," %d %d",nb_noir,nb_blanc);
    fclose(fichier);
	SECOND_menu();
    return 1;
  }
  else if (nb_blanc > nb_noir){
    MLV_draw_text(420,420,
		  "Le joueur 2 a gagné %d à %d",
		  MLV_COLOR_BLACK,
		  nb_blanc,nb_noir
		  );
    MLV_actualise_window();
    MLV_wait_seconds(5);
    fichier=fopen("classement.cl","r+");
    fprintf(fichier," %d %d",nb_noir,nb_blanc);
    fclose(fichier);
       	SECOND_menu();
    return 1;
        
  }

  else {
    MLV_draw_text(420,420,
		  "Il y a égalité %d à %d",
		  MLV_COLOR_BLACK,
		  nb_noir,nb_blanc
		  );
    MLV_actualise_window();
    MLV_wait_seconds(5);
    fichier=fopen("classement.cl","r+");
    fprintf(fichier," %d %d",nb_noir,nb_blanc);
    fclose(fichier);
    SECOND_menu();
    return 1;
  }
}

/* Fonction qui permet de jouer un coup apres avoir lu le coup*/

/*On a les meme choses que dans coup_valide, mais cette fois si on entoure au lieu de dire c'est bon on peut, on transformer toute les cases entourer de la couleur du joueur*/
void JOUER_coup (plateau m, int lig, int col, int joueur) {
  int i, j;
  int cj, ca;/*cj=couleur_joueur ca=couleur_adversaire*/
    
  if (joueur == 1) {
    cj = NOIR;
    ca = BLANC;
  } else {
    cj = BLANC;
    ca = NOIR;
  }
  /*on joue le coup de la case avec la couleur du joueur*/
  m[lig][col] = cj;
    

  /* Vertical vers le haut */
  i = lig - 1;
  /*boucle pour trouver tout les pions de couleur adv  */
  while (CASE_existe(i, col) && m[i][col] == ca)
    i--;
  /* a partir du dernier dernier pion adv trouvé on va regarder si la case du dessus est de notre couleur.
     Si on trouve une case de notre couleur on va tout retourner avec la boucle a l'interieur*/
  if (CASE_existe(i, col) && m[i][col] == cj) {
    i = lig - 1;
    while (m[i][col] == ca) {
      m[i][col] = cj;
      i--;
    }
  }

  /*On va faire cela pour toutes les directions */

      
  /* Vertical vers le bas */
  i = lig + 1;
  while (CASE_existe(i, col) && m[i][col] == ca)
    i++;
  if (CASE_existe(i, col) && m[i][col] == cj) {
    i = lig + 1;
    while (m[i][col] == ca) {
      m[i][col] = cj;
      i++;
    }
  }
    

  /* Horizontal vers la gauche */
  j = col - 1;
  while (CASE_existe(lig, j) && m[lig][j] == ca)
    j--;
  if (CASE_existe(lig, j) && m[lig][j] == cj) {
    j = col - 1;
    while (m[lig][j] == ca) {
      m[lig][j] = cj;
      j--;
    }
  }
    
    
  /* Horizontal vers la droite */
  j = col + 1;
  while (CASE_existe(lig, j) && m[lig][j] == ca) 
    j++;
  if (CASE_existe(lig, j) && m[lig][j] == cj) {
    j = col + 1;
    while (m[lig][j] == ca) {
      m[lig][j] = cj;
      j++;
    }
  }
    
    

  /* Diagonal \ vers le haut */
  i = lig - 1;
  j = col - 1;

  while (CASE_existe(i, j) && m[i][j] == ca) {
    i--;
    j--;
  }
  if (CASE_existe(i, j) && m[i][j] == cj) {
    i = lig - 1;
    j = col - 1;
    while (m[i][j] == ca) {
      m[i][j] = cj;
      i--;
      j--;
    }
  }

  /* Diagonal \ vers le bas */
  i = lig + 1;
  j = col + 1;
  while (CASE_existe(i, j) && m[i][j] == ca) {
    i++;
    j++;
  }
  if (CASE_existe(i, j) && m[i][j] == cj) {
    i = lig + 1;
    j = col + 1;
    while (m[i][j] == ca) {
      m[i][j] = cj;
      i++;
      j++;
    }
  }

  /* Diagonal / vers le haut */
  i = lig - 1;
  j = col + 1;
  while (CASE_existe(i, j) && m[i][j] == ca) {
    i--;
    j++;
  }
  if (CASE_existe(i, j) && m[i][j] == cj) {
    i = lig - 1;
    j = col + 1;
    while (m[i][j] == ca) {
      m[i][j] = cj;
      i--;
      j++;
    }
  }

  /* Diagonal \ vers le bas */
  i = lig + 1;
  j = col - 1;
  while (CASE_existe(i, j) && m[i][j] == ca) {
    i++;
    j--;
  }
  if (CASE_existe(i, j) && m[i][j] == cj) {
    i = lig + 1;
    j = col - 1;
    while (m[i][j] == ca) {
      m[i][j] = cj;
      i++;
      j--;
    }
  }
}

