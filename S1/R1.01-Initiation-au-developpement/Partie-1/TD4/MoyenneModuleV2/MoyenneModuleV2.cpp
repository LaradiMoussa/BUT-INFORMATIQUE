/*
 Programme : MoyenneModuleV2
 But : Affiche la moyenne correspondant aux notes saisies avec message d'erreur
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
    int nbNote;

    ////////////////////////
    ///T R A I T E M E N T S

    //Saisie des notes
    while(true)
    {
        //Saisie des notes
        cout << "Entrez une note : ";
        cin >> note;

        //Si la valeur est 999 on affiche la moyenne
        if (note == 999)
        {
            break;
        }
        //
        else if ((note < 0) || (note > 20))
        {
            cout << "Valeur incorrecte, une note doit etre comprise entre 0 et 20."<< endl;
        }
        else
        {
            moyenne += note;
            nbNote++;
        }
    }

    //Calcul moyenne
    moyenne /= nbNote;

    //Afficher la moyenne
    cout << "La moyenne des notes saisies est egale a " << moyenne << endl;

    return 0;
}