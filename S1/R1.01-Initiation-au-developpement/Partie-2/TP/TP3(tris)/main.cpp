/*
 Programme : test du module bibTableauxEntiers
 But :  Tester la conformité des fonctionnalités de tri du module bibTableaux
        par rapport aux jeux d'essais prévus
 Date de dernière modification : 1 décembre 2021
 Auteur : C.NAUDI
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - TD n°4
*/

// cd "/Users/colasnaudi/Desktop/GitHub/BUT-INFO/S1/R1.01-Initiation-au-developpement/Partie-2/TP/TP4(tris)/" && g++ main.cpp BibTableaux.cpp Personne.cpp -o main && "/Users/colasnaudi/Desktop/GitHub/BUT-INFO/S1/R1.01-Initiation-au-developpement/Partie-2/TP/TP4(tris)/"main

#include "BibTableaux.h"
#include <iostream>
using namespace std;

/* -------------------------------------------------------------------------- */
/*            Déclarations des sous-programmes utilisés dans main()           */
/* -------------------------------------------------------------------------- */

void testTriBulle_entiers();
// BUT : test du triBulle croissant d'un tableau d'entiers

void testTriBulle_entiersAcces();
// BUT : test du triBulle croissant d'un tableau d'entiers affichant
//       aussi le nombre d'accès aux tableaux & le nombre de comparaisons.

void testTriBulle_personnes();
// BUT : test du triBulle croissant selon le champ .nom d'un tableau de Personnes

void testTriParInsertion_entiers();
// BUT : test du tri par Insertion croissant d'un tableau d'entiers

void testTriParInsertion_personnes();
// BUT : test du tri par Insertion croissant d'un tableau d'entiers

void testTriParSelectionDePlace_entiers();
// BUT : test du tri par Sélection de place croissant d'un tableau d'entiers

void testTriParSelectionDePlace_personnes();
// BUT : test du tri par Sélection de place croissant d'un tableau d'entiers

void testTriParSelectionDePlace_entiers_Acces();
// BUT : test du tri par Sélection de place croissant d'un tableau d'entiers
//       affichant aussi le nombre d'accès aux tableaux & le nombre de comparaisons.

void testTrifusionPersonnes ();
// BUT : Affiche les deux tableaux non triés puis le tableau triFusion trié
//       par ordre croissant de nom.

void testTrifusionEntiers ();
// BUT : Affiche les deux tableaux non triés puis le tableau triFusion trié
//       par ordre croissant de nom.


/* -------------------------------------------------------------------------- */
/*                             PROGRAMME PRINCIPAL                            */
/* -------------------------------------------------------------------------- */
int main()
{
    //testTriBulle_entiers();
    //testTriBulle_entiersAcces();
    //testTriBulle_personnes();
    //testTriParInsertion_entiers();
    //testTriParInsertion_personnes();
    //testTriParSelectionDePlace_entiers();
    //testTriParSelectionDePlace_personnes();
    //testTriParSelectionDePlace_entiers_Acces();
    //testTrifusionPersonnes ();
    //testTrifusionEntiers ();
    return 0;
}

/* -------------------------------------------------------------------------- */
/*               Corps des sous-programmes utilisés dans main()               */
/* -------------------------------------------------------------------------- */

void testTriBulle_entiers()
{
    const unsigned int TAILLE = 10 ; // Taille des tableaux

    int tableau1 [TAILLE] = {7, -6, 8, 10, 2, -3, 6, 9, 0, 2}; // non trié au hasard
    int tableau2 [TAILLE] = {-6, -3, 0, 2, 2, 6, 7, 8, 9, 10}; // déjà trié croissant
    int tableau3 [TAILLE] = {10, 9, 8, 7, 6, 2, 2, 0, -3, -6}; //trié à l'envers (= décroissant)
    int tableau4 [TAILLE] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8};    //constant

    cout << " ------------------   TRI BULLE croissant - tableau d'ENTIERS --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau1, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau1, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << endl;

    // ---------tableau 2
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau2, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau2, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau2, TAILLE);
    cout << endl;

    // ---------tableau 3
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau3, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau3, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau3, TAILLE);
    cout << endl;

    // ---------tableau 4
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau4, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau4, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau4, TAILLE);
    cout << endl;

    // ---------tableau VIDE
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau4, 0);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau4,0) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau4, 0);
    cout << endl;
}

