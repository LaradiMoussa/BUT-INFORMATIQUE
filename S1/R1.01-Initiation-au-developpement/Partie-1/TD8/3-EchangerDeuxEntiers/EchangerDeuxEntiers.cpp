/*
 Programme : EchangerDeuxEntiers
 But : Echange de deux entiers
 Date de dernière modification : 18 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme à l'algorithme données en cours
*/

#include <iostream>
using namespace std;

//Déclaration du sous-programme
void echangerDeuxEntiers(int& nb1, int& nb2);

int main (void)
{
    ///////////////////////////////////////
    // V A R I A B L E S
    int nombre1;
    int nombre2;
    ///////////////////////////////////////
    // T R A I T E M E N T S

    //Saisie du nombre 1
    cout << "Saisissez le nombre 1 : ";
    cin >> nombre1;
    //Saisie du nombre 2
    cout << "Saisissez le nombre 2 : ";
    cin >> nombre2;
    cout << endl;
    cout << endl;

    //Afficher les variables avant l'échange
    cout << "Avant echange" << endl;
    cout << endl;
    cout << "Le nombre 1 : " << nombre1 << endl;
    cout << "Le nombre 2 : " << nombre2 << endl;
    cout << endl;

    //Appel du sous-programme
    echangerDeuxEntiers(nombre1, nombre2);

    //Afficher les variables après l'échange
    cout << "Apres echange" << endl;
    cout << endl;
    cout << "Le nombre 1 : " << nombre1 << endl;
    cout << "Le nombre 2 : " << nombre2 << endl;

    return 0;
}

//Définition du sous-programme
void echangerDeuxEntiers(int& nb1, int& nb2)
{
    int aux;
    
    aux = nb1;
    nb1 = nb2;
    nb2 = aux;
}