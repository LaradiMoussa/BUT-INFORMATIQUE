/*
    Programme : SimonEXT
    But : Jeu du Simon avec joker
    Date de dernière modification : 21 Octobre 2021
    Auteur : C.Naudi
    Remarques :
*/
#include <iostream>
#include "game-tools.h"
using namespace std;

int main(void)
{
    /////////////////////////
    // T Y P E S
    enum UneCouleur {Bleu, Vert, Jaune, Rouge};

    const unsigned int NB_CASES=90; //Le nombre de cases du tableau
    UneCouleur tab[NB_CASES]; //Le tableau contenant les couleurs
    UneCouleur verifErreur;
    
    /////////////////////////
    //V A R I A B L E S
    int nbTour=0; //Initialisation du nombre de tour à 0
    int lettreAAfficher; //Le nombre choisi aleatoirement qui servira à stocker la nouvelle lettre dans le tableau et à afficher la nouvelle lettre
    char saisie; //Le caractère de la saisie du joueur
    bool erreur; //Le booléen vérifiant si le joueur a fait une erreur
    int iteration=0; //La variable servant à afficher les caractères précedent durant la saisie du joueur
    //char verifErreur; //La variable servant à verifier si le caractère saisie correspond à celui du Simon
    int numeroErreur; //L'emplacement de l'erreur de la saisie
    bool jokerUtilise = false; //Le booléen servant à savoir si le joker a été utilisé, initialisé à faux

    /////////////////////////
    //T R A I T E M E N T S

    while(true)
    {
        //Affichage en-tête du jeu du Simon
        cout << "** Jeu du Simon **" <<endl;
        cout << endl;
        cout << "Simon : ";

        //Afficher les lettres précédentes
        for (int i = 0; i<=nbTour-1 ; i++)
        {
            switch (tab[i])
            {
                case Bleu:
                    afficherTexteEnCouleur("b ", bleu,false);
                    break;
                case Vert:
                    afficherTexteEnCouleur("v ", vert,false);
                    break;
                case Jaune:
                    afficherTexteEnCouleur("j ", jaune,false);
                    break;
                case Rouge:
                    afficherTexteEnCouleur("r ", rouge,false);
                    break;
            }
            pause(1);
        }

        //Afficher la nouvelle lettre
        lettreAAfficher = random(1,4);
        switch (lettreAAfficher)
        {
            case 1:
                tab[nbTour]= Bleu;
                afficherTexteEnCouleur("b ", bleu,false);
                break;
            case 2:
                tab[nbTour]= Vert;
                afficherTexteEnCouleur("v ", vert,false);
                break;
            case 3:
                tab[nbTour]= Jaune;
                afficherTexteEnCouleur("j ", jaune,false);
                break;
            case 4:
                tab[nbTour]= Rouge;
                afficherTexteEnCouleur("r ", rouge,false);
                break;
        }
        pause(1);
        cout << endl;
        //Faire le décompte de 3 secondes
        for (int i = 3; i >= 1; i--)
        {
            cout << i << "...";
            pause(1);
        }
        effacer();

        //Affichage de l'en-tête de l'écran du joueur
        cout << "** Jeu du Simon **"<<endl;
        cout << "[v -> vert, r -> rouge, b -> bleu, j -> jaune, * -> joker]" << endl;
        cout << endl;
        cout << "Joueur : ";

        //Boucle qui tourne autant de fois que le numero du tour
        for (int i =0; i<=nbTour; i++)
        {
            cin >> saisie;
            //Si le joker n'est pas utilise
            if (jokerUtilise == false)
            {
                //On demande au joueur de saisir tant que la saisie n'est pas une des 4 couleurs ou le joker
                while(!((saisie == 'b')||(saisie == 'v')||(saisie == 'j')||(saisie == 'r')||(saisie == '*')))
                {
                    cout << "Numero de couleur incorrect. Recommencer : ";
                    cin >> saisie;
                }
            }
            //Si le joker a deja ete utilise
            else
            {
                //On demande au joueur de saisir tant que la saisie n'est pas une des 4 couleurs
                while((!((saisie == 'b')||(saisie == 'v')||(saisie == 'j')||(saisie == 'r')))||(saisie=='*'))
                {
                    if((saisie!= '*')&&(!((saisie == 'b')||(saisie == 'v')||(saisie == 'j')||(saisie == 'r'))))   
                    {
                        cout << "Numero de couleur incorrect. Recommencer : "; 
                    }
                    else if(saisie == '*')
                    {
                        cout << "Joker deja utilise. Recommencer : ";
                    }
                    cin >> saisie; 
                }
            }
            //Si la saisie est differente du joker
            if (saisie !='*')
            {
                switch (saisie)
                {
                case 'b':
                    verifErreur = Bleu;
                    break;
                case 'v':
                    verifErreur = Vert;
                    break;
                case 'j':
                    verifErreur = Jaune;
                    break;
                case 'r':
                    verifErreur = Rouge;
                    break;
                }
            }
            //Si la saisie est un joker
            else
            {
                verifErreur = tab[i]; //On affiche le caractère
                jokerUtilise = true; //jokerUtilise passe à vrai
            }
            //Si verifErreur est différent du caractère du Simon
            if (verifErreur != tab[i])
            {
                erreur = true; //Erreur passe à vrai
                numeroErreur = i; //La position de l'erreur est stockée dans numeroErreur
                break; //S'il la saisie ne correspond pas à celle du Simon on quitte la boucle de saisie
            }
            else
            //Si la saisie correspond à celle du Simon
            {
                //On efface l'écran
                effacer();
                //On affiche l'en-tête de l'écran de saisie du joueur
                cout << "** Jeu du Simon **"<<endl;
                cout << "[v -> vert, r -> rouge, b -> bleu, j -> jaune, * -> joker]" << endl;
                cout << endl;
                cout << "Joueur : ";
                //Pour chaque saisie cela affiche les caractères précédents en couleur (sauf si c'est la première)
                for(int i=0; i <= iteration; i++)
                {
                    switch (tab[i])
                    {
                        case Bleu:
                            afficherTexteEnCouleur("b ", bleu,false);
                            break;
                        case Vert:
                            afficherTexteEnCouleur("v ", vert,false);
                            break;
                        case Jaune:
                            afficherTexteEnCouleur("j ", jaune,false);
                            break;
                        case Rouge:
                            afficherTexteEnCouleur("r ", rouge,false);
                            break;
                    }
                }
                iteration ++;
            }
        }
        //S'il n'y a pas d'erreur de saisie
        if(erreur == false)
        {
            pause (1); //Pause d'1 sec pour voir le dernier caractere s'afficher en couleur
            effacer(); //Effacer l'écran
            iteration=0; //Remise à 0 de la variable iteration
            nbTour++; //Incrémentation du nombre de tour
        }
        else
        //S'il y a une erreur de saisie on quitte le jeu pour afficher l'écran de fin
        {
            break;
        }
    }
    effacer();

    //Ecran de fin de partie
    cout << "** Jeu du Simon - Fin de partie **" << endl;
    cout << "Erreur de saisie de la couleur numero " << numeroErreur +1 << endl;
    cout << endl;
    cout << "Simon : ";
    //Affichage du dernier affichage du Simon
    for (int i=0; i <= nbTour; i++)
    {
        switch (tab[i])
        {
        case Bleu:
            afficherTexteEnCouleur("b ", bleu,false);
            break;
        case Vert:
            afficherTexteEnCouleur("v ", vert,false);
            break;
        case Jaune:
            afficherTexteEnCouleur("j ", jaune,false);
            break;
        case Rouge:
            afficherTexteEnCouleur("r ", rouge,false);
            break;
        }
    }
    cout << endl;
    //Affichage de la saisie du joueur jusqu'à l'erreur
    cout << "Joueur : ";
    //Affichage de caractère précédant l'erreur
    for (int i=0; i < numeroErreur; i++)
    {
        switch (tab[i])
        {
        case Bleu:
            afficherTexteEnCouleur("b ", bleu,false);
            break;
        case Vert:
            afficherTexteEnCouleur("v ", vert,false);
            break;
        case Jaune:
            afficherTexteEnCouleur("j ", jaune,false);
            break;
        case Rouge:
            afficherTexteEnCouleur("r ", rouge,false);
            break;
        }
    }
    //Affichage du caractère étant l'erreur
    switch (saisie)
    {
    case 'b':
        afficherTexteEnCouleur("b ", bleu,false);
        break;
    case 'v':
        afficherTexteEnCouleur("v ", vert,false);
        break;
    case 'j':
        afficherTexteEnCouleur("j ", jaune,false);
        break;
    case 'r':
        afficherTexteEnCouleur("r ", rouge,false);
        break;
    }
    cout << endl;
    //Affichage du score
    cout << "Score : " << nbTour << endl;
    return 0;
}