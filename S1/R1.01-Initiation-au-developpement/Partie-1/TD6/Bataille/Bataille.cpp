/*
 Programme : Bataille
 But : Affiche la carte la plus forte des deux
 Date de dernière modification : 7 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : 
*/

#include <iostream>
using namespace std;

int main (void)
{
    ///////////////////////////
    //T Y P E S
    enum Valeur {deux = 2, trois=3, quatre=4, cinq=5, six=6, sept=7, huit=8, neuf=9, dix=10, valet=11, dame=12, roi=13, as=14};
    enum Couleur {carreau, coeur, trefle, pique};

    struct Carte
    {
        Valeur val;
        Couleur coul;
    };

    ///////////////////////////
    //V A R I A B L E S
    Carte carteGagnante;
    Carte carte1 = {roi , trefle};
    Carte carte2 = {dix, coeur};
    bool egalite = false;

    ///////////////////////////
    //T R A I T E M E N T S

    //Comparaison des deux cartes
    if(carte1.val > carte2.val)
    {
        carteGagnante = carte1;
    }
    else if (carte1.val < carte2.val)
    {
        carteGagnante = carte2;
    }
    else
    {
        egalite = true;
    }

    //Affichage du gagnant

    if (egalite == true)
    {
        cout << "Les cartes sont identiques !" << endl;
    }
    else
    {
        //Afficher la Valeur de la carte
        switch (carteGagnante.val)
        {
        case valet:
            cout << "valet";
            break;
        case dame:
            cout << "dame";
            break;
        case roi:
            cout << "roi";
            break;
        case as:
            cout << "as";
            break;
        default:
            cout << carteGagnante.val;
            break;
        }
        cout << " de ";
        //Afficher la Couleur
        switch (carteGagnante.coul)
        {
        case coeur:
            cout << "coeur";
            break;
        case carreau:
            cout << "carreau";
            break;
        case trefle:
            cout << "trefle";
            break;
        case pique:
            cout << "pique";
            break;
        }

    }


    return 0;
}