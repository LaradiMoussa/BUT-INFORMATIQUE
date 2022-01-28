/*
  Programme : AdressePersonne
  But : Retourne l'adresse d'une personne donnée
  Date de dernière modification : 26 octobre 2021
  Auteur : Colas NAUDI
  Remarques : recherche de l'adresse effectuée par une fonction getAdresse
*/

#include <iostream>
using namespace std;

///////////////////////
///T Y P E S
struct Adresse
    {
        string numRue; // Le numéro de la rue
        string nomRue; // Le nom de la rue
        unsigned int codePostal; //Le code postal de l'adresse
        string ville; //Le nom de la ville
    };

struct Personne
    {
        string nom; // Le nom de la personne
        string prenom; //Le nom de la personne
        Adresse adresse; // L'adresse de la personne
    };

//Déclaration de la fonction 
Adresse getAdresse(const Personne& personne);
//But : retourne l'adresse d'une personne donnée

int main (void)
{
    //////////////////////
    ///V A R I A B L E S
    Personne moi = {"NAUDI", "Colas", {"7", "Rue des grives", 40530, "Labenne"}}; // Une personne
    Personne autre = {"MARCHAND", "Paul", {"9", "Impasse des pingouins", 69000, "Lyon"}}; // Une personne
    Adresse adresseMoi; // L'adresse de Jean luc Melenchon
    Adresse adresseAutre; // L'adresse de Marine Le Pen

    ////////////////////////
    //T R A I T E M E N T S
    //Chercher mon adresse
    adresseMoi = getAdresse(moi);

    //Chercher l'adresse de l'autre personne
    adresseAutre = getAdresse(autre);

    //Afficher nom et adresse de MOI
    cout << moi.nom << " " << moi.prenom << endl;
    cout << adresseMoi.numRue << ", " << adresseMoi.nomRue << ", " << adresseMoi.codePostal << " " << adresseMoi.ville << endl;
    cout << endl;


    //Afficher nom et adresse de l'autre
    cout << autre.nom << " " << autre.prenom << endl;
    cout << adresseAutre.numRue << ", " << adresseAutre.nomRue << ", " << adresseAutre.codePostal << " " << adresseAutre.ville << endl;

    return 0;
}

//Définition de la fonction
Adresse getAdresse(const Personne& personne)
{
    return personne.adresse;
}