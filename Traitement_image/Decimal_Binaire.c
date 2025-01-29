// Leo AHMED MUSHTAQ 16/01/2025
// Ce fichier est un teste pour le fichier Bits_poids_forts.c
#include <stdio.h>

void decimal_en_binaire(int nombre_decimal, int nb_bits_poids_forts, int *binaire) {
    // Nombre total de bits pour un entier (dans ce cas, on part de 8 bits)
    int total_bits = 8; 

    if (nb_bits_poids_forts<8){
        // Décaler pour garder uniquement les nb_bits_poids_forts les plus significatifs
        nombre_decimal = nombre_decimal >> (total_bits - nb_bits_poids_forts-1);
    }
    else{
        nombre_decimal = nombre_decimal >> (total_bits - nb_bits_poids_forts);
    }
    
    
    // Convertir en binaire sur nb_bits_poids_forts
    for (int i = 0; i < nb_bits_poids_forts; i++) {
        binaire[nb_bits_poids_forts - 1 - i] = nombre_decimal % 2;
        nombre_decimal = nombre_decimal / 2;
    }
}

int main() {
    int nb[32];  // Tableau pour stocker les bits
    int nombre_decimal = 100;  // Nombre à convertir
    int nb_bits_poids_forts = 4;  // Nombre de bits souhaités (poids forts)

    // Conversion
    decimal_en_binaire(nombre_decimal, nb_bits_poids_forts, nb);

    // Affichage des bits générés
    printf("Représentation binaire de %d sur %d bits (poids forts) : ", nombre_decimal, nb_bits_poids_forts);
    for (int i = 0; i < nb_bits_poids_forts; i++) {
        printf("%d", nb[i]);
    }
    printf("\n");

    return 0;
}