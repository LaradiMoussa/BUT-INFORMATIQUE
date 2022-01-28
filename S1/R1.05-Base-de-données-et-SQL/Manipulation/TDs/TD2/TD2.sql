/* Exercice 1 : Concevez, expliquez et créez (SQL). Le modèle physique pour 2 entités : JOUEUR et EQUIPE liées par
   l'association APPARTENIR avec les cardinalités 1,1 et 1,N */

CREATE TABLE JOUEUR (
    code NUMBER (10) PRIMARY KEY NOT NULL,
    nom VARCHAR2 (25) NOT NULL,
    prenom VARCHAR2 (25) NOT NULL,
    nationalite VARCHAR2 (25) NOT NULL,
    nbSelection NUMBER (3),
    FOREIGN KEY (codeEquipe) REFERENCES EQUIPE (code)
);

CREATE TABLE EQUIPE (
    code NUMBER (10) PRIMARY KEY NOT NULL,
    nom VARCHAR2 (25) NOT NULL,
    capacite VARCHAR2 (25) NOT NULL,
    budget NUMBER (15)
);

/* Exercice 2 : Ecrivez la requête SQL pour obtenir la liste des joueurs d'une équipe donnée */

SELECT *
FROM EQUIPE
WHERE nom = 'nomEquipe';