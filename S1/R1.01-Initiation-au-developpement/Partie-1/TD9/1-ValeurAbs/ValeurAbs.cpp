/*
 Programme : ValeurAbs
 But : Affiche la valeur absolue du nombre entré
 Date de dernière modification : 26 octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

//Déclaration de la fonction
float valeurAbs (float nombre);

int main (void)
{
    ////////////////////////
    ///V A R I A B L E S
    float nb;

    ////////////////////////
    ///T R A I T E M E N T S

    //Saisie du nombre
    cout << "Saisissez un nombre : ";
    cin >> nb;

    //Affichage du résultat
    cout << "La valeur absolue de " << nb << " est " << valeurAbs(nb) << endl;

    return 0;
}

//Définition de la fonction
float valeurAbs (float nombre)
{
    return nombre > 0 ? nombre : -nombre;
}