void testTriBulle_entiersAcces()
{
    const unsigned int TAILLE = 10 ; //Taille des tableaux

    int tableau1 [TAILLE] = {7, -6, 8, 10, 2, -3, 6, 9, 0, 2}; // non trié au hasard
    int tableau2 [TAILLE] = {-6, -3, 0, 2, 2, 6, 7, 8, 9, 10}; // déjà trié croissant
    int tableau3 [TAILLE] = {10, 9, 8, 7, 6, 2, 2, 0, -3, -6}; //trié à l'envers (= décroissant)
    int tableau4 [TAILLE] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8};    //constant

    unsigned int compteurAcces;
    unsigned int comparaison;
    cout << " ------------------   TRI BULLE croissant - tableau d'ENTIERS --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau1, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau1, TAILLE, compteurAcces, comparaison) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << "Nombre d'accès au tableau = " << compteurAcces << endl;
    cout << "Nombre de comparaisons = " << comparaison << endl << endl;

    // ---------tableau 2
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau2, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau2, TAILLE, compteurAcces, comparaison) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau2, TAILLE);
    cout << "Nombre d'accès au tableau = " << compteurAcces << endl;
    cout << "Nombre de comparaisons = " << comparaison << endl << endl;

    // ---------tableau 3
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau3, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau3, TAILLE, compteurAcces, comparaison) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau3, TAILLE);
    cout << "Nombre d'accès au tableau = " << compteurAcces << endl;
    cout << "Nombre de comparaisons = " << comparaison << endl << endl;

    // ---------tableau 4
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau4, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau4, TAILLE, compteurAcces, comparaison) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau4, TAILLE);
    cout << "Nombre d'accès au tableau = " << compteurAcces << endl;
    cout << "Nombre de comparaisons = " << comparaison << endl << endl;

    // ---------tableau VIDE
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau4, 0);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau4,0, compteurAcces, comparaison);
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau4, 0);
    cout << "Nombre d'accès au tableau = " << compteurAcces << endl;
    cout << "Nombre de comparaisons = " << comparaison << endl << endl;
}

