/*
 *  author: Jingbo Su
 *  created: Oct 13 2022
**/

#ifndef __FIFO_H__
#define __FIFO_H__

#include "ins.h"

static int user_vm[__TOTAL__];
static int idx, size;

void __init_fifo__() {
  for (int i = 0; i < __TOTAL__; i++) {
    user_vm[i] = -1;
  }
  idx = size = 0;
}

int fifo(int value, int ram) {
  const int max_size = ram * __1K__;
  for (int i = 0; i < max_size; i++) {
    if (value == user_vm[i]) {
      // hit
      return 0;
    }
  }
  // didn't hit
  size += (size < max_size) * 10;
  for (int i = 0, j = (value / 10) * 10; i < 10; i++, j++, idx++) {
    user_vm[idx] = ins[j];
  }
  idx %= max_size;
  return 1;
}

#endif // __FIFO_H__
