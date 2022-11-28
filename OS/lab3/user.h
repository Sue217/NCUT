// system calls
#ifndef __USER_H__
#define __USER_H__

#define MAX_LEN 256

#define SUCCESS 200
#define FAILED 400

int f_create(char* file_name, char* mode, char* type);  // return file descriptor

int f_delete(char* file_name); // delete through file name, return status

int f_open(char* file_name);

int f_close(char* file_name);

char* f_read(char* file_name);

int f_write(char* file_name, char* content);



#endif  // __USER_H__