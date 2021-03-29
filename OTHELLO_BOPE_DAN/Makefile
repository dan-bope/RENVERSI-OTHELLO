CC= gcc
CFLAGS = -g -Wall -O2 `pkg-config --cflags MLV`
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS = `pkg-config --libs-only-l MLV`


othello : main.o menu.o affichage.o  charge_partie.o choix_partie.o classement.o jouer.o nouvelle_partie.o regles_du_jeu.o sauvegarde.o
	$(CC) $(CFLAGS) $(LDFLAGS) main.o menu.o affichage.o charge_partie.o choix_partie.o classement.o jouer.o nouvelle_partie.o regles_du_jeu.o sauvegarde.o  $(LDLIBS) -o othello 

main.o : main.c  menu.h  affichage.h  charge_partie.h  choix_partie.h  classement.h  jouer.h  nouvelle_partie.h  regles_du_jeu.h  sauvegarde.h
	$(CC) $(CFLAGS) $(LDFLAGS) main.c $(LDLIBS) -c

menu.o : menu.c  menu.h
	$(CC) $(CFLAGS) $(LDFLAGS) menu.c $(LDLIBS) -c
affichage.o : affichage.c  affichage.h
	$(CC) $(CFLAGS) $(LDFLAGS) affichage.c $(LDLIBS) -c
charge_partie.o : charge_partie.c  charge_partie.h
	$(CC) $(CFLAGS) $(LDFLAGS) charge_partie.c $(LDLIBS) -c
choix_partie.o : choix_partie.c  choix_partie.h
	$(CC) $(CFLAGS) $(LDFLAGS) choix_partie.c $(LDLIBS) -c
classement.o : classement.c  classement.h
	$(CC) $(CFLAGS) $(LDFLAGS) classement.c $(LDLIBS) -c
jouer.o : jouer.c jouer.h
	$(CC) $(CFLAGS) $(LDFLAGS) jouer.c $(LDLIBS) -c
nouvelle_partie.o : nouvelle_partie.c  nouvelle_partie.h
	$(CC) $(CFLAGS) $(LDFLAGS) nouvelle_partie.c $(LDLIBS) -c
regles_du_jeu.o : regles_du_jeu.c  regles_du_jeu.h
	$(CC) $(CFLAGS) $(LDFLAGS) regles_du_jeu.c $(LDLIBS) -c
sauvegarde.o : sauvegarde.c  sauvegarde.h
	$(CC) $(CFLAGS) $(LDFLAGS) sauvegarde.c $(LDLIBS) -c

clean :
	rm -f *.o *# *~ othello
