/*
 Programme : InverserTab
 But :  Inverse les valeurs d'un tableau
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
    int tab2[NB_CASES];
    int nbTourInv;
    ///////////////////////////////////////
    // T R A I T E M E N T S

    //Initialisation
    nbTourInv = 0;

    //Parcours du tableau 1 en sens inverse
    for (int i = NB_CASES-1; i>=0 ; i--)
    {
        //Remplissage du deuxieme tableau en sens normal
        tab2[nbTourInv] = tab[i];

        //Incrementation de l'indice de remplissage du deuxieme tableau
        nbTourInv++;
    }
    //Afficher le tableau avec les nouvelles valeurs
    for (int i =0; i <= NB_CASES -1 ; i++)
    {
        cout << tab2[i] << " ";
    }
    
    
    return 0;
}
