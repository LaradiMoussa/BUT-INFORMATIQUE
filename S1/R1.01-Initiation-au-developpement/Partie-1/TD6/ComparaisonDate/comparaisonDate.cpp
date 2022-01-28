/*
 Programme : ComparaisonDate
 But : Compare deux dates et affiche la plus ancienne
 Date de dernière modification : 07 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : 
*/

#include <iostream>
using namespace std;

int main (void)
{
    ///////////////////////////
    //T Y P E S
    enum Mois {Janvier, Fevrier, Mars, Avril, Mai, Juin, Juillet, Aout, Septembre, Octobre, Novembre, Decembre};

    struct Date
    {
        unsigned int jj; // Le jour
        Mois mm;  // Le mois
        unsigned int aa; // L'annee
    };

    ///////////////////////////
    //V A R I A B L E S
    Date date1 = {10, Janvier, 95};
    Date date2 = {10, Janvier, 95};
    Date dateAnc;
    string Mois;
    bool egalite = false;

    ///////////////////////////
    //T R A I T E M E N T S

    //Comparaison des annes
    if (date1.aa<date2.aa)
    {
        dateAnc = date1;
    }
    else if (date1.aa>date2.aa)
    {
        dateAnc = date2;
    }
    else
    {
        //Comparaison des mois
        if(date1.mm<date2.mm)
        {
            dateAnc = date1;
        }
        else if(date1.mm>date2.mm)
        {
            dateAnc = date2;
        }
        else
        {
            //Comparaison des jours
            if(date1.jj<date2.jj)
            {
                dateAnc = date1;
            }
            else if(date1.jj>date2.jj)
            {
                dateAnc = date2;
            }
            else
            {
                egalite = true;
            }
        }
    }

    //Pour chaque cas affecter la chaîne de caractères correspondante pour pouvoir l'afficher
    switch (dateAnc.mm)
    {
    case Janvier:
        Mois = "Janvier";
        break;
    case Fevrier:
        Mois = "Fevrier";
        break;
    case Mars:
        Mois = "Mars";
        break;
    case Avril:
        Mois = "Avril";
        break;
    case Mai:
        Mois = "Mai";
        break;
    case Juin:
        Mois = "Juin";
        break;
    case Juillet:
        Mois = "Janvier";
        break;
    case Aout:
        Mois = "Aout";
        break;
    case Septembre:
        Mois = "Septembre";
        break;
    case Octobre:
        Mois = "Octobre";
        break;
    case Novembre:
        Mois = "Novembre";
        break;
    case Decembre:
        Mois = "Decembre";
        break;
    }

    //Afficher la date la plus ancienne
    if(egalite == true)
    {
        cout << "Les deux dates sont identiques." << endl;
    }
    else
    {
        cout << "La date la plus ancienne est le " << dateAnc.jj << "/" << Mois << "/" << dateAnc.aa << endl;
    }

    return 0;
}