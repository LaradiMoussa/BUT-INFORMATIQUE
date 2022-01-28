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