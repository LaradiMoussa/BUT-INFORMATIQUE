/*
 Programme : Fraction
 But : Afficher le resultat de deux fractions
 Date de dernière modification : 7 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : 
*/

#include <iostream>
using namespace std;

int main (void)
{
    ///////////////////////////
    //T Y P E S
    struct Fraction
    {
        unsigned int num;
        unsigned int den;
    };
    ///////////////////////////
    //V A R I A B L E S
    Fraction frac1 = {10, 3};
    Fraction frac2 = {20, 10};
    double resultat;

    ///////////////////////////
    //T R A I T E M E N T S

    // Calculer la somme des deux fractions
    resultat = (frac1.num/frac1.den)+(frac2.num/frac2.den);

    //Afficher la somme des deux fractions
    cout << "La somme des deux fractions est " << resultat << endl;

    return 0;
}