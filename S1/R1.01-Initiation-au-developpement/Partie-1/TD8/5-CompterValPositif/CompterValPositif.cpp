/*
 Programme : CompterValPositif
 But : Compte les valeurs positives dans un tableau
 Date de dernière modification : 18 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme à l'algorithme données en cours
*/

#include <iostream>
using namespace std;

//Déclaration du sous-programme
void compterPositifDansTab(int tab[]);

int main (void)
{
    ///////////////////////////////////////
    // V A R I A B L E S
    const unsigned int NB_CASES = 5;
    int tab[NB_CASES] = {0,4,-2,-6,8};
    
    ///////////////////////////////////////
    // T R A I T E M E N T S

    //Appel du sous-programme
    compterPositifDansTab(tab);

    return 0;
}

//Définition du sous-programme
void compterPositifDansTab(int tab[])
{
    unsigned int compteur;
    const unsigned int NB_CASES = 5;

    compteur = 0;

    for(int i = 0; i<NB_CASES; i++)
    {
        if (tab[i]>0)
        {
            compteur++;
        }
    }
    cout << compteur << endl;
}