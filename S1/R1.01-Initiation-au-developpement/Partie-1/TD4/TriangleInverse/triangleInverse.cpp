/*
 Programme : triangleInverse
 But : Affiche un triangle inversé sur un nombre de ligne saisie par l'utilisateur
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
    int nbLignes;
    int nbEtoilesAAfficher;

    ////////////////////////
    ///T R A I T E M E N T S

    //Saisie du nombre de lignes à afficher
    cout << "Entrez un nombre de lignes a afficher : ";
    cin >> nbLignes;

    nbEtoilesAAfficher = nbLignes;
    //Affichage du triangle
    for(int i = 1; i <= nbLignes ; i++)
    {
        for (int j = nbEtoilesAAfficher; j >= 1; j--)
        {
            cout << "* ";
        }
        cout << endl;
        nbEtoilesAAfficher--;
    }

    return 0;
}