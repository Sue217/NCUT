#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
//    printf("buf = %s\n", buf);

    char argv[4][MAX_SIZE];
    assert(len < BUF_SIZE);
    int op = parse(buf, argv);
//    printf("op = %d\n", op);

    assert(~op);  // assert if op = -1

//    int fd = INIT;

    switch (op) {
      case CREATE: {
//        printf("1 %s\n2 %s\n3 %s\n", argv[1], argv[2], argv[3]);
        int fd = f_create(argv[1], argv[2], argv[3]);
        if (fd == INIT) {
          puts("\n[Create failed!]\n");
        }
      }
        break;
      case DELETE: {
        int status = f_delete(argv[1]);
        if (status == FAILED) {
          puts("\n[Delete failed!]\n");
        }
      }
        break;
      case OPEN:
        f_open(argv[1]);
        break;
      case CLOSE:
        f_close(argv[1]);
        break;
      case READ: {
        char *content = f_read(argv[1]);
        if (!content) {
          puts("\n[Read failed!]\n");
        } else {
          printf("\n%s\n\n", content);
        }
      }
        break;
      case WRITE: {
        int status = f_write(argv[1], argv[2]);
        if (status == FAILED) {
          puts("\n[Write failed!]\n");
        }
      }
        break;
      case DIR:
        break;
      case LOGOUT:
        puts("\nBye 👋🏻\n");
        return;
      default:
        puts("Oh no!");
        return;
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
//  while (login() == DENIED);

  // login info checked
  fs_create();
  fs_sync();
  run();
  return 0;
}