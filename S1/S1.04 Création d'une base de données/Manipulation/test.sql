/* -------------------------------------------------------------------------- */
/*                             SITE JDOODLE - SQL                             */
/* -------------------------------------------------------------------------- */

CREATE TABLE academie(
code NUMBER,
nom VARCHAR2(20),
CONSTRAINT pk_academie 
    PRIMARY KEY(code)
);

CREATE TABLE etablissement( 
code NUMBER,
type VARCHAR2(10),
nom VARCHAR2(20),
adresRue VARCHAR2(50),
adresVil VARCHAR2(50),
cp NUMBER, 
telFixe VARCHAR2(20), 
fax VARCHAR2(20), 
courriel VARCHAR2(50), 
url VARCHAR2(50), 
codeAcademie NUMBER,
CONSTRAINT fk_etablissement_academie 
    FOREIGN KEY (codeAcademie) REFERENCES academie(code),
CONSTRAINT pk_etablissement 
    PRIMARY KEY(code)
);

CREATE TABLE intervenant( 
code NUMBER, 
nom VARCHAR2(20), 
prenom VARCHAR2(20), 
adresRue VARCHAR2(50), 
adresVil VARCHAR2(50), 
cp NUMBER, 
telFixe VARCHAR2(20), 
telMob VARCHAR2(20), 
courriel VARCHAR2(50),
CONSTRAINT pk_intervenant
    PRIMARY KEY(code)
);

CREATE TABLE salon( 
code NUMBER, 
nom VARCHAR2(20), 
dateS DATE, 
adresRue VARCHAR2(50), 
adresVil VARCHAR2(50), 
cp NUMBER, 
codeAcademie NUMBER, 
codeIntervenant NUMBER,
CONSTRAINT pk_salon
    PRIMARY KEY (code),
CONSTRAINT fk_salon_academie
    FOREIGN KEY (codeAcademie) REFERENCES academie(code),
CONSTRAINT fk_salon_intervenant
    FOREIGN KEY (codeIntervenant) REFERENCES intervenant(code)
);

CREATE TABLE professeur( 
code NUMBER, 
nom VARCHAR2(20), 
prenom VARCHAR2(20), 
adresRue VARCHAR2(50), 
adresVil VARCHAR2(50), 
cp NUMBER, 
telFixe VARCHAR2(20), 
telMob VARCHAR2(20), 
courriel VARCHAR2(50), 
codeEtablissement NUMBER,
CONSTRAINT fk_professeur_etablissement
    FOREIGN KEY (codeEtablissement) REFERENCES etablissement(code),
CONSTRAINT pk_professeur
    PRIMARY KEY (code)
);

CREATE TABLE revendeur( 
code NUMBER, 
nom VARCHAR2(20), 
type VARCHAR2(20), 
adresRue VARCHAR2(50), 
adresVil VARCHAR2(50), 
cp NUMBER, 
telFixe VARCHAR2(20), 
fax VARCHAR2(20), 
courriel VARCHAR2(50), 
url VARCHAR2(50),
CONSTRAINT pk_revendeur
    PRIMARY KEY(code)
);

CREATE TABLE matiere( 
code NUMBER, 
nom VARCHAR2(50), 
CONSTRAINT pk_matiere
    PRIMARY KEY(code)
);

CREATE TABLE classe( 
code NUMBER, 
libelle VARCHAR2(10), 
niveau NUMBER,
CONSTRAINT pk_classe
    PRIMARY KEY(code)
);

CREATE TABLE auteur( 
code NUMBER, 
nom VARCHAR2(20), 
prenom VARCHAR2(20), 
adresRue VARCHAR2(50), 
adresVil VARCHAR2(50), 
cp NUMBER, 
telFixe VARCHAR2(20), 
telMob VARCHAR2(20), 
courriel VARCHAR2(50),
CONSTRAINT pk_auteur
    PRIMARY KEY(code)
);

