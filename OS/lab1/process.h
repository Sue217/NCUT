/*
 *  author: Jingbo Su
 *  created: Thu Sep 29 2022
**/

#ifndef __PROCESS_H__
#define __PROCESS_H__

typedef struct Process {
  int pid;
  int arrival_time;
  int execution_time;
  int wait_time;
  int priority;
  // void (*entry)(int);
} process_t;

#define __NPROCESS__ 5

process_t process[__NPROCESS__];
process_t* ptr = process;

void initialize() {
  *ptr = (process_t) {
    .pid = 1,
    .arrival_time = 0,
    .execution_time = rand() % 10 + 1,
    .wait_time = 0,
    .priority = rand() % 10 + 1,
  };
  ++ptr;
  for (int i = 2; i <= __NPROCESS__; ++i) {
    *ptr = (process_t) {
      .pid = i,
      .arrival_time = rand() % (__NPROCESS__ << 1) + 1,
      .execution_time = rand() % 10 + 1,
      .wait_time = 0,
      .priority = rand() % 10 + 1,
    };
    ++ptr;
  }
  ptr = process;
  /*
  process[0].pid = 1; process[0].arrival_time = 4; process[0].priority = 2;
  process[0].execution_time = 6; process[0].wait_time = 0;
  process[1].pid = 4; process[1].arrival_time = 5; process[1].priority = 1;
  process[1].execution_time = 3; process[1].wait_time = 0;
  process[2].pid = 2; process[2].arrival_time = 5; process[2].priority = 3;
  process[2].execution_time = 1; process[2].wait_time = 0;
  process[3].pid = 3; process[3].arrival_time = 1; process[3].priority = 4;
  process[3].execution_time = 2; process[3].wait_time = 0;
  process[4].pid = 5; process[4].arrival_time = 3; process[4].priority = 5;
  process[4].execution_time = 4; process[4].wait_time = 0;
  */
  puts("PID\tAT\tET\tPRI\n");
  sleep(1);
  for (int i = 0; i < __NPROCESS__; ++i, ++ptr) {
    printf("%d\t%d\t%d\t%d\n", ptr->pid, ptr->arrival_time, ptr->execution_time, ptr->priority);
  }
  puts("---------------------------");
}

void refresh() {
  for (int i = 0; i < __NPROCESS__; ++i) {
    process[i].wait_time = 0;
  }
}

int cmp_1(const void* a, const void* b) {
  process_t* pa = (process_t*) a;
  process_t* pb = (process_t*) b;
  if (pa->arrival_time == pb->arrival_time) {
    return pa->pid - pb->pid;
  }
  return pa->arrival_time - pb->arrival_time;
}

int cmp_2(const void* a, const void* b) {
  process_t* pa = (process_t*) a;
  process_t* pb = (process_t*) b;
  return pa->pid - pb->pid;
}

#endif // __PROCESS_H__
