// Leo AHMED MUSHTAQ 25/01/2025
// Ce fichier permet de créer un histogramme des valeurs binaires cependant il n'est pas abouti.

#include "declaration.h"

// Fonction pour créer un histogramme des valeurs binaires
void creer_histogramme(Liste_RVB_Quantification liste, int histogramme[64]) {
    for (int i = 0; i < 64; i++) {
        histogramme[i] = 0;
    }

    for (int i = 0; i < MAX_DIM; i++) {
        for (int j = 0; j < MAX_DIM; j++) {
            int valeur = 0;
            for (int k = 0; k < 8; k++) {
                valeur = valeur * 2 + liste[i][j].R_Quant[k];
            }
            histogramme[valeur]++;
        }
    }
}

// Fonction pour afficher l'histogramme
void afficher_histogramme(int histogramme[64]) {
    for (int i = 0; i < 64; i++) {
        printf("Valeur %d: %d\n", i, histogramme[i]);
    }
}