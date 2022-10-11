/*
 *  author: Jingbo Su
 *  created: Thu Oct 7 2022
**/

#ifndef __RR_H__
#define __RR_H__

#include "process.h"
#include "queue.h"

#define QUANTUM 2

static int quantum = QUANTUM;
static int cnt = 1;

void rr_exec() {
  qsort(process, __NPROCESS__, sizeof(process_t), cmp_1);
  queue_t head = create();
  append(process[0], head);
  for (int clk = 0; ; ) {
    if (cnt == __NPROCESS__ && is_empty(head)) break;
    if (quantum <= 0) quantum = QUANTUM;
    while (cnt < __NPROCESS__ && process[cnt].arrival_time == clk) {
      append(process[cnt], head);
      cnt += 1;
    }
    if (!is_empty(head)) {
      process_t top = pop(head);
      while (quantum--) {
        if (top.execution_time <= 0) break;
        printf("Now: %d s, PID: %d, [Queue]: ", clk, top.pid); await(head);
        // sleep(1);
        queue_t qptr = head;
        while (qptr->next != head) {
          process[qptr->pcb.pid].wait_time += 1;
          qptr = qptr->next;
        }
        top.execution_time -= 1;
        clk += 1;
        while (cnt < __NPROCESS__ && process[cnt].arrival_time == clk) {
          append(process[cnt], head);
          cnt += 1;
        }
      }
      if (top.execution_time > 0) {
        append(top, head);
      }
    } else {
      printf("Now: %d s, [Waiting for a process, the queue is empty...]\n", clk);
      // sleep(1);
      clk += 1;
    }
  }
  clear(head);
}

void rr_show() {
  qsort(process, __NPROCESS__, sizeof(process_t), cmp_2);
  puts("PID\tWaiting Time");
  double avg = 0.0;
  for (int i = 0; i < __NPROCESS__; ++i) {
    printf("%d\t%d\n", process[i].pid, process[i].wait_time);
    avg += (double) process[i].wait_time;
  }
  // sleep(1);
  puts("===========================");
  printf("Total Waiting Time: %d\n", (int) avg);
  printf("Average Waiting Time: %.2lf\n\n", avg / __NPROCESS__);
}

void rr_run() {
  rr_exec();
  rr_show();
  puts("");
}

#endif // __RR_H__
