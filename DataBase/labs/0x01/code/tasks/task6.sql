-- author: Jingbo Su
-- created: Nov 1 2022

USE NCUT;

SELECT Student.sname, Score.cno, Score.grade
FROM Student, Score
WHERE (Student.sno = Score.sno)
    AND Score.grade IN (
        SELECT MAX(Score.grade)
        FROM Score
        WHERE Student.sno = Score.sno
        GROUP BY Score.sno
    )