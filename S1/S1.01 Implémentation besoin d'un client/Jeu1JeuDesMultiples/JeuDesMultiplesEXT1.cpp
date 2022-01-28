/*
    Programme : Jeu des multiples EXT1
    But : A partir d'un nombre de départ égal à 2, ce petit jeu consiste à saisir une liste de multiples
        respectant la contrainte suivante : chaque multiple saisi doit être un multiple supérieur à la valeur
        précédente (ou au nombre de départ qui est égal à 2 pour la première saisie).
    Date de dernière modification : 30 Septembre 2021
    Auteur : C.Naudi
    Remarques :
*/

#include<iostream>
using namespace std;

int randomMinMax(int min, int max);

int main (){
    //////////////////////////////////
    //V A R I A B L E S
    int difficulte;
    int multiple;
    int reponse = 0;
    int nbTour = 0;
    int verif;
    bool correct = true;
    int reste;

    //////////////////////////////////
    //T R A I T E M E N T S

    //Choix de la difficulté (nombre d'essai pour trouver)
    cout << "Choisissez la difficulté du jeu (nombre de réponses correctes pour gagner) : ";
    cin >> difficulte;

    //Si le nombre entré est inférieur à 1 alors un message d'erreur s'affiche et l'invite à ressaisir un nombre.
    while (!(difficulte >= 1))
    {
        cout << "La valeur attendue doit être supérieure ou égale a 0. Recommencez." <<endl;
        cout << endl;
        cout << "Choisissez la difficulté du jeu (nombre de réponses correctes pour gagner) : ";
        cin >> difficulte;
    }

    //Choix Machine aleatoire
        srand(time(NULL)); // INITIALISATION DU GENERATEUR DE NBRE ALEATOIRE RAND

        //Generation du nombre aleatoire
        multiple = randomMinMax (6,30);

    do
    {
        //Jeu des multiples
        cout << "Proposez un multiple de " << multiple << " supérieur à " << multiple << " : ";
        cin >> reponse;

        //Initialisation de reste
        reste = reponse;

        //Calcul du reste et du reste
        while (true)
        {
            reste -= multiple;
            if (reste == 0 || reste < multiple)
            {
                break;
            }
        }
        
        if((reponse==multiple)||(reste!=0))
        {
            correct = false;
            cout << "Mauvaise réponse !"<< endl;
            cout << endl;
            break;
        }
        else
        {
            multiple=reponse;
            cout << "Bonne réponse !" <<endl;
        }

        cout << endl;

        //Incrémentation du nombre de tour
        nbTour++;

    } while (!(difficulte == nbTour)||(correct == false));

    if (correct == true)
    {
        cout << "Bravo, vous avez gagné cette partie !" << endl;
    }
    else
    {
        cout << "Vous perdez cette partie car votre dernière réponse n'est pas un multiple et/ou n'est pas supérieure à " << multiple << endl;
        cout << "Nombre de bonnes réponses : " << nbTour << endl;    
    }
    
    return 0;
}

int randomMinMax (int min, int max){
    return rand()%(max-min) + min;
}