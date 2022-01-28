/**MODULE bibTableaux 
     regroupe des sous-programmes applicables à des tableaux
     -------------------------------------------------------
But :
    Mettre à dispositon d'un programmeur des sous-programmes applicables aux tableaux.
    Conformes aux exercices des TD n°1 et et 3 de R1.01
    
    Il peut s'agit de tableaux d'entiers ou d'enregistrements de type Personne.
    Les tableaux manipulés doivent être triés par ordre décroissant de valeur.
    Dans le cas des tableaux d'enregistrements de type Personne, ils seront triés par ordre 
    décroissant de nom.
---------

 Date de dernière modification : 23 novembre 2021
 Auteur : C.NAUDI
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°2
*/
#include "BibTableaux.h"
#include "Personne.h"
#include <iostream>
using namespace std;

void afficher (const int tab[],
               unsigned short int lgTab)
{
    if (lgTab > 0)
    {
        cout << "{";
        for (unsigned short int i = 0; i<lgTab-1; i++)
        {
            cout << tab[i] << ", " ;

        };
        cout << tab[lgTab-1] << "} "<< endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}

void recherchePremiereOccDichoEntier(const int tab[], unsigned int NB_CASES, int val, bool& trouve, unsigned int& pos)
{
    //VARIABLES
    unsigned short int borneInf;
    unsigned short int borneSup;
    unsigned int milieu;
    //unsigned int compteur = 0 ;

    //Initialiser les éléments
    trouve = false;
    borneInf = 0;
    borneSup = NB_CASES - 1;

    if (NB_CASES>0)
    {
        //Faire la recherche
        while (borneSup >= borneInf)
        {
            //Calcul milieu
            milieu = ((borneInf + borneSup)/2);

            //Valeur trouvée
            if (tab[milieu]==val)
            {
                trouve = true;
                pos = milieu;
                //compteur++;
                break;
            }
            //compteur++;
            //Préparer tour suivant
            if (tab[milieu] > val)
            {   
                cout << "borne inf " << borneInf << endl;
                cout << "borne sup " << borneSup << endl;
                borneInf = milieu + 1;
            }
            else
            {
                cout << "borne inf " << borneInf << endl;
                cout << "borne sup " << borneSup << endl;
                borneSup = milieu - 1;
            }
        }
    }
    else
    {
        cout << "Le tableau est vide." << endl;
    }
    //cout << "Compteur d'acces = " << compteur << endl;
}

void rechercheSequentielleEntier(const int tab[], unsigned int NB_CASES, int val, bool& trouve, unsigned int& pos)
{
    //VARIABLES
    //unsigned int compteur;

    //Initialiser les éléments
    //compteur = 0;

    //Parcours du tableau élément par élément
    for (int i = 0; i < NB_CASES; i++)
    {
        //compteur++;
        if (tab[i]==val)
        {
            trouve=true;
            pos = i;
            break;
        }
    }
    //cout << "Compteur d'acces = " << compteur << endl; 
}

void determinerPremierDernierEntier(const int tab[], unsigned int NB_CASES, bool& trouve, int& val, unsigned int& premier, unsigned int& dernier)
{
    trouve = false;
    for (int i = 0; i < NB_CASES; i++)
    {
        //compteur++;
        if (tab[i]==val)
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
            if (tab[i]==val)
            {
                dernier = i;
                break;
            }
        }
    }
}