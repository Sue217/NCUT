/*
 *  author: Jingbo Su
 *  created: Thu Oct 6 2022
**/

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "process.h"

#define MAX_SIZE 256

static int qsize = 0;

typedef struct queue {
  struct queue* next;
  struct queue* prev;
  process_t pcb;
} *queue_t;

queue_t create() {
  queue_t head = (queue_t) malloc(sizeof(struct queue));
  queue_t tail = (queue_t) malloc(sizeof(struct queue));
  if (!head || !tail) {
    puts("malloc fault (create)");
    exit(2);
  }
  head->next = head->prev = tail;
  tail->prev = tail->next = head;
  // head->pcb = process[0];
  // qsize = 1;
  return head;
}

void clear(queue_t head) {
  queue_t tail = head->next;
  assert(tail->next == head);
  free(tail);
  free(head);
}

int is_empty(queue_t head) {
  return head->next->next == head;
}

void append(process_t x, queue_t head) {
  queue_t tail = head->prev;
  if (qsize >= MAX_SIZE) {
    puts("memory overflow (queue)");
    exit(1);
  }
  queue_t y = (queue_t) malloc(sizeof(struct queue));
  if (!y) {
    puts("malloc fault (append)");
    exit(2);
  }
  y->prev = tail->prev;
  tail->prev->next = y;
  tail->prev = y;
  y->next = tail;
  y->pcb = x;
  qsize += 1;
}

process_t pop(queue_t head) {
  if (is_empty(head)) {
    puts("invalid access (queue)");
    exit(3);
  }
  if (head->next->next == head) {
    puts("queue is empty (queue)");
    exit(1);
  }
  queue_t cur = head->next;
  process_t ret = cur->pcb;
  //printf("%d\n", cur->pcb.execution_time);
  head->next = cur->next;
  cur->next->prev = head;
  qsize -= 1;
  return ret;
}

void await(queue_t head) {
  if (is_empty(head)) {
    puts("No element in the queue...");
    return;
  }
  queue_t qptr = head->next;
  while (qptr->next != head) {
    (qptr->pcb).wait_time += 1;
    printf("%d ", (qptr->pcb).pid);
    qptr = qptr->next;
  }
  puts("");
}

#endif // __QUEUE_H__
