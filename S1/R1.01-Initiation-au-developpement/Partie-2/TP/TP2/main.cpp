/**\
  * @file   testFile.cpp
  * @author C.Naudi
  * @brief  test file links
\**/

// . Importation Des Bibliothèques Nécessaires.
#include "fractions.h"
// Pour compiler
// cd "/Users/colasnaudi/Desktop/GitHub/BUT-INFO/S1/R1.01-Initiation-au-developpement/Partie-2/TP/TP2/" && g++ main.cpp fractions.cpp -o main && "/Users/colasnaudi/Desktop/GitHub/BUT-INFO/S1/R1.01-Initiation-au-developpement/Partie-2/TP/TP2/"main

using std::cout;
using std::cin;
using std::endl;


int main(void) {

    /* -------------------------------------------------------------------------- */
    /*                            Déclaration Variables                           */
    /* -------------------------------------------------------------------------- */
    Fraction frac1 = {4, 2};
    Fraction frac2 = {4, 2};
    Fraction test = FRACTION_NULLE;

    test = simplifier(frac1);


    // afficherFraction(addition(frac1, frac2));
    // // 4/2 + 4/2 = 4
    // afficherFraction(addition(frac1, 3));
    // // 4/2 + 3 = 5
    // afficherFraction(soustraction(frac1, frac2));
    // // 4/2 - 4/2 = 0
    // afficherFraction(soustraction(frac1, 1));
    // // 4/2 - 1 = 1
    // afficherFraction(multiplication(frac1, frac2));
    // // 4/2 * 4/2 = 4
    // afficherFraction(multiplication(frac1, 3));
    // // 4/2 * 3 = 6
    // afficherFraction(division(frac1, frac2));
    // // 4/2 / 4/2 = 1
    // afficherFraction(saisir());
    
    //afficherFraction(division(frac1, 2));
    // 4/2 / 2 = 1
    

    return 0;
}
