#include "matrice_dynamique.h"
#include "vecteur_dynamique.h"
#include <stdlib.h>

matrice allouer_matrice(int l, int c) {
    double **donnees = malloc(l * sizeof(double*));

    for (int i = 0; i < l; i++) {
        donnees[i] = malloc(c * sizeof(double));
    }

    matrice m = malloc(sizeof(struct donnees_matrice));
    m->l = l;
    m->c = c;
    m->donnees = donnees;

    return m;
}

void liberer_matrice(matrice m) {
    for (int i = 0; i < m->l; i++) {
        free(m->donnees[i]);
    }

    free(m->donnees);
    free(m);
}

int est_matrice_invalide(matrice m) {
    return m->donnees == NULL;
}

double *acces_matrice(matrice m, int i, int j) {
    if (i < 0 || j < 0) return NULL;
    if (j >= m->c) {
        int nouvelle_taille = i + 1;
        for (int x = 0; x < m->l; x++) {
            m->donnees[x] = realloc(m->donnees[x], nouvelle_taille);
        }
        m->c = nouvelle_taille;
    }
    if (i >= m->l) {
        int nouvelle_taille = i + 1;
        m->donnees = realloc(m->donnees, nouvelle_taille * sizeof(double*));
        for (int x = m->l; x < nouvelle_taille; x++) {
            m->donnees[x] = malloc(m->c * sizeof(double));
        } 
        m->l = nouvelle_taille;
    }

    return &m->donnees[i][j];
}

int nb_lignes_matrice(matrice m) {
    return m->l;
}

int nb_colonnes_matrice(matrice m) {
    return m->c;
}
