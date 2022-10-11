/*
 *  author: Jingbo Su
 *  created: Mon Oct 10 2022
**/

#ifndef __PP_H__
#define __PP_H__

#include "process.h"
#include "heapq.h"

static int idx = 0;

void pp_exec() {
  qsort(process, __NPROCESS__, sizeof(process_t), cmp_1);
  for (int clk = 0; ; ) {
    if (idx == __NPROCESS__ && size == 0) break;
    while (idx < __NPROCESS__ && process[idx].arrival_time == clk) {
      push(process[idx], clk);
      idx += 1;
    }
    if (size != 0) {
      process_t top = popq(clk);
      while (1) {
        printf("Now: %d s, PID: %d\n", clk, top.pid);
        // sleep(1);
        top.execution_time -= 1;
        if (top.execution_time == 0) break;
        int min = update();
        if (top.priority > min) {
          push(top, clk);
          clk += 1;
          break;
        }
        clk += 1;
        while (idx < __NPROCESS__ && process[idx].arrival_time == clk) {
          push(process[idx], clk);
          idx += 1;
        }
      }
    } else {
      printf("Now: %d s, [Waiting for a process, the heap is empty...]\n", clk);
      clk += 1;
    }
  }
}

void pp_show() {
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

void pp_run() {
  pp_exec();
  pp_show();
  puts("");
}

#endif // __PP_H__
