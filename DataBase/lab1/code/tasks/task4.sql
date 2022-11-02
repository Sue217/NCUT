-- author: Jingbo Su
-- created: Nov 1 2022

USE NCUT;

SELECT Teacher.tname
FROM Teacher, Score
WHERE (Teacher.cno = Score.cno)
GROUP BY Teacher.tname
HAVING COUNT(Score.sno) > 3