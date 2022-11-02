-- author: Jingbo Su
-- created: Nov 1 2022

USE NCUT;

SELECT Student.sname, Student.sdept
FROM Student
WHERE Student.sno NOT IN (
    SELECT Student.sno
    FROM Student, Score
    WHERE Student.sno = Score.sno
    GROUP BY Score.cno
)