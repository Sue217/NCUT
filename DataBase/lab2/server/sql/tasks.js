export function tasks (task) {
  var task1 = "SELECT Student.sno, Student.sname, (2022 - Student.sage) AS birth \
              FROM Student";
  var task2 = "SELECT sdept, COUNT(sno) \
              FROM Student \
              GROUP BY sdept \
              ORDER BY COUNT(sno) DESC";
  var task3 = "SELECT Student.sno, Course.cname, Score.grade \
              FROM Student, Course, Score \
              WHERE (Course.cno = '61b' OR Course.cno = '828') \
                  AND (Course.cno = Score.cno) \
                  AND (Student.sno = Score.sno)";
  var task4 = "SELECT Teacher.tname \
              FROM Teacher, Score \
              WHERE (Teacher.cno = Score.cno) \
              GROUP BY Teacher.tname \
              HAVING COUNT(Score.sno) > 3";
  var task5 = "SELECT Student.sname, Student.sdept \
              FROM Student \
              WHERE Student.sno NOT IN ( \
                  SELECT Student.sno \
                  FROM Student, Score \
                  WHERE Student.sno = Score.sno \
                  GROUP BY Score.cno \
              )";
  var task6 = "SELECT Student.sname, Score.cno, Score.grade \
              FROM Student, Score \
              WHERE (Student.sno = Score.sno) \
                  AND Score.grade IN ( \
                      SELECT MAX(Score.grade) \
                      FROM Score \
                      WHERE Student.sno = Score.sno \
                      GROUP BY Score.sno \
                  )";
  var task7 = "SELECT Teacher.tname \
              FROM Teacher, Course \
              WHERE (Teacher.cno = Course.cno) \
                  AND (Course.cname = 'Data Base')";
  var task8 = "SELECT Student.sno, Student.sname, Student.ssex, Student.sage, Student.sdept \
              FROM Student, Teacher, Score \
              WHERE (Teacher.tname = 'Severus Snape') \
                  AND (Teacher.cno = Score.cno) \
                  AND (Student.sno = Score.sno)";
  var task9 = "CREATE TABLE `S1` ( \
                  sno char(20) NOT NULL, \
                  sname char(20) NOT NULL, \
                  sd char(30) NOT NULL, \
                  sa int NOT NULL, \
                  PRIMARY KEY (sno) \
              ); \
              INSERT INTO `S1` \
              SELECT Student.sno, Student.sname, Student.sdept, Student.sage \
              FROM Student \
              WHERE Student.sdept = 'Computer Science';";
  var task10 = "SET SQL_SAFE_UPDATES = 0; \
                CREATE VIEW `STUDENT_CS` \
                AS \
                SELECT * \
                FROM Student \
                WHERE Student.sdept = 'Computer Science'; \
                UPDATE Score \
                SET Score.grade = \
                CASE WHEN Score.grade <= 95 THEN Score.grade + 5 \
                ELSE 100 END \
                WHERE Score.sno IN ( \
                    SELECT Score.sno \
                    FROM STUDENT_CS \
                )";
  var task11 = "DELIMITER \/\/ \
                DROP PROCEDURE IF EXISTS `__PROCEDURE_TASK__`; \
                CREATE PROCEDURE __PROCEDURE_TASK__(IN LOW int, IN HIGH int) \
                BEGIN \
                    SET @LB = LOW; \
                    SET @HB = HIGH; \
                    SELECT Student.sname, Student.sdept, Score.grade \
                    FROM Student, Course, Score \
                    WHERE Course.cname = 'Data Base' \
                        AND Student.sno = Score.sno \
                        AND Course.cno = Score.cno \
                        AND Score.grade BETWEEN @LB AND @HB; \
                END \/\/ \
                DELIMITER ;";
  const dict = [task1, task2, task3, task4, task5, task6, task7, task8, task9, task10, task11];
  return dict[task - 1].toString();
}