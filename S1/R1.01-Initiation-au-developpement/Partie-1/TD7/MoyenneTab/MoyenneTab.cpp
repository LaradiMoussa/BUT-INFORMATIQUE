/*
 Programme : MoyenneTab
 But :  Affiche la moyenne des valeurs d'un tableau
 Date de dernière modification : 13 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme à l'algorithme données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    ///////////////////////////////////////
    // V A R I A B L E S
    const unsigned int NB_CASES = 10;
    int tab[NB_CASES] = {6,-6,8,-8,10,-10,12,-12,14,14};
    int somme;
    double moyenne;
    ///////////////////////////////////////
    // T R A I T E M E N T S

    //Initialisation
    somme = 0;

    //Additionner les notes
    for (int i = 0; i <= NB_CASES-1; i++)
    {
        somme += tab[i];
    }

    //Calculer la moyenne
    moyenne = static_cast<float>(somme)/NB_CASES;

    //Afficher la moyenne
    cout << "La moyenne est de : " << moyenne << "." << endl; 

    return 0;
}