CREATE TABLE ouvrage( 
code NUMBER, 
titre VARCHAR2(50), 
tirage NUMBER,
typeCont VARCHAR2(20),
pxPubHT NUMBER, 
avisCteLect VARCHAR2(50),
versionMaq VARCHAR2(10),
refFichierMaq VARCHAR2(50),
codeMatiere NUMBER,
CONSTRAINT pk_ouvrage
    PRIMARY KEY(code),
CONSTRAINT fk_ouvrage_matiere
    FOREIGN KEY (codeMatiere) REFERENCES matiere(code)

);

CREATE TABLE ecrire( 
codeAuteur NUMBER,
codeOuvrage NUMBER,
auteurPpalON CHAR,
contratAccON CHAR,
CONSTRAINT pk_ecrire
    PRIMARY KEY(codeAuteur,codeOuvrage),
CONSTRAINT fk_ecrire_auteur
    FOREIGN KEY (codeAuteur) REFERENCES auteur(code),
CONSTRAINT fk_ecrire_ouvrage
    FOREIGN KEY (codeOuvrage) REFERENCES ouvrage(code)

);

CREATE TABLE concerner( 
codeOuvrage NUMBER,
codeClasse NUMBER,
CONSTRAINT pk_concerner
    PRIMARY KEY(codeOuvrage,codeClasse),
CONSTRAINT fk_concerner_ouvrage
    FOREIGN KEY (codeOuvrage) REFERENCES ouvrage(code),
CONSTRAINT fk_concerner_classe
    FOREIGN KEY (codeClasse) REFERENCES classe(code)

);

CREATE TABLE enseigner( 
codeProfesseur NUMBER,
codeClasse NUMBER,
codeMatiere NUMBER,
CONSTRAINT pk_enseigner
    PRIMARY KEY(codeProfesseur,codeClasse,codeMatiere),
CONSTRAINT fk_enseigner_professeur
    FOREIGN KEY (codeProfesseur) REFERENCES professeur(code),
CONSTRAINT fk_enseigner_classe
    FOREIGN KEY (codeClasse) REFERENCES classe(code),
CONSTRAINT fk_enseigner_matiere
    FOREIGN KEY (codeMatiere) REFERENCES matiere(code)
);

CREATE TABLE acheter( 
codeOuvrage NUMBER,
codeRevendeur NUMBER,
dateAchat DATE,
quantite NUMBER,
txRemise NUMBER, 
CONSTRAINT pk_acheter
    PRIMARY KEY(codeOuvrage,codeRevendeur,dateAchat),
CONSTRAINT fk_acheter_ouvrage
    FOREIGN KEY (codeOuvrage) REFERENCES ouvrage(code),
CONSTRAINT fk_acheter_revendeur
    FOREIGN KEY (codeRevendeur) REFERENCES revendeur(code)
);

/*ACADEMIE*/

INSERT INTO ACADEMIE(code,nom) VALUES(1,'Toulouse');
INSERT INTO ACADEMIE(code,nom) VALUES(2,'Paris');
INSERT INTO ACADEMIE(code,nom) VALUES(3,'Poitiers');
INSERT INTO ACADEMIE(code,nom) VALUES(4,'Bordeaux');
INSERT INTO ACADEMIE(code,nom) VALUES(5,'Nantes');


/*MATIERE*/

INSERT INTO MATIERE(code,nom) VALUES(1,'droit civil');
INSERT INTO MATIERE(code,nom) VALUES(2,'droit constitutionnel');
INSERT INTO MATIERE(code,nom) VALUES(3,'histoire du droit');
INSERT INTO MATIERE(code,nom) VALUES(4,'droit administratif');
INSERT INTO MATIERE(code,nom) VALUES(5,'droit pénal');


/*INTERVENANT*/

INSERT INTO intervenant(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel) 
VALUES(1,'Alvarez','Humberto','28 av. de Arancette', 'Anglet', 64600, '24242424', '2323232323','alvarez@gmail.com');

INSERT INTO intervenant(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel) 
VALUES(2,'Negrete','Jose','2 av. de Mexico', 'Bordeaux', 30072, '55555545', '5845454545','negrete@gmail.com');

