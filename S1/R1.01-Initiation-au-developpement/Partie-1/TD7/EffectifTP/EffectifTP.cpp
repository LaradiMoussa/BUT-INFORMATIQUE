/*
 Programme : EffectifTP
 But :  Affiche l'effectif d'un groupe de TP
 Date de dernière modification : 13 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme à l'algorithme données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    ///////////////////////////////////////
    // T Y P E S
    struct Etudiant
    {
        string nom;            // nom de l'étudiant
        string prenom;         // prénom de l'étudiant
        unsigned short int td; // numéro de TD de l'étudiant
        unsigned short int tp; // numéro de TP de l'étudiant
    };

    // Nombre d'étudiants inscrits en semestre 1
    const unsigned int EFFECTIF_S1 = 15;

    // Etudiants inscrits en semestre 1 :
    Etudiant etudiantsS1[EFFECTIF_S1] = {
        {"Almeras", "Valentin", 1, 1}, {"Gueguen", "Lucie", 1, 1},
        {"Pomeroy", "Thibault", 1, 1}, {"Souchon", "Elodie", 1, 2},
        {"Besnard", "Emmanuel", 1, 2}, {"Gaudreau", "Lucien", 2, 3},
        {"Duret", "Christelle", 2, 3}, {"Laffitte", "Anna", 2, 4},
        {"Barbier", "Remi", 2, 4},     {"Blondeau", "Denise", 2, 4},
        {"Berlioz", "Gabriel", 2, 4},  {"Dupont", "Benjamin", 3, 5},
        {"Maret", "Ludovic", 3, 5},    {"Boutin", "Alain", 3, 5},
        {"Dubuisson", "Marie", 3, 5}};
    
    ///////////////////////////////////////
    // V A R I A B L E S
    int compteur;
    int saisie;
    ///////////////////////////////////////
    // T R A I T E M E N T S

    //Initialisation
    compteur = 0;

    //Saisie du groupe de TP
    cout << "Entrer un numero de tp : ";
    cin >> saisie;

    //Effectuer la recherche
    for(int i = 0; i <= EFFECTIF_S1-1; i++)
    {
        //Incrementation si l'etudiant est du groupe de TP saisi
        if(etudiantsS1[i].tp==saisie)
        {
            compteur++;
        }
    }  
    //Affichage du nombre de personnes
    cout << "Il y a " << compteur << " personnes dans le tp " << saisie << endl;
    
    return 0;
}
