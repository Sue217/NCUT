#include <stdio.h>
#include <string.h>

#include "fcmd.h"

#define USERNAME 32
#define PASSWORD 32

#define ACCEPTED 0
#define DENIED 1

struct Info {
  char username[USERNAME];
  char password[PASSWORD];
};

int match(char* s1, char* s2) {
  return !strcmp(s1, s2);
}

int login() {
  struct Info info;
  printf("Input username: ");
  scanf("%s", info.username);
  printf("Input password: ");
  scanf("%s", info.password);
  if (match(info.username, "sujingbo") && match(info.password, "20105050110")) {
    return ACCEPTED;
  } else {
    puts("No Information!");
    return DENIED;
  }
}