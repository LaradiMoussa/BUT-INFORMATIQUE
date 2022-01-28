/**MODULE bibTableaux 
     regroupe des sous-programmes applicables à des tableaux
     -------------------------------------------------------
But :
    Mettre à dispositon d'un programmeur des sous-programmes applicables aux tableaux.
    Conformes aux exercices des TD n°1 et 3 de R1.01
    
    Il peut s'agit de tableaux d'entiers ou d'enregistrements de type Personne.
    Les tableaux manipulés doivent être triés par ordre décroissant de valeur.
    Dans le cas des tableaux d'enregistrements de type Personne, ils seront triés par ordre 
    décroissant de nom.
---------

 Date de dernière modification : 1 décembre 2021
 Auteur : C.NAUDI
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°4
*/
#include "BibTableaux.h"
#include "Personne.h"
#include <iostream>
using namespace std;

/* -------------------------------------------------------------------------- */
/*                                                                            */
/*                       DECLARATION DES SOUS-PROGRAMMES                      */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void faireMonterLaBulleIci(int tab[], unsigned int bDeb, unsigned int& ici);
// BUT : Fait remonter le plus grand élément de la tranche tab(0..ici] à l'indice ici
//       par échanges successifs.

void faireMonterLaBulleIci(Personne tab[], unsigned int bDeb, unsigned int& ici);
// BUT : Fait remonter le plus grand élément de la tranche tab(0..ici] à l'indice ici
//       par échanges successifs.

void faireMonterLaBulleIci (int tab[] , unsigned int bDeb, unsigned int& ici, unsigned int& nbAcces, unsigned int& nbComparaison);
// BUT : Fait remonter le plus grand élément de la tranche tab(0..ici] à l'indice ici
//       par échanges successifs.
//       nbAcces précise le nombre d'accès au tableau réalisés dans le sous-programme.
//       nbComparaison précise le nombre de comparaison réalisés dans le sous-programme.

void echanger(int tab[], unsigned int& x, unsigned int& y);
// BUT : echange le contenu de deux entiers x et y

void echanger(Personne tab[], unsigned int& x, unsigned int& y);
// BUT : echange le contenu de deux personnes d'indice x et y

void echanger(int tab[], unsigned int& x, unsigned int& y, unsigned int& nbAcces);
// BUT : echange le contenu de deux entiers x et y
//       nbAcces précise le nombre d'accès au tableau réalisés dans le sous-programme.

void insertion  (int tab [], unsigned int bDeb, unsigned int ici);
// BUT : étant donnée une portion de tableau tab(bDeb..ici),
//       telle que tab(bDeb..ici -1) est triée par ordre croissant de valeurs,
//       trouve l’indice saPlace du tableau tab compris entre deb et ici, auquel la
//       valeur tab[ici] devra être insérée pour que la portion tab(bDeb..ici) du
//       tableau soit encore triée par ordre croissant

void insertion  (Personne tab [], unsigned int bDeb, unsigned int ici);
// BUT : étant donnée une portion de tableau tab(bDeb..ici),
//       telle que tab(bDeb..ici -1) est triée par ordre croissant de personnes,
//       trouve l’indice saPlace du tableau tab compris entre deb et ici, auquel la
//       valeur tab[ici] devra être insérée pour que la portion tab(bDeb..ici) du
//       tableau soit encore triée par ordre croissant

/* -------------------------------------------------------------------------- */
/*                                                                            */
/*                       DEFINITION DES SOUS-PROGRAMMES                       */
/*                                                                            */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                                                            */
/*                        PRIMITIVES D'ENTRÉES-SORTIES                        */
/*                                                                            */
/* -------------------------------------------------------------------------- */

void afficher (const int tab[], unsigned int lgTab)
{
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    /* ----------------- Si le tableau contient minimum 1 valeur ---------------- */
    if (lgTab > 0)
    {
        cout << "{";
        for (unsigned int i = 0; i<lgTab-1; i++)
        {
            cout << tab[i] << ", " ;

        };
        cout << tab[lgTab-1] << "} "<< endl;
    }
    /* ------------------------- Si le tableau est vide ------------------------- */
    else
    {
        cout << "tableau vide " << endl;
    }
}

