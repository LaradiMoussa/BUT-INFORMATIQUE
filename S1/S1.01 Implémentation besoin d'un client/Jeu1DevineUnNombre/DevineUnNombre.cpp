/*
    Programme : DevineUnNombre
    But : Le joueur cherche une valeur dans un intervalle connu, en un nombre de tentatives connu.
    Date de dernière modification : 29 Septembre 2021
    Auteur : C.Naudi
    Remarques :
*/

#include<iostream>
#include <unistd.h>
using namespace std;

int randomMinMax(int min, int max);

int main (){
    ///////////////////////////////
    //VARIABLES
    int nbTentatives;
    int nbreAleatoire;
    int nombre;
    int compteurTour;
    bool trouve;

    //////////////////////////////
    //TRAITEMENTS

    //Affichage des règles
    cout << "D E V I N E R   U N   N O M B R E " << endl;
    cout << "Le joueur cherche une valeur dans un intervalle connu, en un nombre de tentatives connu." <<endl;
    cout << endl;

    //Demande du nombre de tentatives
    cout << "Combien de tentatives (1 au minimum) ? ";
    cin >> nbTentatives;

    //Choix Machine aleatoire
    srand(time(NULL)); // INITIALISATION DU GENERATEUR DE NBRE ALEATOIRE RAND

    //Generation du nombre aleatoire
    nbreAleatoire = randomMinMax (1,101);
    cout << nbreAleatoire <<endl;

    //Initialiser compteur
    compteurTour = 1;

    //Initialiser trouve
    trouve = false;

    do
    {
        cout << "Chercher entre 0 et 100. Tentative numero " << compteurTour << "/" << nbTentatives << " ? ";
        cin >> nombre;

        if (nombre == nbreAleatoire)
        {
            trouve = true;
            break;
        }
        else if(nombre > nbreAleatoire)
        {
            cout << "Valeur trop grande !" << endl;
        }
        else if (nombre < nbreAleatoire)
        {
            cout << "Valeur trop petite !" << endl;
        }

        cout << endl;

        //Incrementation compteur
        compteurTour++;

    }while(compteurTour<=nbTentatives);
    
    if(trouve == true)
    {
        cout <<endl;
        cout << "B R A V O : " << compteurTour << " tentatives pour trouver." <<endl;
    }
    else
    {
        cout << "F I N I : Toutes les tentatives ont ete consommees." <<endl;
    }


    return 0;
}

int randomMinMax (int min, int max){
    return rand()%(max-min) + min;
}