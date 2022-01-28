#include <iostream>
using namespace std;

int main (void)
{
    //Declaration des variables
    int nb1;
    int nb2;
    char oper;
    bool divZero;
    bool opInv;
    double resultat;

    //Saisir les nombres
    cout << "Saisissez le nombre 1 : ";
    cin >> nb1;
    cout << "Saisissez le nombre 2 : ";
    cin >> nb2;
    cout << "Saisissez l'operateur ( + ou - ou / ou x ) : ";
    cin >> oper;

    //Essayer de calculer
    divZero = false;
    opInv = false;

    switch (oper)
    {
    case '+':
        resultat = nb1 + nb2;
        break;

    case '-':
        resultat = nb1 - nb2;
        break;

    case 'x':
        resultat = nb1 * nb2;
        break;
         
    case '/':
        if(nb2 != 0)
        {
            resultat = nb1 / nb2;
        }
        else
        {
            divZero = true;
        }
        break;

    default :
        opInv = true;
        break;
    }

    //Afficher resultat
    if(opInv == true)
    {
        cout << "L'operateur saisi est invalide" <<endl;
    }
    else if (divZero == true)
    {
        cout << "La division par 0 est impossible" <<endl;
    }
    else
    {
        cout << "Le resultat du calcul est " << resultat <<endl;
    }

    return 0;
}