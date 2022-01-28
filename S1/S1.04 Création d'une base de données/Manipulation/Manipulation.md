## Manipulation

CREATE TABLE AUTEUR (
    code VARCHAR2 (6) PRIMARY KEY,
    nom VARCHAR2 (26),
    prenom VARCHAR2 (26),
    adresRue VARCHAR2 (26),
    adresVil VARCHAR2 (26),
    cp NUMBER (6),
    telFixe VARCHAR2 (10),
    telMob VARCHAR2 (10),
    courriel VARCHAR2 (40)
);

CREATE TABLE ECRIRE (
    FOREIGN KEY (codeAuteur) REFERENCES AUTEUR(code),
    FOREIGN KEY (codeOuvrage) REFERENCES OUVRAGE(code),
    auteurPpalON NUMBER (1),
    contratAccON NUMBER (1)
);

CREATE TABLE OUVRAGE (
    code VARCHAR2 (6) PRIMARY KEY,
    titre VARCHAR2 (26),
    tirage NUMBER (6),
    typeCont VARCHAR2 (1),
    pxPubHT NUMBER (5),
    avisCteLect VARCHAR2 (100),
    versionMaq NUMBER (2),
    refFichierMaq VARCHAR2 (6),
    FOREIGN KEY (codeMatiere) REFERENCES MATIERE(code)
);