## R1.01 Initiation au devéloppement (Partie 2)

### Utilisation de piles

### 1. Afficher le contenu d'une pile
*On souhaite écrire un sous-programme, nommé `afficher`, qui affiche à l'écran le contenu d'une pile `pile` passée en paramètre (par exemple, une pile d'entiers)*

##### 1. Écrire en C++ la déclaration de ce sous-programme.

```cpp
void afficher (const UnePile& pile);
//BUT : Affiche à l'écran le contenu de la pile.
```

##### 2. Définir la stratégie de cet algorithme.

Il faut `afficher` le sommet de la pile ensuite `depiler`la pile pour accéder au suivant. Faire ces actions tant que la pile n'est pas `vide`.

##### 3. Justifier les choix suivants : procédure/fonction et type de passage de paramètre choisi.

Le choix est de le faire sous forme de procédure car ce n'est que de l'affichage, ensuite le passage de paramètre se fait par **référence constante** car la pile ne doit pas être modifiée.
Donc impossible pas référence.

##### 4. Écrire l'algorithme correspondant, accompagné d'un *dictionnaire succinct* des variables/constantes utilisées : nom, type, signification.

```cpp
#include "pile.h"

void afficher (const UnePile& pile)
{
    unePile copiePile; // La copie de la pile pile inversée
    int x; // Copie de l'élément se situant au sommet de la pile pile

    //Initialiser
    initialiser (copiePile);

    //Afficher le contenu de la pile
    while(estVide(pile)==false)
    {
        depiler(pile, x);
        afficher(x);
        empiler(copiePile, x);
    }

    //Recopier la pile
    while(estVide(copiePile)==false)
    {
        depiler(copiePile, x);
        empiler(pile, x);
    }
}
```

| nom | type | signification |
| :---: | :---: | :---: |
| `pile` | unePile | La pile d'élément(s) passée en paramètre |
| `copiePile` | unePile | La copie de la pile `pile` inversée |
| `x` | int | Copie de l'élément se situant au sommet de la pile `pile` |

```cpp
#include "pile.h"

void afficher (const UnePile& pile)
{
    while(estVide(pile) == false)
    {
        cout << sommet(pile) << " ";
        depiler(pile);
    }
}
```
| nom | type | signification |
| :---: | :---: | :---: |
| `pile` | unePile | La pile d'élément(s) passée en paramètre |

```cpp
#include "pile.h"

void afficher (const UnePile& pile)
{
    unsigned int x; // Copie de l'élément du sommet de la pile

    while(estVide(pile) == false)
    {
        depiler(pile, x);
        cout << x << " ";
    }
}
```
| nom | type | signification |
| :---: | :---: | :---: |
| `pile` | unePile | La pile d'élément(s) passée en paramètre |
| `x` | int | Copie de l'élément se situant au sommet de la pile `pile` |

### 2. Résolution du problème des tours de Hanoï

##### 1. Vérifier le déroulement de l'algorithme en parcourant les résultats d'exécutions fournis.

```cpp
// {nbDisques} >> Résoudre Hanoï

// {nbDisques} >> Préparer les tours >> {t1, t2, t3}
// ...

// {?} >> Déplacer les disques >> {?}
while(true)
{
    if(estVide(t1) && estVide(t2))
    {
        break;
    }

    // {?} >> Déplacer le plus petit disque >> {?}
    // ...

    if(estVide(t1) && estVide(t2))
    {
        break;
    }

    // {?} >> Déplacer un autre disque >> {?}
    // ...
}
```

##### 2. Lister les éléments prenant part à cet algorithme et écrire leur déclaration en C++. Privilégier les collections d'éléments homogènes.

| nom | type | signification |
| :---: | :---: | :---: |
| `nbDisques` | entier non signé | Nombre de disques à déplacer|
| `NB_TOURS` | entier non signé constant = 3 | Nombres de tours présentes dans le jeu |
| `lesTours` | unePile | Le tableau contenant les 3 tours |

##### 3. Corriger/compléter l'algorithme pour le rendre conforme aux réponses précédentes.

```cpp
/* -------------------------------------------------------------------------- */
/*                           CHANGEMENTS DANS PILE.H                          */
/* -------------------------------------------------------------------------- */
typedef unsigned int UnElement;

/* -------------------------------------------------------------------------- */
/*                           CHANGEMENTS DANS L'ALGO                          */
/* -------------------------------------------------------------------------- */
// {nbDisques, NB_TOURS} >> Résoudre Hanoï

// {nbDisques, NB_TOURS} >> Préparer les tours >> {lesTours}
// ...

// {} >> Déplacer les disques >> {}
while(true)
{
    if(estVide(lesTours[0]) && (estVide(lesTours[1])))
    {
        break;
    }

    // {} >> Déplacer le plus petit disque >> {}
    // ...

    if(estVide(lesTours[0]) && (estVide(lesTours[1])))
    {
        break;
    }

    // {} >> Déplacer un autre disque >> {}
    // ...
}
```

##### 4. Pour obtenir les affichages présentés dans le sujet, le programmeur ajouté à l'algorithme initial plusieurs appel d'une action "afficher les tours".
-   a) Marquer d'une croix sur l'algorithme les endroits où cette action a été appelée.
```cpp
#include "pile.h"

// {nbDisques, NB_TOURS} >> Résoudre Hanoï

// {nbDisques, NB_TOURS} >> Préparer les tours >> {lesTours}
// ...

//-----------------AFFICHER LES TOURS-------------------//

// {} >> Déplacer les disques >> {}
while(true)
{
    if(estVide(lesTours[0]) && (estVide(lesTours[1])))
    {
        break;
    }

    // {} >> Déplacer le plus petit disque >> {}
    // ...

    //-----------------AFFICHER LES TOURS-------------------//

    if(estVide(lesTours[0]) && (estVide(lesTours[1])))
    {
        break;
    }

    // {} >> Déplacer un autre disque >> {}
    // ...

    //-----------------AFFICHER LES TOURS-------------------//
}
```
-   b) Écrire la déclaration du sous-programme `afficherLesTours` correspondant.

