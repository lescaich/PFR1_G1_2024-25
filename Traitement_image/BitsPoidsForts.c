// Leo Ahmed Mushtaq 16/01/2025
// Ce fichier permet de convertir les valeurs RVB d'un tableau à 3 dimensions en binaire et de les stocker.
// Il permet également d'afficher les valeurs binaires.

#include "declaration.h"
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
            decimal_en_binaire(ref_liste_RVB[i][j].R, nb_bits_poids_forts, Tableau_RVB_bin[i][j].R_bin);
            decimal_en_binaire(ref_liste_RVB[i][j].V, nb_bits_poids_forts, Tableau_RVB_bin[i][j].V_bin);
            decimal_en_binaire(ref_liste_RVB[i][j].B, nb_bits_poids_forts, Tableau_RVB_bin[i][j].B_bin);
        }
    }
}

// Fonction pour afficher les valeurs binaires d'un tableau RVB_bin
void afficher_liste_binaire(Liste_RVB_bin liste_bin, int nb_bits_poids_forts) {
    for (int i = 0; i < MAX_DIM; i++) {
        for (int j = 0; j < MAX_DIM; j++) {
            printf("Pixel [%d][%d] :\n", i, j);

            printf("  R_bin=");
            for (int k = 0; k < nb_bits_poids_forts; k++) {
                printf("%d", liste_bin[i][j].R_bin[k]);
            }
            printf("\n");

            printf("  V_bin=");
            for (int k = 0; k < nb_bits_poids_forts; k++) {
                printf("%d", liste_bin[i][j].V_bin[k]);
            }
            printf("\n");

            printf("  B_bin=");
            for (int k = 0; k < nb_bits_poids_forts; k++) {
                printf("%d", liste_bin[i][j].B_bin[k]);
            }
            printf("\n");
        }
    }
}