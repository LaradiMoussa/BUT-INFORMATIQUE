/*
 Programme : InverserValsTab
 But : Inverse les valeurs d'un tableau
 Date de dernière modification : 18 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme à l'algorithme données en cours
*/

#include <iostream>
using namespace std;

//Déclaration du sous-programem
void inverserTab(int tab[], int tabModif[], const unsigned int tailleTab);

int main (void)
{
    ///////////////////////////////////////
    // V A R I A B L E S
    const unsigned int NB_CASES = 5;
    int tab[NB_CASES] = {0,1,2,3,4};
    int tab2[NB_CASES];
    ///////////////////////////////////////
    // T R A I T E M E N T S

    //Appel du sous-programme
    inverserTab(tab, tab2, NB_CASES);

    //Afficher le tableau avec les nouvelles valeurs
    for (int i =0; i <= NB_CASES -1 ; i++)
    {
        cout << tab2[i] << " ";
    }
    cout << endl;

}

//Définition du sous-programme
void inverserTab(int tab[], int tabModif[], const unsigned int tailleTab)
{
    unsigned int nbTourInv;

    nbTourInv = 0;

    //Parcours du tableau 1 en sens inverse
    for (int i = tailleTab-1; i>=0 ; i--)
    {
        //Remplissage du deuxieme tableau en sens normal
        tabModif[nbTourInv] = tab[i];

        //Incrementation de l'indice de remplissage du deuxieme tableau
        nbTourInv++;
    }
}