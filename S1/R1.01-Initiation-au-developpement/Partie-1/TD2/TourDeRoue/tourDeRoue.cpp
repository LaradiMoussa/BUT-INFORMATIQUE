#include<iostream>
using namespace std;

int main (){
    //Déclaration des variables
    int rayon;
    int distKm;
    int distCm;
    double perimetre;
    int nbtour;
    int nbCmDansUnKm = 100000;
    double pi = 3.14;

    //Demande de saisie de la distance en Km et du rayon en Cm.
    cout << "Saisissez la distance (en Km) ";
    cin >> distKm;
    cout << "Saisissez votre rayon (en cm) ";
    cin >> rayon;

    //Calcul du perimetre de la roue
    perimetre = 2 * pi * rayon;

    //Conversion Km en cm
    distCm = distKm * nbCmDansUnKm;

    //Calcul du nombre de tour de roue
    nbtour = distCm / perimetre;

    //Affichage du nombre de tour de roue
    cout << "Sur un distance de " << distKm << " Km, la roue fera " << nbtour << " tours." <<endl;

    return 0;
}