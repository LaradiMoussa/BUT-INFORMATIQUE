/*
 Programme : SaisieVerifNote
 But : Le programme se termine si le note entrée est comprise entre 0 et 20
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

    ////////////////////////
    ///T R A I T E M E N T S

    //La note doit être comprise entre 0 et 20 pour sortir de la boucle
    do{
        cout << "Saisissez une note : ";
        cin >> note;
    }while (note < 0 || note > 20);

    //Message de fin car la saisie est bonne
    cout << "Merci" << endl;

    return 0;
}