INSERT INTO Departement VALUES ('1','MIG');
INSERT INTO Departement VALUES ('2','PCT');
INSERT INTO Departement VALUES ('3','GHEV');


INSERT INTO Etudiant VALUES ('1','OUJDI','Reda','1982/02/18','50, Rue des roses','OUJDA','0660000001',NULL,'oujdi@etud.ehtp.aC.ma');
INSERT INTO Etudiant VALUES ('2','RBATI','Karima','1982/08/23','10, Avenue des fleurs','RABAT','0660000002',NULL,'rbati@etud.ehtp.aC.ma');
INSERT INTO Etudiant VALUES ('3','FASSI', 'Amal','1982/05/12','25, Boulevard des lilas','FES','0660000003','0550000003','fassi@etud.ehtp.aC.ma');
INSERT INTO Etudiant VALUES ('4','TAZI', 'Omar','1982/07/15','56, Boulevard des fleurs','FES','0678905645',NULL,'tazi@etud.ehtp.aC.ma');
INSERT INTO Etudiant VALUES ('5','TETOUANI', 'Imane','1982/08/15','45, Avenue des abeilles','FES',NULL,NULL,NULL);

INSERT INTO Enseignant VALUES('1','1','ELHATIMI','Badr','ING','4163','4088','elhatimi@etud.ehtp.aC.ma');
INSERT INTO Enseignant VALUES('2','1','ELGHAZI','Souheil','PES',NULL,NULL,'elghazi@etud.ehtp.aC.ma');


INSERT INTO Salle VALUES('B','020','25');
INSERT INTO Salle VALUES('B','022','25');
INSERT INTO Salle VALUES('A','301','45');
INSERT INTO Salle VALUES('C','Amphi 1','100');
INSERT INTO Salle VALUES('C','Amphi 4','200');


INSERT INTO Enseignement VALUES ('1','1','Bases de Données Relationnelles','Première année : Modèle relationnel, Algèbre Relationnelle, SQL, dépendances fonctionnelles et formes normales');
INSERT INTO Enseignement VALUES ('2','1','Langage C++','Première année : Programmation orientée objet en C++');
INSERT INTO Enseignement VALUES ('3','1','MERISE','Deuxième année : Méthode d analyse et de conception');

INSERT INTO Reservation VALUES ('1','B','022','1','1','1','2010/10/15','08:00:00','12:15:00','4');
INSERT INTO Reservation VALUES ('2','B','022','1','1','2','2010/11/04','08:00:00','12:15:00','4');
INSERT INTO Reservation VALUES ('3','B','022','1','1','2','2010/11/07','08:00:00','12:15:00','4');
INSERT INTO Reservation VALUES ('4','B','020','1','1','1','2010/10/15','08:00:00','12:15:00','4');