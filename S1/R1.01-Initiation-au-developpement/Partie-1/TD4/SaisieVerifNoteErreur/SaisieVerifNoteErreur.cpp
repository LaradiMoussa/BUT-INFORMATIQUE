/*
 Programme : SaisieVerifNoteErreur
 But : Le programme affiche un message d'erreur si le note entrée n'est pas comprise entre 0 et 20
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

    //Affichage du message de saisie
    cout << "Entrer une note entre 0 et 20 : ";
    
    //Verification de la note
    while(true)
    {
        cin >> note;
        if (note >= 0 && note <= 20)
        {
            break;
        }
        //Si la note n'est pas bonne le message d'erreur s'affiche
        cout << "La valeur doit etre comprise entre 0 et 20. Recommencez : ";
    }

    //Message de fin
    cout << "Merci" << endl;



    return 0;
}