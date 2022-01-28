/**\
  * @file   fraction.cpp
  * @author C.Naudi
  * @brief  Exercice TD2 R1.01/PT2
\**/

/* COMPILER !!
cd "/Users/colasnaudi/Desktop/BUT-INFO/S1/R1.01-Initiation-au-developpement/Partie-1/TP/TP2/" && g++ testFile.cpp fraction.cpp -o testFile && "/Users/tom_planche_mbpm1/Desktop/BUT/R1.01-IntroDev/PT2/TD2/"testFile
*/

// ! Importation Des Bibliothèques Nécessaires.
#include "fractions.h"

// ! Définition Sous-Programmes

//.  --------------------------------------- UTILITAIRES -------------------------------------------
int pgcd(int nb1, int nb2) {
    int reste;
    do {
        reste = nb1 % nb2;
        nb1 = nb2;
        nb2 = reste;
    } while (reste != 0);
    
    return nb1;
}

Fraction simplifier(const Fraction fraction) {
    /**\
      * @goal                           :  simplifier une fraction
      * @author :                       :  T.Planche
      * @remarks                        :  aucune
    \**/
    
    Fraction fractionFinale;
    int pgdcFraction;

    pgdcFraction = pgcd(fraction.numerateur, fraction.denominateur);
    
    fractionFinale.numerateur = fraction.numerateur / pgdcFraction;
    fractionFinale.denominateur = fraction.denominateur / pgdcFraction;

    return fractionFinale;
}

void afficherFraction(const Fraction fraction) {
    Fraction fractionSimplifiee = simplifier(fraction);

    if (fractionSimplifiee.numerateur == 0) {
        cout << 0 << endl;
    } else if (fractionSimplifiee.denominateur == 1) {
        cout << fractionSimplifiee.numerateur << endl;
    } else {
        cout << fractionSimplifiee.numerateur << "/" << fractionSimplifiee.denominateur << endl;
    }
}

Fraction saisir() {
    Fraction fraction;
    int numerateur;
    int denominateur;

    cout << "Saisissez le numérateur : ";
    cin >> fraction.numerateur;

    cout << "Saisissez le dénominateur : ";
    cin >> fraction.denominateur;

    return fraction;
}

//.  --------------------------------------- ACCESSEURS --------------------------------------------
int numerateur(Fraction frac) {
    return frac.numerateur;
}

int denominateur(Fraction frac) {
    return frac.denominateur;
}

//.  ----------------------------------- OPÉRATEURS BINAIRES ---------------------------------------
Fraction addition(Fraction frac1, Fraction frac2) {
    Fraction fractionResultat;

    if (frac1.denominateur == frac2.denominateur) {
        fractionResultat.denominateur = frac1.denominateur;
        fractionResultat.numerateur = frac1.numerateur + frac2.numerateur;
    } else {
        fractionResultat.denominateur = frac1.denominateur*frac2.denominateur;
        fractionResultat.numerateur = frac1.numerateur*frac2.denominateur + frac2.numerateur*frac1.denominateur;
    }

    return simplifier(fractionResultat);
}

Fraction addition(Fraction frac, int n) {
    Fraction fractionResultat;

    fractionResultat.numerateur = frac.numerateur + (frac.denominateur * n);
    fractionResultat.denominateur = frac.denominateur;

    return simplifier(fractionResultat);
}

Fraction soustraction(Fraction frac1, Fraction frac2) {
    Fraction fractionResultat;

    if (frac1.denominateur == frac2.denominateur) {
        fractionResultat.numerateur = frac1.numerateur - frac2.numerateur;
        fractionResultat.denominateur = frac1.denominateur;
    } else {
        fractionResultat.numerateur = frac1.numerateur * frac2.denominateur - frac2.numerateur * frac1.denominateur;
        fractionResultat.denominateur = frac1.denominateur + frac2.denominateur;
    }

    return simplifier(fractionResultat);
}

Fraction soustraction(Fraction frac, int n) {
    Fraction fractionResultat;

    fractionResultat.numerateur = frac.numerateur - (frac.denominateur * (frac.numerateur >= frac.denominateur ? n : n + 1));
    fractionResultat.denominateur = frac.denominateur;

    return simplifier(fractionResultat);
}

Fraction multiplication(Fraction frac1, Fraction frac2) {
    Fraction fractionResultat;

    fractionResultat.numerateur = frac1.numerateur * frac2.numerateur;
    fractionResultat.denominateur = frac1.denominateur * frac2.denominateur;

    return simplifier(fractionResultat);
}

Fraction multiplication(Fraction frac, int n) {
    Fraction fractionResultat;

    fractionResultat.numerateur = frac.numerateur * n;
    fractionResultat.denominateur = frac.denominateur;

    return simplifier(fractionResultat);
}

Fraction division(Fraction frac1, Fraction frac2) {
    Fraction fractionResultat = {frac2.denominateur, frac2.numerateur};

    return multiplication(frac1, fractionResultat);
}

Fraction division(Fraction frac, int n) {
    Fraction frac2 = {1, n};

    return multiplication(frac, frac2);
}


//.  --------------------------------- OPÉRATEURS COMPARAISON --------------------------------------
bool estEgal(Fraction frac1, Fraction frac2) {
    return (simplifier(frac1).numerateur == simplifier(frac2).numerateur) && (simplifier(frac1).denominateur == simplifier(frac2).denominateur) ? true : false;
}

bool plusPetit(Fraction frac1, Fraction frac2) {
    if (frac1.denominateur == frac2.denominateur) {
        return frac1.numerateur < frac2.denominateur;
    }

    frac1.denominateur *= frac2.denominateur;
    frac2.denominateur *= frac1.denominateur;
    frac1.numerateur *= frac2.denominateur;
    frac2.numerateur *= frac1.denominateur;

    return frac1.numerateur < frac2.denominateur;
}

bool plusGrand(Fraction frac1, Fraction frac2) {
    if (frac1.denominateur == frac2.denominateur) {
        return frac1.numerateur > frac2.denominateur;
    }

    frac1.denominateur *= frac2.denominateur;
    frac2.denominateur *= frac1.denominateur;
    frac1.numerateur *= frac2.denominateur;
    frac2.numerateur *= frac1.denominateur;

    return frac1.numerateur > frac2.denominateur;
}