INSERT INTO intervenant(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel) 
VALUES(3,'Lisbon','Teresa','55 av. de EEUU', 'Paris', 75001, '96325874', '01478520','lisbon@gmail.com');

INSERT INTO intervenant(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel) 
VALUES(4,'Jane','Patrick','74 rue. de EEUU', 'Paris', 75001, '78965412', '65412300','jane@gmail.com');

INSERT INTO intervenant(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel) 
VALUES(5,'Dongo','Benito','28 av. du Peru', 'Biarritz', 64200, '14785236', '78541236','dongo@gmail.com');

INSERT INTO intervenant(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel) 
VALUES(6,'Tony','Teresa','55 av. de EEUU', 'Paris', 75001, '96325874', '01478520','lisbon@gmail.com');

INSERT INTO intervenant(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel) 
VALUES(7,'Paul','Patrick','74 rue. de EEUU', 'Paris', 75001, '78965412', '65412300','jane@gmail.com');

INSERT INTO intervenant(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel) 
VALUES(8,'Jack','Benito','28 av. du Peru', 'Biarritz', 64200, '14785236', '78541236','dongo@gmail.com');


/*REVENDEUR*/

INSERT INTO revendeur(code, nom, type, adresRue, adresVil, cp, telFixe, fax, courriel, URL) 
VALUES(1,'Fnac','Librairie','Rue Gerantet', 'St Etienne', 42000, '85471236', '11223366','fnac@gmail.com','www.fnac.com');

INSERT INTO revendeur(code, nom, type, adresRue, adresVil, cp, telFixe, fax, courriel, URL) 
VALUES(2,'Carrefour','Grande surface','Route de Givors', 'Lyon', 69000, '77889966', '22554455','carrefour@gmail.com','www.carrefour.com');

INSERT INTO revendeur(code, nom, type, adresRue, adresVil, cp, telFixe, fax, courriel, URL) 
VALUES(3,'Librairie Durance','Librairie','Boulevard des 50 otages', 'Nantes', 44000, '66552211', '14253699','durance@gmail.com','www.durance.com');

INSERT INTO revendeur(code, nom, type, adresRue, adresVil, cp, telFixe, fax, courriel, URL) 
VALUES(4,'Leclerc','Grande surface','Quai des Chartrons', 'Bordeaux', 33000, '96857412', '33669900','leclerc@gmail.com','www.leclerc.com');

INSERT INTO revendeur(code, nom, type, adresRue, adresVil, cp, telFixe, fax, courriel, URL) 
VALUES(5,'casino','Grande surface','Rue de Bayonne', 'Bayonne', 64600, '52369874', '78965412','casino@gmail.com','www.casino.com');


/*AUTEUR*/

INSERT INTO auteur(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel) 
VALUES(1,'Perrousse','Sophie ','33 av. de Arancette', 'Bayonne', 64100, '11223344', '03030303','perrousse@gmail.com');

INSERT INTO auteur(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel) 
VALUES(2,'Larracoechea','Anibal ','11 av. de Anglet', 'Anglet', 64600, '01010101', '45454545','larracoechea@gmail.com');

INSERT INTO auteur(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel) 
VALUES(3,'Macron','Philippe ','28 av. de Paris', 'Paris', 75004, '98747896', '74887744','macron@gmail.com');

INSERT INTO auteur(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel) 
VALUES(4,'Roose','Philippe ','50 rte. de Ustaritz', 'ustaritz', 64480, '33665522', '99778855','roose@gmail.com');

INSERT INTO auteur(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel) 
VALUES(5,'Dalmau','Marc ','77 av. de Arancette', 'Bayonne', 64100, '22554477', '99663355','dalmau@gmail.com');

/*OUVRAGE*/

INSERT INTO ouvrage(code, titre, tirage, typeCont, pxPubHT, avisCteLect, versionMaq, refFichierMaq, codeMatiere)
VALUES(1, 'Decouverte du droit civil', 1000, 'A', 7.5, 'Tres bon', 'V1.1', '/home/sys/droitcivil.doc',1);

