/* Creation de la table étudiant */

CREATE TABLE ETUDIANT (
    code NUMBER (4) PRIMARY KEY NOT NULL,
    nom VARCHAR2 (25) NOT NULL,
    prenom VARCHAR2 (25) NOT NULL,
    groupeTD NUMBER (1) NOT NULL,
    groupeTP NUMBER (1) NOT NULL,
    anneeEtude NUMBER (2) NOT NULL,
    filiere VARCHAR2 (25) NOT NULL,
    genre VARCHAR2 (2) NOT NULL
);

/* Insertion des tuples */

INSERT INTO ETUDIANT
VALUES (1,'NAUDI', 'Colas', 2, 4, 2, 'Informatique', 'M');

INSERT INTO ETUDIANT
VALUES (2,'ETCHEVERRY', 'Laura', 1, 1, 1, 'Biologie', 'F');

INSERT INTO ETUDIANT
VALUES (3,'FERRY', 'Laurent', 3, 5, 1, 'Informatique', 'M');

INSERT INTO ETUDIANT
VALUES (4,'BORRY', 'Florence', 1, 1, 2, 'Biologie', 'F');

INSERT INTO ETUDIANT
VALUES (5,'DEFRET', 'Marie', 2, 4, 1, 'Informatique', 'F');

INSERT INTO ETUDIANT
VALUES (6,'PATRACK', 'Tony', 3, 5, 2, 'Biologie', 'M');

/* Afficher la liste des filles qui sont en biologie */

SELECT nom, prenom
FROM ETUDIANT
WHERE filiere = 'Biologie' AND genre = 'F';

/* Afficher les garçons qui sont dans le TD3 peu importe la filiere */

SELECT nom, prenom
FROM ETUDIANT
WHERE groupeTD=3 AND genre = 'F';
