#include<iostream>
using namespace std;

int main (){
    // Déclaration des variables
    int rayon;
    double pi = 3.14;
    double aire;
    
    //Demande de saisie du rayon
    cout << "Entrer votre rayon : ";
    cin >> rayon;

    //Calcul de l'aire
    aire = pi * (rayon * rayon);

    //Affichage du résultat
    cout << "Le rayon est de " << aire << "." << endl;
    return 0;
}