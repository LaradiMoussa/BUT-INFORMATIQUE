/*
    Programme : SeptEtDemi
    But : Jouer au jeu du septEtdemi
    Date de dernière modification : 25 Septembre 2021
    Auteur : C.Naudi
    Remarques : Version standard du jeu
*/

#include<iostream>
#include <unistd.h>
using namespace std;

int randomMinMax(int min, int max);

int main (){
    ///////////////////////////
    //Déclaration des variables
    int scorePartie = 0;
    int scoreTotal = 0;
    int de1;
    int de2;
    int compteurManches;
    char jouer;
    int nbManches;

    //////////////////////////
    //Traitements

    //Affichage des règles
    cout << "S E P T   E T   D E M I   (j o u e u r   s e u l)"<<endl;
    cout << endl;
    cout << "Une partie se déroule en 5 tours." <<endl;
    cout << "Le cumul du score des 5 tours constitue le score pour la partie." <<endl;
    cout << "L'objectif est d'obtenir le plus grand score." <<endl;
    cout << endl;
    cout << "Dans son tour, le joueur lance 2 des, autant de fois qu'il le veut." <<endl;
    cout << "Il accumule les points de chaque lancer pour etablir le score du tour." <<endl;
    cout << "- S'il décide de s'arreter, il conserve le score accumule dans le tour ;"<<endl;
    cout << "  ce score vient augmenter le score de la partie," <<endl;
    cout << "- S'il obtient 7 lors d'un lancer, le tour se termine avec un score de zero ;" <<endl;
    cout << "  il n'augmente pas le score de la partie."<<endl;
    cout << endl;

    //Demande de saisie du nombre de manches à jouer
    do{
        cout << "Combien de manches voulez-vous jouer ? ";
        cin >> nbManches;
    }while (!(nbManches > 0));

    //Tant que compteurManches n'est pas égal au nombre de manches nbManches saisi on joue une nouvelle manche
    do
    {
        for (int i = 1; i <= nbManches; i++)
        {
            cout << "TOUR " << i << "/" << nbManches << " - SCORE PARTIE (" << scoreTotal << ")" <<endl;
            do
            {
                scoreTotal += scorePartie;
                do
                {
                    cout << " tour " << i << "/5 (" << scoreTotal << ") - jouer (o/n) ? ";
                    cin >> jouer;

                } while (!((jouer == 'o')||(jouer == 'O')||(jouer == 'n')||(jouer == 'N')));
                
                //Choix Machine aleatoire
                srand(time(NULL)); // INITIALISATION DU GENERATEUR DE NBRE ALEATOIRE RAND

                if((jouer == 'o')|| (jouer == 'O'))
                {
                    //Generation du nombre aleatoire
                    de1 = randomMinMax (1,7);
                    de2 = randomMinMax (1,7);

                    scorePartie = de1 + de2;

                    cout << "   " << de1 << " + " << de2 << " = " << scorePartie << endl;
                }

                if (scorePartie == 7)
                {
                    cout << "  remise a zero !!!!" <<endl;
                    scorePartie = 0;
                    scoreTotal = 0;
                    break;
                }

            } while (!((jouer == 'n')||(jouer == 'N')));
            scorePartie = 0;
            compteurManches++;
            cout <<endl;
        }
    } while (!(compteurManches==nbManches));

    //Afficher le score de la partie
    cout << "S C O R E   P A R T I E : " << scoreTotal << endl;

    return 0;
}

int randomMinMax (int min, int max){
    return rand()%(max-min) + min;
}