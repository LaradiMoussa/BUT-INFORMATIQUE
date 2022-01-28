/*
 Programme : AfficherPrixReduit
 But : Affiche le prix après réduction
 Date de dernière modification : 18 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme à l'algorithme données en cours
*/

//  TEST 20€ & 20% = 16€ :: 20€ & 80% = 4€

#include <iostream>
using namespace std;

//Déclaration du sous-programme
void afficherPrixReduit (float prixDepart, unsigned short int reduction);

int main (void)
{
    ///////////////////////////////////////
    // V A R I A B L E S
    float prixInit;
    unsigned short int pourcReduc;
    ///////////////////////////////////////
    // T R A I T E M E N T S

    //Saisie du prix de départ
    cout << "Entrer un prix de depart : ";
    cin >> prixInit;

    //Saisie du pourcentage de réduction
    cout << "Quel est le pourcentage de reduction ? ";
    cin >> pourcReduc;

    //Appel du sous-programme
    afficherPrixReduit(prixInit,pourcReduc);

    return 0;
}

//Définition du sous-programme
void afficherPrixReduit (float prixDepart, unsigned short int reduction)
{
    cout << (prixDepart-(prixDepart*reduction/100)) << endl;
}