/*
    Programme : Hanoi - itératif - avec Tableau de piles et sous-programmes 
    But :  Résolution des tours de Hanoi - version itérative - pour 3 à 9 disques
    Date de dernière modification : 04-12-2021
    Auteur : Pantxika Dagorret
    Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - TD n°4
*/

// cd "/Users/colasnaudi/Desktop/GitHub/BUT-INFO/S1/R1.01-Initiation-au-developpement/Partie-2/TP/TP5(pile)/" && g++ main.cpp pile.cpp -o main && "/Users/colasnaudi/Desktop/GitHub/BUT-INFO/S1/R1.01-Initiation-au-developpement/Partie-2/TP/TP5(pile)/"main

#include <iostream>
#include "pile.h"
using namespace std;


const unsigned int NB_TOURS = 3;     // CONSTANTE dite 'GLOBALE' : 
                                            // portée = tous les Sous-programmes
                                            // présents dans ce fichier

/* ---------- Observateurs
------------------------------------------------------------------*/
bool sontVides(const UnePile &tourA, const UnePile &tourB);
// But : retourne vrai si les deux tours tourA et tourB sont vides, faux sinon

bool disqueEstDeplacable (const UnePile& tourOrigine, const UnePile& tourDestination);
// BUT : retourne vrai si la condition suivante est verifiée sinon retourne faux.

/* ---------- Primitives modifiant 1 tour
------------------------------------------------------------------*/

void remplirTour(const unsigned int nbDisque, UnePile& tourARemplir);
// But remplit la tourARemplir avec nbDisques, du plus grand (en bas) au plus 
// petit (au sommet) de la tour

/* ---------- Primitives modifiant plusieurs tours
------------------------------------------------------------------*/

void initialiserTours(UnePile lesTours[]);
// But : initialise les NB_TOURS tours du tableau lesTours

void deplacerDisques(UnePile& tourOrigine, UnePile& tourDestination);
// But : déplace un disque d'une tour à une autre
// pré-condition : estDeplacable(tourOrigine, tourDestination) est VRAI
//                 c'est à dire :
//
//                 estVide(tourOrigine)  = FAUX
//                 et  (
//                        (estVide(tourDestination) = VRAI ) 
//                         OU 
//                        ( estVide(tourDestination)  = FAUX
//                          et
//                          sommet(tourOrigine) < sommet(tourDestination)
//                         )
//                     )

void deplacerPetit(UnePile lesTours[], unsigned int& posPetit);
// BUT : Déplacer le plus petit disque se trouvant en posPetit
//       vers la tour suivante dans lesTours et met à jour posPetit.

void deplacerAutre(UnePile lesTours[], unsigned int posPetit);
// BUT : Déplacer si c'est possible un autre disque que le petit.

/* ---------- Affichages
------------------------------------------------------------------*/

void afficherTour(UnePile tour);
// Affiche le contenu de la tour passée en paramètre

void afficherTours(const UnePile lesTours[]);
// Affiche le contenu des tours passées en paramètre 


/* ---------- Algorithmes de résolution du problème des tours de Hanoi
--------------------------------------------------------------------*/

void resoudreToursHanoiManuel(unsigned int nbDisques); 
// Buts : 1- faire résoudre les tours de Hanoi avec nbDisques au joueur
//        2-pour tester les primitives 
//        - initialiserTours()
//        - remplirTour()
//        - afficherTour()
//        - afficherTours()
//        - deplacerDisque()


/* ---------- Boîte à outils pour resolutionToursHanoiManuel ()
-------------------------------------------------------------------*/

    void saisieVerifDeplacementDemande(bool& reponseOk, unsigned int& origine, unsigned int& destination);
    // saisie du choix des tours prenant part au déplacement d'un disque :
    // 12 pour deplacement d'un disque de la tour 1 vers la tour 2
    // 13 pour deplacement d'un disque de la tour 1 vers la tour 3
    // 31 pour deplacement d'un disque de la tour 3 vers la tour 1
    // ...
    // 0 si aucun deplacement demandé

    int carToChiffre (char car);
    // convertit un caractère en chiffre



/* ---------- Boîte à outils pour resolutionToursHanoiAutomatique ()
-------------------------------------------------------------------*/
void resoudreToursHanoiAutomatique(unsigned int nbDisques);
// BUT : Résoud le jeu de Hanoi automatiquement suivant le nombre de disques nbDisque passé en paramètre.

