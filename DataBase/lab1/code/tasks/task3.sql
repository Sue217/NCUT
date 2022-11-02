-- author: Jingbo Su
-- created: Nov 1 2022

USE NCUT;

SELECT Student.sno, Course.cname, Score.grade
FROM Student, Course, Score
WHERE (Course.cno = '61b' OR Course.cno = '828')
    AND (Course.cno = Score.cno)
    AND (Student.sno = Score.sno)