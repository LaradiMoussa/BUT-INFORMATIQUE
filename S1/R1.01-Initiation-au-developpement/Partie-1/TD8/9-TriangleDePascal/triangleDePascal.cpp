/*
 Programme : triangleDePascal
 But : Affiche le triangle de pascal de taille choisie
 Date de dernière modification : 19 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme à l'algorithme données en cours
*/

#include <iostream>
using namespace std;

//Déclaration du sous-programme
void afficherTrianglePascal(const unsigned int nbLignes);

int main()
{
    ///////////////////////////////////////
    //T Y P E S
    ///////////////////////////////////////
    // V A R I A B L E S
    unsigned short int lignes;
    ///////////////////////////////////////
    // T R A I T E M E N T S

    //saisie du nombre de ligne
    cout << "Saisissez un nombre de ligne : ";
    cin >> lignes;

    //Appel de la fonction
    afficherTrianglePascal(lignes);

    return 0;
}

//Définition du sous-programme
void afficherTrianglePascal(const unsigned int nbLignes)
{
    int tab[nbLignes][nbLignes];

    //Initialisation de toutes les cases à 0
    for (int i = 0; i <= nbLignes - 1; i++)
    {
        for (int j = 0; j <= nbLignes - 1; j++)
        {
            tab[i][j] = 0;
        }
    }

    //Remplissage du tableau
    for (int i = 0; i <= nbLignes - 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                tab[i][j] = 1;
            }
            else
            {
                tab[i][j] = ((tab[i - 1][j - 1]) + (tab[i - 1][j]));
            }
        }
    }

    //Affichage du tableau
    for (int i = 0; i <= nbLignes - 1; i++)
    {
        for (int j = 0; j <= nbLignes - 1; j++)
        {
            if (tab[i][j] != 0)
            {
                if (tab[i][j] < 10)
                {
                    cout << "    ";
                }
                else if (tab[i][j] < 100)
                {
                    cout << "   ";
                }
                else if (tab[i][j] < 1000)
                {
                    cout << "  ";
                }
                else if (tab[i][j] < 10000)
                {
                    cout << " ";
                }
                else if (tab[i][j] < 100000)
                {
                    cout << "";
                }
                cout << tab[i][j] << "   ";
            }
        }
        cout << endl;
        if (nbLignes < 10)
        {
            cout << endl;
        }
        else if (nbLignes < 14)
        {
            cout << endl;
            cout << endl;
        }
        else if (nbLignes < 17)
        {
            cout << endl;
            cout << endl;
            cout << endl;
        }
        else if (nbLignes < 19)
        {
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
        }
    }
}