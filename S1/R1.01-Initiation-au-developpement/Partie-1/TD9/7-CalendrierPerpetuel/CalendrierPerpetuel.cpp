/*
 Programme : CalendrierPerpetuel
 But : Affcieh le jour d'une date donnée
 Date de dernière modification : 28 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme à l'algorithme données en cours
*/
#include <iostream>
using namespace std;

//Déclaration du sous-programme
int calendrierPerpetuel (unsigned int j, unsigned int decalageMois, unsigned int decalageAnnee);

int main (void)
{
    ///////////////////////////////////////
    // V A R I A B L E S
    unsigned int jour;
    unsigned int mois;
    unsigned int annee;
    string nomJour;
    ///////////////////////////////////////
    // T R A I T E M E N T S

    //Inititialisation

    //Saisie de la date
    cout << "Entrer le jour : ";
    cin >> jour;
    cout << "Entrer le mois : ";
    cin >> mois;
    cout << "Entrer l'annee : ";
    cin >> annee;

    //Appel de la fonction
    switch (calendrierPerpetuel(jour,mois,annee))
    {
    case 1:
        nomJour = "Lundi";
        break;
    case 2:
        nomJour = "Mardi";
        break;
    case 3:
        nomJour = "Mercredi";
        break;
    case 4:
        nomJour = "Jeudi";
        break;
    case 5:
        nomJour = "Vendredi";
        break;
    case 6:
        nomJour = "Samedi";
        break;
    case 7:
        nomJour = "Dimanche";
        break;
    }

    //Affichage du résultat
    cout << nomJour <<endl;
    
    return 0;
}

//Définition du sous-programme
int calendrierPerpetuel (unsigned int j, unsigned int decalageMois, unsigned int decalageAnnee)
{
    unsigned int decalageAnneePartie1;
    unsigned int decalageAnneePartie2;
    unsigned int numJour;

    //Calcul du decalageMois
    if ((decalageMois == 1) || (decalageMois == 2))
    {
        decalageMois += 10;
        decalageAnnee -= 1;
    }
    else
    {
        decalageMois -= 2;
    }

    //Diviser l'annee en deux parties
    decalageAnneePartie1 = decalageAnnee / 100;
    decalageAnneePartie2 = decalageAnnee - (decalageAnneePartie1 *100);

    //Calculer numJour
    numJour = ((j + (13 * decalageMois - 1) / 5 + decalageAnneePartie2 + decalageAnneePartie2 / 4 + decalageAnneePartie1 / 4 + 5 * decalageAnneePartie1) % 7);

    return numJour;
}