#include "fap.h"
#include <stdio.h>
#include <stdlib.h>

#define TAILLE_BUFFER 128

void aide()
{
  fprintf(stderr,"Aide :\n");
  fprintf(stderr,"Saisir l'une des commandes suivantes\n");
  fprintf(stderr,"\n");
  fprintf(stderr,"i nombre priorite  :   inserer un nombre avec sa priorite\n");
  fprintf(stderr,"e                  :   extraire le nombre de priorite maximale\n");
  fprintf(stderr,"v                  :   teste si la fap est vide\n");
  fprintf(stderr,"h                  :   afficher cette aide\n");
  fprintf(stderr,"q                  :   quitter ce programme\n");
}

bool fp_basic(int a, int b) {
  return a < b;
}

bool fp_inverse(int b, int a) {
  return a < b;
}

bool fp_0(int a, int b) {
  return 0;
}

bool fp_1(int a, int b) {
  return 1;
}

bool fp_rand(int a, int b) {
  return rand() % 2;
}

int main()
{
  char buffer[TAILLE_BUFFER];
  char commande;
  int nombre,priorite;

  fap f0 = creer_fap_vide(&fp_basic);
  fap f1 = creer_fap_vide(&fp_0);
  aide();
  while (1)
    {
      commande = getchar();
      switch (commande)
        {
        case 'i':
          scanf ("%d",&nombre);
          scanf ("%d",&priorite);
          f0 = inserer(f0, nombre, priorite);
          f1 = inserer(f1, nombre, priorite);
          printf("(%d,%d) a ete insere\n",nombre,priorite);
          break;
        case 'e':
          if (!est_fap_vide(f0))
            {
              int nombre2, priorite2;
              f0 = extraire(f0, &nombre, &priorite);
              f1 = extraire(f1, &nombre2, &priorite2);
              printf("(%d,%d) et (%d,%d) ont ete extrait\n", nombre, priorite, nombre2, priorite2);
            }
          else
              printf("La fap est vide !\n");
          break;
        case 'v':
          printf("Est_fap_vide a retourne %d\n", est_fap_vide(f0));
          break;
        case 'h':
          aide();
          break;
        case 'q':
          detruire_fap(f0);
          detruire_fap(f1);
          exit(0);
        default:
          fprintf(stderr,"Commande inconnue !\n");
        }
      /* vide ce qu'il reste de la ligne dans le buffer d'entree */
      fgets(buffer,TAILLE_BUFFER,stdin);
    }
  detruire_fap(f0);
  detruire_fap(f1);
  return 0;
}
