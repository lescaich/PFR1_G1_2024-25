#include "declaration.h"

// Fonction pour convertir un nombre décimal en binaire
int decimal_en_binaire(int nombre) {
    if (nombre == 0) {
        printf("0");
        return;
    }

    int binaire[32];
    int index = 0;

    while (nombre > 0) {
        binaire[index] = nombre % 2;
        nombre = nombre / 2;
        index++;
    }

}

void liste_decimal_en_binaire(int ref_tableau[MAX_DIM][MAX_DIM], int ref_Image_R_Binaire[MAX_DIM][MAX_DIM]){
    for(int i = 0; i < MAX_DIM; i++){
        for(int j = 0; j < MAX_DIM; j++){
            ref_Image_R_Binaire[i][j] = decimal_en_binaire(ref_tableau[i][j]);
        }
    }

    return ;
}

int main() {
    // Valeurs des images en binaire
    int Image_R_Binaire[MAX_DIM][MAX_DIM];
    int Image_V_Binaire[MAX_DIM][MAX_DIM];
    int Image_B_Binaire[MAX_DIM][MAX_DIM];

    liste_decimal_en_binaire(IMAGE_R,Image_R_Binaire);
    
    
    
    
    
    
    int nombre;
    decimal_en_binaire(nombre);

    return 0;
}