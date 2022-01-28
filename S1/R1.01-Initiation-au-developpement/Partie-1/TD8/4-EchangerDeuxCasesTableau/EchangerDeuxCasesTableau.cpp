/*
 Programme : EchangerDeuxCasesTableau
 But : Echange deux cases d'un tableau
 Date de dernière modification : 18 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme à l'algorithme données en cours
*/

#include <iostream>
using namespace std;

//Déclaration du sous-programme
void echangerDeuxCasesTab(int tab[], unsigned int indice1, unsigned int indice2);

int main (void)
{
    ///////////////////////////////////////
    // V A R I A B L E S
    const unsigned int NB_CASES = 5;
    int tab[NB_CASES] = {1,2,3,4,5};
    ///////////////////////////////////////
    // T R A I T E M E N T S

    //Affichage du tableau avant l'échange
    for (int i = 0; i < NB_CASES; i++)
    {
        cout << tab[i] << " ";
    }

    //Appel du sous-programme
    echangerDeuxCasesTab(tab,0,4);
    cout << endl;

    //Affichage du tableau après l'échange
    for (int i = 0; i < NB_CASES; i++)
    {
        cout << tab[i] << " ";
    }

    cout << endl;

    return 0;
}

//Définition du sous-programme
void echangerDeuxCasesTab(int tab[], unsigned int indice1, unsigned int indice2)
{
    int aux;
    
    aux = tab[indice1];
    tab[indice1] = tab[indice2];
    tab[indice2] = aux;
}