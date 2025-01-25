#include "declaration.h"

// Fonction pour détecter la couleur dominante
char detecter_couleur_dominante(Liste_RVB Tableau_RVB, int nb_lignes, int nb_colonnes) {
    long somme_R = 0;
    long somme_V = 0;
    long somme_B = 0;

    for (int i = 0; i < nb_lignes; i++) {
        for (int j = 0; j < nb_colonnes; j++) {
            somme_R += Tableau_RVB[i][j].R;
            somme_V += Tableau_RVB[i][j].V;
            somme_B += Tableau_RVB[i][j].B;
        }
    }

    if (somme_R > somme_V && somme_R > somme_B) {
        return 'R'; // Rouge est dominant
    } else if (somme_V > somme_R && somme_V > somme_B) {
        return 'V'; // Vert est dominant
    } else {
        return 'B'; // Bleu est dominant
    }
}
