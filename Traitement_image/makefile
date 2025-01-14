tstCouleur.out: tstCouleur.o Liste_RVB.o Valeur_RVB_pour_chaque_pixel.o
	gcc tstCouleur.o Liste_RVB.o Valeur_RVB_pour_chaque_pixel.o -o tstCouleur.out

tstCouleur.o: tstCouleur.c declaration.h
	gcc -c tstCouleur.c

Liste_RVB.o: Liste_RVB.c declaration.h
	gcc -c Liste_RVB.c


Moyenne_couleur.o: Moyenne_couleur.c declaration.h
	gcc -c Moyenne_couleur.c

Valeur_RVB_pour_chaque_pixel.o: Valeur_RVB_pour_chaque_pixel.c declaration.h
	gcc -c Valeur_RVB_pour_chaque_pixel.c

clean:
	rm -f tstCouleur.out Liste_RVB.o tstCouleur.o Moyenne_couleur.o Valeur_RVB_pour_chaque_pixel.o
