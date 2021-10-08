#include "matrice_lineaire.h"
#include <stdlib.h>

matrice allouer_matrice(int l, int c) {
    return (matrice) {
        .l = l,
        .c = c,
        .donnees = malloc(c * l * sizeof(double))
    };
}

void liberer_matrice(matrice m) {
    free(m.donnees);
}

int est_matrice_invalide(matrice m) {
    return m.donnees == NULL;
}

double *acces_matrice(matrice m, int i, int j) {
    if (i < 0 || j < 0 || i >= m.l || j >= m.c) {
        // TODO print error
        exit(2);
    }

    return &m.donnees[i * m.c + j];
}

int nb_lignes_matrice(matrice m) {
    return m.l;
}

int nb_colonnes_matrice(matrice m) {
    return m.c;
}
