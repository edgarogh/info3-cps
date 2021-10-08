#include "matrice_dynamique.h"
#include "utils_matrice.h"
#include "utils_tests.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    init(argv[1]);

    matrice m = allouer_matrice(1, 2);
    *acces_matrice(m, 0, 0) = 1;
    *acces_matrice(m, 0, 1) = 2;
    *acces_matrice(m, 1, 0) = 3;
    *acces_matrice(m, 1, 1) = 4;
    affiche_test("%d x %d\n", nb_lignes_matrice(m), nb_colonnes_matrice(m));
    affiche_matrice(m);
    liberer_matrice(m);

    m = allouer_matrice(2, 1);
    *acces_matrice(m, 0, 0) = 1;
    *acces_matrice(m, 0, 1) = 2;
    *acces_matrice(m, 1, 0) = 3;
    *acces_matrice(m, 1, 1) = 4;
    affiche_test("%d x %d\n", nb_lignes_matrice(m), nb_colonnes_matrice(m));
    affiche_matrice(m);
    liberer_matrice(m);

    affiche_test("Difference malloc/free : %d\n", malloc_counter - free_counter);
    shutdown();
    return 0;
}
