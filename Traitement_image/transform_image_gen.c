// Leo AHMED MUSHTAQ 19/01/2025
// Binarisation de l'image
#include "declaration.h"
#include <math.h>

int pixel_bin = 0;
int seuil = 0;
int pixel = 0; // C'est le pixel qui va etre pris en scanf et puis qui sera modifé


void transform_image_gen(int bin_4n, int nb_lignes, int nb_colonnes, Liste_RVB Tableau_RVB, char couleur){    
    if (bin_4n<1 || bin_4n>256) printf("Erreur 1 : le niveau de gris n’est pas valide");
    else if ((int)log2(bin_4n) != log2(bin_4n)) printf("Erreur 2 : le niveau de gris n’est pas une puissance de 2 ");
    else{
        if (couleur == 'R'){
            for(int i=0 ; i< nb_lignes ; i++){
                for(int k=0; k< nb_colonnes ; k++){   
                    seuil = 256 / bin_4n;
                    pixel = Tableau_RVB[i][k].R ;
                    pixel_bin = pixel/seuil;
                    printf("%d ", pixel_bin);
                }     
                printf("\n");
            }
        }
        else if (couleur == 'V'){
            for(int i=0 ; i< nb_lignes ; i++){
                for(int k=0; k< nb_colonnes ; k++){   
                    seuil = 256 / bin_4n;
                    pixel = Tableau_RVB[i][k].V ;
                    pixel_bin = pixel/seuil;
                    printf("%d ", pixel_bin);
                }     
                printf("\n");
            }
        }
        else if (couleur == 'B'){
            for(int i=0 ; i< nb_lignes ; i++){
                for(int k=0; k< nb_colonnes ; k++){   
                    seuil = 256 / bin_4n;
                    pixel = Tableau_RVB[i][k].B ;
                    pixel_bin = pixel/seuil;
                    printf("%d ", pixel_bin);
                }     
                printf("\n");
            }
        }
        else{
            printf("Erreur 3 : la couleur n’est pas valide");
        }
            printf("\n");
        }
    }

