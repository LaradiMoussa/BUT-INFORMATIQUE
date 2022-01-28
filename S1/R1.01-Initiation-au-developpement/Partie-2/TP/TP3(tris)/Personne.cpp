/**  MODULE Personne
     contient la définition du type Personne
     -------------------------------------------

 Date de dernière modification : 1 décembre 2021
 Auteur : C.NAUDI
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°4
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