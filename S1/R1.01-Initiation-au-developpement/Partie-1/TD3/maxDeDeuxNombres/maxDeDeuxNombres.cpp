#include <iostream>
using namespace std;

int main (void)
{
    //Déclaration des variables
    int nb1;
    int nb2;
    int max;

    //Saisie des nombres
    cout << "Saisissez le nombre 1 : ";
    cin >> nb1;
    cout << "Saisissez le nombre 2 : ";
    cin >> nb2;

    //Determination du max
    max = nb1-nb2;

    if(max == 0)
    {
        cout << "Les nombres sont égaux." <<endl;
    }
    else if (max < 0)
    {
        max = nb2;
        cout << "Le max des deux nombres est " << max << "." <<endl;
    }
    else
    {
        max = nb1;
        cout << "Le max des deux nombres est " << max << "." <<endl;
    }

    return 0;
}