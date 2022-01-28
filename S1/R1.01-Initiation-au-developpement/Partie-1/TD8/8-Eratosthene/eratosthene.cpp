/*
 Programme : Eratosthene
 But : Affiche un tableau de boolean correspondant au nombres premiers jusqu'à la borne donnée
 Date de dernière modification : 22 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme à l'algorithme données en cours
*/

#include<iostream>
#include <math.h>
using namespace std;

//Déclaration du sous-programme
void determinerPremiers(bool tab[], unsigned int borneRecherchesPremiers);

int main (){
    ///////////////////////////////////////
    //T Y P E S
    ///////////////////////////////////////
    // V A R I A B L E S
    const unsigned int NB_CASES = 100;
    bool tableau[NB_CASES];
    unsigned int borne;
    ///////////////////////////////////////
    // T R A I T E M E N T S

    //La borne
    cout << "Entrer une borne entre 2 et 102 : ";
    cin >> borne;

    //Remplissage du tableau à true 
    for (int i = 0; i <= NB_CASES; i++)
    {
        tableau[i] = true;
    }

    //Appel du sous-programme
    determinerPremiers(tableau,borne);
    
    return 0;
}

//Définition du sous-programme
void determinerPremiers(bool tab[], unsigned int borneRecherchesPremiers)
{
    for (int i = 2; i <= sqrt(borneRecherchesPremiers+1); i++)
    {
        if(tab[i]==true)
        {
            for (int j = i; j <= borneRecherchesPremiers+1; j += i)
            {
                if((j+i) < borneRecherchesPremiers+1)
                {
                    tab[j+i] = false;
                }
            }
        }
    }
    //Afficher la liste des nombres premiers
    for (int i = 2; i <= borneRecherchesPremiers; i++)
    {
        cout << i << " : " << tab[i] << endl;
    }
}