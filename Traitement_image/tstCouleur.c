#include "declaration.h"

int main() {
    // Ouvrir le fichier image
    FILE *file = fopen("/Users/leo_a_m/Desktop/Cours/PFR/PFR1_G1_2024-25/Traitement_image/DATA/IMG_5389.txt", "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier image.\n");
    }

    int lignes, colonnes, d;
    readImage(file, &lignes, &colonnes, &d);
    fclose(file);

    // Afficher les valeurs RVB du pixel (0,0)
    printf("Les valeurs RVB du pixel (0,0) sont : %d %d %d\n", IMAGE_R[0][0], IMAGE_V[0][0], IMAGE_B[0][0]);

    // Stocker les valeurs RVB dans la structure Liste_RVB
    valeur_RVB(IMAGE_R, IMAGE_V, IMAGE_B);

    // TEST DE LA FONCTION BitsPoidsForts
    int nb_bits_poids_forts = 2;

    // Conversion des pixels en binaire
    liste_decimal_en_binaire(Tableau_RVB, nb_bits_poids_forts);

    // Affichage des pixels convertis en binaire
    afficher_liste_binaire(Tableau_RVB_Quantification, nb_bits_poids_forts);
    printf("###################################################################################\n");

    // Afficher les valeurs binaires du pixel (0,0)
    printf("Les valeurs binaires du pixel (0,0) sont :\n");
    printf("%d\n",Tableau_RVB[0][0].R );
    printf("R_bin: ");
    for (int i = 0; i < nb_bits_poids_forts; i++) {
        printf("%d", Tableau_RVB_Quantification[0][0].R_Quant[i]);
    }
    printf("\nV_bin: ");
    for (int i = 0; i < nb_bits_poids_forts; i++) {
        printf("%d", Tableau_RVB_Quantification[0][0].V_Quant[i]);
    }
    printf("\nB_bin: ");
    for (int i = 0; i < nb_bits_poids_forts; i++) {
        printf("%d", Tableau_RVB_Quantification[0][0].B_Quant[i]);
    }
    printf("\n");

    // Créer et afficher l'histogramme
    // int histogramme[64];
    // creer_histogramme(Tableau_RVB_Quantification, histogramme);
    //afficher_histogramme(histogramme);

    // Binarisation de l'image
    int bin_4n = 4; // niveaux de gris
    char couleur = 'R'; // couleur à traiter
    transform_image_gen(bin_4n, lignes, colonnes, Tableau_RVB, couleur, Tableau_RVB_Binarisation);
    
    affiche_binarisation(lignes, colonnes, Tableau_RVB_Binarisation, couleur); // affichage de l'image binarisée pour les valeurs de R
    printf("###################################################################################\n");
 
    int Quantification[MAX_DIM * MAX_DIM];
    //Concatenation_bit(Tableau_RVB_Quantification, Quantification);
    //afficher_concatenation(Quantification);

    // Détecter la couleur dominante
    char couleur_dominante = detecter_couleur_dominante(Tableau_RVB, lignes, colonnes);
    printf("La couleur dominante est : %c\n", couleur_dominante);


    return 0;
}