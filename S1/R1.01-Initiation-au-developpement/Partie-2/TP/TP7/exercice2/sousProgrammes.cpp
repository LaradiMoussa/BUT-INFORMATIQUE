#include <iostream>
#include "sousProgrammes.h"
#include "fichierTexte.h"
using namespace std;

void produireMoyenne (string nomSysFic)
{
    /* -------------------------------------------------------------------------- */
    /*                                DECLARATIONS                                */
    /* -------------------------------------------------------------------------- */
    UnFichierTexte monFichier; // Le fichier à analyser
    bool fdf; // Indicateur de fin de fichier
    string val; // Le mot parcouru
    int nombre; // Le mot converti en nombre
    unsigned int somme; // La somme des valeurs
    float moyenne; // La moyenne finale
    unsigned int compteur; // Compteur du nombre de valeur
    string verif;
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */

    /* ------------------------------- Initialiser ------------------------------ */
    somme = 0;
    compteur = 0;

    /* --------------------------- Associer et ouvrir --------------------------- */
    associer(monFichier, nomSysFic);
    ouvrir(monFichier, consultation);

    /* ---------------------- Somme des nombres du fichier ---------------------- */
    while (true)
    {
        /* ------------------------------- Lire le mot ------------------------------ */
        lireMot(monFichier, val, fdf);
        /* ------------------------ Quitter si fin de fichier ----------------------- */
        if(fdf)
        {
            break;
        }
        
        if(val[0]=='1'||val[0]=='2'||val[0]=='3'||val[0]=='4'||val[0]=='5'||val[0]=='6'||val[0]=='7'||val[0]=='8'||val[0]=='9')
        {
            nombre = atoi(val.c_str());
            
            /* ---------------------------- Somme des valeurs --------------------------- */
            somme += nombre;
            compteur++;
            cout << "somme : " << somme << endl;
            cout << "compteur : " << compteur << endl;
        }
    }

    /* -------------------------- Calcul de la moyenne -------------------------- */

    if ( compteur > 0 )
    {
        moyenne = float(somme) / float(compteur);
    }

    /* ---------------------------- Fermeture fichier --------------------------- */
    fermer(monFichier);

    /* -------------------------- Affichage du résultat ------------------------- */
    if (compteur > 0)
    {
        cout << "La moyenne des valeurs de ce fichier est : " << moyenne;
    }
    else
    {
        cout << " pas de moyenne, fichier vide !";
    }
}
