#include<iostream>
using namespace std;

int main (){
    //Declaration des variables
    int nb1;
    int nb2;
    int copieNb1;

    //Demande de saisie de nb1
    cout << "Entrer le nombre 1 : ";
    cin >> nb1;

    //Demande de saisie de nb2
    cout << "Entrer le nombre 2 : ";
    cin >> nb2;

    //Echange des deux nombres
    copieNb1 = nb1;
    nb1 = nb2;
    nb2 = copieNb1;

    //Affichage du résultat
    cout << "Le nombre 1 est " << nb1 << " et le nombre 2 est " << nb2 << "."<<endl;

    return 0;
}