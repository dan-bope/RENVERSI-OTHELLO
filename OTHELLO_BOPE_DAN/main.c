#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include "type.h"
#include "nouvelle_partie.h"
#include "affichage.h"
#include "jouer.h"
#include "menu.h"
#include <time.h>


int main () {
  srand(time(NULL));
  /*creation de la fenetre graphique*/
  MLV_create_window("OTHELLO","PROJET OTHELLO",650,520);
  ACCUEIL();
  return 0;
}

