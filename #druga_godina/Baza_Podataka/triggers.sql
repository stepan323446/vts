-- Okidaci (Triggers)  --

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

IF OBJECT_ID('dbo.publishers_audit', 'U') IS NOT NULL
	DROP TABLE publishers_audit;
IF OBJECT_ID('dbo.titles_audit', 'U') IS NOT NULL
	DROP TABLE titles_audit;

CREATE TABLE publishers_audit(
	change_id	INT IDENTITY PRIMARY KEY,

	-- Same as 'titles' table
	pub_id			CHAR(3) NOT NULL ,
	pub_name		VARCHAR(20) NOT NULL ,
	city			VARCHAR(15) NOT NULL ,
	state			CHAR(2) NULL ,
	country			VARCHAR(15) NOT NULL ,
	-------

	updated_at	DATETIME NOT NULL,
	operation	CHAR(3) NOT NULL,
	
	CHECK(operation = 'INS' or operation = 'DEL' or operation = 'UPD')
);
CREATE TABLE titles_audit(
	change_id	INT IDENTITY PRIMARY KEY,
	
	-- Same as 'titles' table
	title_id		CHAR(3) NOT NULL,
	title_name		VARCHAR(40) NOT NULL,
	type			VARCHAR(10) ,
	pub_id			CHAR(3) NOT NULL,
	pages			INTEGER ,
	price			DECIMAL(5,2) ,
	sales			INTEGER ,
	pubdate			DATETIME ,
	contract		SMALLINT NOT NULL,
	-------

	updated_at	DATETIME NOT NULL,
	operation	CHAR(3) NOT NULL,
	
	CHECK(operation = 'INS' or operation = 'DEL' or operation = 'UPD')
);

GO

-- Trigger for INSERT and DELETE for publishers
CREATE TRIGGER trg_publishers_audit ON publishers
AFTER INSERT, DELETE
AS
BEGIN
	SET NOCOUNT ON;
	INSERT INTO publishers_audit(pub_id, pub_name, city, state, country, updated_at, operation)
		SELECT i.pub_id, i.pub_name, i.city, i.state, i.country, GETDATE(), 'INS'
		FROM inserted i
	UNION ALL
		SELECT d.pub_id, d.pub_name, d.city, d.state, d.country, GETDATE(), 'DEL'
		FROM deleted d
END

GO

-- Trigger for INSERT and DELETE for titles
CREATE TRIGGER trg_titles_audit ON titles
AFTER INSERT, DELETE
AS
BEGIN
	SET NOCOUNT ON;
	INSERT INTO titles_audit(title_id, title_name, type, pub_id, pages, price, sales, pubdate, contract, updated_at, operation)
		SELECT i.title_id, i.title_name, i.type, i.pub_id, i.pages, i.price, i.sales, i.pubdate, i.contract, GETDATE(), 'INS'
		FROM inserted i
	UNION ALL
		SELECT d.title_id, d.title_name, d.type, d.pub_id, d.pages, d.price, d.sales, d.pubdate, d.contract, GETDATE(), 'DEL'
		FROM deleted d
END



-- Test working triggers
-- publishers
INSERT INTO publishers VALUES('P05','Kontora','Berlin',NULL,'Germany');
DELETE FROM publishers WHERE pub_id = 'P05';
SELECT * FROM publishers_audit;

-- titles
INSERT INTO titles VALUES('T15','Hello world','Informatic','P04',802,29.99,10467, '2000-05-31',1);
DELETE FROM titles WHERE pub_id = 'T15';
SELECT * FROM titles_audit;

SELECT * FROM titles;

