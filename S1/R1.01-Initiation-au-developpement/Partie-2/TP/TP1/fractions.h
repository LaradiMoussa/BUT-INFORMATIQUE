/**
 * @file fractions.h
 * @author Colas Naudi
 * @brief Entête présentant les sous-programmes permettant de manipuler une fraction
 * @version 0.1
 * @date 2021-11-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef FRACTIONS_H
#define FRACTIONS_H

struct Fraction
{
    int num; // numérateur de la fraction
    unsigned int den; // dénominateur de la fraction
};

const Fraction FRACTION_NULLE = {0,1}; 

//Constructeurs

//Observateurs

/**
 * @brief Indique si la fraction est réduite
 * 
 * @param [in] frac la fraction à analyser
 * @return true si la fraction est réduite
 * @return false si la fraction n'est pas réduite
 */
bool estReduite (Fraction frac);

//Accesseurs

//Opérateurs binaires

//Opérateurs de comparaisons

//Entrée - Sortie

/**
 * @brief Affiche a l'ecran le contenu du paramètre fraction frac sous sa forme irréductible
 * 
 * @param [in] frac la fraction a afficher
 */
void afficher (Fraction frac);

#endif