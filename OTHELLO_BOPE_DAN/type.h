
#ifndef STRUCTURES_H
#define STRUCTURES_H 

#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>


/* taille de la grille */
#define N 8

/* Pions du jeu */
#define VIDE 0   
#define NOIR 1  //  
#define BLANC 2 

/* configuration du plateau*/
typedef int plateau[N][N];

/* une structure pour une partie donnée*/
typedef struct{
  plateau grille;
  int joueur;
}Partie;

/*la structures pour pouvoir recuperer plusieurs informations au moment de charger une sauvegarde effectué*/

typedef struct{
  int plateau[N][N];
  int joueur[1];
}Charger;


#endif
