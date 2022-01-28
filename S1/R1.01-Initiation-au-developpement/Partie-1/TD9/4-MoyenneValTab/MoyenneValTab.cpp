/*
 Programme : MoyenneValTab
 But : Affiche la moyenne des valeurs contenues dans le tableau
 Date de dernière modification : 26 octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

//Déclaration de la fonction
double moyenneTab (const float tab[], unsigned int NB_CASES);

int main (void)
{
    ////////////////////////
    ///V A R I A B L E S
    const unsigned int nbCases = 10;
    float tableau[nbCases] = {0,2,4,6,8,8.9,3.4,7.8,7.7,9.2};

    ////////////////////////
    ///T R A I T E M E N T S

    cout << "La moyenne des valeurs du tableau est de " << moyenneTab(tableau, nbCases) << endl;

    return 0;
}

//Définition de la fonction
double moyenneTab (const float tab[], unsigned int NB_CASES)
{
    double moyenne;

    //Initialisation
    moyenne = 0;

    //Somme des notes
    for (int i = 0; i<=NB_CASES; i++)
    {
        moyenne += tab[i];
    }

    //Détermination de la moyenne
    moyenne = moyenne / NB_CASES;

    //Retourner la moyenne
    return moyenne;
}