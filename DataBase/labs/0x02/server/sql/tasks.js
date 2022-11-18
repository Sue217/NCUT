export function tasks (task) {
  var task0 = "CREATE TABLE IF NOT EXISTS `Student` ( \
                  sno char(20) NOT NULL, \
                  sname char(20) NOT NULL, \
                  ssex char(10) NOT NULL, \
                  sage int NOT NULL, \
                  sdept char(30) NOT NULL, \
                  PRIMARY KEY (sno) \
              ); \
              CREATE TABLE IF NOT EXISTS `Course` ( \
                  cno char(20) NOT NULL, \
                  cname char(20) NOT NULL, \
                  ctime int NOT NULL, \
                  ccredit int NOT NULL, \
                  PRIMARY KEY (cno) \
              ); \
              CREATE TABLE IF NOT EXISTS `Teacher` ( \
                  tno char(20) NOT NULL, \
                  tname char(20) NOT NULL, \
                  tsex char(10) NOT NULL, \
                  tdept char(30) NOT NULL, \
                  cno char(20) NOT NULL, \
                  PRIMARY KEY (tno) \
              ); \
              CREATE TABLE IF NOT EXISTS `Score` ( \
                  sno char(20) NOT NULL, \
                  cno char(20) NOT NULL, \
                  grade int NOT NULL, \
                  PRIMARY KEY (sno, cno) \
              );";
  var task1 = "SELECT Student.sno, Student.sname, (2022 - Student.sage) AS birth \
              FROM Student";
  var task2 = "SELECT sdept, COUNT(sno) AS total\
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
  // var task9 = "CREATE TABLE IF NOT EXISTS `S1` ( \
  //                 sno char(20) NOT NULL, \
  //                 sname char(20) NOT NULL, \
  //                 sd char(30) NOT NULL, \
  //                 sa int NOT NULL, \
  //                 PRIMARY KEY (sno) \
  //             ); \
  //             INSERT INTO `S1` \
  //             SELECT Student.sno, Student.sname, Student.sdept, Student.sage \
  //             FROM Student \
  //             WHERE Student.sdept = 'Computer Science'; \
  //             SELECT * FROM S1";
  var task9 = "SELECT * FROM S1;";
  // var task10 = "SET SQL_SAFE_UPDATES = 0; \
  //               CREATE VIEW `STUDENT_CS` \
  //               AS \
  //               SELECT * \
  //               FROM Student \
  //               WHERE Student.sdept = 'Computer Science'; \
  //               UPDATE Score \
  //               SET Score.grade = \
  //               CASE WHEN Score.grade <= 95 THEN Score.grade + 5 \
  //               ELSE 100 END \
  //               WHERE Score.sno IN ( \
  //                   SELECT Score.sno \
  //                   FROM STUDENT_CS \
  //               ); \
  //               SELECT STUDENT_CS.sno, STUDENT_CS.sname, Score.grade \
  //               FROM STUDENT_CS, Score \
  //               WHERE STUDENT_CS.sno = Score.sno";
  var task10 = "SELECT STUDENT_CS.sno, STUDENT_CS.sname, Score.grade \
                FROM STUDENT_CS, Score \
                WHERE STUDENT_CS.sno = Score.sno;";
  const dict = [task0, task1, task2, task3, task4, task5, task6, task7, task8, task9, task10];
  return dict[task].toString();
}