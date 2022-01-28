/*
 Programme : Les5suivants
 But : Le programme affiche les 5 nombres suivants le nombre saisi
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
    int nombre;

    ////////////////////////
    ///T R A I T E M E N T S

    //Demande de saisie du nombre
    cout << "Entrer un nombre : ";
    cin >> nombre;

    //Affichage des 5 nombres suivants
    for (int i = 1; i <= 5; i++)
    {
        cout << nombre + i <<endl;
    }

    return 0;
}