/*
 Programme : SommeEntiersC
 But : Le programme affiche la somme des entiers entre deux bornes entrées sauf si la borne inferieure
       est supérieure à la borne superieure, la somme sera de 0.
 Date de dernière modification : 23 septembre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    ////////////////////////
    ///V A R I A B L E S
    int borneInf;
    int borneSup;
    int somme = 0;

    ////////////////////////
    ///T R A I T E M E N T S

    //Demande de saisie des bornes
    cout << "Entrer une borne inferieure : ";
    cin >> borneInf;
    cout << "Entrer une borne superieure : ";
    cin >> borneSup;

    //Verification si borneInf est supérieure à borneSup
    for (int i = borneInf; i <= borneSup ; i++)
    {
        somme += i;
    }

    //Affichage du resultat
    cout << "La somme des nombres de la borne superieure a la borne inferieure est de " << somme << "." <<endl;

    return 0;
}