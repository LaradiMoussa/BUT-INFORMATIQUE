/*
  Programme : NbEmployeVille
  But : Affiche le nombre d'employes contenues dans un tableau habitant dans la meme ville
  Date de dernière modification : 26 octobre 2021
  Auteur : Colas NAUDI
  Remarques : recherche du nombre de personnes habitant dans la meme ville délégué à un sous programme nbMemeVille
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
unsigned int NbEmployeVille (const Personne tab[], unsigned int nbCases, unsigned int codePostalCherche);
//But : calcule le nombre de personnes parmi tab de taille nbCases ayant le meme code postal que codeCherche

int main (void)
{
    //////////////////////
    ///V A R I A B L E S
    const unsigned int NBRE_EMPLOYES = 15; // nombre d'employés dans la structure
    Personne listeEmployes[NBRE_EMPLOYES] = { // nom, prénom et adresse des employés
        {"Almeras", "Valentin", {"29", "impasse Michelle Reynaud", 64600, "Anglet"}},
        {"Gueguen", "Lucie", {"631bis", "rue Leconte", 64100, "Bayonne"}},
        {"Pomeroy", "Thibault", {"158", "boulevard Devaux", 64200, "Biarritz"}},
        {"Souchon", "Elodie", {"68", "chemin Eric Pascal", 64200, "Biarritz"}},
        {"Besnard", "Emmanuel", {"08", "place Ferrand", 64600, "Anglet"}},
        {"Gaudreau", "Lucien", {"46", "impasse Simone Humbert", 64100, "Bayonne"}},
        {"Duret", "Christelle", {"02bis", "Chemin Imbert", 64200, "Biarritz"}},
        {"Laffitte", "Anna", {"31", "rue Lemoins", 64600, "Anglet"}},
        {"Barbier", "Remi", {"88", "impasse Richard Marin", 64100, "Bayonne"}},
        {"Blondeau", "Denise", {"83", "avenue Laroche", 64200, "Biarritz"}},
        {"Berlioz", "Gabriel", {"55", "rue Descamps", 64100, "Bayonne"}},
        {"Dupont", "Benjamin", {"40", "boulevard Duvois", 64200, "Biarritz"}},
        {"Maret", "Ludovic", {"76", "impasse de Meunier", 64600, "Anglet"}},
        {"Boutin", "Alain", {"13", "boulevard de Guillou", 64200, "Biarritz"}},
        {"Dubuisson", "Marie", {"24", "rue Capucine Chevallier", 64600, "Anglet"}}
    };
    unsigned int nombreTotal; // Le nombre d'employés ayant la même adresse
    unsigned int codePostalSaisi; // Le code postal que l'on veut trouver

    ////////////////////////
    //T R A I T E M E N T S
    //Saisir le code à chercher
    cout << "Saisir le code postal que vous desirez trouver : ";
    cin >> codePostalSaisi;
    cout << endl;

    //Affecter le nombre total de personne habitant dans la même ville à nombreTotal
    nombreTotal = NbEmployeVille (listeEmployes, NBRE_EMPLOYES, codePostalSaisi);

    //Afficher le résultat
    if (nombreTotal == 0)
    {
        cout << "Personne n'habite ici !";
    }
    else
    {
        cout << nombreTotal << " personne(s) habitent dans la ville dont le code postal est " << codePostalSaisi << "." << endl;
        cout << "Cette/Ces personnne(s) est(sont) : " << endl;

        for (unsigned int i = 0 ; i <= (NBRE_EMPLOYES-1) ; i++ )
        {
            if (listeEmployes[i].adresse.codePostal == codePostalSaisi)
                {
                    cout << " - " << listeEmployes[i].nom << " " << listeEmployes[i].prenom << endl ;
                }
        }
    }


}

//Définition de la fonction
unsigned int NbEmployeVille (const Personne tab[], unsigned int nbCases, unsigned int codePostalCherche)
{
    //////////////////////
    ///V A R I A B L E S
    unsigned int compteur; //Compteur du nombre de personnes habitant dans la même ville

    ////////////////////////
    //T R A I T E M E N T S

    //Initialisation
    compteur = 0;

    //Compter les employes de la même ville
    for (unsigned int i = 0 ; i <= (nbCases-1) ; i++ )
    {
        if (tab[i].adresse.codePostal == codePostalCherche)
        {
            compteur += 1;
        }
    }

    //retourner le nomre Total
    return compteur;
}