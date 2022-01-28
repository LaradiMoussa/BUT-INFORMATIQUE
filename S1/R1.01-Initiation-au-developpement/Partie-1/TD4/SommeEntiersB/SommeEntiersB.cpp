/*
 Programme : SommeEntiersB
 But : Le programme affiche la somme des entiers entre deux bornes entrées.
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

    //Calcul de la somme des entiers de 1 à la borne entrée
    for (int i = borneInf; i <= borneSup ; i++)
    {
        somme += i;
    }

    //Affichage du resultat
    cout << "La somme des nombres de 1 a la borne est de " << somme << "." <<endl;

    return 0;
}