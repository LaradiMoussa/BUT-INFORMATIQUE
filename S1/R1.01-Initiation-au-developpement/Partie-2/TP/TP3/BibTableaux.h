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
#ifndef BIBTABLEAUX_H
#define BIBTABLEAUX_H

#include <iostream>
using namespace std;
#include "Personne.h"

// Primitives d'Entrée-Sortie
void afficher (const int tab[],
               unsigned short int lgTab);

 
void recherchePremiereOccDichoEntier(const int tab[], unsigned int NB_CASES, int val, bool& trouve, unsigned int& pos);

void rechercheSequentielleEntier(const int tab[], unsigned int NB_CASES, int val, bool& trouve, unsigned int& pos);

void determinerPremierDernierEntier(const int tab[], unsigned int NB_CASES, bool& trouve, int& val, unsigned int& premier, unsigned int& dernier);

#endif