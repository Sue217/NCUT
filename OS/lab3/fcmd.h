#ifndef __FILE_CMD_H__
#define __FILE_CMD_H__

#define ERROR (-1)
#define NIL 0
#define LOGIN 1
#define CREATE 2
#define DELETE 3
#define OPEN 4
#define CLOSE 5
#define READ 6
#define WRITE 7
#define DIR 8
#define LOGOUT 9

#define TOTAL_OP 9

#define MAX_OP 8
#define MAX_SIZE 64

int Tag[TOTAL_OP] = {LOGIN, CREATE, DELETE, OPEN,
                     CLOSE, READ, WRITE, DIR, LOGOUT};

char Model[TOTAL_OP][MAX_OP] = {"login", "create", "delete", "open",
                                "close", "read", "write", "ls", "logout"};

#endif  // __FILE_CMD_H__