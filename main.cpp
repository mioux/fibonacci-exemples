#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <ratio>
#include <chrono>
#include <climits>

using namespace std;
using namespace std::chrono;

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
    if (pos < 2)
    {
        return 1;
    }
    return fibo_recurs(pos - 1) + fibo_recurs(pos - 2);
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
    if (pos < 2)
    {
        return 1;
    }

    long long val_pos_2 = 1;
    long long val_pos_1 = 1;
    long long val_pos;

    for (unsigned int i = 2; i <= pos; ++i)
    {
        val_pos = val_pos_1 + val_pos_2;
        val_pos_2 = val_pos_1;
        val_pos_1 = val_pos;
    }
    return val_pos;
}

/*
 * Ceci est la fonction principale du programme, c'est elle qui est appelée au démarrage.
 * Elle va demander la postiion du terme à calculer, et appeler les 2 fonctions pour déterminer le temps d'exécution de chacune (en milisecondes)
 * À part si vous êtes un développeur, ce n'est pas la partie qui va vous intéresser
 */

int main()
{
    unsigned int pos;
    long long valeur;
    long long valeur_1;

    cout.precision(numeric_limits<double>::digits10);

    cout << "Quelle position souhaitez vous calculer ?" << endl << "Rappel, les positions sont calculées à partir de 0. Max " << UINT_MAX << "." << endl << "Position: ";
    cin >> pos;

    cout << "Calcul en itératif : " << flush;
    high_resolution_clock::time_point start = high_resolution_clock::now();
    valeur = fibo_iter(pos);
    duration<double, std::milli> time_span = high_resolution_clock::now() - start;
    cout << time_span.count() << "ms" << endl;
    cout << "Valeur calculée : fibo_iter(" << pos << ") = " << valeur << endl;
    
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

    return EXIT_SUCCESS;
}
