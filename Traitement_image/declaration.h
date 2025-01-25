// Leo AHMED MUSHTAQ 11/01/2025
#ifndef _Liste_RVB_
#define _Liste_RVB_

#include <stdio.h>
#include <stdlib.h>

/*####################################################################################################################*/

// VARIABLES GLOBALES
#define MAX_DIM 300
int IMAGE_R[MAX_DIM][MAX_DIM];
int IMAGE_V[MAX_DIM][MAX_DIM];
int IMAGE_B[MAX_DIM][MAX_DIM];
FILE* file;



/*####################################################################################################################*/

// STRUCTURES
typedef struct {
    int R;
    int V;
    int B;
} RVB;

typedef RVB Liste_RVB[MAX_DIM][MAX_DIM]; // Tableau des valeurs RVB de chaque pixel

Liste_RVB Tableau_RVB; // Tableau des valeurs RVB de chaque pixel (ex: Tableau_RVB[0][0].R = 255)

// Structure pour stocker les bits de quantifications
typedef struct {
    int R_bin[8];
    int V_bin[8];
    int B_bin[8];
} RVB_bin;

typedef RVB_bin Liste_RVB_bin[MAX_DIM][MAX_DIM];

Liste_RVB_bin Tableau_RVB_bin;


/*####################################################################################################################*/

// Structure des fonctions :
void readImage(FILE* , int *, int *, int *);

//int moyenne_couleur(int ref_tableau[MAX_DIM][MAX_DIM]);

void valeur_RVB(int ref_tableau_R[MAX_DIM][MAX_DIM],int ref_tableau_V[MAX_DIM][MAX_DIM],int ref_tableau_B[MAX_DIM][MAX_DIM]);

//BitsPoidsForts.c
void decimal_en_binaire(int nombre_decimal, int nb_bits_poids_forts, int *binaire);

void liste_decimal_en_binaire(Liste_RVB ref_liste_RVB, int nb_bits_poids_forts);

void afficher_liste_binaire(Liste_RVB_bin liste_bin, int nb_bits_poids_forts);

//histogramme.c
void creer_histogramme(Liste_RVB_bin liste, int histogramme[64]);

void afficher_histogramme(int histogramme[64]);

//transform_image_gen.c
int calcul_bin(int bin_4n, int pixel);

void transform_image_gen(int bin_4n, int nb_lignes, int nb_colonnes, Liste_RVB Tableau_RVB, char couleur); 

//couleur_dominante.c
char detecter_couleur_dominante(Liste_RVB Tableau_RVB, int nb_lignes, int nb_colonnes);

#endif
