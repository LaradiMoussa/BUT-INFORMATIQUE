#include <iostream>
using namespace std;

int main (void)
{
    //Declaration des variables
    int numeroTP;
    int numeroTD;

    //Saisie du groupe de TP
    cout << "Saisissez votre groupe de TP : ";
    cin >> numeroTP;

    //Recherche du groupe de TD
    if(numeroTP == 1 || numeroTP == 2)
    {
        numeroTD = 1;
    }
    else if (numeroTP == 3 || numeroTP == 4)
    {
        numeroTD = 2;
    }
    else if (numeroTP == 5)
    {
        numeroTD = 3;
    }

    //Afficher le resultat
    cout << "Si vous etes dans le groupe de TP" << numeroTP << " vous appartenez au TD" << numeroTD << "." <<endl;

    return 0;
}