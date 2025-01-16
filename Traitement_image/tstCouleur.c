// Leo AHMED MUSHTAQ
#include "declaration.h"


int main() {
    int lignes, colonnes, d;
    
    // Ouverture du fichier
    FILE* file;
    
    file = fopen("/Users/leo_a_m/Desktop/Cours/PFR/PFR1_G1_2024-25/Traitement_image/DATA/IMG_5389.txt", "r");
    if (file == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier.\n");
        exit(1);
    }
   
 /*####################################################################################################################*/
    
    // Lecture de l'image
    readImage(file, &lignes, &colonnes, &d);
/*
    //Affichage des 10 premières lignes du canal Vert
    printf("Canal Vert (IMAGE_V) :\n");
    for (int i = 0; i < 300 && i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%d ", IMAGE_V[i][j]);
        }
    }
*/
    // Fermeture du fichier
    fclose(file);

/*####################################################################################################################*/
   
   // Test de la fonction valeur_RVB
    valeur_RVB(IMAGE_R, IMAGE_V, IMAGE_B);
    printf("\n%s\n", "###################################################################################");
    printf("Les valeurs RVB du pixel (0,0) sont : %d %d %d\n", IMAGE_R[0][0], IMAGE_V[0][0], IMAGE_B[0][0]);
   
/*####################################################################################################################*/
    
    // TEST DE LA FONCTION BitsPoidsForts
    int nb_bits_poids_forts = 4;
    
    // Conversion des pixels en binaire
    liste_decimal_en_binaire(Tableau_RVB, nb_bits_poids_forts);

    // Affichage des pixels convertis en binaire
    afficher_liste_binaire(Tableau_RVB_bin, nb_bits_poids_forts);


    return 0;
}