/*
 Programme : test du module bibTableauxEntiers
 But :  Tester la conformité de chaque fonctionnalité du module bibTableauxEntiers
        par rapport aux jeux d'essais prévus
 Date de dernière modification : 23 Octobre 2021
 Auteur : C.NAUDI
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - TD n°3
*/

// Compiler !!
//cd "/Users/colasnaudi/Desktop/GitHub/BUT-INFO/S1/R1.01-Initiation-au-developpement/Partie-2/TP/TP3/" && g++ main.cpp BibTableaux.cpp Personne.cpp -o main && "/Users/colasnaudi/Desktop/GitHub/BUT-INFO/S1/R1.01-Initiation-au-developpement/Partie-2/TP/TP3/"main

#include <iostream>
using namespace std;

#include "BibTableaux.h"
#include "Personne.h"

/* -------------------------------------------------------------------------- */
/*                   Déclaration des sous-programmes de test                  */
/* -------------------------------------------------------------------------- */

void testRechercheDichoEntiers(const int tab[], unsigned int NB_CASES, int val, bool& trouve, unsigned int& pos);
//BUT : Affiche l'emplacement de la première occurence de la valeur dans le tableau si elle est présente.
//      Cette fonction utilise la recherche de première occurence par dichotomie.

void testRechercheSequentielleEntier(const int tab[], unsigned int NB_CASES, int val, bool& trouve, unsigned int& pos);
//BUT : Affiche l'emplacement de la première occurence de la valeur dans le tableau si elle est présente.
//      Cette fonction utilise la recherche sequentielle.

void testRechercheDichoPersonne(const Personne tab[], unsigned int NB_CASES, string nomPersonne , bool& trouve, unsigned int& pos);
//BUT : Affiche l'emplacement d'une personne dans un tableau tab de nbCases à partir de son nom.
//      Indique qu'il ne fait pas partie du tableau si on ne le trouve pas.

void testDeterminerPremierDernierEntier(const int tab[], unsigned int NB_CASES, bool& trouve, int val, unsigned int& premier, unsigned int& dernier);
//BUT : Affiche l'emplacement de la premiere fois (premier) que la valeur val apparaît dans le tableau tab de NB_CASES et la dernière fois (dernier)
//      Si la valeur n'a pas été trouvée (trouve) dans le tableau on affiche que la valeur n'est pas dans le tableau.

void testDeterminerPremierDernierPersonne(const Personne tab[], unsigned int NB_CASES, bool& trouve, string nomSaisie, unsigned int& premier, unsigned int& dernier);
//BUT : Affiche l'emplacement de la premiere fois (premier) que le nom (nom) apparaît dans le tableau tab de NB_CASES et la dernière fois (dernier)
//      Si la valeur n'a pas été trouvée (trouve) dans le tableau on affiche que la valeur n'est pas dans le tableau.

