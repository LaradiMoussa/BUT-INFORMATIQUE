/*
 Programme : ToutesVoyelles
 But :  Affiche la position de toutes les voyelles d'un chaine de caractères
 Date de dernière modification : 13 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme à l'algorithme données en cours
*/
#include <iostream>
using namespace std;

int main (void)
{
    ///////////////////////////////////////
    // V A R I A B L E S
    string chaine = "bbavoir";
    unsigned int posCourante;
    bool trouve;
    unsigned int posDerLettre;
    ///////////////////////////////////////
    // T R A I T E M E N T S
    
    //Initialisation
    trouve = false;
    posCourante = 0;
    posDerLettre = (chaine.size()-1);

    //Effectuer la recherche
    while(posCourante<=posDerLettre)
    {
        if((chaine[posCourante]=='a')||(chaine[posCourante]=='e')||(chaine[posCourante]=='i')||(chaine[posCourante]=='o')||(chaine[posCourante]=='u')||(chaine[posCourante]=='y'))
        {
            if(trouve == false)
            {
                cout << "La/Les voyelle(s) se trouvent en position : ";
            }
            trouve = true;
            cout << posCourante +1 << " ";
        }
        posCourante ++;
    }

    //Afficher le resultat
    if(trouve == false)
    {
        cout << "La chaine ne contient pas de voyelle." << endl;
    }
    
    return 0;
}