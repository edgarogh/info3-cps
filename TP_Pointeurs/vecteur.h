#ifndef __VECTEUR__
#define __VECTEUR__

struct donnees_vecteur {
    int taille;
    double *donnees;
};

typedef struct donnees_vecteur vecteur;

/*
   allouer_vecteur
   description : alloue un vecteur en memoire
   parametres : la taille du vecteur
   valeur de retour : un vecteur de la taille demandee si l'allocation s'est
                      bien passee et le vecteur invalide si une erreur est
                      survenue
   effets de bord : alloue de la memoire
*/
vecteur allouer_vecteur(int taille);

/*
   liberer_vecteur
   description : libere un vecteur precedemment alloue par alloue_vecteur
   parametres : le vecteur
   valeur de retour : aucune
   effets de bord : libere de la memoire
*/
void liberer_vecteur(vecteur v);

/*
   est_vecteur_invalide
   description : retourne 1 si le vecteur est invalide
   un vecteur est invalide si le pointeur vers ses données est nul
   parametres : le vecteur
   valeur de retour : 1 si le vecteur est invalide 0 sinon
   effets de bord : aucun
*/
int est_vecteur_invalide(vecteur v);

/*
   acces_vecteur
   description : retourne un pointeur vers l'element d'indice i du vecteur
   parametres : le vecteur, l'indice de l'element souhaite
   valeur de retour : un pointeur vers double
   effets de bord : aucun
*/
double *acces_vecteur(vecteur v, int i);

/*
   taille_vecteur
   description : retourne le nombre de composantes d'un vecteur
   parametres : le vecteur
   valeur de retour : la taille du vecteur
   effets de bord : aucun
*/
int taille_vecteur(vecteur v);

#endif
