/**  MODULE Personne
     contient la définition du type Personne
     -------------------------------------------

 Date de dernière modification : 23 novembre 2021
 Auteur : C.NAUDI
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°3
*/
#include "Personne.h"
#include <iostream>
using namespace std;

void afficher (const Personne& personne)
{
    cout << "{" << personne.nom << ", " << personne.prenom << ", { " ;
    cout <<        personne.adresse.numRue << ", " ;
    cout <<        personne.adresse.nomRue << ", ";
    cout <<        personne.adresse.codePostal << ", ";
    cout <<        personne.adresse.nomVille << " }";
    cout << "}"<< endl;
}

void recherchePremiereOccDichoPersonne(const Personne tab[], unsigned int NB_CASES, string val, bool& trouve, unsigned int& pos)
{
    //VARIABLES
    unsigned short int borneInf;
    unsigned short int borneSup;
    unsigned int milieu;

    //Initialiser les éléments
    trouve = false;
    borneInf = 0;
    borneSup = NB_CASES - 1;

    // La recherche ne se fait qu'avec des tableau rempli
    if (NB_CASES>0)
    {
        //Faire la recherche
        while (borneSup >= borneInf)
        {
            //Calcul milieu
            milieu = ((borneInf + borneSup)/2);

            //Valeur trouvée
            if (tab[milieu].nom==val)
            {
                trouve = true;
                pos = milieu;
                break;
            }
            //Préparer tour suivant
            if (tab[milieu].nom[0] > val[0])
            {   
                borneInf = milieu + 1;
            }
            else
            {
                borneSup = milieu - 1;
            }
        }
    }
    else //Si le tableau est vide
    {
        cout << "Le tableau est vide." << endl;
    }
}

void determinerPremierDernierPersonne(const Personne tab[], unsigned int NB_CASES, bool& trouve, string& nomSaisie, unsigned int& premier, unsigned int& dernier)
{
    trouve = false;
    for (int i = 0; i < NB_CASES; i++)
    {
        //compteur++;
        if (tab[i].nom==nomSaisie)
        {
            premier = i;
            trouve = true;
            break;
        }
    }
    if(trouve)
    {
        for (int i = NB_CASES-1; i >= 0; i--)
        {
            //compteur++;
            if (tab[i].nom==nomSaisie)
            {
                dernier = i;
                break;
            }
        }
    }
}