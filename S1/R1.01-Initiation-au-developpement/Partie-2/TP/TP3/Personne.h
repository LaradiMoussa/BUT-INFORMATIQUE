/**  MODULE Personne
     contient la définition du type Personne
     -------------------------------------------

 Date de dernière modification : 23 novembre 2021
 Auteur : C.NAUDI
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°3
*/
#ifndef PERSONNE_H
#define PERSONNE_H

#include <iostream>
using namespace std;

// Définition des types du module
struct Adresse 
{
    string numRue; 
    string nomRue;
    unsigned short int codePostal;
    string nomVille; 
};

struct Personne
{
    string nom;
    string prenom;
    Adresse adresse;
};

// Primitives d'Entrée-Sortie
void afficher(const Personne& personne);
// Affiche sur une ligne le contenu de l'enregistrement passé en paramètre

void recherchePremiereOccDichoPersonne(const Personne tab[], unsigned int NB_CASES, string val, bool& trouve, unsigned int& pos);

void determinerPremierDernierPersonne(const Personne tab[], unsigned int NB_CASES, bool& trouve, string& nomSaisie, unsigned int& premier, unsigned int& dernier);

#endif