INSERT INTO ouvrage(code, titre, tirage, typeCont, pxPubHT, avisCteLect, versionMaq, refFichierMaq, codeMatiere)
VALUES(2, 'Intro au droit constitutionnel', 2000, 'A', 10.5, 'Tres tres bon', 'V1.1', '/home/sys/droitconst.doc',2);

INSERT INTO ouvrage(code, titre, tirage, typeCont, pxPubHT, avisCteLect, versionMaq, refFichierMaq, codeMatiere)
VALUES(3, 'histoire du droit', 2050, 'B', 10.5, 'Tres bon', 'V1.1', '/home/sys/histoiredudroit.doc',3);

INSERT INTO ouvrage(code, titre, tirage, typeCont, pxPubHT, avisCteLect, versionMaq, refFichierMaq, codeMatiere)
VALUES(4, 'Intro. droit administratif', 5000, 'A', 18.5, 'moyen', 'V1.1', '/home/sys/droitAdministratif.doc',4);

INSERT INTO ouvrage(code, titre, tirage, typeCont, pxPubHT, avisCteLect, versionMaq, refFichierMaq, codeMatiere)
VALUES(5, 'Histoire du droit pénal', 7100, 'C', 10.5, 'pas mal', 'V1.1', '/home/sys/droitpenal.doc',5);

/*ECRIRE*/

INSERT INTO ecrire(codeAuteur, codeOuvrage, auteurPpalON, contratAccON)
VALUES(1,1,'O','O');

INSERT INTO ecrire(codeAuteur, codeOuvrage, auteurPpalON, contratAccON)
VALUES(2,2,'O','O');

INSERT INTO ecrire(codeAuteur, codeOuvrage, auteurPpalON, contratAccON)
VALUES(3,3,'O','O');

INSERT INTO ecrire(codeAuteur, codeOuvrage, auteurPpalON, contratAccON)
VALUES(4,4,'O','O');

INSERT INTO ecrire(codeAuteur, codeOuvrage, auteurPpalON, contratAccON)
VALUES(5,5,'O','O');

/*ACHETER*/

INSERT INTO acheter(codeOuvrage, codeRevendeur, dateAchat, quantite, txRemise)
VALUES(1,1,'13-NOV-20',500,25);

INSERT INTO acheter(codeOuvrage, codeRevendeur, dateAchat, quantite, txRemise)
VALUES(2,2,'13-OCT-20',700,25);

INSERT INTO acheter(codeOuvrage, codeRevendeur, dateAchat, quantite, txRemise)
VALUES(3,3,'23-NOV-20',900,50);

INSERT INTO acheter(codeOuvrage, codeRevendeur, dateAchat, quantite, txRemise)
VALUES(4,4,'13-NOV-20',800,15);

INSERT INTO acheter(codeOuvrage, codeRevendeur, dateAchat, quantite, txRemise)
VALUES(5,5,'13-DIC-20',500,24);

/*CLASSE*/

INSERt INTO CLASSE(code, libelle, niveau)
VALUES(1,'1er A',1);

INSERt INTO CLASSE(code, libelle, niveau)
VALUES(2,'2ème A',2);

INSERt INTO CLASSE(code, libelle, niveau)
VALUES(3,'3ème A',3);

INSERt INTO CLASSE(code, libelle, niveau)
VALUES(4,'4ème A',4);

INSERt INTO CLASSE(code, libelle, niveau)
VALUES(5,'5ème A',5);

/*CONCERNER*/

INSERT INTO CONCERNER(codeOuvrage, codeClasse)
VALUES(1,1);

INSERT INTO CONCERNER(codeOuvrage, codeClasse)
VALUES(2,2);

INSERT INTO CONCERNER(codeOuvrage, codeClasse)
VALUES(3,3);

INSERT INTO CONCERNER(codeOuvrage, codeClasse)
VALUES(4,4);

