/*
 Programme : Trier un tableau d'étudiants
 But :  exercice A
 Date de création : 
 Auteur : Colas NAUDI
 Remarques éventuelles pour le correcteur:
 */

//Certaines variables ne respectent pas les conventions de nommage (NBCASES)
//Le but du sous programme est incomplet (roles des variables non expliquées)
// Note : 19.25/20

#include <iostream>
using namespace std;

// Définition du type Etudiant
struct Etudiant
{
    string nom;            // nom de l'étudiant
    string prenom;         // prénom de l'étudiant
    unsigned short int td; // numéro de TD de l'étudiant
    unsigned short int tp; // numéro de TP de l'étudiant
};

////////////////////////////////////////////////////////////////
// D E C L A R A T I O N   D E S   S O U S - P R O G R A M M E S
////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////
//Déclaration du sous-programme TrierParTpDecroissant
void TrierParTpDecroissant (Etudiant tab[], const unsigned int NB_CASES);
// BUT : Trie par tp décroissant une liste d'étudiants

// PROGRAMME PRINCIPAL
int main(void)
{
    // Nombre d'étudiants inscrits en semestre 1
    const unsigned int EFFECTIF_S1 = 15;

    // Etudiants inscrits en semestre 1 et à trier :
    Etudiant etudiantsS1[EFFECTIF_S1] = {
       {"Barbier", "Remi", 2, 4},     {"Gueguen", "Lucie", 1, 1},
       {"Maret", "Ludovic", 3, 5},    {"Souchon", "Elodie", 1, 2},
       {"Dubuisson", "Marie", 3, 5},  {"Gaudreau", "Lucien", 2, 3},
       {"Besnard", "Emmanuel", 1, 2}, {"Boutin", "Alain", 3, 5},
       {"Almeras", "Valentin", 1, 1}, {"Blondeau", "Denise", 2, 4},
       {"Berlioz", "Gabriel", 2, 4},  {"Dupont", "Benjamin", 3, 5},
       {"Pomeroy", "Thibault", 1, 1}, {"Laffitte", "Anna", 2, 4},
       {"Duret", "Christelle", 2, 3}
    };

    // Trier le tableau : A COMPLETER AVEC L'APPEL DE VOTRE SOUS-PROGRAMME
    TrierParTpDecroissant(etudiantsS1, EFFECTIF_S1);

    // Affichage du tableau trié
    for (unsigned int i = 0; i < EFFECTIF_S1; i++)
    {
        cout << etudiantsS1[i].nom << "  " << etudiantsS1[i].prenom << " TP" << etudiantsS1[i].tp << endl;
    }
    cout << endl;

    return 0;
}

//////////////////////////////////////////////////////////
// D E F I N I T I O N   D U   S O U S - P R O G R A M M E
//////////////////////////////////////////////////////////

////////////////////////////////////////////////////
//Définition du sous-programme TrierParTpDecroissant
// {tab, nbCases} >> TrierParTpDecroissant >> {tab}
//TrierParTpDecroissant
void TrierParTpDecroissant (Etudiant tab[], const unsigned int NB_CASES)
{
    ///////////////////////////////
    //VARIABLES DU SOUS-PROGRAMME
    bool estTrie; // Indique si tab est totalement trié
    unsigned int i; //Indice de parcours du tableau
    Etudiant aux; //Servira pour l'échange des deux cases du tableau

    //Considérer que le tableau n'est pas trié >> {estTrie}
    //Considérer que le tableau n'est pas trié
    estTrie = false;

    //{tab, nbCases, estTrie} >> Trier le tableau >> {tab}
    //Trier le tableau
    while (estTrie == false)
    {
        //Supposer que le tableau est totalement trie >> {estTrie}
        //Supposer que le tableau est totalement trie
        estTrie = true;

        //{tab, nbCases} >> Comparer les étudiants aux indices pairs - impairs >> {[tab], [estTrie]}
        //Comparer les étudiants aux indices pairs - impairs
        for (i = 0; i<=NB_CASES-2; i+=2)
        {
            if (tab[i].tp < tab[i+1].tp)
            {
                //{tab, i} >> Echanger tab[i] et tab[i+1] >> {tab}
                //Echanger tab[i] et tab[i+1]
                aux = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = aux;

                //Infirmer l'hypothèse de départ supposant que le tableau était trié >>{estTrie}
                //Infirmer l'hypothèse de départ supposant que le tableau était trié
                estTrie = false;
            }
        }

        //{tab, nbCases} >> Comparer les étudiants aux indices impairs - pairs >> {[tab], [estTrie]}
        //Comparer les étudiants aux indices impairs - pairs
        for (i = 1; i <= NB_CASES-2; i+=2)
        {
            if (tab[i].tp < tab[i+1].tp)
            {
                //{tab, i} >> Echanger tab[i] et tab[i+1] >> {tab}
                //Echanger tab[i] et tab[i+1]
                aux = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = aux;

                //Infirmer l'hypothèse de dépat supposant que le tableau était trié >> {estTrie}
                //Infirmer l'hypothèse de dépat supposant que le tableau était trié
                estTrie = false;
            }
        }   
    }
}