void afficher (const Personne tab[], unsigned int lgTab)
{
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    /* ---------------- Si le tableau contient minimum 1 personne --------------- */
    if (lgTab > 0)
    {
        cout << "{" << endl;
        for (unsigned int i = 0; i<lgTab-1; i++)
        {
            afficher(tab[i]) ;
            cout << ", "<< endl ;
        };
        afficher (tab[lgTab-1]);
        cout << endl <<  "} "<< endl;
    }
    /* ------------------------- Si le tableau est vide ------------------------- */
    else
    {
        cout << "tableau vide " << endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                                                                            */
/*                                 RECHERCHES                                 */
/*                                                                            */
/* -------------------------------------------------------------------------- */

void recherchePremiereOccDichoEntier(const int tab[], unsigned int nbCases, int val, bool& trouve, unsigned int& pos)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    unsigned int borneInf; // La borne inférieur dans laquelle la recherche s'effectue
    unsigned int borneSup; // La borne supérieur dans laquelle la recherche s'effectue
    unsigned int milieu; // Le milieu des bornes borneInf & borneSup

    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */

    /* ------------------------ Initialiser les éléments ------------------------ */
    trouve = false;
    borneInf = 0;
    borneSup = nbCases - 1;

    if (nbCases>0)
    {
        /* --------------------------- Faire la recherche --------------------------- */
        while (borneSup >= borneInf)
        {
            /* ------------------------------ Calcul milieu ----------------------------- */
            milieu = ((borneInf + borneSup)/2);
            /* ----------------------------- Valeur trouvée ----------------------------- */
            if (tab[milieu]==val)
            {
                trouve = true;
                pos = milieu;
                break;
            }
            /* -------------------------- Préparer tour suivant ------------------------- */
            if (tab[milieu] > val)
            {   
                borneInf = milieu + 1;
            }
            else
            {
                borneSup = milieu - 1;
            }
        }
    }
    else
    {
        cout << "Le tableau est vide." << endl;
    }
}

void recherchePremiereOccDichoPersonne(const Personne tab[], unsigned int nbTab, string val, bool& trouve, unsigned int& pos)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    unsigned short int borneInf; // La borne inférieur dans laquelle on doit effectuer la recherche
    unsigned short int borneSup; // La borne inférieur dans laquelle on doit effectuer la recherche
    unsigned int milieu; // Le milieu des bornes borneInf & borneSup

    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */

    /* ------------------------ Initialiser les éléments ------------------------ */
    trouve = false;
    borneInf = 0;
    borneSup = nbTab - 1;

    /* ----------- La recherche ne se fait qu'avec des tableau rempli ----------- */
    if (nbTab>0)
    {
        /* --------------------------- Faire la recherche --------------------------- */
        while (borneSup >= borneInf)
        {
            /* ------------------------------ Calcul milieu ----------------------------- */
            milieu = ((borneInf + borneSup)/2);

            /* ----------------------------- Valeur trouvée ----------------------------- */
            if (tab[milieu].nom==val)
            {
                trouve = true;
                pos = milieu;
                break;
            }
            /* -------------------------- Préparer tour suivant ------------------------- */
            if (tab[milieu].nom[0] > val[0])
            {   
                borneInf = milieu + 1;
            }
            else
            {
                borneSup = milieu - 1;
            }
        }
    }
    /* ------------------------- Si le tableau est vide ------------------------- */
    else
    {
        cout << "Le tableau est vide." << endl;
    }
}

void rechercheSequentielleEntier(const int tab[], unsigned int nbCases, int val, bool& trouve, unsigned int& pos)
{
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    /* ----------------- Parcours du tableau élément par élément ---------------- */
    for (int i = 0; i < nbCases; i++)
    {
        /* ------------------------ Si la valeur est trouvée ------------------------ */
        if (tab[i]==val)
        {
            trouve=true;
            pos = i;
            break;
        }
    } 
}

