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

 Date de dernière modification : 1 décembre 2021
 Auteur : C.NAUDI
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°4
*/
#ifndef BIBTABLEAUX_H
#define BIBTABLEAUX_H

#include <iostream>
using namespace std;
#include "Personne.h"

/* ----------------------- Primitives d'Entrée-Sortie ----------------------- */
void afficher (const int tab[], unsigned int lgTab);
//BUT : affiche à l'écran le tableau tab de taille lgTab

void afficher (const Personne tab[], unsigned int lgTab);
// BUT : affiche à l'écran le contenu d'un tableau tab contenant lgTab > 0 éléments de type Personne
//       si lgTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide')

/* ------------------------------- Recherches ------------------------------- */
void recherchePremiereOccDichoEntier(const int tab[], unsigned int nbCases, int val, bool& trouve, unsigned int& pos);
//BUT : Affiche l'emplacement de la première occurence de la valeur dans le tableau si elle est présente.
//      Cette fonction utilise la recherche de première occurence par dichotomie.

void recherchePremiereOccDichoPersonne(const Personne tab[], unsigned int nbTab, string val, bool& trouve, unsigned int& pos);
//BUT : Affiche l'emplacement d'une personne dans un tableau tab de nbCases à partir de son nom.
//      Indique qu'il ne fait pas partie du tableau si on ne le trouve pas.

void rechercheSequentielleEntier(const int tab[], unsigned int nbCases, int val, bool& trouve, unsigned int& pos);
//BUT : Affiche l'emplacement de la première occurence de la valeur dans le tableau si elle est présente.
//      Cette fonction utilise la recherche sequentielle.

void determinerPremierDernierEntier(const int tab[], unsigned int nbCases, bool& trouve, int& val, unsigned int& premier, unsigned int& dernier);
//BUT : Affiche l'emplacement de la premiere fois (premier) que la valeur val apparaît dans le tableau tab de NB_CASES et la dernière fois (dernier)
//      Si la valeur n'a pas été trouvée (trouve) dans le tableau on affiche que la valeur n'est pas dans le tableau.

void determinerPremierDernierPersonne(const Personne tab[], unsigned int nbTab, bool& trouve, string& nomSaisie, unsigned int& premier, unsigned int& dernier);
//BUT : Affiche l'emplacement de la premiere fois (premier) que le nom (nom) apparaît dans le tableau tab de NB_CASES et la dernière fois (dernier)
//      Si la valeur n'a pas été trouvée (trouve) dans le tableau on affiche que la valeur n'est pas dans le tableau.


/* -------------------------------------------------------------------------- */
/*                               POSITION DU MAX                              */
/* -------------------------------------------------------------------------- */
unsigned int positionDuMax(const int tab[], unsigned int bDeb, unsigned int bFin);
//BUT : retourne l'indice de la plus grande valeur du tableau tab
//      comprise entre les bornes bDeb et bFin

unsigned int positionDuMax(const Personne tab[], unsigned int bDeb, unsigned int bFin);
//BUT : retourne l'indice de le plus grand nom du tableau tab
//      comprise entre les bornes bDeb et bFin

void positionDuMax(const int tab[], unsigned int bDeb, unsigned int bFin, unsigned int& pos, unsigned int& nbAcces, unsigned int& nbComparaisons);
//BUT : retourne l'indice de la plus grande valeur du tableau tab
//      comprise entre les bornes bDeb et bFin
//      nbAcces précise le nombre d'accès au tableau réalisés dans le sous-programme.
//      nbComparaison précise le nombre de comparaison réalisés dans le sous-programme.

/* ----------------------- Tris de tableaux d'entiers ----------------------- */

/* -------------------------------------------------------------------------- */
/*                                  TRIBULLE                                  */
/* -------------------------------------------------------------------------- */
void triBulle(int tab[], unsigned int nbTab);
// BUT : tri des nbTab(>0) éléments de tab (avec d’éventuels doublons)
//       par ordre croissant de valeur par la méthode de tri de même nom.

void triBulle(Personne tab[], unsigned int nbTab);
// BUT : tri des nbTab(>0) personnes de tab (avec d’éventuels doublons)
//       par ordre croissant de nom par la méthode de tri de même nom.

void triBulle(int tab[], unsigned int nbTab, unsigned int& nbAcces, unsigned int& nbComparaison);
// BUT : tri des nbTab(>0) éléments de tab (avec d’éventuels doublons)
//       par ordre croissant de valeur par la méthode de tri de même nom.
//       nbAcces précise le nombre d'accès au tableau réalisés dans le sous-programme.
//       nbComparaison précise le nombre de comparaison réalisés dans le sous-programme.

/* -------------------------------------------------------------------------- */
/*                         TRI PAR SELECTION DE PLACE                         */
/* -------------------------------------------------------------------------- */
void triParSelectionDePlace (int tab[], unsigned int nbTab);
// BUT : tri des nbTab(>0) éléments de tab (avec d’éventuels doublons)
//       par ordre croissant de valeur par la méthode de tri de même nom.

void triParSelectionDePlace (Personne tab[], unsigned int nbTab);
// BUT : tri des nbTab(>0) personnes de tab (avec d’éventuels doublons)
//       par ordre croissant de valeur par la méthode de tri de même nom.

void triParSelectionDePlace (int tab[], unsigned int nbTab, unsigned int& nbAcces, unsigned int& nbComparaison);
// BUT : tri des nbTab(>0) éléments de tab (avec d’éventuels doublons)
//       par ordre croissant de valeur par la méthode de tri de même nom.
//       nbAcces précise le nombre d'accès au tableau réalisés dans le sous-programme.
//       nbComparaison précise le nombre de comparaison réalisés dans le sous-programme.

/* -------------------------------------------------------------------------- */
/*                              TRI PAR INSERTION                             */
/* -------------------------------------------------------------------------- */
void triParInsertion(int tab[], unsigned int nbTab);
// BUT : tri CROISSANT des nbTab (>0) éléments de tab (avec d’éventuels doublons)
//       par la méthode de tri de même nom

void triParInsertion(Personne tab[], unsigned int nbTab);
// BUT : tri CROISSANT des nbTab (>0) personnes de tab (avec d’éventuels doublons)
//       par la méthode de tri de même nom

/* -------------------------------------------------------------------------- */
/*                                 TRI FUSION                                 */
/* -------------------------------------------------------------------------- */
void triFusion(const int tableau1[], unsigned int nbTab1, const int tableau2[], unsigned int nbTab2, int tabFusion[]);
// BUT : Retourne le tableau triFusion contenant les entiers du tableau1 & tableau 2
//       triés par ordre croissant.

void triFusion(const Etudiant tableau1[], unsigned int nbTab1, const Etudiant tableau2[], unsigned int nbTab2, Etudiant tabFusion[]);
// BUT : Retourne le tableau triFusion contenant les personnes du tableau1 & tableau 2
//       triés par nom croissant.

#endif