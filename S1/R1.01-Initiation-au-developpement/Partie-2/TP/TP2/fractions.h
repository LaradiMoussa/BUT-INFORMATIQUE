#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Fraction {
    int numerateur; // Le signe est porté sur ce nombre
    unsigned int denominateur; // > 0
};

const Fraction FRACTION_NULLE = {0, 1};

//.  --------------------------------------- UTILITAIRES -------------------------------------------

int pgcd(int nb1, int nb2);
//! @goal : Retourne Le Pdcg De Deux Entiers

Fraction simplifier(const Fraction fraction);
//! @goal : Simplifier Une Fraction

void afficherFraction(const Fraction fraction);
//! @goal : Afficher Une Fraction

Fraction saisir();
//! @goal : Saisir Une Fonction




//.  --------------------------------------- ACCESSEURS --------------------------------------------
int numerateur(Fraction frac);
//! @goal : Retourne le numérateur de la fonction

int denominateur(Fraction frac);
//! @goal : Retourne le Dénominateur de la fonction


//.  ----------------------------------- OPÉRATEURS BINAIRES ---------------------------------------
Fraction addition(Fraction frac1, Fraction frac2);
//! @goal : Additionner Deux Fractions

Fraction addition(Fraction frac1, int n);
//! @goal : Additionner Une Fraction Avec Un Entier

Fraction soustraction(Fraction frac1, Fraction frac2);
//! @goal : Soustraire Deux Fractions

Fraction soustraction(Fraction frac1, int n);
//! @goal : Soustraire Un Entier à Une Fraction

Fraction multiplication(Fraction frac1, Fraction frac2);
//! @goal : Multiplier Deux Fractions

Fraction multiplication(Fraction frac1, int n);
//! @goal : Multiplier Une Fraction Et Un Entier

Fraction division(Fraction frac1, Fraction frac2);
//! @goal : Diviser Deux Fractions

Fraction division(Fraction frac1, int n);
//! @goal : Diviser Deux Fractions


//.  --------------------------------- OPÉRATEURS COMPARAISON --------------------------------------
bool estEgal(Fraction frac1, Fraction frac2);

bool plusPetit(Fraction frac1, Fraction frac2);

bool plusGrand(Fraction frac1, Fraction frac2);


#endif