#ifndef JOUER_H
#define JOUER_H


#include "type.h"


/*initialise les valeurs des cases a 0 et celle du milieu en Noir et Blanc*/
void INIT_plateau(plateau m);

/*verifie si les coordonnees sont dans le tableau*/
int CASE_existe(int lig,int col);

/*regarde si pour un joueur donné, avec une coordonnée ligne et colonne, si le coup est valide dans le plateau m*/
int COUP_valide(plateau m, int lig, int col,int joueur);
/*regarde si l'on peut jouer*/
int PEUT_jouer(plateau m, int joueur);

/*fonction qui definie le joueur suivant, grace a au modulo 2*/
int JOUEUR_suivant(int joueur);

/*Lit un coup pour les joueurs "Humain" via la souris , elle pointe sur une ligne et colonne qu'on recupere dans jouer_coup */
void LIRE_coup(plateau m, int *lig,int *col,int joueur);

/*Regarde si la partie est terminee et affiche le gagnnat avec la grille trie*/
int PARTIE_terminee (plateau m,int joueur);

/*fonction qui va jouer un coup qui est lu, avec un joueur sur le plateau*/
void JOUER_coup (plateau m, int lig, int col, int joueur);



#endif
