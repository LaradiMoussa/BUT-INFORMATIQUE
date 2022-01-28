/*
 Programme : DivisionEntiere
 But : Affiche le quotient et le reste de la division
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
    int nb1;
    int nb2;
    int quotient = 0;
    int reste = 0;

    ////////////////////////
    ///T R A I T E M E N T S

    //Demande de saisie du nombre
    cout << "La division de : ";
    cin >> nb1;
    cout << "           par : ";
    cin >> nb2;

    //Initialisation de reste
    reste = nb1;

    //Calcul du quotient et du reste
    while (true)
    {
        reste -= nb2;
        quotient++;
        if (reste == 0 || reste < nb2)
        {
            break;
        }
    }

    //Affichage du resultat
    cout << "Le quotient est de "<< quotient << " et le reste est de " << reste <<endl;

    return 0;
}