#include<iostream>
using namespace std;

int main (){
    // Déclaration des variables
    int abo;
    int NbCopie;
    double prixTotal;
    // Demande si la personne est abonnée stockée dans la variable abo
    cout << "Etes-vous abonné ? NON = 0/OUI = 1 : ";
    cin >> abo;
    // Demande du nombre de photocopies stocké dans NbCopie
    cout << "Combien de photocopies voulez-vous ? ";
    cin >> NbCopie;
    // Calcul du prix total de base
    prixTotal = NbCopie * 0.30;
    // S'il est abonné on applique les 30% avant d'afficher le prix sinon on affiche le prix de base
    if (abo == 1){
        prixTotal = prixTotal * 0.70;
        cout << "Le montant est de " << prixTotal << "€." << endl;
    }
    else{
        cout << "Le montant est de " << prixTotal << "€." << endl;
    }

    return 0;
}