```cpp
void afficherLesTours(const unePile& lesTours[]);
// BUT : Affiche le contenu des tours
// Remarque : La taille du tableau, càd le nombre de tours étant
//            toujours constant = 3, on ne le met pas en paramètre
//            ce sera une variable globale de notre problème.
```

-   c) Écrire l'algorithme de `afficherLesTours`.

```cpp
#include "pile.h"

void afficherLesTours(const unePile& lesTours[])
{
    for(int i = 0; i <= NB_TOURS - 1; i++)
    {
        afficher(lesTours[i]);
    }
}
```

##### 5. Écrire la déclaration C++ du sous-programme correspondant à l'algorithme "résoudre Hanoï".

```cpp
void resoudreToursHanoi(unsigned int nbDisques);
// BUT : Résoud le problème des tours de Hanoi avec nbDisque >= 3
```

##### 6. Nous aurons à deplacer les disques entre les tours. Pour ce faire :
-   a) Écrire la déclaration C++ du sous-programme `déplacerDisque` dont les paramètres sont :
    -   `tourOrigine`, une tour
    -   `tourDestination`, une tour
    -   et dont le but est de déplacer le sommet de `tourOrigine` vers la tour `tourDestination`. On supposera que le déplacement est possible.
    ```cpp
    void deplacerDisques(unePile& tourOrigine, unePile& tourDestination);
    // BUT : Déplace 1 disque de la tourOrigine vers la tour Destination
    // Pré-conditions : Pour que le déplacement dans le jeu soit autorisé :
    //                  - tourOrigine non vide
    //                  - ET (tourDestination vide ou (tourDestination vide ET
    //                    (sommet(tourOrigine)<sommet(tourDestination))
    ```
    -   Écrire l'algorithme de ce sous-programme
    ```cpp
    void deplacerDisques(unePile& tourOrigine, unePile& tourDestination)
    {
        depiler(tourOrigine, disques);
        empiler(tourDestination, disques);
    }
    ```

##### 7. Action `preparerLesTours`
-   b) En vous basant sur les résultats d'éxecution founis, indiquer le contenu de chaque tour après éxecution de cette action.
`t1` = `lesTours[0]` est **pleine** avec les disques empilés du plus grand (en bas) au plus petit (en haut).
`t2` & `t3` = `lesTours[1]` & `lesTours[2]` sont **vides**.
-   c) Écrire la déclaration C++ d'un sous-programme `remplirTour` dont les paramètres sont :
    -   `nbDisques`, le nombre de disques à empiler sur
    -   `tourARemplir`, la tour recevant les disques.
    -   et dont le but est de remplir la tour avec le nombre de disques fournis, du plus, grand (en bas) au plus petit (en haut) de la tour.
    ```cpp
    void remplirTour (unsigned int nbDisque, unePile& tourARemplir);
    // BUT : Remplir une tour de nbDisque du plus grand au plus
    //       petit de bas en haut.
    // Pré-condition : tourARemplir est vide.
    ```