int main()
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */

    /* ------------------ Variables de test module BibTableaux ------------------ */
    
    const unsigned int NB_CASES = 10;
    const unsigned int CASES = 1;
    int tableau[CASES] = {7};
    int monTab[NB_CASES] = {-60, -45, -30, -25, -15, -10, 0, 15, 20, 45};
    int tab[NB_CASES] = {60, 60, 60, 60, 60, 60, 60, 60, 60, 60};
    int tab1[NB_CASES] = {60, 50, 45, 40, 30, 20, 20, 20, 10, 5};
    int valeur = 3;
    bool estTrouve;
    unsigned int position;
    int monTab2[NB_CASES] = {60, 30, 30, 25, 15, 10, 0, -15, -20, -45};
    const unsigned short int NB_CASES2 = 1;
    int monTab3[NB_CASES2] = {50};
    unsigned int premier;
    unsigned int dernier;

    /* --------------- Variables de test module RessourcesPersonne -------------- */

    const unsigned int TAILLE = 10;
    Personne tableau1[TAILLE]={
        {"Voisin","Sophie",{"12","rue des arenes",64240,"Hasparren"}},
        {"Urruty","Damien",{"6","rue des lilas",64240,"Hasparren"}},
        {"Marquesuzaa","Christophe",{"8","avenue d'Anglet",64600,"Anglet"}},
        {"Lopisteguy","Philippe",{"1","avenue d'Anglet",64600,"Anglet"}},
        {"Etcheverry","Patrick",{"2bis","allee des alouettes",64100,"Bayonne"}},
        {"Dijon-Duboue","Simone",{"5","rue des roses",64600,"Anglet"}},
        {"Dagorret","Pantxika",{"10","chemin des bois",64250,"Itxassou"}},
        {"Corbineau","Sandrine",{"23","allee des fleurs",64100,"Bayonne"}},
        {"Bruyere","Marie",{"4","rue de la musique",64240,"Hasparren"}},
        {"Alami","Chakib",{"41","allee de la patisserie",64250,"Itxassou"}}
    };
    Personne tableau2[TAILLE]={
        {"Voisin","Sophie",{"12","rue des arenes",64240,"Hasparren"}},
        {"Urruty","Damien",{"6","rue des lilas",64240,"Hasparren"}},
        {"Marquesuzaa","Christophe",{"8","avenue d'Anglet",64600,"Anglet"}},
        {"Marquesuzaa","Philippe",{"1","avenue d'Anglet",64600,"Anglet"}},
        {"Marquesuzaa","Patrick",{"2bis","allee des alouettes",64100,"Bayonne"}},
        {"Dijon-Duboue","Simone",{"5","rue des roses",64600,"Anglet"}},
        {"Dagorret","Pantxika",{"10","chemin des bois",64250,"Itxassou"}},
        {"Corbineau","Sandrine",{"23","allee des fleurs",64100,"Bayonne"}},
        {"Bruyere","Marie",{"4","rue de la musique",64240,"Hasparren"}},
        {"Alami","Chakib",{"41","allee de la patisserie",64250,"Itxassou"}}
    };
    const unsigned int TAILLE2 = 0;
    Personne tableau3[TAILLE2];
    string nom = "Marquesuzaa";

    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */

    /* ------------------------- test module BibTableaux ------------------------ */
    //afficher(tab, NB_CASES);

    testRechercheDichoEntiers(tableau, CASES, valeur, estTrouve, position);

    //testRechercheSequentielleEntier(monTab, NB_CASES, valeur, estTrouve, position);

    //testDeterminerPremierDernierEntier(tab1, NB_CASES, estTrouve, valeur, premier, dernier);

    /* --------------------- test module RessourcesPersonne --------------------- */

    //afficher(unePersonne);

    //testRechercheDichoPersonne(tableau1, TAILLE, nom, estTrouve, position);

    //testDeterminerPremierDernierPersonne(tableau2, TAILLE, estTrouve, nom, premier, dernier);

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                     Définitions sous-programmes de test                    */
/* -------------------------------------------------------------------------- */
void testRechercheDichoEntiers(const int tab[], unsigned int NB_CASES, int val, bool& trouve, unsigned int& pos)
{
    recherchePremiereOccDichoEntier(tab, NB_CASES, val, trouve, pos);
    if(trouve){
        cout << "La valeur " << val << " se trouve pour la première fois en position " << pos+1 << " dans le tableau monTab." << endl;
    }
    else{
        cout << "La valeur " << val << " ne se trouve pas dans le tableau." << endl;
        pos = 0;
    }
}

void testRechercheSequentielleEntier(const int tab[], unsigned int NB_CASES, int val, bool& trouve, unsigned int& pos)
{
    rechercheSequentielleEntier(tab, NB_CASES, val, trouve, pos);
    if(trouve){
        cout << "La valeur " << val << " se trouve pour la première fois en position " << pos+1 << " dans le tableau monTab." << endl;
    }
    else{
        cout << "La valeur " << val << " ne se trouve pas dans le tableau." << endl;
        pos = 0;
    }
}

void testRechercheDichoPersonne(const Personne tab[], unsigned int NB_CASES, string nomPersonne , bool& trouve, unsigned int& pos)
{
    recherchePremiereOccDichoPersonne(tab, NB_CASES, nomPersonne, trouve, pos);
    if (NB_CASES>0)
    {
        if(trouve){
            cout << "La Personne " << nomPersonne << " se trouve pour la première fois en position " << pos+1 << " dans le tableau monTab." << endl;
        }
        else{
            cout << "La Personne " << nomPersonne << " ne se trouve pas dans le tableau." << endl;
            pos = 0;
        }
    }
}

void testDeterminerPremierDernierEntier(const int tab[], unsigned int NB_CASES, bool& trouve, int val, unsigned int& premier, unsigned int& dernier)
{
    determinerPremierDernierEntier(tab, NB_CASES, trouve, val, premier, dernier);
    if(trouve)
    {
        cout << "La premiere fois que " << val << " apparaît, c'est en position " << premier+1 << "." << endl;
        cout << "La dernière fois que " << val << " apparaît, c'est en position " << dernier+1 << "." << endl;
    }
    else
    {
        cout << "Le valeur " << val << " n'est pas présente dans le tableau." << endl;   
    }
}

void testDeterminerPremierDernierPersonne(const Personne tab[], unsigned int NB_CASES, bool& trouve, string nomSaisie, unsigned int& premier, unsigned int& dernier)
{
    determinerPremierDernierPersonne(tab, NB_CASES, trouve, nomSaisie, premier, dernier);
    if(trouve)
    {
        cout << "La premiere fois que " << nomSaisie << " apparaît, c'est en position " << premier+1 << "." << endl;
        cout << "La dernière fois que " << nomSaisie << " apparaît, c'est en position " << dernier+1 << "." << endl;
    }
    else
    {
        cout << "Le valeur " << nomSaisie << " n'est pas présente dans le tableau." << endl;   
    }
}
