#include <iostream>
using namespace std;

void systeme3d(const int tab[][3], const int tabRes[], const unsigned int nbCases);

void remontee(const int tab[][3], const int tabRes[], const unsigned int nbCases);

int main()
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    const unsigned int NB_CASES = 3;
    int tab[NB_CASES][NB_CASES] = {{-5, 3, 2}, {0, -2, 4}, {0, 0, 6}};
    int tabRes[NB_CASES] = {10, 2, 12};

    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */

    //systeme3d(tab, tabRes, NB_CASES);
    remontee(tab, tabRes, NB_CASES);

    return 0;
}

void systeme3d(const int tab[][3], const int tabRes[], const unsigned int nbCases)
{
    /* -------------------------------------------------------------------------- */
    /*                                DECLARATIONS                                */
    /* -------------------------------------------------------------------------- */
    float z;
    float y;
    float x;

    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */

    /* --------------------------- Afficher le système -------------------------- */
    cout << "                   SYSTEME" << endl;
    cout << tab[0][0] << "x + " << tab[0][1] << "y + " << tab[0][2] << "z = " << tabRes[0] <<endl;
    cout << tab[1][1] << "y + " << tab[1][2] << "z = "  << tabRes[1] <<endl;
    cout << tab[2][2] << "z = "  << tabRes[2] <<endl;

    /* ------------------------------ Trouver le z ------------------------------ */

    z = (tabRes[2]/tab[2][2]);
    cout << "z = " << z << endl;

    /* ------------------------------ Trouver le y ------------------------------ */

    y = ((tabRes[1]-(tab[1][2]*z))/tab[1][1]);
    cout << "y = " << y << endl;

    /* ------------------------------ Trouver le x ------------------------------ */
    x = ((tabRes[0]-((tab[0][1]*y)+(tab[0][2]*z)))/tab[0][0]);
    cout << "x = " << x << endl;
}

void remontee(const int tab[][3], const int tabRes[], const unsigned int nbCases)
{
    /* -------------------------------------------------------------------------- */
    /*                                DECLARATIONS                                */
    /* -------------------------------------------------------------------------- */
    float valeur;
    float tabVal[nbCases];
    char inconnu;
    unsigned int cmpt;
    unsigned int compteur;
    unsigned int nbTour;

    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */

    /* ----------------------------- Initialisation ----------------------------- */
    compteur = nbCases-1;
    cmpt = 0;
    nbTour = 0;

    /* ------------------------------------ - ----------------------------------- */
    /* --------------------------- Afficher le système -------------------------- */
    /* ------------------------------------ - ----------------------------------- */

    cout << "                   SYSTEME" << endl;
    for (unsigned int i = 0; i < nbCases; i++)
    {

        for (int j = nbTour; j <= compteur; j++)
        {
            /* --------------------- Trouver la lettre de l'inconnu --------------------- */
            inconnu = ('z'-j);

            /* -------- Afficher l'élement du tableau et l'inconnu correspondant -------- */
            cout << tab[i][j] << inconnu << " ";

            /* ----------------- Afficher le + si le suivant est positif ---------------- */
            if((j<compteur) && (tab[i][j+1]>0))
            {
                cout << "+ ";
            }
        }
        /* -------------------------- Afficher le résultat -------------------------- */
        cout << " = " << tabRes[i];
        /* ---------------------------- Retour à la ligne --------------------------- */
        cout << endl;
        /* ---------------------- Incrémenter le nombre de tour --------------------- */
        nbTour++;
    }

    /* ------------------------------------ - ----------------------------------- */
    /* -------------------------- Trouver les inconnus -------------------------- */
    /* ------------------------------------ - ----------------------------------- */

    compteur = nbCases-1;

    for(int i = 0; i <= nbCases-1; i++)
    {
        /* --------------- Valeur finale prend pour valeur le résultat -------------- */
        valeur = tabRes[compteur];

        /* ---------------------- Soustraire les autres indices --------------------- */
        for (int j = 0; j < i; i++)
        {
            /*code*/
        }

        /* -------------------- Valeur finale divisée par indice -------------------- */
        valeur = valeur / tab[compteur][compteur];

        /* ------------------- Valeur trouvée stockée dans tableau ------------------ */
        tabVal[i] = valeur;


        /* ------------------------ Afficher la valeur finale ----------------------- */
        cout << valeur << endl;
        
        /* ------------------------- Décrémentater compteur ------------------------- */
        compteur--;
    }
}