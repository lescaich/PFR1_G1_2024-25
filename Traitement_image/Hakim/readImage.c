#include <stdio.h>

int IMAGE_R[1000][1000];
int IMAGE_V[1000][1000];
int IMAGE_B[1000][1000];

void readImage(FILE* ptr_file, int *lignes, int *colonnes, int *d) {

    if (ptr_file == NULL) printf("Erreur de lecture de fichier");
    else {
        fscanf(ptr_file, "%d", lignes);
        fscanf(ptr_file, "%d", colonnes);
        fscanf(ptr_file, "%d", d);

        if (*d ==3) {
            for (int j=0; j<*lignes;j++) {
                for (int k=0; k<*colonnes;k++) {
                    fscanf(ptr_file, "%d", &IMAGE_R[j][k]);
                }
            }

            for (int j=0; j<*lignes;j++) {
                for (int k=0; k<*colonnes;k++) {
                    fscanf(ptr_file, "%d", &IMAGE_V[j][k]);
                }
            }

            for (int j=0; j<*lignes;j++) {
                for (int k=0; k<*colonnes;k++) {
                    fscanf(ptr_file, "%d", &IMAGE_B[j][k]);
                }
            }
        }

    }
}

int main() {
    int lignes;
    int colonnes;
    int d;
    FILE* file;

    file = fopen("/Users/leo_a_m/Desktop/Cours/PFR/Traitement image/DATA/IMG_5389.txt" , "r");
    readImage(file, &lignes, &colonnes, &d);
    for (int i=0; i<lignes; i++) {
        for (int j = 0; j<colonnes; j++) {
            printf("%d ", IMAGE_V[i][j]);
        }
    }
}
