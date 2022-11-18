-- author: Jingbo Su
-- created: Nov 1 2022

USE NCUT;
SET SQL_SAFE_UPDATES = 0;

CREATE VIEW `STUDENT_CS`
AS
SELECT *
FROM Student
WHERE Student.sdept = 'Computer Science';

-- SELECT * FROM STUDENT_CS;

UPDATE Score
SET Score.grade =
CASE WHEN Score.grade <= 95 THEN Score.grade + 5
ELSE 100 END
WHERE Score.sno IN (
	SELECT Score.sno
    FROM STUDENT_CS
);

-- SELECT *
-- FROM Student, Course, Score
-- WHERE (Student.sno = Score.sno)
--     AND (Course.cno = Score.cno);

SELECT STUDENT_CS.sno, STUDENT_CS.sname, Score.grade
FROM STUDENT_CS, Score
WHERE STUDENT_CS.sno = Score.sno;

DROP VIEW `STUDENT_CS`;