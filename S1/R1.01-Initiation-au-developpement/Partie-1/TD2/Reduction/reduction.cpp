#include<iostream>
using namespace std;

int main (){
    //Déclaration des variables
    double prixInit;
    double prixFinal;
    double reduction;

    //Demande de saisie du prix initial
    cout << "Quel est le prix de base ? ";
    cin >> prixInit;

    //Demande de saisie de la reduction
    cout << "Quel est le montant de la reduction ? ";
    cin >> reduction;
    
    //Calcul du prix final
    prixFinal = prixInit * (1-reduction/100);

    //Affichage du résultat
    cout << "Le prix final est de " << prixFinal << "€."<<endl;
    
    return 0;
}