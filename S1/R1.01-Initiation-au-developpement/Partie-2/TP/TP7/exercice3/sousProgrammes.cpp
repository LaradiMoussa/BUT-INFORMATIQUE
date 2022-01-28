#include <iostream>
#include "sousProgrammes.h"
#include "fichierTexte.h"

using namespace std;

// Sous-programmes utilisés par les sous-programmes de cryptage
// ---------------------------------------------------------------------
string genererNom(string nom);
/* retourne un nouveau nom de fichier contenant --> _crypted
   cas de figure :
   nom    -->  nouveauNom généré     : motif
   .           .                     : nom de fichier illégal, la fonction retourne le paramètre initial donné
   .h          .h_crypted            : le point est ici unla marque d'un fichier caché, "_crypted" est donc ajouté  
                                       en fin de nom pour que le nouveau nom de fichier soit aussi un nom de fichier caché
   x.          x._crypted            : pas de suffixe après la point, "_crypted" ajouté en fin de nom
   x           x_crypted             : pas de suffixe, "_crypted" ajouté en fin de nom
   x.h         x_crypted.h           : "_crypted" inséré avant le point de suffixe
   x.js        x_crypted.js          : "_crypted" inséré avant le point de suffixe
   x.cpp       x_crypted.cpp         : "_crypted" inséré avant le point de suffixe
   x.data      x_crypted.data        : "_crypted" inséré avant le point de suffixe
   x.config    x_crypted.config      : "_crypted" inséré avant le point de suffixe
   x.texinfo   x_crypted.texinfo     : "_crypted" inséré avant le point de suffixe
   x.12345678  x.12345678_crypted    : au dela de 7 caractères après le point, on considère
                                       que le point fait partie du nom du fichier et ne marque pas
                                       un suffixe --> "_crypted" ajouté en fin de nom
   ../x.h      ../x_crypted.h
   ../x        ../x_crypted
   ./x.h       ./x_crypted.h
   ./x         ./x_crypted

    sources : https://fr.wikipedia.org/wiki/Extension_de_nom_de_fichier
              https://fr.wikipedia.org/wiki/Liste_d%27extensions_de_fichiers
    
    cas particulier non (ou mal traité) : x.tar.gz --> x.tar_crypted.gz
   */
  // ---------------------------------------------------------------------

string cryptage (string nomSysFicSource)
{
    /* -------------------------------------------------------------------------- */
    /*                                 DECLARATION                                */
    /* -------------------------------------------------------------------------- */
    UnFichierTexte monFichierSource; // Le fichier source
    UnFichierTexte monFichierCible; // Le fichier cible
    string newName; // La nom du nouveau fichier créer
    char caractere; // Le caractere courant
    bool fdfSource; // Indicateur de fin de fichier
    bool lower; // Inidicateur de caractère en minuscule

    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */

    /* --------------------------- Générer nouveau nom -------------------------- */
    newName = genererNom(nomSysFicSource);

    /* --------- Associer et ouvrir le fichier source & le fichier cible -------- */
    associer(monFichierSource, nomSysFicSource);
    associer(monFichierCible, newName);
    ouvrir(monFichierSource, consultation);
    ouvrir(monFichierCible, creation);

    /* -------------------------- Traitement du fichier ------------------------- */
    while (true)
    {
        lireCar(monFichierSource, caractere, fdfSource);
        /* -------------- On regarde si on a atteint la fin du fichier -------------- */
        if(fdfSource)
        {
            break;
        }

        /* -------------------------------- Cryptage -------------------------------- */
        switch (caractere)
        {
        case 'A':
            caractere = 'E';
            break;
        case 'E':
            caractere = 'I';
            break;
        case 'I':
            caractere = 'O';
            break;
        case 'O':
            caractere = 'U';
            break;
        case 'U':
            caractere = 'Y';
            break;
        case 'Y':
            caractere = 'A';
            break;
        case 'a':
            caractere = 'e';
            break;
        case 'e':
            caractere = 'i';
            break;
        case 'i':
            caractere = 'o';
            break;
        case 'o':
            caractere = 'u';
            break;
        case 'u':
            caractere = 'y';
            break;
        case 'y':
            caractere = 'a';
            break;
        }

        /* --------------------- On ecrit dans le fichier cible --------------------- */
        ecrire(monFichierCible, caractere);
    }

    /* --------------------------- Fermer les fichier --------------------------- */
    fermer(monFichierSource);
    fermer(monFichierCible);

    /* -------------------- retourner le nom du fichier créé -------------------- */
    return newName;
}

