#include <iostream>
using namespace std;

int main (void)
{
    //Déclaration des variables
    int noteOral;
    int noteEcrit;
    double moyenne;
    bool admis;
    string valid;

    //Saisie des notes
    while (noteOral < 0 || noteOral > 20)
    {
        cout << "Saisissez votre note d'oral (coeff 1) : ";
        cin >> noteOral;
    }

    while (noteEcrit < 0 || noteEcrit > 20)
    {
        cout << "Saisissez votre note d'ecrit (coeff 2) : ";
        cin >> noteEcrit;
    }

    //Calcul moyenne
    moyenne = ((noteOral + (noteEcrit*2)) / 3);

    //Verif admission
    if(moyenne >= 10)
    {
        admis = true;
        valid = "recu";
    }
    else
    {
        admis = false;
        valid = "non recu";
    }
    
    //Afficher le resultat
    cout << "Votre moyenne est de " << moyenne << " vous etes " << valid << "." <<endl;

    return 0;
}