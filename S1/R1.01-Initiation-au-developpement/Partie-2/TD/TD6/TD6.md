## R1.01 Initiation au devéloppement (Partie 2)

### Utilisation de Files

#### 1. Afficher le contenu d'une file

1.  Écrire en C++ la déclaration du sous-programme

```cpp
#include "File.h"

void afficher (const UnePile& file)
{
    while(estVide(file) == false)
    {
        cout << premier(file) << " ";
        defiler(file);
    }
}
```
| nom | type | signification |
| :---: | :---: | :---: |
| `file` | UneFile | La file d'élément(s) passée en paramètre |
2. Justifier les choix suivants : procédure/fonction et type de passage de paramètre choisi.

3. Définir la stratégie de cet algorithme
    a.  Modèles d'algorithmes vu en cours applicables pour atteindre le but visé. *Justifier*
    b.  Action à répéter
    c.  La/Les conditions de fin de répétition

4. Écrire l'algorithme correspondant accompagné d'un *dictionnaire succints* des variables/constantes utilisées : nom, type, signification

#### 2. Manipulation de files

1.  Écrire les pré-conditions et les post-conditions associées à ce sous-programme

2.  Écrire en C++ la déclaration de ce sous-programme

3. Décrire la stratégie utilisée dans l'algorithme (max 8 lignes). Pour cela, préciser :
    a.  Le modèle d'algorithme à utiliser
    b.  La/Les actions à répéter
    c.  Si cela est pertinent, la/les condition(s) de fin d'itération.

4.
    a. Écrire l'algorithme de ce sous-programme
    b. Accompagner l'algorithme d'un dictionnaire succint (nom, type, signification) des éléments autres que ceux déjà données dans le sujet.

5. *Pour une file contenant nbElements. Remplacer chaque élément par sa valeur dans les phrases ci-dessous*
    Pour une file contenant `nbElements`, mon sous-programme `defilerJusquA(file)` appelle :
    a.  le sous-programme `premier(file)` au maximum `nbAppelsPremier` fois
    b.  le sous-programme `defiler(file)` au maximum `nbAppelsDefiler` fois
    c.  le sous-programme `defiler(file)` au maximum `nbAppelsEnfiler` fois
    d.  le sous-programme `taille(file)` au maximum `nbAppelsTaille` fois

6.  Remarque : dans quelle situation les maximums calculés précédemment seront-ils atteints ?

#### 3. Structure de données adéquate

1.  Pour chacun des cas (a, b, c), indiquer quelle est la structure de données ***la plus appropriée*** à choisir pour l'élément `contenant_2` de sorte à produire l'affichage indiqué.

2.  Pour chacun des cas (a, b, c)
    -   Écrire la déclaration d'un sous-programme `remplirContenant` dont les paramètres sont :
        -   `nbValeurs`, le nombre de valeurs à mettre dans
        -   `nbDestination`, l'élément recevant les `nbValeurs` entiers
    -   Écrire l'algorithme de ce sous-programme

3.  Pour chacun des cas (a, b, c) :
    -   Écrire la délaration d'un sous-programme `TransfertContenu` dont les paramètres sont :
        -   `origine`, le paramètre duquel on enlève le contenu
        -   `destination`, le paramètre recevant le contenu
    -   Écrire l'algorithme de ce sous-programme