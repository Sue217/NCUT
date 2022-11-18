-- author: Jingbo Su
-- created: Nov 1 2022

USE NCUT;

SELECT sdept, COUNT(sno) AS total
FROM Student
GROUP BY sdept
ORDER BY COUNT(sno) DESC