#include "vecteur.h"
#include <stdlib.h>

vecteur allouer_vecteur(int taille) {
    return (vecteur) {
        .taille = taille,
        .donnees = malloc(taille * sizeof(double)),
    };
}

void liberer_vecteur(vecteur v) {
    free(v.donnees);
}

int est_vecteur_invalide(vecteur v) {
    return v.donnees == NULL;
}

double* acces_vecteur(vecteur v, int i) {
    if (i >= v.taille) {
        // TODO log a message
        exit(2);
    }

    return &v.donnees[i];
}

int taille_vecteur(vecteur v) {
    return v.taille;
}
