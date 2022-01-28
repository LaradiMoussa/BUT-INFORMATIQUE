/*Afficher la liste des nationalites des joueurs*/
SELECT DISTINCT nationalite
FROM JOUEUR2;

/*Afficher la liste des équipes (nom, capacité, budget)*/
/*1*/
SELECT nom, capaciteStade, budget
FROM EQUIPE2;

/*2*/

/*Afficher la liste des joueurs (nom,prenom) dont le nom finit par la lettre "o"*/
SELECT nom, prenom
FROM JOUEUR2
WHERE nom LIKE '%o';

/*Afficher le nombre de nationalités différentes*/
SELECT COUNT (DISTINCT nationalite)
FROM JOUEUR2;

/*Afficher la liste des joueurs de l'équipe "Manchester City"*/
SELECT J.nom, prenom
FROM JOUEUR2 J JOIN EQUIPE2 E ON codeEquipe = E.codeEquipe
WHERE E.nom = 'Manchester City';

/*Afficher le nombre de joueur de l'équipe "Manchester City"*/
SELECT COUNT (DISTINCT J.code)
FROM JOUEUR2 J JOIN EQUIPE2 E ON codeEquipe = E.code
WHERE E.nom = 'Manchester City';

/*Afficher le total de sélection en équipe nationale des joueurs de l'équipe ** */

/*Afficher la liste des équipes (nom, capacité) dont le stade a une capcité comprise entre 70000 & 80000 */
/*1*/
SELECT nom, capaciteStade
FROM EQUIPE2
WHERE capaciteStade BETWEEN 70000 AND 80000;

/*2*/
SELECT nom, capaciteStade
FROM EQUIPE2
WHERE capaciteStade>=70000 AND capaciteStade<=80000;

/*Afficher la capacite moyenne des stades*/
SELECT AVG (capaciteStade)
FROM EQUIPE2;

/*Afficher la somme des budgets*/
SELECT SUM(budget)
FROM EQUIPE2;