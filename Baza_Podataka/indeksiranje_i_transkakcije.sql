-- Indeksiranje podataka --

----------------------------------------
----------------------------------------
-------- FROM OTHER SQL (LESSON) --------
-- Delete all tables if exist
IF OBJECT_ID('dbo.titles', 'U') IS NOT NULL
	DROP TABLE titles;
IF OBJECT_ID('dbo.publishers', 'U') IS NOT NULL
	DROP TABLE publishers;

CREATE TABLE publishers
(
	pub_id			CHAR(3) NOT NULL ,
	pub_name		VARCHAR(20) NOT NULL ,
	city			VARCHAR(15) NOT NULL ,
	state			CHAR(2) NULL ,
	country			VARCHAR(15) NOT NULL ,
	
	CONSTRAINT publishers_pk PRIMARY KEY (pub_id)
);
CREATE TABLE titles
(
	title_id		CHAR(3) NOT NULL PRIMARY KEY ,
	title_name		VARCHAR(40) NOT NULL,
	type			VARCHAR(10) ,
	pub_id			CHAR(3) NOT NULL REFERENCES publishers(pub_id) ,
	pages			INTEGER ,
	price			DECIMAL(5,2) ,
	sales			INTEGER ,
	pubdate			DATETIME ,
	contract		SMALLINT NOT NULL
);

INSERT INTO publishers VALUES('P01','Abatis Publishers','New York','NY','USA');
INSERT INTO publishers VALUES('P02','Core Dump Books','San Francisco','CA','USA');
INSERT INTO publishers VALUES('P03','Schadenfreude Press','Hamburg',NULL,'Germany');
INSERT INTO publishers VALUES('P04','Tenterhooks Press','Berkeley','CA','USA');

INSERT INTO titles VALUES('T01','1977!','history','P01',107,21.99,566, '2000-08-01',1);
INSERT INTO titles VALUES('T02','200 Years of German Humor','history','P03',14,19.95,9566, '1998-04-01',1);
INSERT INTO titles VALUES('T03','Ask Your System Administrator','computer','P02',1226,39.95,25667, '2000-09-01',1);
INSERT INTO titles VALUES('T04','But I Did It Unconsciously','psychology','P04',510,12.99,13001, '1999-05-31',1);
INSERT INTO titles VALUES('T05','Exchange of Platitudes','psychology','P04',201,6.95,201440, '2001-01-01',1);
INSERT INTO titles VALUES('T06','How About Never?','biography','P01',473,19.95,11320, '2000-07-31',1);
INSERT INTO titles VALUES('T07','I Blame My Mother','biography','P03',333,23.95,1500200, '1999-10-01',1);
INSERT INTO titles VALUES('T08','Just Wait Until After School','children','P04',86,10.00,4095, '2001-06-01',1);
INSERT INTO titles VALUES('T09','Miss My Yoo-Yoo','children','P04',22,13.95,5000, '2002-05-31',1);
INSERT INTO titles VALUES('T10','Not Without My Faberge Egg','biography','P01',NULL,NULL,NULL,NULL,0);
INSERT INTO titles VALUES('T11','Perhaps It''s a Glandular Problem','psychology','P04',826,7.99,94123, '2000-11-30',1);
INSERT INTO titles VALUES('T12','Spontaneous, Not Annoying','biography','P01',507,12.99,100001, '2000-08-31',1);
INSERT INTO titles VALUES('T13','What Are The Civilian Applications?','history','P03',802,29.99,10467, '1999-05-31',1);
----------------------------------------
----------------------------------------
----------------------------------------
----------------------------------------

CREATE INDEX pub_id_idx ON titles(pub_id);
CREATE UNIQUE INDEX title_name_idx ON titles(title_name);
CREATE INDEX state_city_inx ON publishers(state, city);

DROP INDEX pub_id_idx ON titles;

-- Ne treba 
IF OBJECT_ID('dbo.title_view', 'V') IS NOT NULL
    DROP VIEW dbo.title_view;
IF OBJECT_ID('dbo.publishers_view', 'V') IS NOT NULL
    DROP VIEW dbo.publishers_view;

--


-- Pogledi (VIEW)
-- https://www.w3schools.com/sql/sql_view.asp
-- 'CREATE VIEW' must be the first statement in a query batch.
GO

CREATE VIEW title_view  AS SELECT title_id, title_name, type FROM titles;

GO

-- VIEW i WITH CHECK OPTION
-- https://stackoverflow.com/questions/41923298/sql-view-with-with-check-option
CREATE VIEW publishers_view
AS SELECT pub_name, state 
FROM publishers
WHERE state = 'CA'
WITH CHECK OPTION;

GO

-- AVG()
-- Nisam pisao

-- SELECT DISTINCT
-- The SELECT DISTINCT statement is used to return only distinct (different) values.
SELECT DISTINCT type FROM titles;

-- LIKE
SELECT title_name FROM titles WHERE title_name LIKE '%It%';

-- DROP VIEW
DROP VIEW dbo.publishers_view;

---------
UPDATE publishers
SET pub_name = 'Netflix'
WHERE pub_id = 'P01';

DELETE FROM publishers
WHERE pub_id = 'P02';

------ Transakcije -------
-- Garantovanje izvrisavanje jednog bloka upita ili ne jednog
-- https://www.geeksforgeeks.org/sql-transactions/

BEGIN TRANSACTION;
UPDATE titles SET pages = 0;
UPdaTE titles SET price = price * 2;

SELECT 
SUM(pages) AS "All pages", 
AVG(price) AS "AVG Price"
FROM titles;
ROLLBACK; -- Nista ne promenjeno posle transakciji
-- COMMIT; -- Posle transakciji sacuvamo promeni

SELECT 
SUM(pages) AS "All pages", 
AVG(price) AS "AVG Price"
FROM titles;
