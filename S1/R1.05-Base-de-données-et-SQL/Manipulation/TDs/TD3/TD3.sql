/* Exercice 1 : Expliquez en quoi consiste les 4 types de JOIN et quelles sont les instructions SQL qui les exécutent

INNER JOIN : jointure interne pour retourner les enregistrements quand la condition est vrai
            dans les 2 tables. C'est l'une des jointures les plus communes.

LEFT JOIN (ou LEFT OUTER JOIN) : joiture externe pour retourner tous les enregistrements de la table
            de gauche (LEFT=gauche) même si la condition n'est pas vérifiée dans l'autre table.

RIGHT JOIN (ou RIGHT OUTER JOIN) : joiture externe pour retourner tous les enregistrements de la table
            de droite (RIGHT=droite) même si la condition n'est pas vérifiée dans l'autre table.

FULL JOIN (ou FULL OUTER JOIN) : jointure externe pour retourner les résultats quand la condition est
            vrai dans au moins une des 2 tables.

*/

/* Exercice 2 : Concevez, expliquez et créez (commande SQL) 2 entités : EQUIPE (déjà introduite la semaine dernière)
                et COMPETITION liéez par l'association PARTICIPER avec les cardinalités 1,N et 1,N */

SELECT *
FROM JOUEUR JOIN EQUIPE ON codeEquipe = Equipe.code;

CREATE TABLE COMPETITION (
    code NUMBER (3) PRIMARY KEY NOT NULL,
    type VARCHAR2 (25) NOT NULL,
    saison NUMBER (4) NOT NULL
);

/* Exercice 3 : Ecrire la requête permettant d'établir la liste des compétitions (nom & type) auxquelles
                l'équipe dont le nom est 'E' */

SELECT nom, type
FROM COMPETITION JOIN EQUIPE ON codeEquipe = Equipe.code
WHERE Equipe.nom = 'E' ;