void testTriBulle_personnes()
{
    const unsigned short int TAILLE = 10; // Taille des tableaux
    Personne tableau1[TAILLE] =   {                                             // à l'envers
        {"Voisin", "Sophie", {"12", "rue des arenes",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Marquesuzaa", "Christophe", {"8", "avenue d'Anglet",64600, "Anglet"}},
        {"Lopisteguy", "Philippe", {"1", "avenue d'Anglet",64600, "Anglet"}},
        {"Etcheverry", "Patrick", {"2bis", "allee des alouettes",64100, "Bayonne"}},
        {"Dijon-Duboue", "Simone", {"5", "rue des roses",64600, "Anglet"}},
        {"Dagorret", "Pantxika", {"10", "chemin des bois",64250, "Itxassou"}},
        {"Corbineau", "Sandrine", {"23", "allee des fleurs",64100, "Bayonne"}},
        {"Bruyere", "Marie", {"4", "rue de la musique",64240, "Hasparren"}},                               
        {"Alami", "Chakib", {"41", "allee de la patisserie",64250, "Itxassou"}}
        }; 

    Personne tableau2[TAILLE] =   {                                                 // en désordre quelconque, avec doublons
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Alami", "Chakib", {"41", "allee de la patisserie",64250, "Itxassou"}},
        {"Marquesuzaa", "Philippe", {"1", "avenue d'Anglet",64600, "Anglet"}},
        {"Marquesuzaa", "Christophe", {"8", "avenue d'Anglet",64600, "Anglet"}},       
        {"Marquesuzaa", "Patrick", {"2bis", "allee des alouettes",64100, "Bayonne"}},
        {"Dijon-Duboue", "Simone", {"5", "rue des roses",64600, "Anglet"}},
        {"Dagorret", "Pantxika", {"10", "chemin des bois",64250, "Itxassou"}},
        {"Corbineau", "Sandrine", {"23", "allee des fleurs",64100, "Bayonne"}},
        {"Voisin", "Sophie", {"12", "rue des arenes",64240, "Hasparren"}},        
        {"Bruyere", "Marie", {"4", "rue de la musique",64240, "Hasparren"}}                              
        };                                                                              // remarquer l'ordre des 3 Marquesuzaa

    cout << " ------------------   TRI BULLE croissant - tableau de PERSONNES --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau1, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau1, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << endl;

    // ---------tableau 2
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau2, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau2, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau2, TAILLE);
    cout << endl;

    // le tri Bulle est stable : 
    // - AVANT le tri, les 3 Marquesuzaa etaient dans un certain ordre : Philippe, Christophe, Christophe
    // - APRES le tri, les 3 Marquesuzaa sont dans le même ordre --> le triBulle respecte l'ordre initial des doublons 
}

void testTriParInsertion_entiers()
{
    const unsigned int TAILLE = 10 ; // Taille des tableaux

   int tableau1 [TAILLE] = {7, -6, 8, 10, 2, -3, 6, 9, 0, 2}; // non trié au hasard
   int tableau2 [TAILLE] = {-6, -3, 0, 2, 2, 6, 7, 8, 9, 10}; // déjà trié croissant
   int tableau3 [TAILLE] = {10, 9, 8, 7, 6, 2, 2, 0, -3, -6}; //trié à l'envers (= décroissant)
   int tableau4 [TAILLE] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8};    //constant

    cout << " ------------------   TRI par INSERTION croissant - tableau d'ENTIERS --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri par INSERTION croissant, tableau = ";
    afficher (tableau1, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParInsertion(tableau1, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par INSERTION croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << endl;

    // ---------tableau 2
    // afficher monTab avant le tri
    cout << "Avant tri par INSERTION croissant, tableau = ";
    afficher (tableau2, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParInsertion(tableau2, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par INSERTION croissant, tableau = " ;
    afficher (tableau2, TAILLE);
    cout << endl;

    // ---------tableau 3
    // afficher monTab avant le tri
    cout << "Avant tri par INSERTION croissant, tableau = ";
    afficher (tableau3, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParInsertion(tableau3, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par INSERTION croissant, tableau = " ;
    afficher (tableau3, TAILLE);
    cout << endl;

    // ---------tableau 4
    // afficher monTab avant le tri
    cout << "Avant tri par INSERTION croissant, tableau = ";
    afficher (tableau4, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParInsertion(tableau4, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par INSERTION croissant, tableau = " ;
    afficher (tableau4, TAILLE);
    cout << endl;

    // ---------tableau VIDE
    // afficher monTab avant le tri
    cout << "Avant tri par INSERTION croissant, tableau = ";
    afficher (tableau4, 0);
    // monTab1, TAILLE >> triBulle >> monTab
    triParInsertion(tableau4,0) ;
    // afficher monTab après le tri
    cout << "Apres tri par INSERTION croissant, tableau = " ;
    afficher (tableau4, 0);
    cout << endl;

}

void testTriParInsertion_personnes()
{
    const unsigned short int TAILLE = 10;  //Taille des tableaux
    Personne tableau1[TAILLE] =   {                                                 // en désordre quelconque
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Alami", "Chakib", {"41", "allee de la patisserie",64250, "Itxassou"}},
        {"Marquesuzaa", "Philippe", {"1", "avenue d'Anglet",64600, "Anglet"}},
        {"Marquesuzaa", "Christophe", {"8", "avenue d'Anglet",64600, "Anglet"}},       
        {"Marquesuzaa", "Patrick", {"2bis", "allee des alouettes",64100, "Bayonne"}},
        {"Dijon-Duboue", "Simone", {"5", "rue des roses",64600, "Anglet"}},
        {"Dagorret", "Pantxika", {"10", "chemin des bois",64250, "Itxassou"}},
        {"Corbineau", "Sandrine", {"23", "allee des fleurs",64100, "Bayonne"}},
        {"Voisin", "Sophie", {"12", "rue des arenes",64240, "Hasparren"}},        
        {"Bruyere", "Marie", {"4", "rue de la musique",64240, "Hasparren"}}                              
        };

    Personne tableau2[TAILLE] =   {                                             // déjà trié croissant                          
        {"Alami", "Chakib", {"41", "allee de la patisserie",64250, "Itxassou"}},
        {"Bruyere", "Marie", {"4", "rue de la musique",64240, "Hasparren"}},
        {"Corbineau", "Sandrine", {"23", "allee des fleurs",64100, "Bayonne"}},
        {"Dagorret", "Pantxika", {"10", "chemin des bois",64250, "Itxassou"}},
        {"Dijon-Duboue", "Simone", {"5", "rue des roses",64600, "Anglet"}},
        {"Etcheverry", "Patrick", {"2bis", "allee des alouettes",64100, "Bayonne"}},
        {"Lopisteguy", "Philippe", {"1", "avenue d'Anglet",64600, "Anglet"}},
        {"Marquesuzaa", "Christophe", {"8", "avenue d'Anglet",64600, "Anglet"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Voisin", "Sophie", {"12", "rue des arenes",64240, "Hasparren"}}
        }; 

    Personne tableau3[TAILLE] =   {                                             // à l'envers
        {"Voisin", "Sophie", {"12", "rue des arenes",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Marquesuzaa", "Christophe", {"8", "avenue d'Anglet",64600, "Anglet"}},
        {"Lopisteguy", "Philippe", {"1", "avenue d'Anglet",64600, "Anglet"}},
        {"Etcheverry", "Patrick", {"2bis", "allee des alouettes",64100, "Bayonne"}},
        {"Dijon-Duboue", "Simone", {"5", "rue des roses",64600, "Anglet"}},
        {"Dagorret", "Pantxika", {"10", "chemin des bois",64250, "Itxassou"}},
        {"Corbineau", "Sandrine", {"23", "allee des fleurs",64100, "Bayonne"}},
        {"Bruyere", "Marie", {"4", "rue de la musique",64240, "Hasparren"}},                               
        {"Alami", "Chakib", {"41", "allee de la patisserie",64250, "Itxassou"}}
        }; 

    Personne tableau4[TAILLE] =   {                                                 // constant
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},                             
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}}
        };                                                                              // remarquer l'ordre des 3 Marquesuzaa

    cout << " ------------------   TRI par INSERTION croissant - tableau d'ENTIERS --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri par INSERTION croissant, tableau = ";
    afficher (tableau1, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParInsertion(tableau1, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par INSERTION croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << endl;

    // ---------tableau 2
    // afficher monTab avant le tri
    cout << "Avant tri par INSERTION croissant, tableau = ";
    afficher (tableau2, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParInsertion(tableau2, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par INSERTION croissant, tableau = " ;
    afficher (tableau2, TAILLE);
    cout << endl;

    // ---------tableau 3
    // afficher monTab avant le tri
    cout << "Avant tri par INSERTION croissant, tableau = ";
    afficher (tableau3, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParInsertion(tableau3, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par INSERTION croissant, tableau = " ;
    afficher (tableau3, TAILLE);
    cout << endl;

    // ---------tableau 4
    // afficher monTab avant le tri
    cout << "Avant tri par INSERTION croissant, tableau = ";
    afficher (tableau4, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParInsertion(tableau4, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par INSERTION croissant, tableau = " ;
    afficher (tableau4, TAILLE);
    cout << endl;

    // ---------tableau VIDE
    // afficher monTab avant le tri
    cout << "Avant tri par INSERTION croissant, tableau = ";
    afficher (tableau4, 0);
    // monTab1, TAILLE >> triBulle >> monTab
    triParInsertion(tableau4,0) ;
    // afficher monTab après le tri
    cout << "Apres tri par INSERTION croissant, tableau = " ;
    afficher (tableau4, 0);
    cout << endl;

}

void testTriParSelectionDePlace_entiers()
{
    const unsigned int TAILLE = 10 ;  //Taille des tableaux

    int tableau1 [TAILLE] = {7, -6, 8, 10, 2, -3, 6, 9, 0, 2}; // non trié au hasard
    int tableau2 [TAILLE] = {-6, -3, 0, 2, 2, 6, 7, 8, 9, 10}; // déjà trié croissant
    int tableau3 [TAILLE] = {10, 9, 8, 7, 6, 2, 2, 0, -3, -6}; //trié à l'envers (= décroissant)
    int tableau4 [TAILLE] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8};    //constant

    cout << " ------------------   TRI par SELECTION de PLACE croissant - tableau d'ENTIERS --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau1, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau1, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << endl;

    // ---------tableau 2
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau2, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau2, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE  croissant, tableau = " ;
    afficher (tableau2, TAILLE);
    cout << endl;

    // ---------tableau 3
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau3, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau3, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau3, TAILLE);
    cout << endl;

    // ---------tableau 4
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau4, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau4, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau4, TAILLE);
    cout << endl;

    // ---------tableau VIDE
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau4, 0);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau4,0) ;
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau4, 0);
    cout << endl;
}

void testTriParSelectionDePlace_personnes()
{
    const unsigned short int TAILLE = 10;  //Taille des tableaux
    Personne tableau1[TAILLE] =   {                                                 // en désordre quelconque
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Alami", "Chakib", {"41", "allee de la patisserie",64250, "Itxassou"}},
        {"Marquesuzaa", "Philippe", {"1", "avenue d'Anglet",64600, "Anglet"}},
        {"Marquesuzaa", "Christophe", {"8", "avenue d'Anglet",64600, "Anglet"}},       
        {"Marquesuzaa", "Patrick", {"2bis", "allee des alouettes",64100, "Bayonne"}},
        {"Dijon-Duboue", "Simone", {"5", "rue des roses",64600, "Anglet"}},
        {"Dagorret", "Pantxika", {"10", "chemin des bois",64250, "Itxassou"}},
        {"Corbineau", "Sandrine", {"23", "allee des fleurs",64100, "Bayonne"}},
        {"Voisin", "Sophie", {"12", "rue des arenes",64240, "Hasparren"}},        
        {"Bruyere", "Marie", {"4", "rue de la musique",64240, "Hasparren"}}                              
        };

    Personne tableau2[TAILLE] =   {                                             // déjà trié croissant                          
        {"Alami", "Chakib", {"41", "allee de la patisserie",64250, "Itxassou"}},
        {"Bruyere", "Marie", {"4", "rue de la musique",64240, "Hasparren"}},
        {"Corbineau", "Sandrine", {"23", "allee des fleurs",64100, "Bayonne"}},
        {"Dagorret", "Pantxika", {"10", "chemin des bois",64250, "Itxassou"}},
        {"Dijon-Duboue", "Simone", {"5", "rue des roses",64600, "Anglet"}},
        {"Etcheverry", "Patrick", {"2bis", "allee des alouettes",64100, "Bayonne"}},
        {"Lopisteguy", "Philippe", {"1", "avenue d'Anglet",64600, "Anglet"}},
        {"Marquesuzaa", "Christophe", {"8", "avenue d'Anglet",64600, "Anglet"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Voisin", "Sophie", {"12", "rue des arenes",64240, "Hasparren"}}
        }; 

    Personne tableau3[TAILLE] =   {                                             // à l'envers
        {"Voisin", "Sophie", {"12", "rue des arenes",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Marquesuzaa", "Christophe", {"8", "avenue d'Anglet",64600, "Anglet"}},
        {"Lopisteguy", "Philippe", {"1", "avenue d'Anglet",64600, "Anglet"}},
        {"Etcheverry", "Patrick", {"2bis", "allee des alouettes",64100, "Bayonne"}},
        {"Dijon-Duboue", "Simone", {"5", "rue des roses",64600, "Anglet"}},
        {"Dagorret", "Pantxika", {"10", "chemin des bois",64250, "Itxassou"}},
        {"Corbineau", "Sandrine", {"23", "allee des fleurs",64100, "Bayonne"}},
        {"Bruyere", "Marie", {"4", "rue de la musique",64240, "Hasparren"}},                               
        {"Alami", "Chakib", {"41", "allee de la patisserie",64250, "Itxassou"}}
        }; 

    Personne tableau4[TAILLE] =   {                                                 // constant
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},                             
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}},
        {"Urruty", "Damien", {"6", "rue des lilas",64240, "Hasparren"}}
        };                                                                              // remarquer l'ordre des 3 Marquesuzaa

    cout << " ------------------   TRI par SELECTION de PLACE croissant - tableau d'ENTIERS --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau1, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau1, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << endl;

    // ---------tableau 2
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau2, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau2, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE  croissant, tableau = " ;
    afficher (tableau2, TAILLE);
    cout << endl;

    // ---------tableau 3
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau3, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau3, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau3, TAILLE);
    cout << endl;

    // ---------tableau 4
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau4, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau4, TAILLE) ;
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau4, TAILLE);
    cout << endl;

    // ---------tableau VIDE
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau4, 0);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau4,0) ;
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau4, 0);
    cout << endl;
}

void testTriParSelectionDePlace_entiers_Acces()
{
    const unsigned int TAILLE = 10 ;    // Taille des tableaux

    int tableau1 [TAILLE] = {7, -6, 8, 10, 2, -3, 6, 9, 0, 2}; // non trié au hasard
    int tableau2 [TAILLE] = {-6, -3, 0, 2, 2, 6, 7, 8, 9, 10}; // déjà trié croissant
    int tableau3 [TAILLE] = {10, 9, 8, 7, 6, 2, 2, 0, -3, -6}; //trié à l'envers (= décroissant)
    int tableau4 [TAILLE] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8};    //constant

    unsigned int compteurAcces;
    unsigned int comparaison;

    cout << " ------------------   TRI par SELECTION de PLACE croissant - tableau d'ENTIERS --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau1, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau1, TAILLE, compteurAcces, comparaison);
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << "Nombre d'accès au tableau = " << compteurAcces << endl;
    cout << "Nombre de comparaisons = " << comparaison << endl << endl;

    // ---------tableau 2
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau2, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau1, TAILLE, compteurAcces, comparaison);
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE  croissant, tableau = " ;
    afficher (tableau2, TAILLE);
    cout << "Nombre d'accès au tableau = " << compteurAcces << endl;
    cout << "Nombre de comparaisons = " << comparaison << endl << endl;

    // ---------tableau 3
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau3, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau1, TAILLE, compteurAcces, comparaison);
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau3, TAILLE);
    cout << "Nombre d'accès au tableau = " << compteurAcces << endl;
    cout << "Nombre de comparaisons = " << comparaison << endl << endl;

    // ---------tableau 4
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau4, TAILLE);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau1, TAILLE, compteurAcces, comparaison);
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau4, TAILLE);
    cout << "Nombre d'accès au tableau = " << compteurAcces << endl;
    cout << "Nombre de comparaisons = " << comparaison << endl << endl;

    // ---------tableau VIDE
    // afficher monTab avant le tri
    cout << "Avant tri par SELECTION de PLACE croissant, tableau = ";
    afficher (tableau4, 0);
    // monTab1, TAILLE >> triBulle >> monTab
    triParSelectionDePlace(tableau1, TAILLE, compteurAcces, comparaison);
    // afficher monTab après le tri
    cout << "Apres tri par SELECTION de PLACE croissant, tableau = " ;
    afficher (tableau4, 0);
    cout << "Nombre d'accès au tableau = " << compteurAcces << endl;
    cout << "Nombre de comparaisons = " << comparaison << endl << endl;
}

