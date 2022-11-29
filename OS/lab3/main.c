#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "fs.h"
#include "input.c"
#include "user.h"

#define BUF_SIZE 128

void run() {
  while (1) {
    printf("#sujingbo $ ");

    char buf[BUF_SIZE];
    int len = input(buf, BUF_SIZE);
    if (len == RETURN) continue;
    if (len == CLS) {
      system("clear");
      continue;
    }
//    printf("buf = %s\n", buf);

    char argv[4][MAX_SIZE];
    assert(len < BUF_SIZE);
    int ops = parse(buf, argv);
//    printf("ops = %d\n", ops);

//    assert(~ops);  // assert if ops = -1

//    int fd = INIT;

    switch (ops) {
      case CREATE: {
//        printf("1 %s\n2 %s\n3 %s\n", argv[1], argv[2], argv[3]);
        int fd = f_create(argv[1], argv[2], argv[3]);
        if (fd == INIT) {
          puts("[Create failed!]");
        }
      }
        break;
      case DELETE: {
        int status = f_delete(argv[1]);
        if (status == FAILED) {
          puts("[Delete failed!]");
        }
      }
        break;
      case OPEN:
        puts("file opened");
        break;
      case CLOSE:
        puts("file closed");
        break;
      case READ: {
        char *content = f_read(argv[1]);
        if (!content) {
          puts("[Read failed!]");
        } else {
          printf("\n%s\n\n", content);
        }
      }
        break;
      case WRITE: {
        int status = f_write(argv[1], argv[2]);
        if (status == FAILED) {
          puts("[Write failed!]");
        }
      }
        break;
      case DIR:
        f_dir();
        break;
      case LOGOUT:
        puts("\nBye 👋🏻\n");
        return;
      default:
        printf("command not found: %s\n", op);
        break;
    }
    fs_sync();
  }
}

int main() {
/*  test
  fs_create();
  fs_sync();
  fs_mount();

  falloc("first");
  falloc("second");
  falloc("third");
  int fd = falloc("another");

  fsset(0, 1024);
  fsset(1, 1024);
  fsset(2, 1024);
  fsset(fd, 1024);
  print();

  char* xsa = "Hello, world!";
  char* xsb = "This is my";
  char* xsc = "File System.";
  write_byte(0, 0, xsa);
  write_byte(1, 0, xsb);
  write_byte(2, 0, xsc);
  write_byte(fd, 0, "for test");

  fs_sync();

  // TODO: User: login, logout
  // TODO: File: read_byte, fs_delete, ls(dir)

  print();
  puts("[Done]");
*/

  // infinite loop if username or password didn't match
  while (login() == DENIED);
  getchar();
  system("clear");
  puts("Login Successfully!\n");

  // login info checked
  fs_create();
  fs_sync();
  run();
  return 0;
}