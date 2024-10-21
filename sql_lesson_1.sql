-- Delete all tables if exist
IF OBJECT_ID('dbo.points', 'U') IS NOT NULL
	DROP TABLE points;
IF OBJECT_ID('dbo.students', 'U') IS NOT NULL
	DROP TABLE students;
IF OBJECT_ID('dbo.documents', 'U') IS NOT NULL
	DROP TABLE documents;
IF OBJECT_ID('dbo.education_school', 'U') IS NOT NULL
	DROP TABLE education_school;
IF OBJECT_ID('tempdb..#editor_properties') IS NOT NULL
	DROP TABLE #editor_properties;


-- Create table with schools
CREATE TABLE education_school (
	id int  NOT NULL,
	name VARCHAR(50) NOT NULL,
	type VARCHAR(15) NOT NULL DEFAULT 'high',

	CONSTRAINT pk_education_school PRIMARY KEY (id),
	CONSTRAINT type_school_check CHECK(type IN ('secondary', 'high', 'primary'))
);

-- Create table with students
CREATE TABLE students (
	id int  NOT NULL,
	name VARCHAR(50) NOT NULL,
	surname VARCHAR(50) NOT NULL,
	jmbg VARCHAR(50) UNIQUE NOT NULL,
	school_id int NOT NUll,
	date_entered DATE NOT NULL,

	CONSTRAINT students_pk PRIMARY KEY(id),
	FOREIGN KEY (school_id) REFERENCES education_school(id)
);

-- Create table with documents by school
CREATE TABLE documents (
	id int  NOT NULL,
	title VARCHAR(50) NOT NULL,
	school_id int NOT NUll,
	content TEXT DEFAULT '',

	CONSTRAINT documents_pk PRIMARY KEY(id),
	FOREIGN KEY (school_id) REFERENCES education_school(id)
);
-- Student points table
CREATE TABLE points (
	student_id int,
	points int NOT NULL,

	CONSTRAINT foreign_student_pk FOREIGN KEY (student_id) REFERENCES students(id)
);

-- Local temporary table for editor
CREATE TABLE #editor_properties (
	name varchar(20) NOT NULL UNIQUE,
	value varchar(255) NULL,
);
INSERT INTO #editor_properties(name, value) VALUES
	('domain', 'localhost'),
	('port', '8000'),
	('protocol', 'http'),
	('env', '/sites/example_website/.env/bin/python3');
ALTER TABLE #editor_properties
	ADD meta TEXT DEFAULT '';

-- Insert vts and MGU university
INSERT INTO education_school(id, name, type) VALUES
	(1, 'vtš', 'high');
INSERT INTO education_school(id, name, type) VALUES
	(2, 'MGU', 'high');

-- Insert some students for vts
INSERT INTO students(id, name, surname, jmbg, school_id, date_entered) VALUES
	(26123000, 'Henry', 'Sarko', '11001100112', 1, '2021-9-1'),
	(26123012, 'Sara', 'Maja', '11001100542', 1, '2021-9-1'),
	(26121241, 'Alexandar', 'Popov', '11001100888', 2, '2021-9-1');

-- Insert points for "Henry Sarko"
INSERT INTO points(student_id, points) VALUES
	(26123000, 9),
	(26123000, 7),
	(26123000, 10),
	(26123000, 7),
	(26123000, 8);

-- Insert points for "Sara Maja"
INSERT INTO points(student_id, points) VALUES
	(26123012, 7),
	(26123012, 6),
	(26123012, 5),
	(26123012, 8),
	(26123012, 6);

-- Insert points for "Alexandar Popov"
INSERT INTO points(student_id, points) VALUES
	(26121241, 10),
	(26121241, 10),
	(26121241, 1),
	(26121241, 8),
	(26121241, 9);

-- Delete table with documents
DROP TABLE documents;

-- Change student name
UPDATE students SET surname = 'Marko' WHERE id = 26123012;

-- Show results with average points and school name for every student
SELECT 
    s.id, 
    s.name, 
    s.surname, 
    s.jmbg,
    s.date_entered,
	e.name AS school_name,
    AVG(CAST(p.points AS FLOAT)) AS grade
FROM 
    students s 
JOIN 
    points p ON s.id = p.student_id 
JOIN
	education_school e ON s.school_id = e.id
GROUP BY 
    s.id, s.name, s.surname, s.jmbg, s.school_id, s.date_entered, e.name;

-- Show all schools with id and name
SELECT id, name FROM education_school;

-- Show editor properties
SELECT * FROM #editor_properties;

-- -- -- -- LESSON 1 -- -- -- -- 21.10.2024 -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- limit params:		NOT NULL, NULL, PRIMARY KEY, FOREIGN KEY, UNIQUE, CHECK(IN, LIKE)
-- operations:			CREATE TABLE, SELECT, DROP TABLE, INSERT INTO, ALTER TABLE, UPDATE, DROP DATABASE
-- Type tables:			https://stackoverflow.com/questions/2920836/local-and-global-temporary-tables-in-sql-server

	-- Local temporary tables (CREATE TABLE #t) are visible only to the connection that creates it, and are deleted when the connection is closed.
	-- Global temporary tables (CREATE TABLE ##t) are visible to everyone, and are deleted when all connections that have referenced them have closed.
	-- Tempdb permanent tables (USE tempdb CREATE TABLE t) are visible to everyone, and are deleted when the server is restarted.
