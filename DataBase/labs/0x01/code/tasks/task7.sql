-- author: Jingbo Su
-- created: Nov 1 2022

USE NCUT;

SELECT Teacher.tname
FROM Teacher, Course
WHERE (Teacher.cno = Course.cno)
    AND (Course.cname = 'Data Base')