void determinerPremierDernierEntier(const int tab[], unsigned int nbCases, bool& trouve, int& val, unsigned int& premier, unsigned int& dernier)
{
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    /* ----------------------------- Initialisation ----------------------------- */
    trouve = false;

    /* ---------------- Parcours du tableau de manière croissante --------------- */
    for (int i = 0; i < nbCases; i++)
    {
        if (tab[i]==val)
        {
            premier = i;
            trouve = true;
            break;
        }
    }
    /* ----- Parcours du tableau de manière décroissante si trouve est vrai ----- */
    if(trouve)
    {
        for (int i = nbCases-1; i >= 0; i--)
        {
            if (tab[i]==val)
            {
                dernier = i;
                break;
            }
        }
    }
}

void determinerPremierDernierPersonne(const Personne tab[], unsigned int nbTab, bool& trouve, string& nomSaisie, unsigned int& premier, unsigned int& dernier)
{
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */

    /* ----------------------------- Initialisation ----------------------------- */
    trouve = false;

    /* ---------------- Parcours du tableau de manière croissante --------------- */
    for (int i = 0; i < nbTab; i++)
    {
        if (tab[i].nom==nomSaisie)
        {
            premier = i;
            trouve = true;
            break;
        }
    }
    /* ----- Parcours du tableau de manière décroissante si trouve est vrai ----- */
    if(trouve)
    {
        for (int i = nbTab-1; i >= 0; i--)
        {
            if (tab[i].nom==nomSaisie)
            {
                dernier = i;
                break;
            }
        }
    }
}

/* -------------------------------------------------------------------------- */
/*                                                                            */
/*                               TRI DE TABLEAU                               */
/*                                                                            */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                       PROCÉDURES ET FONCTIONS UTILES                       */
/* -------------------------------------------------------------------------- */

void faireMonterLaBulleIci(int tab[], unsigned int bDeb, unsigned int& ici)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    int copieTab; // La copie du nombre contenu dans tab[i] pour effectuer l'échange
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    for (unsigned int i = bDeb; i <= ici-1; i++)
    {
        if (tab[i] > tab[i+1])
        {
            copieTab = tab[i];
            tab[i] = tab[i+1];
            tab[i+1] = copieTab;
        }
    }
}

void faireMonterLaBulleIci(Personne tab[], unsigned int bDeb, unsigned int& ici)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    Personne copieTab; // La copie de la personne pour effectuer l'échange

    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    for (unsigned int i = bDeb; i <= ici-1; i++)
    {
        if (tab[i].nom > tab[i+1].nom)
        {
            copieTab = tab[i];
            tab[i] = tab[i+1];
            tab[i+1] = copieTab;
        }
    }
}

void faireMonterLaBulleIci (int tab[] , unsigned int bDeb, unsigned int& ici, unsigned int& nbAcces, unsigned int& nbComparaison)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    int copieTab; // La copie du nombre contenu dans tab[i] pour effectuer l'échange
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    for (unsigned int i = bDeb; i <= ici-1; i++)
    {
        //nbAcces+=2;
        nbComparaison++;
        if (tab[i] > tab[i+1])
        {
            copieTab = tab[i];
            tab[i] = tab[i+1];
            tab[i+1] = copieTab;
            nbAcces += 4;
        }
    }
}

unsigned int positionDuMax(const int tab[], unsigned int bDeb, unsigned int bFin)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    unsigned int posMax; //La position de l'élément maximum durant le parcours
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    /* ----------------------------- Initialisation ----------------------------- */
    posMax = bDeb;

    /* ------- Recherche de la position du nombre maximum entre les bornes ------ */
    for(int i=bDeb; i<= bFin; i++)
    {
        if(tab[posMax] < tab[i])
        {
            posMax = i;
        }
    }
    /* --------- Retourne la position du l'élément max entre bDeb & bFin -------- */
    return posMax;
}

