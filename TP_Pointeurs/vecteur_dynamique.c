#include "vecteur_dynamique.h"
#include <stdlib.h>

vecteur allouer_vecteur(int taille) {
    vecteur v = malloc(sizeof(struct donnees_vecteur));

    v->taille = taille;
    v->donnees = malloc(taille * sizeof(double));

    return v;
}

void liberer_vecteur(vecteur v) {
    free(v->donnees);
    free(v);
}

int est_vecteur_invalide(vecteur v) {
    return v->donnees == NULL;
}

double* acces_vecteur(vecteur v, int i) {
    if (i < 0) return NULL;
    if (i >= v->taille) {
        int nouvelle_taille = (i + 1);
        v->donnees = realloc(v->donnees, nouvelle_taille * sizeof(double));
        v->taille = nouvelle_taille;
    }

    return &v->donnees[i];
}

int taille_vecteur(vecteur v) {
    return v->taille;
}
