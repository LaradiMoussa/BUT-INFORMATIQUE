/*
 Programme : Palindrome
 But :  Affiche si le mot entré est un palindrome ou pas
 Date de dernière modification : 12 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme à l'algorithme données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    ///////////////////////////////////////
    // V A R I A B L E S
    string chaine;
    bool erreur;
    bool finmot;
    int i;
    int j;
    int nbTour;
    ///////////////////////////////////////
    // T R A I T E M E N T S

    //Initialisation
    erreur = false;
    finmot = false;
    i = 0;

    //Demande de saisie de la chaine
    cout << "Saisissez un mot : ";
    cin >> chaine;

    //Initialiser j
    j = chaine.size()-1;

    //Determiner nombre de tour
    if(chaine.size()%2==0)
    {
        nbTour=chaine.size()/2;
    }
    else
    {
        nbTour= (chaine.size()-1) / 2;
    }

    //Effectuer la recherche
    while ((finmot==false)||(erreur==false))
    {
        if (chaine[i]!=chaine[j])
        {
            erreur = true;
        }

        if (i == nbTour-1)
        {
            finmot = true;
            break;
        }
        i++;
        j--;
    }

    //Afficher le message
    if (erreur == true)
    {
        cout << "Ce n'est pas un palindrome" << endl;
    }
    else
    {
        cout << "C'est un palindrome" << endl;
    }
    
    return 0;
}