unsigned int positionDuMax(const Personne tab[], unsigned int bDeb, unsigned int bFin)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    unsigned int posMax; //La position de l'élément maximum durant le parcours
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    /* ----------------------------- Initialisation ----------------------------- */
    posMax = bDeb;

    /* ------- Recherche de la position du nombre maximum entre les bornes ------ */
    for(int i=bDeb; i<= bFin; i++)
    {
        if(tab[posMax].nom < tab[i].nom)
        {
            posMax = i;
        }
    }
    /* --------- Retourne la position du l'élément max entre bDeb & bFin -------- */
    return posMax;
}

void positionDuMax(const int tab[], unsigned int bDeb, unsigned int bFin, unsigned int& pos, unsigned int& nbAcces, unsigned int& nbComparaisons)
{
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    /* ----------------------------- Initialisation ----------------------------- */
    pos = bDeb;

    /* ------- Recherche de la position du nombre maximum entre les bornes ------ */
    for(int i=bDeb; i<= bFin; i++)
    {
        nbComparaisons++;
        nbAcces+=2;
        if(tab[pos] < tab[i])
        {
            pos = i;
        }
    }
}

void echanger(int tab[], unsigned int& x, unsigned int&y)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    int copie; // copie du contenu de tab[x] pour effectuer l'échange
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    copie = tab[x];
    tab[x] = tab[y];
    tab[y] = copie;
}

void echanger(Personne tab[], unsigned int& x, unsigned int&y)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    Personne copie; // copie du contenu de tab[x] pour effectuer l'échange
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    copie = tab[x];
    tab[x] = tab[y];
    tab[y] = copie;
}

void echanger(int tab[], unsigned int& x, unsigned int& y, unsigned int& nbAcces)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    int copie; // copie du contenu de tab[x] pour effectuer l'échange
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    nbAcces+=4;
    copie = tab[x];
    tab[x] = tab[y];
    tab[y] = copie;
}

void insertion(int tab [], unsigned int bDeb, unsigned int ici)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    unsigned int j; //Indice de case courant
    int copieTab; //Copie de la valeur contenue dans tab[ici]
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    /* ----------------------------- Initialisation ----------------------------- */
    copieTab = tab[ici];
    /* ------------- Recherche de l'emplacement où insérer la valeur ------------ */
    for (j = ici; j > 0 && tab[j - 1] > copieTab; j--)
    {
        tab[j] = tab[j - 1];
    }
    /* -------- Copie de la valeur à l'emplacement qu'on le lui a trouvé -------- */
    tab[j] = copieTab;
}

void insertion(Personne tab [], unsigned int bDeb, unsigned int ici)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    unsigned int j; //Indice de case courant
    Personne copieTab; //Copie de la valeur contenue dans tab[ici]
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    /* ----------------------------- Initialisation ----------------------------- */
    copieTab = tab[ici];
    /* ------------- Recherche de l'emplacement où insérer la valeur ------------ */
    for (j = ici; j > 0 && tab[j - 1].nom > copieTab.nom; j--)
    {
        tab[j].nom = tab[j - 1].nom ;
    }
    /* -------- Copie de la valeur à l'emplacement qu'on le lui a trouvé -------- */
    tab[j] = copieTab;
}

/* -------------------------------------------------------------------------- */
/*                             PROCÉDURES DE TRIS                             */
/* -------------------------------------------------------------------------- */

void triBulle(int tab[], unsigned int nbTab)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    unsigned int ici; // Emplacement auquel la valeur doit être traitée
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */

    /* --------------- Si le tableau contient au minimum 1 valeur --------------- */
    if (nbTab > 0)
    {
        for (ici = nbTab-1 ; ici >= 1; ici--)
        {
            faireMonterLaBulleIci(tab, 0, ici);
        }
    }
}

