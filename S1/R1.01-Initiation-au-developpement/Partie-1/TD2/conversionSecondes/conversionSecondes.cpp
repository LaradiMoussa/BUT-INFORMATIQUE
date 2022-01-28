#include<iostream>
using namespace std;

int main (){
    //Declaration des variables
    int heures;
    int heuresEnSecondes;
    int minutes;
    int minutesEnSecondes;
    int secondes;

    //Demande de saisie de la durée en heures/minutes
    cout << "Saisissez votre durée"<<endl;
    cout << "   en heures : "; 
    cin >> heures;
    cout << "   et en minutes : ";
    cin >> minutes;

    //Conversion en secondes
    heuresEnSecondes = heures * 3600;
    minutesEnSecondes = minutes * 60;
    secondes = heuresEnSecondes + minutesEnSecondes;

    //Affichage du résultat
    cout << "Dans " << heures << " heures " << minutes << " minutes, il y a " << secondes << " secondes." << endl;
    
    return 0;
}