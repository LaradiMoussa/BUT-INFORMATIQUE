/**
 * @file main.cpp
 * @author Colas Naudi
 * @brief Programme principal pour tester au fur et à mesure
 * les différents sous-programmes élaborés dans le module Fractions
 * @version 0.1
 * @date 2021-11-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/* -------------------------------------------------------------------------- */
/*                   Déclaration des sous-programmes de test                  */
/* -------------------------------------------------------------------------- */
void testAfficher();
void testEstReduite();

#include "fractions.h"
#include <iostream>
using namespace std;

int main(void)
{
    testAfficher();

    testEstReduite();
    
    return 0;
}

/* -------------------------------------------------------------------------- */
/*                   Définition des sous-programmes de test                   */
/* -------------------------------------------------------------------------- */

void testAfficher()
{
    afficher(FRACTION_NULLE);
}

void testEstReduite()
{
    if(estReduite(FRACTION_NULLE))
    {
        cout << "La fraction est réduite" << endl;
    }
    else
    {
        cout << "La fraction n'est pas réduite" << endl;
    }
}