#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <ratio>
#include <climits>
#include <string.h>
#include <iomanip>
#include <gmp.h>
#include <gmpxx.h>

using namespace std;

unsigned long long *valeurs_recurs = NULL;
bool do_table = false;

/*
 * Explications :
 * Cet algorithme est itératif, consomme beaucoup moins de mémoire, et est plus rapide.
 * val_pos_2 contient la valeur de fibonacci à la position n - 2
 * val_pos_1 à la position n - 1
 * val_pos est la valeur recherchée
 */

void fibo_iter()
{
    mpz_class i = 0;
    mpz_class val_pos_2 = 1;
    mpz_class val_pos_1 = 1;
    mpz_class val_pos;

    size_t headerWidth[3] = {
        string("Position     ").size(),
        string("Valeur                                ").size()
    };

    if (do_table == true)
    {
        cout << "Position      | Valeur                                " << endl
             << "------------------------------------------------------" << endl
             << "0             | 1                                     " << endl
             << "1             | 1                                     " << endl;
    }

    while (true)
    {
        val_pos = val_pos_1 + val_pos_2;
        val_pos_2 = val_pos_1;
        val_pos_1 = val_pos;

        cout << left << setw(headerWidth[0]) << i << flush;
        cout << " | ";
        cout << left << setw(headerWidth[1]) << val_pos << endl;

        ++i;
    }
}

/*
 * Ceci est la fonction principale du programme, c'est elle qui est appelée au démarrage.
 * Elle va demander la postiion du terme à calculer, et appeler les 2 fonctions pour déterminer le temps d'exécution de chacune (en milisecondes)
 * À part si vous êtes un développeur, ce n'est pas la partie qui va vous intéresser
 */

int main()
{
    fibo_iter();

    return EXIT_SUCCESS;
}