INSERT INTO CONCERNER(codeOuvrage, codeClasse)
VALUES(5,5);

/*ETABLISSEMENT*/

INSERT INTO etablissement(code, type, nom, adresRue, adresVil, cp, telFixe, fax, courriel, url, codeAcademie)
VALUES(1,'Lycée','Cantau','1 All. de Cantau','Anglet',64600,'0559580606','0559580606','anglet@lycee-cantau.net','https://www.lycee-cantau.fr/',4);

INSERT INTO etablissement(code, type, nom, adresRue, adresVil, cp, telFixe, fax, courriel, url, codeAcademie)
VALUES(2,'Collège','Endarra','5 Av. Eugène Bernain','Anglet',64600,'0559630704','0559630704','ce.0640003f@ac-bordeaux.fr','https://blogpeda.ac-bordeaux.fr/endarra/',4);

INSERT INTO etablissement(code, type, nom, adresRue, adresVil, cp, telFixe, fax, courriel, url, codeAcademie)
VALUES(3,'Collège','Notre-Dame','4 Rue Montaut','Bayonne',64100,'0559592861','0559592861','dir.collegenotredame@orange.fr','http://www.collegenotredamebayonne.com/',4);

INSERT INTO etablissement(code, type, nom, adresRue, adresVil, cp, telFixe, fax, courriel, url, codeAcademie)
VALUES(4,'Lycée','Saint?Louis Gonzague','2 Av. Lahouze','Biarritz',64200,'0559410033','0559410033','franklin@franklinparis.com','http://www.franklinparis.fr',2);

INSERT INTO etablissement(code, type, nom, adresRue, adresVil, cp, telFixe, fax, courriel, url, codeAcademie)
VALUES(5,'Lycée','Emilie de Rodat','25 Av. de Lombez','Toulouse',31300,'0562485757','0562485757','direction@rodat.fr','https://www.rodat.fr/',1);

/*PROFESSEUR*/

INSERT INTO professeur(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel, codeEtablissement)
VALUES(1,'Aniorte','Philippe','77 av. de Bayonne','Bayonne',64100,'02010407','06050505','aniorte@mail.fr',1);

INSERT INTO professeur(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel, codeEtablissement)
VALUES(2,'Alvarez','Hernan','66 av. de Bayonne','Bayonne',64100,'24242424','23232323','hernan@mail.fr',2);

INSERT INTO professeur(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel, codeEtablissement)
VALUES(3,'Valera','Beto','1 av. de Anglet','Anglet',64600,'42424242','32323232','beto@gmail.fr',3);

INSERT INTO professeur(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel, codeEtablissement)
VALUES(4,'Negrete','Manuel','23 rte. de Toulouse','Toulouse',31000,'98989898','74747474','manu@gmail.fr',4);

INSERT INTO professeur(code, nom, prenom, adresRue, adresVil, cp, telFixe, telMob, courriel, codeEtablissement)
VALUES(5,'Dongo','Venito','23 rte. de Arequipa','Paris',75001,'54545454','45454545','donguito@gmail.fr',5);

/*ENSEIGNER*/

INSERT INTO ENSEIGNER(codeProfesseur, codeClasse, codeMatiere)
VALUES(1,1,1);

INSERT INTO ENSEIGNER(codeProfesseur, codeClasse, codeMatiere)
VALUES(2,2,2);

INSERT INTO ENSEIGNER(codeProfesseur, codeClasse, codeMatiere)
VALUES(3,3,3);

INSERT INTO ENSEIGNER(codeProfesseur, codeClasse, codeMatiere)
VALUES(4,4,4);

INSERT INTO ENSEIGNER(codeProfesseur, codeClasse, codeMatiere)
VALUES(5,5,5);

/*SALON*/

INSERT INTO salon(code, nom, dateS, adresRue, adresVil, cp, codeAcademie, codeIntervenant)
VALUES(1,'Nantes','13-NOV-92','17 rue de l’Ediv','Nantes',44000,5,1);

