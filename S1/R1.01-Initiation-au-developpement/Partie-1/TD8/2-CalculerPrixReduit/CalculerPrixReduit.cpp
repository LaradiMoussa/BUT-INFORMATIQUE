/*
 Programme : CalculerPrixReduit
 But : Calcule le prix après réduction
 Date de dernière modification : 18 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme à l'algorithme données en cours
*/

#include <iostream>
using namespace std;

//Déclaration du sous-programme
void calculerPrixReduit (float prixDepart, unsigned short int reduction, float& prixReduit);

int main (void)
{
    ///////////////////////////////////////
    // V A R I A B L E S
    float prixInit;
    unsigned short int pourcReduc;
    float prixFinal;
    ///////////////////////////////////////
    // T R A I T E M E N T S

    //Saisie du prix de départ
    cout << "Entrer un prix de depart : ";
    cin >> prixInit;

    //Saisie du pourcentage de réduction
    cout << "Quel est le pourcentage de reduction ? ";
    cin >> pourcReduc;

    //Appel de la fonction
    calculerPrixReduit(prixInit,pourcReduc,prixFinal);

    //Afficher le prix final réduit
    cout << prixFinal << endl;

    return 0;
}

//Définition du sous-programme
void calculerPrixReduit (float prixDepart, unsigned short int reduction, float& prixReduit)
{
    prixReduit = prixDepart-(prixDepart*reduction/100);
}