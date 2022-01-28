/*
 Programme : AfficherTableau
 But :  Affiche le contenu d'un tableau
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
    int tab[NB_CASES] = {0,1,2,3,4,5,6,7,8,9};
    ///////////////////////////////////////
    // T R A I T E M E N T S
    
    //Parcours complet du tableau
    for (int i =0; i <= NB_CASES -1 ; i++)
    {
        //Affichage du tableau case par case
        cout << tab[i] << " ";
    }

    return 0;
}
