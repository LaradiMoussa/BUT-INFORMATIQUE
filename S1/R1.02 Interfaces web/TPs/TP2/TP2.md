# TP2


### Scénario du cas où l'utilisateur ajoute une nouvelle pièce pour son ampoule dans l'application

| Scénario |  |  |
| ----------- | ----------- | ----------- |
| **Cas d'utilisation** | L'utilisateur ajoute une nouvelle pièce pour son ampoule à l'application |  |
| **Acteurs primaires** | L'utilisateur |  |
| **Système** | L'application |  |
| **Intervenants** |  |  |
| **Niveau** |  |  |
| **Pré-conditions** | L'utilisateur est connecté et est sur la page d'accueil |  |
|  | Utilisateur | Système |
| 1 | L'utilisateur clique sur l'icône ampoule |  |
| 2 |  | Le système affiche la liste des pièces dans lesquelles l'utilisateur a paramétré les ampoules |
| 3 | L'utilisateur clique sur le bouton ajouter |  |
| 4 |  | Le système affiche un "formulaire" et le bouton "se connecter" |
| 5 | "L'utilisateur saisi le nom ""nomDeLaPièce"" pour désigner la pièce où est son ampoule" |  |
| 6 | "L'utilisateur clique sur le bouton connecter afin que le lien se fasse entre l'application et l'ampoule" |  |
| 7 |  | Le système essaye de se connecter à l'ampoule |
| 8 |  | Le système affiche le message "Connexion établie avec succès" |
| 9 |  | Le système ferme le formulaire |
| 10 |  | Le système ajoute la nouvelle pièce à la liste |
| **Extension** | **Le système ne parvient pas à se connecter à l'ampoule** |  |
| 8.A.1 |  | Le système affiche le message "Connexion echouée avec l'ampoule" |
| 8.A.2 |  | Retour en 6 |
