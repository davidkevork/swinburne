PROMPT *** Group Number: 5 ***
PROMPT *** 102100902 -> David Kevork
PROMPT *** 102104302 -> Matthew Thorne
PROMPT *** 102101219 -> Phillip Weinstock

PROMPT *** Drop Table WorkSession ***
-- Drop Table WorkSession
DROP TABLE WorkSession;

PROMPT *** Drop Table Allocation ***
-- Drop Table Allocation
DROP TABLE Allocation;

PROMPT *** Drop Table Book ***
-- Drop Table Book
DROP TABLE Book;

PROMPT *** Drop Table AUTHOR ***
-- Drop Table AUTHOR
DROP TABLE AUTHOR;

PROMPT *** Create Table AUTHOR ***
-- Create Table AUTHOR
CREATE TABLE AUTHOR(
    authid NUMBER(4),
    sname VARCHAR2(30),
    fname VARCHAR2(30),
    PRIMARY KEY (authid),
    CONSTRAINT AU_AUTHOR UNIQUE (sname, fname)
);

PROMPT *** Creating Table Book ***
-- Creating Table Book
CREATE TABLE Book(
    bid NUMBER(4),
    title VARCHAR2(30) NOT NULL,
    sellingprice NUMBER(6,2),
    PRIMARY KEY (bid),
    CONSTRAINT BO_SELLINGPRICE CHECK (sellingprice > 0)
);

PROMPT *** Create Table Allocation ***
-- Create Table Allocation
CREATE TABLE Allocation(
    bid NUMBER(4),
    authid NUMBER(4),
    payrate NUMBER(6,2),
    CONSTRAINT AL_PAYRATE CHECK (payrate < 80 AND payrate >= 1),
    Foreign Key (authid) References AUTHOR,
    Foreign Key (bid) References Book
);

PROMPT *** Inserting AUTHOR data ***
-- Inserting AUTHOR data
INSERT INTO AUTHOR VALUES(40, 'Ziggle', 'Carl');
INSERT INTO AUTHOR VALUES(42, 'Taylor', 'Tayla');
INSERT INTO AUTHOR VALUES(44, 'Merdovic', 'Damir');
INSERT INTO AUTHOR VALUES(45, 'Grossman', 'Paul');
INSERT INTO AUTHOR VALUES (47, 'Ziggle', 'Annie');
INSERT INTO AUTHOR VALUES(48, 'Zhao', 'Cheng');
INSERT INTO AUTHOR VALUES(50, 'Phan', 'Annie');

PROMPT *** Inserting book data ***
-- Inserting book data
INSERT INTO BOOK VALUES(101, 'Knitting with Dog Hair', 6.99);
INSERT INTO BOOK VALUES(105, 'Avoiding Large Ships', 11);
INSERT INTO BOOK VALUES(107, 'Dealing with stuff', 6.5);
INSERT INTO BOOK VALUES(108, 'Teach fish to sing', 10.99);
INSERT INTO BOOK VALUES(109, 'Guide to hands free texting', 10.5);
INSERT INTO BOOK VALUES(113, 'You call that a lecture?', 17.5);

PROMPT *** Inserting Allocation data ***
-- Inserting Allocation data
INSERT INTO ALLOCATION VALUES (101, 42, 25);
INSERT INTO ALLOCATION VALUES (101, 45, 32);
INSERT INTO ALLOCATION VALUES (108, 47, 35);
INSERT INTO ALLOCATION VALUES (113, 48, 40);
INSERT INTO ALLOCATION VALUES (109, 47, 42);
INSERT INTO ALLOCATION VALUES (105, 42, 26);
INSERT INTO ALLOCATION VALUES (105, 47, 25);
INSERT INTO ALLOCATION VALUES (105, 40, 19);
INSERT INTO ALLOCATION VALUES (107, 42, 35);
INSERT INTO ALLOCATION VALUES (108, 40, 45);

