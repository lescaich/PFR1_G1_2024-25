// Leo AHMED MUSHTAQ 09/01/2025
// Ce fichier permet de lire une image et de stocker les valeurs RVB dans un tableau à deux dimensions.
#include "declaration.h"


// Fonction pour lire une image
void readImage(FILE* ptr_file, int *lignes, int *colonnes, int *d) {
    if (ptr_file == NULL) {
        printf("Erreur de lecture du fichier.\n");
        exit(1);  // Quitte le programme en cas d'erreur
    }

    // Lecture des dimensions et du nombre de canaux
    fscanf(ptr_file, "%d", lignes);
    fscanf(ptr_file, "%d", colonnes);
    fscanf(ptr_file, "%d", d);

    // Vérification des dimensions
    if (*lignes > MAX_DIM || *colonnes > MAX_DIM) {
        printf("Erreur : Dimensions de l'image trop grandes (%d x %d).\n", *lignes, *colonnes);
        exit(1);
    }

    // Lecture des valeurs en fonction du nombre de canaux
    if (*d == 3) {
        // Lecture des trois canaux
        for (int i = 0; i < *lignes; i++) {
            for (int j = 0; j < *colonnes; j++) {
                fscanf(ptr_file, "%d", &IMAGE_R[i][j]);  // Rouge
            }
        }
        for (int i = 0; i < *lignes; i++) {
            for (int j = 0; j < *colonnes; j++) {
                fscanf(ptr_file, "%d", &IMAGE_V[i][j]);  // Vert
            }
        }
        for (int i = 0; i < *lignes; i++) {
            for (int j = 0; j < *colonnes; j++) {
                fscanf(ptr_file, "%d", &IMAGE_B[i][j]);  // Bleu
            }
        }
    } else {
        printf("Erreur : Seules les images RGB (d = 3) sont prises en charge.\n");
        exit(1);
    }
}
