/*****************************************************************
******                  SELECT IMBRIQUES                   *******
*****************************************************************/

/*Requêtes décorrélées*/
/**********************/

/*Nom des équipes ayant un budget supérieur à la moyenne des budgets*/

SELECT nom
FROM EQUIPE2
WHERE budget > (SELECT AVG(budget)
                  FROM EQUIPE2);

/*Nom des équipes ayant un budget inférieur à ceux des équipes "equipe1" "equipe2" et "equipe3" */

SELECT nom
FROM EQUIPE2
WHERE budget < (SELECT MAX(budget)
                  FROM EQUIPE2
        WHERE code BETWEEN 1 AND 3) AND code > 3;

/*Nom des joueurs ayant un nombre de séléctions supérieur à au moins un des joueurs de l'équipe "equipe1" */

SELECT nom
FROM JOUEUR2
WHERE NBSELECTION > (SELECT MIN(NBSELECTION)
                   FROM JOUEUR2 JOIN EQUIPE2 ON codeEquipe = EQUIPE2.code
             WHERE codeEquipe = 1) AND codeEquipe > 1;

/*Joitures*/
/**********/

/*Nom des joueurs de l'équipe "équipe1"*/

SELECT J.nom
FROM JOUEUR2 J JOIN EQUIPE2 E ON codeEquipe = E.code
WHERE codeEquipe = 1;

/*Nom des joueurs ayant remporté la compétition "compétition2"*/

SELECT J.nom
FROM JOUEUR2 J JOIN EQUIPE2 E ON codeEquipe = E.code
WHERE E.nom NOT IN (SELECT E.nom
                      FROM EQUIPE2 E JOIN PARTICIPER2 ON E.code = codeEquipe
                     WHERE codeEquipe NOT IN (SELECT codeEquipe
                                                  FROM PARTICIPER2
                              WHERE resultat = 1 and codeCompetition = 2));

/*Joitures externes*/
/*******************/

/*Nom des équipes n'ayant pas gagné la compétition "competition2" */

SELECT E.nom
FROM EQUIPE2 E JOIN PARTICIPER2 ON E.code = codeEquipe
WHERE codeEquipe NOT IN (SELECT codeEquipe
                              FROM PARTICIPER2
                 WHERE resultat = 1 and codeCompetition = 2);

/*Nom des équipes n'ayant gagné aucun titre*/

SELECT E.nom
FROM EQUIPE2 E JOIN PARTICIPER2 ON E.code = codeEquipe
WHERE codeEquipe NOT IN (SELECT codeEquipe
                              FROM PARTICIPER2
                 WHERE resultat = 1);

/*Nom et prénom des joueurs n'ayant pas gagné la compétition "competition1" */

SELECT J.nom, J.prenom
FROM JOUEUR2 J JOIN EQUIPE2 E ON codeEquipe = E.code
WHERE E.nom IN (SELECT E.nom
                 FROM EQUIPE2 E JOIN PARTICIPER2 ON E.code = codeEquipe
                WHERE codeEquipe NOT IN (SELECT codeEquipe
                                             FROM PARTICIPER2
                         WHERE resultat = 1 and codeCompetition = 2));
                   
/*Nom et prénom des joueurs n'ayant aucun titre*/

SELECT J.nom, J.prenom
FROM JOUEUR2 J JOIN EQUIPE2 E ON codeEquipe = E.code
WHERE E.nom IN (SELECT E.nom
                  FROM EQUIPE2 E JOIN PARTICIPER2 ON E.code = codeEquipe
               WHERE codeEquipe NOT IN (SELECT codeEquipe
                                           FROM PARTICIPER2
                          WHERE resultat = 1));

/*Nom des équipes n'ayant pas gagné de compétition de type "coupe" */

SELECT E.nom
FROM EQUIPE2 E JOIN PARTICIPER2 ON E.code = codeEquipe
WHERE codeEquipe NOT IN (SELECT codeEquipe
                        FROM PARTICIPER2 JOIN COMPETITION2 C ON codeCompetition = C.code
             WHERE C.type = 'Coupe');


/*Nom et prénom des joueurs n'ayant pas gagné de compétition de type "coupe" */

SELECT J.nom, J.prenom
FROM JOUEUR2 J JOIN EQUIPE2 E ON codeEquipe = E.code
WHERE E.nom IN (SELECT E.nom
                  FROM EQUIPE2 E JOIN PARTICIPER2 ON E.code = codeEquipe
        WHERE codeEquipe NOT IN (SELECT codeEquipe
                                     FROM PARTICIPER2 JOIN COMPETITION2 C ON codeCompetition = C.code
                      WHERE C.type = 'Coupe'));