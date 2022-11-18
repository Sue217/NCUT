-- author: Jingbo Su
-- created: Oct 31 2022

CREATE TABLE `Student` (
    sno char(20) NOT NULL,
    sname char(20) NOT NULL,
    ssex char(10) NOT NULL,
    sage int NOT NULL,
    sdept char(30) NOT NULL,
    PRIMARY KEY (sno)
);

CREATE TABLE `Course` (
    cno char(20) NOT NULL,
    cname char(20) NOT NULL,
    ctime int NOT NULL,
    ccredit int NOT NULL,
    PRIMARY KEY (cno)
);

CREATE TABLE `Teacher` (
    tno char(20) NOT NULL,
    tname char(20) NOT NULL,
    tsex char(10) NOT NULL,
    tdept char(30) NOT NULL,
    cno char(20) NOT NULL,
    PRIMARY KEY (tno)
);

CREATE TABLE `Score` (
    sno char(20) NOT NULL,
    cno char(20) NOT NULL,
    grade int NOT NULL,
    PRIMARY KEY (sno, cno)
);
