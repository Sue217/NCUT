-- author: Jingbo Su
-- created: Nov 1 2022

USE NCUT;

DELIMITER //

DROP PROCEDURE IF EXISTS `__PROCEDURE_TASK__`;
CREATE PROCEDURE __PROCEDURE_TASK__(IN LOW int, IN HIGH int)
BEGIN
    SET @LB = LOW;
    SET @HB = HIGH;
    SELECT Student.sname, Student.sdept, Score.grade
    FROM Student, Course, Score
    WHERE Course.cname = 'Data Base'
        AND Student.sno = Score.sno
        AND Course.cno = Score.cno
        AND Score.grade BETWEEN @LB AND @HB;
END //

DELIMITER ;

CALL __PROCEDURE_TASK__(85, 100);