unsigned int futurePosition (unsigned int posactuelle);
// BUT : Retourner la tour suivant celle definie par position
//       actuelle dans le sens T1 -> T2 -> T3 -> T1

// ======================================================================
int main()
{

    const unsigned int NB_MINIMUM_DISQUES = 3;   // nbre minimum autoris� de disques
    const unsigned int NB_MAXIMUM_DISQUES = 9;   // nbre maximum autoris� de disques
    unsigned int nbDisques;                     // nbre de disques à déplacer
    
    // (clavier), NB_MINIMUM_DISQUES, NB_MINIMUM_DISQUES >> saisie du nbre de disques >> nbDisques
    do
    {
        cout << "Entrer le nbre de disques de la tour de Hanoi (entre " << NB_MINIMUM_DISQUES << " et " << NB_MAXIMUM_DISQUES << ") : ";
        cin >> nbDisques;
    }
    while (!((nbDisques >=NB_MINIMUM_DISQUES) && (nbDisques <= NB_MAXIMUM_DISQUES)));


    // nbDisques >>  résoudre Hanoi manuellement pour le nb de disques entré >> ()
    //resoudreToursHanoiManuel(nbDisques);
    resoudreToursHanoiAutomatique(nbDisques);

    return 0;
}

// ======================================================================

// ---------- Observateurs
bool sontVides(const UnePile &tourA, const UnePile &tourB)
{
    return (estVide(tourA) && estVide(tourB));
}

bool disqueEstDeplacable (const UnePile& tourOrigine, const UnePile& tourDestination)
{
    bool estDeplacable;

    estDeplacable = false;

    if(estVide(tourOrigine)==false)
    {
        if(estVide(tourDestination)==true)
        {
            estDeplacable = true;
        }
        else if ((estVide(tourDestination)==false)&&(sommet(tourDestination)>sommet(tourOrigine)))
        {
            estDeplacable = true;
        }
    }
    return estDeplacable;
}

// ---------- Primitives modifiant 1 tour
void remplirTour(const unsigned int nbDisque, UnePile& tourARemplir)
{
    for(int i = nbDisque; i >= 1; i--)
    {
        empiler(tourARemplir, i);
    }
}

// ---------- Primitives modifiant plusieurs tours

void initialiserTours(UnePile lesTours[])
{
    for (unsigned int i = 0; i < 3; i++)
    {
        initialiser(lesTours[i]);
    }
}

void deplacerDisques(UnePile& tourOrigine, UnePile& tourDestination)
{
    /* -------------------------------- VARIABLES ------------------------------- */
    UnElement disques;

    /* ------------------------------- TRAITEMENTS ------------------------------ */
    depiler(tourOrigine, disques);
    empiler(tourDestination, disques);
}

void deplacerPetit(UnePile lesTours[], unsigned int& posPetit)
{   
    // VARIABLES
    unsigned int futurePetit;
    
    // TRAITEMENTS
    //Calculer la future position du petit disque
    futurePetit = futurePosition(posPetit);
    //Déplacer 1 disque depuis la Tour où il se trouve vers la Tour suivante
    deplacerDisques(lesTours[posPetit], lesTours[futurePetit]);
    //Mettre à jour posPetit
    posPetit = futurePetit;
}

void deplacerAutre (UnePile lesTours[], unsigned int posPetit)
{
    // VARIABLES
    unsigned int posSuivantPetit;
    unsigned int posRestante;

    //TRAITEMENTS
    posSuivantPetit = futurePosition(posPetit);
    posRestante = futurePosition(posSuivantPetit);
    // Tenter de déplacer Disque entre lesTours[posSuivantPetit] et lesTours[posRestante]
    if(disqueEstDeplacable(lesTours[posSuivantPetit], lesTours[posRestante])==true)
    {
        deplacerDisques(lesTours[posSuivantPetit], lesTours[posRestante]);
    }
    else if (disqueEstDeplacable(lesTours[posRestante], lesTours[posSuivantPetit])==true)
    {
        deplacerDisques(lesTours[posRestante], lesTours[posSuivantPetit]);
    }
}

// ---------- Affichages

void afficherTour(UnePile tour)
// paramètre passé par valeur
{
    unsigned int disque;
    cout << "{ ";
    while (!estVide(tour))
    {
        depiler(tour, disque);
        cout << disque << ". ";
    }
    cout << " }";
}

