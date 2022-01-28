/*
 Programme : MoyenneModuleV1
 But : Affiche la moyenne correspondant aux 10 notes saisies
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
    double note;
    double moyenne;

    ////////////////////////
    ///T R A I T E M E N T S

    //Message de saisie
    cout << "Entrez les notes :" << endl;

    //Saisie des notes
    for (int i=1 ; i<= 10; i++)
    {
        cin >> note;
        moyenne += note;
    }

    //Calcul de la moyenne
    moyenne /= 10;

    //Afficher la moyenne
    cout << "Moyenne : " << moyenne << endl;

    return 0;
}
