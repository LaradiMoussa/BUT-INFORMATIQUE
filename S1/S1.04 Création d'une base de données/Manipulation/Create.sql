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
