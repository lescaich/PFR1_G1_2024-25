#include "declaration.h"

void valeur_RVB(int ref_tableau_R[MAX_DIM][MAX_DIM],int ref_tableau_V[MAX_DIM][MAX_DIM],int ref_tableau_B[MAX_DIM][MAX_DIM]){
    //Liste_RVB Tableau_RVB;
    for(int i = 0 ; i < MAX_DIM ; i++){
        for(int j = 0 ; j < MAX_DIM ; j++){
            Tableau_RVB[i][j].R = ref_tableau_R[i][j];
            Tableau_RVB[i][j].V = ref_tableau_V[i][j];
            Tableau_RVB[i][j].B = ref_tableau_B[i][j];
        }
    }
    return;
}