void triBulle(Personne tab[], unsigned int nbTab)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    unsigned int ici; // Emplacement auquel la plus grande valeur doit être insérée

    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */

    /* -------------- Si le tableau contient au minimum 1 personne -------------- */
    if (nbTab > 0)
    {
        for (ici = nbTab-1 ; ici >= 1; ici--)
        {
            faireMonterLaBulleIci(tab, 0, ici);
        }
    }
}

void triBulle(int tab[], unsigned int nbTab, unsigned int& nbAcces, unsigned int& nbComparaison)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    unsigned int ici; // Emplacement auquel la valeur doit être traitée
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    /* ----------------------------- Initialisation ----------------------------- */
    nbAcces = 0;
    nbComparaison = 0;
    
    /* --------------- Si le tableau contient au minimum 1 valeur --------------- */
    if (nbTab > 0)
    {
        for (ici = nbTab-1 ; ici >= 1; ici--)
        {
            faireMonterLaBulleIci(tab, 0, ici, nbAcces, nbComparaison);
        }
    }
}

void triParSelectionDePlace (int tab[], unsigned int nbTab)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    unsigned int ici; // Emplacement auquel la valeur doit être traitée
    unsigned int posMax; //La position de l'élément maximum durant le parcours
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    /* --------------- Si le tableau contient au minimum 1 valeur --------------- */
    if (nbTab > 0)
    {
        for(ici=nbTab-1; ici >= 1; ici--)
        {
            posMax = positionDuMax(tab, 0, ici);
            echanger(tab, posMax, ici);
        }
    }
}

void triParSelectionDePlace (Personne tab[], unsigned int nbTab)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    unsigned int ici; // Emplacement auquel la valeur doit être traitée
    unsigned int posMax; //La position de l'élément maximum durant le parcours
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    /* --------------- Si le tableau contient au minimum 1 valeur --------------- */
    if (nbTab > 0)
    {
        for(ici=nbTab-1; ici >= 1; ici--)
        {
            posMax = positionDuMax(tab, 0, ici);
            echanger(tab, posMax, ici);
        }
    }
}

void triParSelectionDePlace (int tab[], unsigned int nbTab, unsigned int& nbAcces, unsigned int& nbComparaison)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    unsigned int ici; // Emplacement auquel la valeur doit être traitée
    unsigned int posMax; //La position de l'élément maximum durant le parcours
    unsigned int pos; //La position du caractère ayant la valeur maximum dans l'espace de recherche
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    /* ----------------------------- Initialisation ----------------------------- */
    nbAcces = 0;
    nbComparaison = 0;
    /* --------------- Si le tableau contient au minimum 1 valeur --------------- */
    if (nbTab > 0)
    {
        for(ici=nbTab-1; ici >= 1; ici--)
        {
            positionDuMax(tab, 0, ici, pos, nbAcces, nbComparaison);
            echanger(tab, pos, ici, nbAcces);
            afficher (tab, nbTab);
            cout << "nb Acces : " << nbAcces << endl;
            cout << "nb Comp : " << nbComparaison << endl << endl;
        }
    }
}

void triParInsertion(int tab[], unsigned int nbTab)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    unsigned int ici; // Emplacement auquel la valeur doit être traitée
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    /* --------------- Si le tableau contient au minimum 1 valeur --------------- */
    if (nbTab > 0)
    {
        for (ici = 1; ici <= nbTab-1; ici++)
        {
            insertion(tab, 1, ici);
        }
    }
}

void triParInsertion(Personne tab[], unsigned int nbTab)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    unsigned int ici; // Emplacement auquel la valeur doit être traitée
    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */
    /* --------------- Si le tableau contient au minimum 1 valeur --------------- */
    if (nbTab > 0)
    {
        for (ici = 1; ici <= nbTab-1; ici++)
        {
            insertion(tab, 1, ici);
        }
    }
}

