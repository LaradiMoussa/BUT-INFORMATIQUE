/*
 Programme : CompterNegatifs
 But :  Compte les valeurs negatives d'un tableau
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
    //int tab[NB_CASES] = {0,1,-2,3,-4,5,-6,7,-8,9};
    int tab[NB_CASES] = {0,1,2,3,4,5,6,7,8,9};
    int compteur;
    ///////////////////////////////////////
    // T R A I T E M E N T S

    //Initialisation
    compteur = 0;

    //Parcours complet du tableau
    for(int i =0; i <= NB_CASES-1; i++)
    {
        //Si la valeure rencontrée est négative on l'incremente
        if(tab[i]<0)
        {
            compteur ++;
        }
    }
    //Affichage du nombre de valeurs negatives
    cout << "Il y a dans le tableau " << compteur << " valeurs negatives." << endl;
    return 0;
}
