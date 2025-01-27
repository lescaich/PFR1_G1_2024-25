// Leo Ahmed Mushtaq 16/01/2025
// Ce fichier permet de convertir les valeurs RVB d'un tableau à 3 dimensions en binaire et de les stocker.
// Il permet également d'afficher les valeurs binaires.

#include "declaration.h"
#include <math.h>

// Fonction pour convertir un nombre décimal en binaire
void decimal_en_binaire(int nombre_decimal, int nb_bits_poids_forts, int *binaire) {
    int total_bits = 8; // Taille totale en bits (octet)
    // Décaler pour garder uniquement les nb_bits_poids_forts bits les plus significatifs
    nombre_decimal = nombre_decimal >> (total_bits - nb_bits_poids_forts);

    // Conversion en binaire sur nb_bits_poids_forts
    for (int i = 0; i < nb_bits_poids_forts; i++) {
        binaire[nb_bits_poids_forts - 1 - i] = nombre_decimal % 2;
        nombre_decimal = nombre_decimal / 2;
    }

    // Compléter avec des zéros pour les bits non utilisés
    for (int i = nb_bits_poids_forts; i < 8; i++) {
        binaire[i] = 0;
    }
}

// Fonction pour convertir les valeurs RVB d'une liste en binaire
void liste_decimal_en_binaire(Liste_RVB ref_liste_RVB, int nb_bits_poids_forts) {
    for (int i = 0; i < MAX_DIM; i++) {
        for (int j = 0; j < MAX_DIM; j++) {
            decimal_en_binaire(ref_liste_RVB[i][j].R, nb_bits_poids_forts, Tableau_RVB_Quantification[i][j].R_Quant);
            decimal_en_binaire(ref_liste_RVB[i][j].V, nb_bits_poids_forts, Tableau_RVB_Quantification[i][j].V_Quant);
            decimal_en_binaire(ref_liste_RVB[i][j].B, nb_bits_poids_forts, Tableau_RVB_Quantification[i][j].B_Quant);
        }
    }
}

// Fonction pour afficher les valeurs binaires d'un tableau RVB_Quantification
void afficher_liste_binaire(Liste_RVB_Quantification liste_quant, int nb_bits_poids_forts) {
    for (int i = 0; i < MAX_DIM; i++) {
        for (int j = 0; j < MAX_DIM; j++) {
            printf("Pixel [%d][%d] :\n", i, j);

            printf("  R_bin=");
            for (int k = 0; k < nb_bits_poids_forts; k++) {
                printf("%d", liste_quant[i][j].R_Quant[k]);
            }
            printf("\n");

            printf("  V_bin=");
            for (int k = 0; k < nb_bits_poids_forts; k++) {
                printf("%d", liste_quant[i][j].V_Quant[k]);
            }
            printf("\n");

            printf("  B_bin=");
            for (int k = 0; k < nb_bits_poids_forts; k++) {
                printf("%d", liste_quant[i][j].B_Quant[k]);
            }
            printf("\n");
        }
    }
}


void Concatenation_bit(Liste_RVB_Quantification liste_quant, int Quantification[MAX_DIM * MAX_DIM]) {
    unsigned int valeur_bin_R, valeur_bin_V, valeur_bin_B, filtre;

    for (int i = 0; i < MAX_DIM; i++) {
        for (int j = 0; j < MAX_DIM; j++) {
            // Calcul des valeurs binaires pour R, V, et B
            valeur_bin_R = (liste_quant[i][j].R_Quant[0] << 1) | liste_quant[i][j].R_Quant[1];
            valeur_bin_V = (liste_quant[i][j].V_Quant[0] << 1) | liste_quant[i][j].V_Quant[1];
            valeur_bin_B = (liste_quant[i][j].B_Quant[0] << 1) | liste_quant[i][j].B_Quant[1];
            
            // Assemblage des valeurs R, V, et B dans un seul entier
            filtre = (valeur_bin_R << 4) | (valeur_bin_V << 2) | valeur_bin_B;
            printf("Valeur en decimal de RVB : %d\n", filtre);
            // Calcul de l'indice dans le tableau unidimensionnel
            int index = i * MAX_DIM + j;

            // Stockage du filtre dans le tableau de quantification
            Quantification[index] = filtre;
        }
    }
}

// int decimal_en_binaire2(int filtre) {
//     int Tab_nb[6];
//     int nb;
//     for(int i = 0; i < 6; i++) {
//         if(filtre % 2 == 1){
//             Tab_nb[i] = 1;
//         }
//         else if (filtre % 2 == 0) {
//             Tab_nb[i] = 0;
//         }
//     }
//         nb = Tab_nb[0]*pow(10,5) + Tab_nb[1]*pow(10,4) + Tab_nb[2]*pow(10,3) + Tab_nb[3]*pow(10,2) + Tab_nb[4]*pow(10,1) + Tab_nb[5]*pow(10,0);
    
//     return nb;}




// void afficher_concatenation(int Quantification[MAX_DIM * MAX_DIM]) {
//     for (int i = 0; i < MAX_DIM * MAX_DIM; i++) {
//         printf("Pixel [%d] :\n", i);
//         printf("  Concatenation=");
//         printf("%d",  Quantification[i]);
//         printf("\n");
//     }
// }
