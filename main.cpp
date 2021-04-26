#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <ratio>
#include <chrono>
#include <climits>
#include <string.h>
#include <iomanip>

using namespace std;
using namespace std::chrono;

unsigned long long *valeurs_recurs = NULL;
bool do_table = false;

/*
 * Explications :
 * Cet algorithme est récursif (il s'appelle lui même)
 * Il est simple à coder mais plus gourmand en ressources
 * Dans mon tweet, j'avais mis des types « int » (qui signigie « entier relatif (peut être négatif) »)
 * Dans le code j'ai mis «unsigned long long » (qui signifie « entier plus gand que int, positif) »)
 * C'est pour pouvoir profiter des capacités des processeurs actuels qui gèrent des nombres beaucoup plus grand
 * Le « else » a disparu parce qu'il ne servait à rien (et j'ai mis en forme au passsage)
 * Les positions restent en « int » car on ne peut pas calculer le nombre de fibonacci pour le plus grand « int » dans un « long long »
 */

unsigned long long fibo_recurs(unsigned int pos)
{
    static bool overflow = false;

    if (valeurs_recurs == NULL)
    {
        /* +1 car on veut l'élément de position pos en partant de 0.
         * Or si un tableau a une longueur de pos, il contient exactement pos élément DONT le 0
         */
        valeurs_recurs = new unsigned long long [pos + 1]; 
        for (unsigned int i = 0; i <= pos; ++i)
        {
            valeurs_recurs[i] = (i < 2 ? 1 : 0);
        }
    }

    if (valeurs_recurs[pos] != 0)
    {
        return valeurs_recurs[pos];
    }

    unsigned long long val_pos_1 = valeurs_recurs[pos - 1];
    if (val_pos_1 == 0)
    {
        val_pos_1 = fibo_recurs(pos - 1);
    }

    unsigned long long val_pos_2 = valeurs_recurs[pos - 2];
    /*
     * Pas besoin de vérifier que la valeur existe dans le tableau, elle y est forcément
     * car calculée pour trouver val_pos_1
     */

    valeurs_recurs[pos] = val_pos_1 + val_pos_2;

    if (overflow == false && valeurs_recurs[pos] < valeurs_recurs[pos - 1])
    {
        cerr << "Dépassement de capacité, on ne peut calculer plus loin que le terme " << pos - 1 << "." << endl;
        overflow = true;
    }

    return val_pos_1 + val_pos_2;
}

/*
 * Explications :
 * Cet algorithme est itératif, consomme beaucoup moins de mémoire, et est plus rapide.
 * val_pos_2 contient la valeur de fibonacci à la position n - 2
 * val_pos_1 à la position n - 1
 * val_pos est la valeur recherchée
 */

unsigned long long fibo_iter(unsigned int pos)
{
    bool overflow = false;

    if (pos < 2)
    {
        return 1;
    }

    unsigned long long val_pos_2 = 1;
    unsigned long long val_pos_1 = 1;
    unsigned long long val_pos;
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1b9d22edfd4af16086c1875a13d50a321e73a9c4

    size_t headerWidth[3] = {
        string("Position").size(),
        string("Valeur              ").size(),
        string("Phi             ").size()
    };

    if (do_table == true)
    {
        cout << "Position | Valeur               | Phi             " << endl
             << "-------------------------------------------------" << endl
             << "0        | 1                    |                1" << endl
             << "1        | 1                    |                1" << endl;
    }
<<<<<<< HEAD
>>>>>>> 1b9d22e (Version optimisée + affichage de la table)
=======
>>>>>>> 1b9d22edfd4af16086c1875a13d50a321e73a9c4

    for (unsigned int i = 2; i <= pos; ++i)
    {
        val_pos = val_pos_1 + val_pos_2;
        val_pos_2 = val_pos_1;
        val_pos_1 = val_pos;

        if (overflow == false && val_pos_1 < val_pos_2)
        {
            cerr << "Dépassement de capacité, on ne peut calculer plus loin que le terme " << i - 1 << "." << endl;
            overflow = true;
        }

        if (do_table == true)
        {
            cout << left << setw(headerWidth[0]) << i << flush;
            cout << " | ";
            cout << left << setw(headerWidth[1]) << val_pos << flush;
            cout << " | ";
            cout << right << setw(headerWidth[2]) << ((val_pos_1 * 1.0) / (val_pos_2 * 1.0)) << endl;
        }
    }
    return val_pos;
}

/*
 * Ceci est la fonction principale du programme, c'est elle qui est appelée au démarrage.
 * Elle va demander la postiion du terme à calculer, et appeler les 2 fonctions pour déterminer le temps d'exécution de chacune (en milisecondes)
 * À part si vous êtes un développeur, ce n'est pas la partie qui va vous intéresser
 */

int main(int argc, char *argv[])
{
    unsigned int pos;
    unsigned long long valeur;
    unsigned long long valeur_1;
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1b9d22edfd4af16086c1875a13d50a321e73a9c4

    if (argc > 1 && strcmp(argv[1], "--table") == 0)
    {
        do_table = true;
    }
<<<<<<< HEAD
>>>>>>> 1b9d22e (Version optimisée + affichage de la table)
=======
>>>>>>> 1b9d22edfd4af16086c1875a13d50a321e73a9c4

    cout.precision(numeric_limits<double>::digits10);

    cout << "Quelle position souhaitez vous calculer ?" << endl << "Rappel, les positions sont calculées à partir de 0." << endl << "Position: ";
    cin >> pos;

    if (do_table == false)
    {
        cout << "Calcul en itératif : " << flush;
    }
    high_resolution_clock::time_point start = high_resolution_clock::now();
    valeur = fibo_iter(pos);
    duration<double, std::milli> time_span = high_resolution_clock::now() - start;
    if (do_table == true)
    {
        cout << "Calcul en itératif : ";
    }
    cout << time_span.count() << "ms" << endl;
    cout << "Valeur calculée : fibo_iter(" << pos << ") = " << valeur << endl;
    
    if (do_table == false)
    {
        cout << "Calcul en récursif : " << flush;
        start = high_resolution_clock::now();
        valeur = fibo_recurs(pos);
        time_span = high_resolution_clock::now() - start;
        cout << time_span.count() << "ms" << endl;
        cout << "Valeur calculée : fibo_recurs(" << pos << ") = " << valeur << endl;
    

        cout << "Approximation de φ : " << flush;
        if (pos > 0)
        {
            valeur_1 = fibo_iter(pos - 1);
            double phi = (valeur * 1.0) / (valeur_1 * 1.0);
            cout << phi << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }

    return EXIT_SUCCESS;
}
