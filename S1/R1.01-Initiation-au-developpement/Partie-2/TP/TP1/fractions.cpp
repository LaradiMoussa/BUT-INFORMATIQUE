/**
 * @file fractions.cpp
 * @author Colas Naudi
 * @brief Le corps du module Fractions
 * @version 0.1
 * @date 2021-11-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "fractions.h"
#include <iostream>
using namespace std;

void afficher (const Fraction& frac)
{
    cout << " " << frac.num << "/" << frac.den << " " ;
}

bool estReduite (const Fraction& frac)
{
    return true;
}