void testTrifusionPersonnes ()
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    const unsigned int NB_CASES1 = 6; // Nombre d'étudiants du tp1
    Etudiant tp1[NB_CASES1] = {
    {"AUBRY", "Loïc", 1},
    {"BACONNIER", "Anaïs", 1},
    {"BOISSE", "Lucas", 1},
    {"DAUBA", "Roxanne", 1},
    {"FAGET", "Corentin", 1},
    {"ZINANE", "Ayoub", 1}
    }; // Tableau contenant les étudiants du tp1

    const unsigned int NB_CASES2 = 7; // Nombre d'étudiants du tp2
    Etudiant tp2[NB_CASES2] = {
    {"BOSCALS", "Tanguy", 2},
    {"CHINGNAGUET", "Adrien", 2},
    {"FLEURY", "Baptiste", 2},
    {"FLEURY", "Michon", 2},
    {"FLEURY", "Arnaud", 2},
    {"LE ROY", "Gabriel", 2},
    {"LEVELU", "Pierre", 2}
    }; // Tableau contenant les étudiants du tp2

    const unsigned int NB_CASES = NB_CASES1 + NB_CASES2; // Nombre de cases du tableau fusion
    Etudiant tabFusion[NB_CASES]; // Le tableau contenant les etudiants tp1 & tp2 classés par ordre croissant de nom

    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */

    /* ------------------ Affichage du tableau tp1 avant le tri ----------------- */
    cout << "-------------------------Avant le triFusion-------------------------" << endl << endl;
    cout << "Tableau des étudiants du tp1 : " << endl << endl;
    for (int i = 0; i <= NB_CASES1-1 ; i++)
    {
        cout << tp1[i].nom << " " << tp1[i].prenom << " " << tp1[i].groupeTP << "." << endl;
    }
    cout << endl;
    /* ------------------ Affichage du tableau tp2 avant le tri ----------------- */
    cout << "Tableau des étudiants du tp1 : " << endl << endl;
    for (int i = 0; i <= NB_CASES2-1 ; i++)
    {
        cout << tp2[i].nom << " " << tp2[i].prenom << " " << tp2[i].groupeTP << "." << endl;
    }
    /* --------------------- Appel du la procédure triFusion -------------------- */
    triFusion(tp1, NB_CASES1, tp2, NB_CASES2, tabFusion);
    cout << endl << "-------------------------Après le triFusion-------------------------" << endl << endl;
    /* --------------------- Affichage du tableau triFusion --------------------- */
    for (int i = 0; i <= NB_CASES-1 ; i++)
    {
        cout << tabFusion[i].nom << " " << tabFusion[i].prenom << " " << tabFusion[i].groupeTP << "." << endl;
    }
}

