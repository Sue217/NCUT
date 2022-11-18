-- author: Jingbo Su
-- created: Nov 1 2022

USE NCUT;

SELECT Student.sno, Student.sname, Student.ssex, Student.sage, Student.sdept
FROM Student, Teacher, Score
WHERE (Teacher.tname = 'Severus Snape')
    AND (Teacher.cno = Score.cno)
    AND (Student.sno = Score.sno)