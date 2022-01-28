CREATE TABLE EQUIPE2 (
       code NUMBER(3) PRIMARY KEY,
       nom VARCHAR2(25),
       nationalite VARCHAR2 (25),
       abbreviation VARCHAR2 (5)
);

CREATE TABLE JOUEUR2 (
       code NUMBER(3) PRIMARY KEY,
       nom VARCHAR2 (25) NOT NULL,
       prenom VARCHAR2 (25) NOT NULL,
       poste VARCHAR2 (15),
       nationalite VARCHAR2 (25),
       dateNais DATE,
       numMaillot NUMBER (2),
       genre VARCHAR2 (2),
       codeEquipe NUMBER(3),
       FOREIGN KEY (codeEquipe) REFERENCES EQUIPE2(code)
);

CREATE TABLE COMPETITION2(
       code NUMBER (3) PRIMARY KEY,
       nom VARCHAR2 (25) NOT NULL,
       type VARCHAR2 (25),
       nationalite VARCHAR2(25),
       saison NUMBER (4)
);

CREATE TABLE PARTICIPER2(
       resultat NUMBER(2),
       codeCompetition NUMBER(3),
       codeEquipe NUMBER(3),
       FOREIGN KEY (codeCompetition) REFERENCES COMPETITION2(code),
       FOREIGN KEY (codeEquipe) REFERENCES EQUIPE2(code)
);

/*Table Equipe*/
INSERT INTO EQUIPE2
VALUES (1,'Paris Saint Germain', 'France', 'PSG');

INSERT INTO EQUIPE2
VALUES (2,'Olympique Lyonnais', 'France', 'OL');

INSERT INTO EQUIPE2
VALUES (3,'Manchester United', 'Angleterre', 'MNU');

INSERT INTO EQUIPE2
VALUES (4,'Manchester City', 'Angleterre', 'MNC');

/*Table Joueur*/

/*PSG*/
INSERT INTO JOUEUR2
VALUES (1, 'Mbappe', 'Kylian', 'Attaquant', 'France', '20-12-1998', 7, 'M', 1);

INSERT INTO JOUEUR2
VALUES (2, 'Messi', 'Lionel', 'Attaquant', 'Argentine','24/06/1987', 30, 'M', 1);

INSERT INTO JOUEUR2
VALUES (3, 'Verrati', 'Marco', 'Milieu', 'Italie', '05/11/1992', 6, 'M', 1);

INSERT INTO JOUEUR2
VALUES (4, 'Bernat', 'Juan', 'Defenseur', 'Espagne', '01/03/1993', 14, 'M', 1);

/*OL*/
INSERT INTO JOUEUR2
VALUES (5, 'Dembele', 'Moussa', 'Attaquant', 'France', '12/07/1996', 9, 'M', 2);

INSERT INTO JOUEUR2
VALUES (6, 'Mendes', 'Thiago', 'Milieu', 'Bresil', '15/03/1992', 23, 'M', 2);

INSERT INTO JOUEUR2
VALUES (7, 'Denayer', 'Jason', 'Defenseur', 'Belgique', '28/06/1995', 5, 'M', 2);

INSERT INTO JOUEUR2
VALUES (8, 'Diomande', 'Sinaly', 'Defenseur', 'Cote d Ivoire', '09/04/2001', 2, 'M', 2 );

/*MNU*/
INSERT INTO JOUEUR2
VALUES (9, 'De Gea', 'David', 'Gardien', 'Espagne', '07/11/1990', 1, 'M', 3);

INSERT INTO JOUEUR2
VALUES (10, 'Telles', 'Alex', 'Defenseur', 'Bresil', '15/12/1992', 27, 'M', 3);

INSERT INTO JOUEUR2
VALUES (11, 'Ronaldo', 'Cristiano', 'Attaquant', 'Portugal', '05/02/1985', 7, 'M', 3);

INSERT INTO JOUEUR2
VALUES (12, 'Rashford', 'Marcus', 'Attaquant', 'Angleterre', '31/10/1997', 10, 'M', 3);

/*MNC*/
INSERT INTO JOUEUR2
VALUES (13, 'Walker', 'Kyle', 'Defenseur', 'Angleterre', '28/05/1990', 2, 'M', 4);

INSERT INTO JOUEUR2
VALUES (14, 'Stones', 'John', 'Defenseur', 'Angleterre', '28/05/1994', 5, 'M', 4);

INSERT INTO JOUEUR2
VALUES (15, 'Silva', 'Bernardo', 'Milieu', 'Portugal', '10/08/1994', 20, 'M', 4);

INSERT INTO JOUEUR2
VALUES (16, 'Mahrez', 'Riyad', 'Attaquant', 'Algerie', '21/02/1991', 26, 'M', 4);

/*Table Competition*/
INSERT INTO COMPETITION2
VALUES (1, 'Premiere League', 'Championnat', 'Angleterre', 2021);

INSERT INTO COMPETITION2
VALUES (2, 'Dominos Ligue 1', 'Championnat', 'France', 2020);

/*Table Participer*/
INSERT INTO PARTICIPER2
VALUES (1, 2, 1);

INSERT INTO PARTICIPER2
VALUES (4, 2, 2);

INSERT INTO PARTICIPER2
VALUES (2, 1, 3);

INSERT INTO PARTICIPER2
VALUES (3, 1, 4);

/*Affiche la liste des joueurs de l'équipe Manchester City*/
SELECT J.nom, prenom
FROM JOUEUR2 J JOIN EQUIPE2 E ON codeEquipe = E.code
WHERE abbreviation = 'MNC';

/*Liste des compétitions (nom & type) auxquelles l'équipe dont le nom 'PSG' particpe*/
SELECT C.nom, type
FROM COMPETITION2 C JOIN PARTICIPER2 P ON C.code = codeCompetition JOIN EQUIPE2 E ON codeEquipe = E.code
WHERE E.abbreviation = 'PSG';