void triFusion(const int tableau1[], unsigned int nbTab1, const int tableau2[], unsigned int nbTab2, int tabFusion[])
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    unsigned int indice1; // Indice de parcours de tableau1
    unsigned int indice2; // Indice de parcours de tableau2
    unsigned int indice; // Indice de parcours du tableau triFusion
    /* -------------------------------------------------------------------------- */
    /*                               INITIALISATION                               */
    /* -------------------------------------------------------------------------- */
    indice1 = 0;
    indice2 = 0;
    indice = 0;

    while(!((indice1 == nbTab1) && (indice2 == nbTab2)))
    {
        /* ----------- S'il n'y a plus d'éléments à traiter dans tableau1 ----------- */
        if((indice1==nbTab1)&&(indice2<=nbTab2))
        {
            tabFusion[indice] = tableau2[indice2];
            indice2++;
            indice++;
        }
        /* ----------- S'il n'y a plus d'éléments à traiter dans tableau2 ----------- */
        else if((indice1<=nbTab1)&&(indice2==nbTab2))
        {
            tabFusion[indice] = tableau1[indice1];
            indice1++;
            indice++;
        }
        else
        {
            /* ------- Si le nom de l'élément courant du tableau2 est supérieur à ------- */
            /* ----------------- celui de l'élément courant du tableau1 ----------------- */
            if(tableau1[indice1] < tableau2[indice2])
            {
                tabFusion[indice] = tableau1[indice1];
                indice1++;
                indice++;
            }
            /* ------- Si le nom de l'élément courant du tableau1 est supérieur à ------- */
            /* ----------------- celui de l'élément courant du tableau2 ----------------- */
            else if (tableau1[indice1] > tableau2[indice2])
            {
                tabFusion[indice] = tableau2[indice2];
                indice2++;
                indice++;
            }
            /* --------- Si les deux éléments sont égaux on les ajoute les deux --------- */
            else
            {
                tabFusion[indice] = tableau1[indice1];
                tabFusion[indice] = tableau2[indice2];
                indice1++;
                indice2++;
                indice++;
            }
        }
    }
}

void triFusion(const Etudiant tableau1[], unsigned int nbTab1, const Etudiant tableau2[], unsigned int nbTab2, Etudiant tabFusion[])
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    unsigned int indice1; // Indice de parcours de tableau1
    unsigned int indice2; // Indice de parcours de tableau2
    unsigned int indice; // Indice de parcours du tableau triFusion
    /* -------------------------------------------------------------------------- */
    /*                               INITIALISATION                               */
    /* -------------------------------------------------------------------------- */
    indice1 = 0;
    indice2 = 0;
    indice = 0;

    while(!((indice1 == nbTab1) && (indice2 == nbTab2)))
    {
        /* ----------- S'il n'y a plus d'éléments à traiter dans tableau1 ----------- */
        if((indice1==nbTab1)&&(indice2<=nbTab2))
        {
            tabFusion[indice] = tableau2[indice2];
            indice2++;
            indice++;
        }
        /* ----------- S'il n'y a plus d'éléments à traiter dans tableau2 ----------- */
        else if((indice1<=nbTab1)&&(indice2==nbTab2))
        {
            tabFusion[indice] = tableau1[indice1];
            indice1++;
            indice++;
        }
        else
        {
            /* ------- Si le nom de l'élément courant du tableau2 est supérieur à ------- */
            /* ----------------- celui de l'élément courant du tableau1 ----------------- */
            if(tableau1[indice1].nom < tableau2[indice2].nom)
            {
                tabFusion[indice] = tableau1[indice1];
                indice1++;
                indice++;
            }
            /* ------- Si le nom de l'élément courant du tableau1 est supérieur à ------- */
            /* ----------------- celui de l'élément courant du tableau2 ----------------- */
            else if (tableau1[indice1].nom > tableau2[indice2].nom)
            {
                tabFusion[indice] = tableau2[indice2];
                indice2++;
                indice++;
            }
            /* --------- Si les deux éléments sont égaux on les ajoute les deux --------- */
            else
            {
                tabFusion[indice] = tableau1[indice1];
                tabFusion[indice] = tableau2[indice2];
                indice1++;
                indice2++;
                indice++;
            }
        }
    }
}