PROMPT *** Invalid Query ***
-- 1D Invalid Queries
INSERT INTO AUTHOR VALUES(51, 'Phan', 'Annie');
INSERT INTO BOOK VALUES(114, NULL, 20);
INSERT INTO BOOK VALUES(115, 'Test Book', -2);
INSERT INTO ALLOCATION VALUES (108, 40, 85);

-- 1E
-- Query One
PROMPT *** 1E ***
PROMPT *** Query One ***
SELECT bid, authid, payrate
	FROM ALLOCATION
	ORDER BY bid ASC, authid ASC;

-- Query Two
PROMPT *** Query Two ***
SELECT BO.bid, BO.title, AL.authid, AL.payrate
    FROM BOOK BO
    INNER JOIN ALLOCATION AL
        ON BO.bid = AL.bid;

-- Query Three
PROMPT *** Query Three ***
SELECT BO.bid, BO.title, BO.sellingprice,
	AU.authid, AU.sname, AL.payrate
	FROM BOOK BO
	INNER JOIN ALLOCATION AL
		ON BO.bid = AL.bid
	INNER JOIN AUTHOR AU
		ON AU.authid = AL.authid 
	ORDER BY BO.bid, AU.authid;


-- Query Four
PROMPT *** Query Four ***
SELECT AVG(BO.sellingprice) FROM BOOK BO;

-- Query Five
PROMPT *** Query Five ***
SELECT BO.bid, BO.title, BO.sellingprice
	FROM BOOK BO
	WHERE BO.sellingprice < (
		SELECT AVG(BO.sellingprice)
			FROM BOOK BO
	)
	ORDER BY BO.bid ASC;

-- Query Six
PROMPT *** Query Six ***
SELECT AL.bid, COUNT(*)
	FROM ALLOCATION AL
	GROUP BY AL.bid
	ORDER BY COUNT(*), AL.bid;

-- Query Seven
PROMPT *** Query Seven ***
SELECT DISTINCT BO.bid, BO.title, (
	SELECT COUNT(*)
		FROM ALLOCATION AL
		WHERE AL.bid = BO.bid
) COUNT
	FROM BOOK BO
	INNER JOIN ALLOCATION AL
		ON BO.bid = Al.bid
	ORDER BY COUNT ASC, BO.bid ASC;

-- Query Eight
PROMPT *** Query Eight ***
SELECT AL.bid, BO.title, COUNT(*) FROM Allocation AL
  INNER JOIN BOOK BO
    ON BO.bid = AL.bid
  GROUP BY AL.bid, BO.title
  HAVING Count(*) > 1
  ORDER BY Count(*), AL.bid;

-- Query Nine
PROMPT *** Query Nine ***
SELECT AU.authid, AU.sname, AU.fname, AL.bid
	FROM AUTHOR AU
	INNER JOIN ALLOCATION AL
		ON AU.authid = AL.authid
	ORDER BY AU.authid ASC, AL.bid ASC;

--Query Ten
PROMPT *** Query Ten ***
SELECT AU.authid, AU.sname, AU.fname, AL.bid
	FROM AUTHOR AU
	LEFT JOIN ALLOCATION AL
		ON AU.authid = AL.authid
	ORDER BY AU.authid ASC, AL.bid ASC;

-- Query Eleven
PROMPT *** Query Eleven ***
SELECT AU.authid, AU.sname, AU.fname, AL.bid, BO.title
	FROM AUTHOR AU
	LEFT JOIN ALLOCATION AL
		ON AU.authid = AL.authid
	INNER JOIN BOOK BO
		ON BO.bid = AL.bid
	ORDER BY AU.authid ASC, AL.bid ASC;

PROMPT *** Task 2 ***

PROMPT *** Creating Table Book ***
-- Creating Table Book
CREATE TABLE WorkSession(
	bid NUMBER(4),
	authid NUMBER(4),
	WorkYear NUMBER(4) CHECK (WorkYear >= 2011 AND WorkYear <= 2013),
	WorkWeek NUMBER(2) CHECK (WorkWeek >= 1 AND WorkWeek <= 52),
	WorkHours NUMBER(4,2) CHECK (WorkHours >= 0.5 AND WorkHours <= 99.99),
	Foreign Key (authid) References Author,
	Foreign Key (bid) References Book
);

