// Leo AHMED MUSHTAQ
#include "declaration.h"


int main() {
    int lignes, colonnes, d;
    
    // Ouverture du fichier
    FILE* file;
    
    file = fopen("/Users/leo_a_m/Desktop/Cours/PFR/Traitement image/DATA/IMG_5389.txt", "r");
    if (file == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier.\n");
        exit(1);
    }
   
 
    // Lecture de l'image
    readImage(file, &lignes, &colonnes, &d);

    // Affichage des 10 premières lignes du canal Vert
    printf("Canal Vert (IMAGE_V) :\n");
    for (int i = 0; i < 300 && i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%d ", IMAGE_V[i][j]);
        }
    }
    // Fermeture du fichier
    fclose(file);

    // moyenne de la couleur rouge 
    float Moy;
    Moy=moyenne_couleur(IMAGE_R);
    
    printf("La moyenne de la couleur rouge est : %f\n", Moy);
   
    // Test de la fonction valeur_RVB
    valeur_RVB(IMAGE_R, IMAGE_V, IMAGE_B);
    printf("Les valeurs RVB du pixel (0,0) sont : %d %d %d\n", IMAGE_R[0][0], IMAGE_V[0][0], IMAGE_B[0][0]);
   
    return 0;
}