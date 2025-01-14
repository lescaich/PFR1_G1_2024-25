#include "declaration.h"

// Fonction pour convertir un nombre décimal en binaire
int decimal_en_binaire(int nombre_decimal, int nb_bits_poids_forts) {
    if (nombre_decimal == 0) {
        return;
    }

    int binaire[32];
    int index = 0;

    while (nombre_decimal > 0 || index != nb_bits_poids_forts) {
        binaire[index] = nombre_decimal % 2;
        nombre_decimal = nombre_decimal / 2;
        index++;
    }

}

void liste_decimal_en_binaire(Liste_RVB ref_liste_RVB, int nb_bits_poids_forts) {
    //Liste_RVB_bin Tableau_RVB_bin;
    
    for(int i = 0; i < MAX_DIM; i++){
        for(int j = 0; j < MAX_DIM; j++){
            Tableau_RVB_bin[i][j].R_bin = decimal_en_binaire(ref_liste_RVB[i][j].R, nb_bits_poids_forts);
            Tableau_RVB_bin[i][j].V_bin = decimal_en_binaire(ref_liste_RVB[i][j].V, nb_bits_poids_forts);
            Tableau_RVB_bin[i][j].B_bin = decimal_en_binaire(ref_liste_RVB[i][j].B, nb_bits_poids_forts);
        }
    }

    return ;
}

