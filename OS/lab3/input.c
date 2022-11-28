#include <stdio.h>

#include "login.c"

#define RETURN -1

int input(char *buf, int max_size) {
  int nn = 0;
  char ch;
  while ((ch = getchar()) && ch != '\n' && nn + 1 < max_size) {
    buf[nn++] = ch;
  }
  buf[nn] = '\0';

  if (nn == 0 && ch == '\n') {
    return RETURN;
  }
//  getchar();
//  printf("%s\n", buf);
  return nn;
}

int check(char *op) {
  for (int i = 0; i < TOTAL_OP; i++) {
    if (match(op, Model[i])) {
      return Tag[i];
    }
  }
  return ERROR;
}

int parse(char *buf, char argv[][MAX_SIZE]) {
  char *sp = buf;
  printf("buf: %s\n", buf);
  // leading space
  while (*sp == ' ' || *sp == '\n' || *sp == '\0') sp++;

  // null string
  if (*sp == '\0') return NIL;

  // parse the instruction
  // operation
  char op[MAX_OP] = {0};
  int p = 0;
  while (*sp != ' ' && *sp) {
    op[p++] = *sp;
    sp++;
  }
  strcpy(argv[0], op);
  printf("operation: %s\n", argv[0]);

  // no file content
  if (*sp == '\0') return check(op);

  // middle space
  while (*sp == ' ') sp++;

  // target (file)
  char fn[MAX_SIZE] = {0};
  p = 0;
  while (*sp != ' ' && *sp) {
    fn[p++] = *sp;
    sp++;
  }
  strcpy(argv[1], fn);
  printf("filename: %s\n", fn);

  // no mode
  if (*sp == '\0') return check(op);

  // middle space
  while (*sp == ' ') sp++;

  // file mode
  // write mode
  if (match(op, "write")) {
    char content[MAX_SIZE] = {0};
    int nn = 0;
    while (*sp) {
      content[nn++] = *sp;
      sp++;
    }
    strcpy(argv[2], content);
    return check(op);
  }
  // others
  char md = *sp;
  sp++;
  strcpy(argv[2], &md);
  printf("content: %c\n", md);

  // no type
  if (*sp == '\0') return check(op);

  // middle space
  while (*sp == ' ') sp++;

  // file type
  char tp = *sp;
  sp++;
  strcpy(argv[3], &tp);
//  printf("type: %c\n", tp);

  // no mode
  if (*sp == '\0') return check(op);

  return ERROR;
}
