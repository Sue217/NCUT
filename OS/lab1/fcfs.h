/*
 *  author: Jingbo Su
 *  created: Thu Sep 29 2022
**/

#ifndef __FCFS_H__
#define __FCFS_H__

#include "process.h"

#define max(a, b) \
  ({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
   _a > _b ? _a : _b; })

void fcfs_exec() {
  qsort(process, __NPROCESS__, sizeof(process_t), cmp_1);
  int zone = 0;
  ptr = process;
  puts("(Executing...)\n");
  // sleep(1);
  puts("Now\tPID\t");
  int tot = 0;
  for (int i = 0; ; ++i) {
    if (i >= zone + ptr->execution_time) {
      zone = i;
      ++ptr;
      ++tot;
      ptr->wait_time = max(0, zone - ptr->arrival_time);
      printf("[Context Switching! Process %d has waited %d s]\n", ptr->pid, ptr->wait_time);
    }
    if (tot == __NPROCESS__ - 1) {
      return;
    }
    printf("%d\t%d\n", i + 1, ptr->pid);
    // sleep(1);
  }
}

void fcfs_show() {
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

void fcfs_run() {
  fcfs_exec();
  fcfs_show();
  puts("");
}

#endif // __FCFS_H__
