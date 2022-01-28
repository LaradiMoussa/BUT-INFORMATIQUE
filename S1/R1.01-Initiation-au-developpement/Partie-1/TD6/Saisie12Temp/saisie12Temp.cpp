/*
 Programme : Stocker12Temp
 But : Stocker 12 valeurs dans un tableau
 Date de dernière modification : 7 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : 
*/

#include <iostream>
using namespace std;

int main (void)
{
    ///////////////////////////
    //V A R I A B L E S
    const unsigned int NB_CASES = 12;
    float tabTemp[NB_CASES];
    float temp;

    ///////////////////////////
    //T R A I T E M E N T S

    for (int i = 1; i <= NB_CASES; i++)
    {
        cout << "Saisissez la temperature " << i << " : ";
        cin >> temp;
        tabTemp[i] = temp;
    }

    return 0;
}