PROMPT *** Inserting Data Into WorkSession Table ***
-- Inserting Data Into WorkSession Table
INSERT INTO WorkSession VALUES (101, 42, 2012, 5, 5);
INSERT INTO WorkSession VALUES (101, 42, 2012, 6, 4);
INSERT INTO WorkSession VALUES (101, 42, 2012, 7, 5);
INSERT INTO WorkSession VALUES (101, 45, 2012, 5, 10);
INSERT INTO WorkSession VALUES (101, 45, 2012, 7, 10);
INSERT INTO WorkSession VALUES (105, 42, 2012, 5, 6);
INSERT INTO WorkSession VALUES (105, 47, 2012, 4, 8);
INSERT INTO WorkSession VALUES (105, 47, 2012, 6, 7);
INSERT INTO WorkSession VALUES (105, 47, 2012, 8, 8);
INSERT INTO WorkSession VALUES (108, 40, 2011, 52, 4);
INSERT INTO WorkSession VALUES (108, 40, 2012, 4, 15);
INSERT INTO WorkSession VALUES (108, 40, 2012, 6, 6);
INSERT INTO WorkSession VALUES (108, 47, 2012, 8, 4);
INSERT INTO WorkSession VALUES (109, 47, 2012, 5, 5);
INSERT INTO WorkSession VALUES (109, 47, 2012, 6, 5);
INSERT INTO WorkSession VALUES (113, 48, 2012, 10, 15);
INSERT INTO WorkSession VALUES (113, 48, 2012, 11, 4);
INSERT INTO WorkSession VALUES (113, 48, 2012, 12, 1);

PROMPT *** Invalid Insert Statements ***
-- Invalid Insert Statements
INSERT INTO WorkSession VALUES (102, 48, 2012, 1, 1);
INSERT INTO WorkSession VALUES (109, 41, 2012, 2, 2);
INSERT INTO WorkSession VALUES (101, 42, 2014, 9, 6);
INSERT INTO WorkSession VALUES (101, 45, 2012, 55, 3);
INSERT INTO WorkSession VALUES (108, 40, 2012, 7, 120);

-- Query One
PROMPT *** Query One ***
SELECT WS.authid, WS.WorkYear, WS.WorkWeek, WS.WorkHours
	FROM WorkSession WS
	ORDER BY WS.authid ASC, WS.WorkYear ASC, WS.WorkWeek ASC;

-- Query Two
PROMPT *** Query Two ***
SELECT WS.authid, WS.WorkYear, SUM(WS.WorkHours) AS TotalHours
	FROM WorkSession WS
	GROUP BY WS.WorkYear, WS.authid
	ORDER BY TotalHours DESC, WS.authid ASC;

-- Query Three
PROMPT *** Query Three ***
SELECT WS.bid, WS.authid, WS.WorkYear, WS.WorkWeek, WS.WorkHours
	FRom WorkSession WS
	ORDER BY WS.bid ASC, WS.authid ASC, WS.WorkYear ASC, WS.WorkWeek ASC;

-- Query Four
PROMPT *** Query Four ***
SELECT WS.bid, WS.authid, WS.WorkYear, SUM(WS.WorkHours) AS TotalHours
	FROM WorkSession WS
	GROUP BY WS.bid, WS.authid, WS.WorkYear
	ORDER BY WS.bid ASC, WS.authid ASC, WS.WorkYear ASC;


-- Query Five
PROMPT *** Query Five ***
SELECT WS.bid, WS.authid, WS.WorkYear, SUM(WS.WorkHours) * (
	SELECT AL.payrate
		FROM ALLOCATION AL
		WHERE AL.bid = WS.bid
		AND AL.authid = WS.authid
) AS TotalPay
	FROM WorkSession WS
	INNER JOIN ALLOCATION AL
		ON WS.bid = AL.bid
		AND WS.authid = AL.authid
	GROUP BY WS.bid, WS.authid, WS.WorkYear
	ORDER BY WS.bid ASC, WS.authid ASC, WS.WorkYear ASC;