string cryptage (string nomSysFicSource, string nomSysFicCodes)
{
    /* -------------------------------------------------------------------------- */
    /*                                 DECLARATION                                */
    /* -------------------------------------------------------------------------- */
    UnFichierTexte monFichierSource; // Le fichier source
    UnFichierTexte monFichierCible; // Le fichier cible
    UnFichierTexte monCryptage; // Le fichier de cryptage
    string newName; // La nom du nouveau fichier créer
    char caractere; // Le caractere courant
    char carCrypte; // Le caractere crypte
    string mot; // Element courant de monFichierCryptage
    string motCrypte; // Element crypté correspondant de monFichierCryptage
    bool fdfSource; // Indicateur de fin de fichier
    bool fdfCryptage; // Indicateur de fin de fichier de cryptage
    bool trouve; // Indicateur de reussite de recherche

    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */

    /* --------------------------- Générer nouveau nom -------------------------- */
    newName = genererNom(nomSysFicSource);

    /* --------- Associer et ouvrir le fichier source & le fichier cible -------- */
    associer(monFichierSource, nomSysFicSource);
    associer(monFichierCible, newName);
    associer(monCryptage, nomSysFicCodes);
    ouvrir(monFichierSource, consultation);
    ouvrir(monFichierCible, creation);

    /* -------------------------- Traitement du fichier ------------------------- */
    while (true)
    {
        lireCar(monFichierSource, caractere, fdfSource);
        if(fdfSource)
        {
            break;
        }

        /* -------------------------------- Cryptage -------------------------------- */
        ouvrir(monCryptage, consultation);

        trouve = false;

        //Recherche premiere occ du car dans ficCryptage
        while (true)
        {
            /* ---------------------- Lire le caractere à modifier ---------------------- */
            lireMot(monCryptage, mot, fdfCryptage);

            /* ------------ Si on atteint la fin du fichier, fin de recherche ----------- */
            if(fdfCryptage)
            {
                break;
            }
            /* ----------------- Lire le caractère crypté correspondant ----------------- */
            lireMot(monCryptage, motCrypte, fdfCryptage);

            /* ------ Regarder si le caractère est présent dans le fichier cryptage ----- */
            if(mot[0]==caractere)
            {
                trouve = true;
                carCrypte = motCrypte[0];
                break;
            }
        }
        
        /* ----------- S'il y a une correspondance on change le caractère ----------- */
        if(trouve)
        {
            caractere = carCrypte;
        }

        /* ---------------------- Fermer le fichier de cryptage --------------------- */
        fermer(monCryptage);

        /* --------------------- On ecrit dans le fichier cible --------------------- */
        ecrire(monFichierCible, caractere);
    }

    /* --------------------------- Fermer les fichier --------------------------- */
    fermer(monFichierSource);
    fermer(monFichierCible);

    /* -------------------- retourner le nom du fichier créé -------------------- */
    return newName;
}

// ---------------------------------------------------------------------
// Corps des sous-programmes utilisés par les sous-programmes de cryptage
string genererNom(string nom)
{
    enum UnCas {nomIllegal, ajouterEnFin, insererAvantPoint};
    string nouveauNom = "";
    bool trouvePoint = false;
    bool trouveSlash = false;
    unsigned int posPoint ;  // position du dernier point, s'il en existe dans la chaîne nom
    unsigned int posSlash ;  // position du dernier slash, s'il en existe dans la chaîne nom    
    UnCas cas;

    // nom >> determiner position dernierSlash >> posSlash
     for (unsigned int i = 0; i < nom.length() ; i++)
    {
        if (nom[i] == '/')
        {
            trouveSlash = true;
            posSlash = i;
        }
    }   
    // nom, trouveSlash, [posSlash] >> Déterminer position du dernier point >> trouvé, posPoint
    if (trouveSlash)
    {
        // on cherche le point de suffixe après les caractères indiquant le chemin relatif
       for (unsigned int i = posSlash+1; i < nom.length() ; i++)
        {
            if (nom[i] == '.')
            {
                trouvePoint = true;
                posPoint = i;
            }
        }     
    }
    else 
    {
        // on cherche le point de suffixe dès le début du nom de fichier
        for (unsigned int i = 0; i < nom.length() ; i++)
        {
            if (nom[i] == '.')
            {
                trouvePoint = true;
                posPoint = i;
            }
        }
    }

    // posPoint, mot >> Analyse de la situation >> cas
    if (trouvePoint && (posPoint == 0) && nom.length() == 1)
    {
        // le nom ne contient qu'un point --> mauvais nom de fichier, on ne fait rien
        cas = nomIllegal;
    }
    else if (trouvePoint && (posPoint == 0) && nom.length() > 1)
    {
        // le nom démarre par un point --> c'est un fichier caché, on ajoute _crypted en fin de nom (après le point)
        cas = ajouterEnFin;
    }
    else if (trouvePoint && (posPoint > 0))
    {
        // mot contient au moins un point.
        // le dernier . est considéré comme . de suffixe si la longueur du suffixe est <= 7
        // sinon, le . est considéré comme faisant partie du nom de fichier
        if ( ((nom.length() - posPoint - 1) <= 7) && ((nom.length() - posPoint - 1) >0) )
        {
            cas = insererAvantPoint;
        }
        else 
        {
            cas = ajouterEnFin;
        }
    }
    else    // !trouve
    {
        // pas de point, ajout de la chaîne en fin de nom
        cas = ajouterEnFin;
    }

    // cas, posPoint, nom >> Generer le nouveaunom selon le cas >> nouveauNom
    switch (cas)
    {
        case nomIllegal : nouveauNom = nom;
                          break;
        case ajouterEnFin : nouveauNom = nom + "_crypted";
                            break;
        case insererAvantPoint :
                            // ajouter la partie avant le point
                            for (unsigned int i = 0; i < posPoint; i++)
                            {
                                nouveauNom = nouveauNom + nom[i];
                            }

                            // ajouter le tterme "_crypted" et le point
                            nouveauNom = nouveauNom + "_crypted.";

                            // ajouter la fin
                            for (unsigned int i = posPoint+1; i < nom.length(); i++)
                            {
                                nouveauNom = nouveauNom + nom[i];
                            }
                            break;
    }

    return nouveauNom;
}