INSERT INTO salon(code, nom, dateS, adresRue, adresVil, cp, codeAcademie, codeIntervenant)
VALUES(2,'Poitiers','18-DIC-05','12 av du Sénat','Poitiers',86000,3,2);

INSERT INTO salon(code, nom, dateS, adresRue, adresVil, cp, codeAcademie, codeIntervenant)
VALUES(3,'Bordeaux','13-DIC-06','25 bd de la Concorde','Bordeaux',33000,4,3);

INSERT INTO salon(code, nom, dateS, adresRue, adresVil, cp, codeAcademie, codeIntervenant)
VALUES(4,'Bordeaux','13-DIC-08','12 rue de la Truffe','Périgueux',24000,4,4);

INSERT INTO salon(code, nom, dateS, adresRue, adresVil, cp, codeAcademie, codeIntervenant)
VALUES(5,'Nantes','25-FEB-18','23 rue du Recteur Schmitt','Nantes',44322,5,5);



/************************************************/
/*-------------------REQUETES-------------------*/
/************************************************/

/* -------------------------------------------------------------------------- */
/*                                    JOIN                                    */
/*                     2 requêtes dont une multi-jointure                     */
/* -------------------------------------------------------------------------- */

/*Le nom des établissements appartenant à l'académie de Bordeaux */
/*Résultat : Cantau
            Endarra
            Notre-Dame */
SELECT E.nom
FROM etablissement E JOIN ACADEMIE A ON codeAcademie = A.code
WHERE A.nom = 'Bordeaux';


/*Le courriel du professeur qui enseigne le droit civil */
/*Résultat : aniorte@mail.fr */
SELECT P.courriel
FROM professeur P JOIN ENSEIGNER ON P.code = codeProfesseur JOIN matiere M ON codeMatiere = M.code
WHERE M.nom = 'droit civil'; /*XXX*/

/* -------------------------------------------------------------------------- */
/*                                  ORDER BY                                  */
/*       2 requêtes dont une mettant en œuvre plusieurs attributs de tri      */
/* -------------------------------------------------------------------------- */

/*Afficher les titres des livres par prix décroissants */
/*Résultat : Intro. droit administratif
            Intro au droit constitutionnel
            histoire du droit
            Histoire du droit pénal
            Decouverte du droit civil */
SELECT titre
FROM ouvrage
ORDER BY pxPubHT DESC;


/*Afficher les codes postals croissants des établissement puis par nom d'établissement décroissants */
/* Résultat :   Emilie de Rodat|31300
                Notre-Dame|64100
                Saint?Louis Gonzague|64200
                Endarra|64600
                Cantau|64600 */
SELECT nom, cp
FROM etablissement
ORDER BY cp ASC, nom DESC; /*XXX*/

/* -------------------------------------------------------------------------- */
/*                                  GROUP BY                                  */
/*                                 3 requêtes                                 */
/* -------------------------------------------------------------------------- */

/*Afficher les villes dans lesquelles il y a des salons */
/* Résultat :   Bordeaux
                Nantes
                Poitiers */
SELECT nom
FROM salon
GROUP BY nom; /*XXX*/


/*Afficher le prix public ainsi que le nombre de tirage total des livres qui ont ce même prix */
/*Résultat :    7.5|1000
                10.5|11150
                18.5|5000  */
SELECT pxPubHT, SUM(tirage)
FROM ouvrage
GROUP BY pxPubHT;


/*Afficher le nombre d'occurences de chaque prénom dans les intervenants */
/* Résultat :   2|Benito
                1|Humberto
                1|Jose
                2|Patrick
                2|Teresa */
SELECT COUNT(prenom), prenom
FROM intervenant
GROUP BY prenom;

/* -------------------------------------------------------------------------- */
/*                               GROUP BY HAVING                              */
/*                                 3 requêtes                                 */
/* -------------------------------------------------------------------------- */

/*Afficher le nom des villes commençant par B et dans lesquelles il y a un etablissement */
/*Résultat :    Bayonne
                Biarritz */
