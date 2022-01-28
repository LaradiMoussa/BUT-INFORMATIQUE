/*
 Programme : VerifNote
 But : Verifie que la note est comprise entre 0 et 20
 Date de dernière modification : 26 octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

//Déclaration de la fonction
bool verifNote (float note);

int main (void)
{
    ////////////////////////
    ///V A R I A B L E S
    float nb;

    ////////////////////////
    ///T R A I T E M E N T S
    cout << "Entrer une note : ";
    cin >> nb;

    if (verifNote(nb))
    {
        cout << nb << " est une note." << endl;
    }
    else 
    {
        cout << nb << " n'est pas une note." << endl;
    }

    return 0;
}

//Définition de la fonction
bool verifNote (float note)
{
    return ((note >= 0) && (note <= 20)) ? true : false;
}