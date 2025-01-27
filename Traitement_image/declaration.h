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
    int R_Quant[8];
    int V_Quant[8];
    int B_Quant[8];
} RVB_Quantification;

typedef RVB_Quantification Liste_RVB_Quantification[MAX_DIM][MAX_DIM];
Liste_RVB_Quantification Tableau_RVB_Quantification; // creation du tableau pour stocker les valeurs quantifiees


// // Tentative de rectification partielle de ma betise juste au dessus :)
// typedef struct{
//     int Concatenation_Quant[8];
// } Concatenation_Quantification;

// typedef Concatenation_Quantification Tableau_Quantification[MAX_DIM];
// Tableau_Quantification Liste_Quantification;

// Structure pour stocker les valeurs apres binarisation de l'image
typedef struct {
    uint8_t R_binarise;
    uint8_t V_binarise;
    uint8_t B_binarise;
} RVB_Binarisation;

typedef RVB_Binarisation Liste_RVB_Binarisation[MAX_DIM][MAX_DIM];

Liste_RVB_Binarisation Tableau_RVB_Binarisation; // creation du tableau pour stocker les valeurs binarisees
/*####################################################################################################################*/

// Structure des fonctions :
void readImage(FILE* , int *, int *, int *);

//int moyenne_couleur(int ref_tableau[MAX_DIM][MAX_DIM]);

void valeur_RVB(int ref_tableau_R[MAX_DIM][MAX_DIM],int ref_tableau_V[MAX_DIM][MAX_DIM],int ref_tableau_B[MAX_DIM][MAX_DIM]);

//BitsPoidsForts.c
void decimal_en_binaire(int nombre_decimal, int nb_bits_poids_forts, int *binaire);

void liste_decimal_en_binaire(Liste_RVB ref_liste_RVB, int nb_bits_poids_forts);

void afficher_liste_binaire(Liste_RVB_Quantification liste_quant, int nb_bits_poids_forts);

void Concatenation_bit(Liste_RVB_Quantification liste_quant, int Quantification[MAX_DIM * MAX_DIM]);

void afficher_concatenation(int Quantification[MAX_DIM * MAX_DIM]);
int decimal_en_binaire2(int filtre);

//histogramme.c
void creer_histogramme(Liste_RVB_Quantification liste, int histogramme[64]);

void afficher_histogramme(int histogramme[64]);

//transform_image_gen.c
int calcul_bin(int bin_4n, int pixel);

void transform_image_gen(int bin_4n, int nb_lignes, int nb_colonnes, Liste_RVB Tableau_RVB, char couleur, Liste_RVB_Binarisation Tableau_RVB_Binarisation);   

void affiche_binarisation(int nb_lignes, int nb_colonnes, Liste_RVB_Binarisation Tableau_RVB_Binarisation, char couleur);
//couleur_dominante.c
char detecter_couleur_dominante(Liste_RVB Tableau_RVB, int nb_lignes, int nb_colonnes);

#endif
