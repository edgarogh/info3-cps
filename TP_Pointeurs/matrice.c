#include "matrice.h"
#include <stdlib.h>

matrice allouer_matrice(int l, int c) {
    double **donnees = malloc(l * sizeof(double*));

    for (int i = 0; i < l; i++) {
        donnees[i] = malloc(c * sizeof(double));
    }

    return (matrice) {
        .l = l,
        .c = c,
        .donnees = donnees,
    };
}

void liberer_matrice(matrice m) {
    for (int i = 0; i < m.l; i++) {
        free(m.donnees[i]);
    }

    free(m.donnees);
}

int est_matrice_invalide(matrice m) {
    return m.donnees == NULL;
}

double *acces_matrice(matrice m, int i, int j) {
    return &m.donnees[i][j];
}

int nb_lignes_matrice(matrice m) {
    return m.l;
}

int nb_colonnes_matrice(matrice m) {
    return m.c;
}
