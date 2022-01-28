/*Afficher la capacité du stade le plus petit*/

SELECT MIN (capaciteStade)
FROM EQUIPE2;

/*Afficher le budget du stade le plus important*/

SELECT MAX (budget)
FROM EQUIPE2;

/*Afficher la liste des joueurs (nom,prenom) triée par ordre alphabétique*/

SELECT nom, prenom
FROM JOUEUR2
ORDER BY nom;

/*Afficher la liste des équipes (nom, capacite) triée par capacité de stade décroissant*/

SELECT nom, capaciteStade
FROM EQUIPE2
ORDER BY capaciteStade DESC;

/*Afficher le nombre de joueurs par équipe*/

SELECT COUNT (nom)
FROM JOUEUR2
GROUP BY codeEquipe;

/*Afficher la liste des équipes (nom) participant à la compétition "compétition"*/

SELECT EQUIPE2.nom
FROM EQUIPE2 JOIN PARTICIPER2 ON EQUIPE2.code = codeEquipe JOIN COMPETITION2 ON codeCompetition = COMPETITION2.code
WHERE COMPETITION2.nom = 'Premiere League';

/*Afficher la liste des équipes (nom) encore qualifiées pour la competition "competition*/

/*Afficher le classement de la compétition "compétition" (rang, nom, équipe)*/

SELECT resultat, C.nom, E.nom
FROM EQUIPE2 E JOIN PARTICIPER2 ON E.code = codeEquipe JOIN COMPETITION2 C ON codeCompetition = C.code
WHERE C.nom = 'Premiere League';

/*Afficher la liste des joueurs (nom) ayant un ou plusieurs homonymes*/

SELECT nom, prenom
FROM JOUEUR2 t1
WHERE EXISTS (SELECT * FROM JOUEUR2 t2 WHERE t1.code <> t2.code AND t1.prenom = t2.prenom);

/*Afficher le nom de l'équipe ayant le stade le plus petit*/

SELECT nom
FROM EQUIPE2
WHERE budget = (SELECT MIN(budget)
                 FROM EQUIPE2);

/*Afficher le nom de l'équipe ayant le budget le plus important*/

SELECT nom
FROM EQUIPE2
WHERE budget = (SELECT MAX (budget)
                 FROM EQUIPE2);