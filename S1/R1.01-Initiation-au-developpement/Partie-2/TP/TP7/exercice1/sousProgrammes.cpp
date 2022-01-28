#include "sousProgrammes.h"
#include "fichierTexte.h"
#include "pile.h"
#include <iostream>
using namespace std;

void afficherFichierTexte(string nomSysFic)
{
      /* -------------------------------------------------------------------------- */
      /*                                 DECLARATION                                */
      /* -------------------------------------------------------------------------- */
      UnFichierTexte monFichier; // Le fichier texte
      bool fdf; // Indicateur de fin de fichier
      string maChaine; // La chaine à afficher

      /* -------------------------------------------------------------------------- */
      /*                                 TRAITEMENTS                                */
      /* -------------------------------------------------------------------------- */
      // association et ouverture du fichier
      associer(monFichier, nomSysFic);
      ouvrir(monFichier, consultation);

      // Parcours complet pour consultation
      while (true){
            // tentative de lecture
            lireLigne(monFichier, maChaine, fdf);
            if (fdf)
            {
                  break;
            }
            // traitement si pas d'erreur de lecture
            cout << maChaine << endl;
      }
      fermer(monFichier);
}

void afficherInverseFichierTexte(string nomSysFic)
{
      /* -------------------------------------------------------------------------- */
      /*                                 DECLARATION                                */
      /* -------------------------------------------------------------------------- */
      UnFichierTexte monFichierSource; // Le fichier texte source
      bool fdf; // Indicateur de fin de fichier
      string maChaine; // La chaine à afficher
      unsigned int compteurLigne; // Compte le nombre de lignes
      UnePile pile; // La pile qui sert à inverser

      /* -------------------------------------------------------------------------- */
      /*                                 TRAITEMENTS                                */
      /* -------------------------------------------------------------------------- */

      /* ----------------------------- INITIALISATION ----------------------------- */
      compteurLigne = 0;

      /* ------------- Association, création & ouverture des fichiers ------------- */
      associer(monFichierSource, nomSysFic);
      ouvrir(monFichierSource, consultation);

      /* ------------------- Parcours complet pour consultation ------------------- */
      while (true)
      {
            lireLigne(monFichierSource, maChaine, fdf);
            if(fdf)
            {
                  break;
            }
            empiler(pile, maChaine);
            compteurLigne++;
      }

      /* --------------------- Parcours complet pour affichage -------------------- */
      for (unsigned int i = 0; i<=compteurLigne-1; i++)
      {
            depiler(pile, maChaine);
            cout << maChaine << endl;
      }

      /* --------------------------- Fermer les fichiers -------------------------- */
      fermer(monFichierSource);
}

void etendreFichierTexte (string nomSysFicSource, string nomSysFicCible)
{
      /* -------------------------------------------------------------------------- */
      /*                                 DECLARATION                                */
      /* -------------------------------------------------------------------------- */
      UnFichierTexte monFichierSource; // Le fichier texte source
      UnFichierTexte monFichierCible; // Le fichier texte cible
      bool fdf; // Indicateur de fin de fichier
      string maChaine; // La chaine à afficher

      /* -------------------------------------------------------------------------- */
      /*                                 TRAITEMENTS                                */
      /* -------------------------------------------------------------------------- */
      // association et ouverture du fichier
      associer(monFichierSource, nomSysFicSource);
      ouvrir(monFichierSource, consultation);
      associer(monFichierCible, nomSysFicCible);
      ouvrir(monFichierCible, extension);
      // Parcours séquentiel complet pour consultation
      while (true){
            // tentative de lecture
            lireLigne(monFichierSource, maChaine, fdf);
            if (fdf){
                  break;
            }
            // traitement si pas d'erreur de lecture
            ecrire(monFichierCible, maChaine);
      }

      /* --------------------------- Fermer les fichiers -------------------------- */
      fermer(monFichierSource);
      fermer(monFichierCible);
}

void viderFichierTexte(string nomSysFic)
{
      /* -------------------------------------------------------------------------- */
      /*                                DECLARATIONS                                */
      /* -------------------------------------------------------------------------- */
      UnFichierTexte monFichier; // Le fichier à supprimer

      /* -------------------------------------------------------------------------- */
      /*                                 TRAITEMENTS                                */
      /* -------------------------------------------------------------------------- */

      /* --------------------- Création du fichier de même nom -------------------- */
      associer(monFichier, nomSysFic);
      ouvrir(monFichier, creation);
      fermer(monFichier);
}