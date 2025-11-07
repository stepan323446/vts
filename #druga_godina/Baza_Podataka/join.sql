-- Delete all tables if exist
IF OBJECT_ID('dbo.titles', 'U') IS NOT NULL
	DROP TABLE titles;
IF OBJECT_ID('dbo.publishers', 'U') IS NOT NULL
	DROP TABLE publishers;


----------------------------------------
----------------------------------------
-------- FROM OTHER SQL (LESSON) --------
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

---------------- JOIN ------------------
-- https://miro.medium.com/v2/resize:fit:991/0*Nrjozs1i0XIiACKd.png

SELECT * FROM titles ttl
	INNER JOIN publishers p ON ttl.pub_id = p.pub_id
	WHERE p.country = 'USA';

-- SELECT * FROM titles ttl
--	CROSS JOIN publishers p;
