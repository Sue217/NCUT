-- author: Jingbo Su
-- created: Oct 31 2022

USE NCUT;

INSERT INTO `Student`
VALUES
    ('001', 'Jingbo Su', 'Male', 20, 'Computer Science'),
    ('002', 'Harry Potter', 'Male', 22, 'Gryffindor'),
    ('003', 'Ron Weasley', 'Male', 22, 'Gryffindor'),
    ('004', 'Hermione Granger', 'Female', 21, 'Gryffindor'),
    ('005', 'Draco Malfoy', 'Male', 22, 'Slughorn'),
    ('006', 'Tom Riddle', 'Male', 96, 'Slughorn');
    
INSERT INTO `Course`
VALUES
    ('050', 'Computer Intro.', 32, 3),
    ('61b', 'Advanced Programming', 48, 4),
    ('193', 'IOS Development', 48, 2),
    ('221', 'Machine Learning', 48, 3),
    ('828', 'Operation System', 64, 6),
    ('75p', 'Data Base', 64, 6);
    
INSERT INTO `Teacher`
VALUES
    ('910', 'Albus Dumbledore', 'Male', 'Computer Science', '050'),
    ('911', 'Minerva McGonagall', 'Female', 'Gryffindor', '61b'),
    ('912', 'Remus Lupin', 'Male', 'Gryffindor', '193'),
    ('913', 'Rubeus Hagrid', 'Male', 'Gryffindor', '221'),
    ('914', 'Severus Snape', 'Male', 'Slughorn', '828'),
    ('915', 'Olivia Green', 'Female', 'Slughorn', '75p');

INSERT INTO `Score`
VALUES
    ('001', '050', 100),
    ('001', '61b', 96),
    ('001', '193', 92),
    ('001', '221', 98),
    ('002', '050', 90),
    ('002', '61b', 96),
    ('002', '193', 88),
    ('002', '221', 90),
    ('002', '75p', 80),
    ('003', '050', 80),
    ('003', '61b', 86),
    ('003', '193', 82),
    ('003', '221', 78),
    ('003', '75p', 90),
    ('004', '050', 100),
    ('004', '61b', 96),
    ('004', '193', 98),
    ('004', '221', 98),
    ('004', '828', 95),
    ('004', '75p', 99),
    ('005', '050', 90),
    ('005', '193', 82),
    ('005', '221', 82),
    ('005', '828', 83),
    ('006', '050', 99),
    ('006', '61b', 90),
    ('006', '193', 99),
    ('006', '221', 99),
    ('006', '828', 90),
    ('006', '75p', 99);