void testTrifusionEntiers ()
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    const unsigned int NB_CASES1 = 6; // Nombre d'étudiants du tp1
    int tableau1[NB_CASES1] = {0, 3, 5, 7, 9, 10}; // Tableau contenant les étudiants du tp1

    const unsigned int NB_CASES2 = 5; // Nombre d'étudiants du tp2
    int tableau2[NB_CASES2] = {1, 2, 4, 6, 11}; // Tableau contenant les étudiants du tp2

    const unsigned int NB_CASES = NB_CASES1 + NB_CASES2; // Nombre de cases du tableau fusion
    int tabFusion[NB_CASES]; // Le tableau contenant les etudiants tp1 & tp2 classés par ordre croissant de nom

    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */

    /* ------------------ Affichage du tableau tp1 avant le tri ----------------- */
    cout << "-------------------------Avant le triFusion-------------------------" << endl << endl;
    cout << "Tableau 1 : " << endl << endl;
    for (int i = 0; i <= NB_CASES1-1 ; i++)
    {
        cout << tableau1[i] << " " << endl;
    }
    cout << endl;
    /* ------------------ Affichage du tableau tp2 avant le tri ----------------- */
    cout << "Tableau 2 : " << endl << endl;
    for (int i = 0; i <= NB_CASES2-1 ; i++)
    {
        cout << tableau2[i] << " " << endl;
    }
    /* --------------------- Appel du la procédure triFusion -------------------- */
    triFusion(tableau1, NB_CASES1, tableau2, NB_CASES2, tabFusion);
    cout << endl << "-------------------------Après le triFusion-------------------------" << endl << endl;
    /* --------------------- Affichage du tableau triFusion --------------------- */
    for (int i = 0; i <= NB_CASES-1 ; i++)
    {
        cout << tabFusion[i] << " " << endl;
    }
}