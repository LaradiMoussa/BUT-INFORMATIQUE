/*
 Programme : DerniereVoyelle
 But :  Affiche la position de la derniere voyelle d'un chaine de caractères
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
    string chaine = "bbavonnir";
    unsigned int posCourante;
    bool trouve;
    ///////////////////////////////////////
    // T R A I T E M E N T S
    
    //Initialisation
    trouve = false;
    posCourante = chaine.size()-1;

    //Effectuer la recherche
    while(posCourante!=0)
    {
        if((chaine[posCourante]=='a')||(chaine[posCourante]=='e')||(chaine[posCourante]=='i')||(chaine[posCourante]=='o')||(chaine[posCourante]=='u')||(chaine[posCourante]=='y'))
        {
            trouve = true;
            break;
        }
        posCourante --;
    }

    //Afficher le resultat
    if(trouve == false)
    {
        cout << "La chaine ne contient pas de voyelle." << endl;
    }
    else
    {
        cout << "La derniere voyelle est a la position : " << posCourante+1 << "." << endl;
    }
    
    return 0;
}