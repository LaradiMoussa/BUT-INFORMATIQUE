/*
 Programme : AfficherLigneEtoile
 But : Affiche autant de ligne d'étoile que le nombre entré par l'utilisateur
 Date de dernière modification : 23 septembre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    ////////////////////////
    ///V A R I A B L E S
    int nbLignes;

    ////////////////////////
    ///T R A I T E M E N T S

    //Demande de saisie du nombre de ligne(s)
    cout << "Entrer un nombre de ligne a afficher : ";
    cin >> nbLignes;

    //Affichage des lignes
    for (int i = 1; i<= nbLignes ; i++)
    {
        cout << "* * * * *" << endl;
    }

    return 0;
}