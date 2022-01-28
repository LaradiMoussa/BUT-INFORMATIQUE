#include <iostream>
using namespace std;

int main (void)
{
    //Declaration des variables
    int nombre;
    string signe;

    //Demande de saisie du nombre
    cout << "Saisissez un nombre : ";
    cin >> nombre;

    //Determination du signe
    if(nombre < 0)
    {
        signe = "negatif";
    }
    else
    {
        signe = "positif";
    }

    //Affichage du resultat
    cout << "Le nombre est " << signe << "." <<endl;
    
    return 0;
}