SELECT E.adresVil
FROM etablissement E
GROUP BY E.adresVil
HAVING E.adresVil LIKE 'B%';


/*Afficher le prix, le nom du livre et le revendeur dont un des magasins de situe à Lyon */
/*Résultat : 10.5|Intro au droit constitutionnel|Carrefour */
SELECT pxPubHT, ouvrage.titre, revendeur.nom
FROM revendeur JOIN acheter ON revendeur.code = codeRevendeur JOIN ouvrage ON ouvrage.code = codeOuvrage
GROUP BY revendeur.nom
HAVING adresVil ='Lyon';

/*Afficher le type d'établissement, l'adresse de rue et de ville, des établissements ayant un courriel se finissant par
.fr et étant localisés dans le 64 */
/*Résultat :    Endarra|5 Av. Eugène Bernain|Anglet
                Notre-Dame|4 Rue Montaut|Bayonne */
SELECT type, nom, adresRue, adresVil
FROM etablissement
WHERE courriel LIKE '%.fr'
GROUP BY nom
HAVING cp LIKE '64%' ;

/* -------------------------------------------------------------------------- */
/*                              SELECT IMBRIQUÉS                              */
/*           6 requêtes à l’exclusion de l’équivalent de la jointure          */
/*                   , utilisant au niveau de l’imbrication                   */
/*    des opérateurs de comparaison et les prédicats IN, NOT IN, ALL et ANY   */
/* -------------------------------------------------------------------------- */

/*Le nom du professeur qui enseigne à l'établissement Endarra */
/* Résultat : Alvarez */
SELECT professeur.nom
FROM professeur
WHERE codeEtablissement IN (SELECT code FROM etablissement WHERE nom = 'Endarra');

/*Le nom des professseurs qui n'enseigne pas dans la ville de code postal 64600 */
/* Résultat :   Valera
                Negrete
                Dongo*/
SELECT professeur.nom
FROM professeur
WHERE codeEtablissement NOT IN (SELECT code FROM etablissement WHERE cp = 64600);


/*Afficher le nom du revendeur, le titre du livre et la quantite du livre le plus vendu aux revendeurs*/
/*Résultat : Librairie Durance|histoire du droit|900 */
SELECT R.nom, O.titre, quantite
FROM ouvrage O JOIN acheter ON O.code = codeOuvrage JOIN revendeur R ON codeRevendeur = R.code
WHERE quantite = (SELECT MAX(quantite) FROM acheter);


/*Afficher le titre du livre le moins cher, son prix ainsi que le revendeur de ce livre */
/*Résultat : Decouverte du droit civil|7.5|Fnac */
SELECT ouvrage.titre, ouvrage.pxPubHT, revendeur.nom
FROM revendeur JOIN acheter ON revendeur.code = codeRevendeur JOIN ouvrage ON ouvrage.code = codeOuvrage
WHERE pxPubHT = (SELECT MIN(pxPubHT) FROM ouvrage);


/* -------------------------------------------------------------------------- */
/*                                   ORACLE                                   */
/* -------------------------------------------------------------------------- */

/*Afficher le codes postal et le nom des professeurs qui ont un code postal supérieur à la moyenne
    des codes postaux des revendeurs */
/* Résultat :   64100	Aniorte
                64100	Alvarez
                64600	Valera
                75001	Dongo*/
SELECT professeur.cp, professeur.nom
FROM professeur
WHERE cp > ALL (
    SELECT AVG(cp)
    FROM revendeur
)

/*Affiche le nom des professeurs si elle trouve que n'importe quel enregistrement de la table établissement a un code
postal supérieur à 64000*/
/* Résultat :
Aniorte
Alvarez
Valera
Negrete*/
SELECT professeur.nom
FROM professeur
WHERE code = ANY (SELECT code FROM etablissement WHERE cp > 64000);


/* --------------------------------- RESTE 1 -------------------------------- */


/*Ecrire et tester les 16 requêtes. Pour cela constituer un jeu d’essai significatif, quitte à compléter le contenu de la 
base.*/