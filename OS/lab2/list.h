/*
 *  author: Jingbo Su
 *  created: Oct 14 2022
**/

#ifndef __LIST_H__
#define __LIST_H__

#include "ins.h"

static int len;

typedef struct list {
  struct list* next;
  struct list* prev;
  int page[__1K__];
} *list_t;

list_t create() {
  list_t head = (list_t) malloc(sizeof(struct list));
  list_t tail = (list_t) malloc(sizeof(struct list));
  if (!head || !tail) {
    puts("malloc fault (create)");
    exit(2);
  }
  head->next = head->prev = tail;
  tail->next = tail->prev = head;
  return head;
}

void __clear__(list_t head) {
  list_t tail = head->next;
  while (head != tail) {
    list_t cur = head;
    head = head->next;
    free(cur);
    len -= 10;
  }
  free(head);
}

int is_empty(list_t head) {
  return head->next->next == head;
}

void append(list_t head, int a[]) {
  list_t tail = head->prev;
  if (len > __TOTAL__) {
    puts("memory overflow (list)");
    exit(1);
  }
  list_t x = (list_t) malloc(sizeof(struct list));
  if (!x) {
    puts("malloc fault (append)");
    exit(2);
  }
  tail->prev->next = x;
  x->prev = tail->prev;
  x->next = tail;
  tail->prev = x;
  for (int i = 0; i < __1K__; i++) {
    x->page[i] = a[i];
  }
  len += 10;
}

void pop(list_t head) {
  if (is_empty(head)) {
    puts("invalid access (list)");
    exit(3);
  }
  if (head->next->next == head) {
    puts("list is empty (pop)");
    exit(1);
  }
  list_t cur = head->next;
  head->next = cur->next;
  cur->next->prev = head;
  len -= 10;
}

void replace(list_t head, list_t x) {
  if (x->next->next == x) {
    puts("list is empty (replace)");
    exit(1);
  }
  x->prev->next = x->next;
  x->next->prev = x->prev;
  int* p = x->page;
  free(x);
  append(head, p);
  len -= 10;
}

list_t is_hit(list_t head, int value) {
  if (is_empty(head)) {
    return NULL;
  }
  list_t ptr = head->next;
  while (ptr->next != head) {
    if ((value / 10) * 10 == ptr->page[0]) {
      return ptr;
    }
    ptr = ptr->next;
  }
/*
  printf("is_hit: %d\n", value);
  ptr = head->next;
  while (ptr->next != head) {
    printf("%d ", ptr->page[0]);
    ptr = ptr->next;
  }
  puts("\n");
*/
  return NULL;
}

#endif  // __LIST_H__
