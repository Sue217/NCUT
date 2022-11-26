#include <stdio.h>
#include <stdlib.h>

#include "fs.h"
#include "user.h"

int main(int argc, char* argv[]) {
  fs_create();
  fs_sync();
  fs_mount();

  falloc("first");
//  falloc("second");
//  falloc("third");

//  fsset(0, 100);
//  fsset(0, 1000);
  fsset(0, 5000);
//  print();

  char xc = 'a';
  for (int i = 0; i < 49; i++) {
    write_byte(0, i * 100, &xc);
  }

//  for (int i = 10; i < 20; i++) {
//    write_byte(0, i * 100, 'b');
//  }
//
//  for (int i = 20; i < 30; i++) {
//    write_byte(0, i * 100, 'c');
//  }

  print();
  puts("[Done]");

  return 0;
}