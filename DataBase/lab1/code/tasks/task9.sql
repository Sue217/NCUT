-- author: Jingbo Su
-- created: Nov 1 2022

USE NCUT;

CREATE TABLE IF NOT EXISTS `S1` (
    sno char(20) NOT NULL,
    sname char(20) NOT NULL,
    sd char(30) NOT NULL,
    sa int NOT NULL,
    PRIMARY KEY (sno)
);

INSERT INTO `S1`
SELECT Student.sno, Student.sname, Student.sdept, Student.sage
FROM Student
WHERE Student.sdept = 'Computer Science';

SELECT * FROM S1;
-- SHOW COLUMNS FROM S1;
DROP TABLE S1