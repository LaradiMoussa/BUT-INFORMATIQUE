/* 1. Modifier le schéma de la relation ETUDIANT en ajoutant les attributs : 
        1. annee (1 pour les 1ère année et 2 pour les 2ème année)
        2. parcours (pas de valeur en 1ère année, 'PEL' ou 'IPI' en 2ème année)*/

/* 1.1 */
ALTER TABLE ETUDIANT
RENAME COLUMN anneeEtude TO annee;

/* 1.2 */
ALTER TABLE ETUDIANT
ADD parcours VARCHAR2(4) NULL;

UPDATE ETUDIANT
SET parcours = 'IPI'
WHERE annee = 2 AND genre = 'F';

UPDATE ETUDIANT
SET parcours = 'PEL'
WHERE annee = 2 AND genre = 'M';

/* 2. Mettre à jour l'attribut annee (1 pour tous le n-ulpets) */
UPDATE ETUDIANT
SET annee = 1;

/* 3. Supprimer les étudiants du groupe de TP 5 */
DELETE FROM ETUDIANT
WHERE groupeTP = 5;

/* 4. Modifier le schéma de la relation ETUDIANT en supprimant l'attribut parcours */
ALTER TABLE ETUDIANT
DROP COLUMN parcours;

/* 5. Modifier le schéma de la relation ETUDIANT en modifiant l'attribut prénom (nouveau domaine
       = chaîne de caratères de longueur 35 */
ALTER TABLE ETUDIANT
MODIFY prenom VARCHAR2 (35);

/* 6. Modifier le schéma de la base en supprimant la relation ETUDIANT */
DROP TABLE ETUDIANT;