/*
 *  author: Jingbo Su
 *  created: Oct 13 2022
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "ins.h"
#include "gen.h"
#include "list.h"
#include "fifo.h"
#include "lru.h"

int main(int argc, char* argv[]) {
  srand(time(NULL));
  int strategy = 0;
  if (argc == 2) {
    if (strlen(argv[1]) == 4) {
      // fifo
      strategy = 1;
    } else
    if (strlen(argv[1]) == 3) {
      // lru
      strategy = 2;
    } else {
      puts("Invalid input operation");
    }
  } else
  if (argc == 1) {
    strategy = 3;
  } else {
    puts("Invalid input operation");
    exit(0);
  }
  __init__();
  if (strategy == 3) {
    puts("User Mem\tFIFO\t\tLRU\n");
  }
  for (int ram = 4; ram <= 32; ram++) {
    double miss_fifo, miss_lru, hit_rate;
    miss_fifo = miss_lru = hit_rate = 0.0;
    int steps = __TOTAL__;
    int flip = 1;
    int addr = rand() % (__TOTAL__ - 1);
    idx = size = 0;
    __init_fifo__();
    __init_lru__();
    while (steps > 0) {
      __generate__(&steps, &flip, &addr);
      if (strategy == 1) {
        miss_fifo += (double) fifo(ins[addr], ram);
      } else
      if (strategy == 2) {
        miss_lru += (double) lru(ins[addr], ram);
      } else {
        miss_fifo += (double) fifo(ins[addr], ram);
        miss_lru += (double) lru(ins[addr], ram);
      }
      steps -= 1;
    }
    if (strategy == 1) {
      hit_rate = 1.0 - miss_fifo / (double) __TOTAL__;
    } else
    if (strategy == 2) {
      hit_rate = 1.0 - miss_lru / (double) __TOTAL__;
      __clear__(lst);
    }
    if (strategy != 3) {
      printf("User Mem: %d, Hit rate = %.4lf\n", ram, hit_rate);
      continue;
    }
    double rate_fifo = 1.0 - miss_fifo / (double) __TOTAL__;
    double rate_lru = 1.0 - miss_lru / (double) __TOTAL__;
    printf("\n%d\t", ram);
    printf("\t%.4lf\t\t%.4lf\n", rate_fifo, rate_lru);
    __clear__(lst);
  }
  return 0;
}
