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

// Valeurs des images en binaire
int Image_R_Binaire[MAX_DIM][MAX_DIM];
int Image_V_Binaire[MAX_DIM][MAX_DIM];
int Image_B_Binaire[MAX_DIM][MAX_DIM];
/*####################################################################################################################*/

// STRUCTURES
typedef struct {
    int R;
    int V;
    int B;
} RVB;

typedef RVB Liste_RVB[MAX_DIM][MAX_DIM]; // Tableau des valeurs RVB de chaque pixel

typedef struct {
    int R_bin;
    int V_bin;
    int B_bin;
} RVB_bin;

typedef RVB_bin Liste_RVB_bin[MAX_DIM][MAX_DIM];


/*####################################################################################################################*/

// Structure des fonctions :
void ouvrir_fichier(FILE* file);

void readImage(FILE* , int *, int *, int *);

//int moyenne_couleur(int ref_tableau[MAX_DIM][MAX_DIM]);

void valeur_RVB(int ref_tableau_R[MAX_DIM][MAX_DIM],int ref_tableau_V[MAX_DIM][MAX_DIM],int ref_tableau_B[MAX_DIM][MAX_DIM]);

void liste_decimal_en_binaire(Liste_RVB ref_liste_RVB, int nb_bits_poids_forts);

#endif