-   d) Écrire l'algorithme de l'action `remplirTour`
    ```cpp
    for(int i = nbDisque; i >= 1; i--)
    {
        empiler(tourARemplir, i);
    }
    ```
-   e) Écrire l'algorithme de l'action `preparerLesTours`
    ```cpp
    //Initialiser les tours
    for( int i = 0; i <= NB_TOURS-1; i++)
    {
        initialiser(lesTours[i]);
    }

    remplirTour(nbDisques, lesTours[0]);
    ```

##### 8. Action `deplacerPetit`
-   a) Trouver une stratégie de résolution pour les actions `deplacerPetit`.
-   b) Écrire en C++ la déclaration de ce sous-programme.
    ```cpp
    void deplacerPetit(UnePile lesTours[], unsigned int& posPetit);
    // BUT : Déplacer le plus petit disque se trouvant en posPetit
    //       vers la tour suivante dans lesTours et met à jour posPetit.
    ```
-   c) Écrire l'algorithme de ce sous-programme.
    ```cpp
    void deplacerPetit(UnePile lesTours[], unsigned int& posPetit)
    {   
        // VARIABLES
        unsigned int futurePetit;
        
        // TRAITEMENTS
        //Calculer la future position du petit disque
        futurePetit = (posPetit+1)%%NB_TOURS;
        //Déplacer 1 disque depuis la Tour où il se trouve vers la Tour suivante
        deplacerDisques(lesTours[posPetit], lesTours[futurePetit]);
        //Mettre à jour posPetit
        posPetit = futurePetit;
    } 
    ```
    ##### Action `futurePosition`
    ```cpp
    unsigned int futurePosition (unsigned int posactuelle);
    // BUT : Retourner la tour suivant celle definie par position
    //       actuelle dans le sens T1 -> T2 -> T3 -> T1
    ```

##### 9. Action `deplacerAutre`
-   a) Trouver les déplacements qu'il est possible de faire dans cette action.
    Il faut que A soit **non vide** et :
    -   **B vide**
    -   OU **B non vide** et **sommet(B) > sommet(A)**
-   b) Trouver une stratégie de résolution pour les actions.

-   c) Écrire en C++ la déclaration de ce sous-programme.
    ```cpp
    void deplacerAutre(UnePile lesTours[], unsigned int posPetit);
    ```
-   d) Écrire l'algorithme de ce sous-programme.
    ```cpp
    void deplacerAutre (UnePile lesTours[], unsigned int posPetit)
    {
        posSuivantPetit = futurePosition(posPetit);
        posRestante = futurePosition(posSuivantPetit);
        // Tenter de déplacer Disque entre lesTours[posSuivantPetit] et lesTours[posRestante]
        if(disqueEstDeplacable(lesTours[posSuivantPetit], lesTours[posRestante])==true)
        {
            deplacerDisque(lesTours[posSuivantPetit], lesTours[posRestante]);
        }
        else if (disqueEstDeplacable(lesTours[posRestante], lesTours[posSuivantPetit])==true)
        {
            deplacerDisque(lesTours[posRestante], lesTours[posSuivantPetit]);
        }
    }
    ```
    **Action `disqueEstDeplacable`**
    ```cpp
    bool disqueEstDeplacable (const UnePile& tourOrigine, const UnePile& tourDestination);
    // BUT : retourne vrai si la condition suivante est verifiée sinon retourne faux.
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
    ```
    **Action `sontVides`**
    ```cpp
    bool sontVides(const UnePile& tourA, UnePile& tourB);
    // BUT : retourne vrai si tour A et tourB sont vides, retourne faux sinon

    bool sontVides(const UnePile& tourA, UnePile& tourB)
    {
        return (estVide(tourA)&&estVide(tourB));
    }
    ```

##### 10. Sous-programme `afficherTour`
-   a) Écrire la déclaration C++ d'un sous-programme `afficherTour` dont les paramètres sont :
    -   `tour`, la tour (pile) à afficher
    -   et dont le but est d'afficher le contenu d'une tour selon le format suivant
    -   {2. 3. } pour une tour non vide
    -   { } pour une tour vide
    **Inspirez-vous de l'exercice 1 pour faire votre choix**
-   b) Écrire l'algorithme associé à la déclaration choisie.

