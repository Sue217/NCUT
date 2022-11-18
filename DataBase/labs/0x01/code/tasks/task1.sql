-- author: Jingbo Su
-- created: Nov 1 2022

USE NCUT;

SELECT Student.sno, Student.sname, (2022 - Student.sage) AS birth
FROM Student