void afficherTours(const UnePile lesTours[])
{
    for(unsigned int i = 0; i <= NB_TOURS - 1; i++)
    {
        afficherTour(lesTours[i]);
    }
}


// ---------- Algorithme de résolution du problème des tours de Hanoi

void resoudreToursHanoiManuel(unsigned int nbDisques)
{
    /*  A DéCOMMENTER lorsque vous aurez codé les sous-programmes suivants :
        - initialiserTours()
        - remplirTour()
        - afficherTour()
        - afficherTours()
        - deplacerDisque()*/

    const unsigned int NOMBRE_DE_TOURS = 3;
    UnePile lesTours[NOMBRE_DE_TOURS];

    unsigned int tourOrigine;       // tour origine du déplacement
    unsigned int tourDestination;   // tour destination du déplacement
    bool deplacementDemande;        // = vrai si, mors de la saisie, un déplacement est demandé, 
                                    // = faux si pas de déplacement demandé

     // Initialiser tours et éléments de la réussite
    initialiserTours(lesTours);
    remplirTour(nbDisques, lesTours[0]);
    afficherTours(lesTours); cout << endl;

    // faire des déplacements manuels jusqu'à gagner
    do
    {
        // saisie - verif
        saisieVerifDeplacementDemande(deplacementDemande, tourOrigine, tourDestination);

        if (deplacementDemande)
        {
            // faire le déplacement demandé
            deplacerDisques (lesTours[tourOrigine], lesTours[tourDestination]);
            afficherTours(lesTours);
        }
    } while (!(estVide(lesTours[0]) && estVide(lesTours[1])));
}

void resoudreToursHanoiAutomatique(unsigned int nbDisques)
{
    UnePile lesTours[NB_TOURS];
    unsigned int posTourAvecPlusPetitDisque = 0;

    // Préparer les tours
    initialiserTours(lesTours);
    remplirTour(nbDisques, lesTours[0]);
    afficherTours(lesTours);
    cout << endl << "-----------------------------------------------" << endl<< endl;

    // lesTours >> déplacer les disques >> lesTours
    while (true)
    {
        if (sontVides(lesTours[0], lesTours[1]))
        {
            break;
        }

        deplacerPetit(lesTours, posTourAvecPlusPetitDisque);
        afficherTours(lesTours); cout << endl;

        if (sontVides(lesTours[0], lesTours[1]))
        {
            break;
        }

        deplacerAutre(lesTours, posTourAvecPlusPetitDisque);
        afficherTours(lesTours); cout << endl << endl;
    }
}

/* ---------- Boîte à outils pour Hanoi Manuel 
-------------------------------------------------------------------*/

void saisieVerifDeplacementDemande(bool& deplacement, unsigned int& origine, unsigned int& destination)
{
    string demandeSaisie    ;  // la demande de déplacement saisie
    bool reponseOk ;            // indicateur de validité de la réponse saisie : "12", "21", .... "31", ou "0xx"
    
    
    deplacement = false;   // = faux si l'utilisateur saisit "0" (pas de déplacement), vrai s'il saisit une des autres combinaisons autorisées
    cout << endl << " tourOrigine-tourDestination (exple : 12), 0 si pas de deplacement : " ;

    do
    {
        // saisie
        cin >> demandeSaisie;

        // analyse de validité
        reponseOk = false;
        if (
            (demandeSaisie[0] == '0') 
            || (    (demandeSaisie[0] >= '1') && (demandeSaisie[0] <= '3')
                    && (demandeSaisie[1] >= '1') && (demandeSaisie[1] <= '3')
                )
            ) 
        {
            reponseOk = true;
        }
    } while (!reponseOk);

    // demandeSaisie >> Analyse de la réponse correcte >>  >> deplacement, [origine, destination] 
    if (demandeSaisie[0] != '0')
    {
        origine = carToChiffre(demandeSaisie[0]) - 1;
        destination = carToChiffre(demandeSaisie[1]) - 1;
        deplacement = true;
    }
}

int carToChiffre (char car)
{
    int chiffre;
    chiffre = int(car-int('0'));
    return chiffre;
}

/* ---------- Boîte à outils pour resolutionToursHanoiAutomatique ()
---------------------------------------------------------------------*/

unsigned int futurePosition (unsigned int posactuelle)
{
    return (posactuelle+1)%NB_TOURS;
}