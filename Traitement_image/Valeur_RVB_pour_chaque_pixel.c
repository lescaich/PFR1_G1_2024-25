#include "declaration.h"

void valeur_RVB(int ref_tableau_R[MAX_DIM][MAX_DIM],int ref_tableau_V[MAX_DIM][MAX_DIM],int ref_tableau_B[MAX_DIM][MAX_DIM]){
    Liste_RVB liste_RVB;
    for(int i = 0 ; i < MAX_DIM ; i++){
        for(int j = 0 ; j < MAX_DIM ; j++){
            liste_RVB[i][j].R = ref_tableau_R[i][j];
            liste_RVB[i][j].V = ref_tableau_V[i][j];
            liste_RVB[i][j].B = ref_tableau_B[i][j];
        }
    }
    return;
}