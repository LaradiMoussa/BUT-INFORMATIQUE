/*
 Programme : MoyenneEtudiants-ouPas
 But : Compte le nombre d'étudiants qui ont la moyenne et ceux qui ne l'ont pas
 Date de dernière modification : 22 Octobre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme à l'algorithme données en cours
*/

#include <iostream>
using namespace std;

///////////////////////////////////////
//T Y P E S
struct UnEtudiant
{
    string nom;            // nom de l'étudiant
    string prenom;         // prénom de l'étudiant
    float note;            // note de l'étudiant
};

// Nombre d'étudiants inscrits en semestre 1 :
const unsigned int EFFECTIF_S1 = 15;

// Résultats examen du 15 février :
UnEtudiant notesExamDu15fevrier[EFFECTIF_S1] = {
    {"Almeras", "Valentin", 15}, {"Gueguen", "Lucie", 8.5},
    {"Pomeroy", "Thibault", 4.5}, {"Souchon", "Elodie", 18},
    {"Besnard", "Emmanuel", 12}, {"Gaudreau", "Lucien", 0},
    {"Duret", "Christelle", 10.5}, {"Laffitte", "Anna", 13},
    {"Barbier", "Remi", 15}, {"Blondeau", "Denise", 7},
    {"Berlioz", "Gabriel", 9.5}, {"Dupont", "Benjamin", 3},
    {"Maret", "Ludovic", 13.5}, {"Boutin", "Alain", 12},
    {"Dubuisson", "Marie", 19}};


//Déclaration du sous-programme
void compteurMoyenne_ouPas(UnEtudiant tableauNotes[],unsigned short int nbEtudiant, unsigned short int& compteurMoyenne, unsigned short int& compteurPasMoyenne);

int main (void)
{
    ///////////////////////////////////////
    // V A R I A B L E S
    unsigned short int moyenne;
    unsigned short int pasMoyenne;
    ///////////////////////////////////////
    // T R A I T E M E N T S

    //Appel du sous-programme
    compteurMoyenne_ouPas(notesExamDu15fevrier, EFFECTIF_S1, moyenne, pasMoyenne);

    //Afficher le nombre d'élèves qui ont et qui n'ont pas la moyenne
    cout << moyenne << " eleves ont la moyenne" << endl;
    cout << pasMoyenne << " eleves n'ont pas la moyenne" << endl;

    return 0;
}

//Définition du sous-programme
void compteurMoyenne_ouPas(UnEtudiant tableauNotes[],unsigned short int nbEtudiant, unsigned short int& compteurMoyenne, unsigned short int& compteurPasMoyenne)
{
    compteurMoyenne = 0;
    compteurPasMoyenne = 0;

    for (int i = 0; i <= nbEtudiant-1; i++)
    {
        if(tableauNotes[i].note<10)
        {
            compteurPasMoyenne ++;
        }
        else
        {
            compteurMoyenne ++;
        }
    }
}