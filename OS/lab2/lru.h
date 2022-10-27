/*
 *  author: Jingbo Su
 *  created: Oct 14 2022
**/

#ifndef __LRU_H__
#define __LRU_H__

#include "ins.h"
#include "list.h"

list_t lst = NULL;

void __init_lru__() {
  len = 0;
  lst = create();
}

int lru(int value, int ram) {
  const int max_size = ram * __1K__;
  list_t target = is_hit(lst, value);
  if (target != NULL) {
    // hit
    replace(lst, target);
    return 0;
  }
  // didn't hit
  int a[__1K__];
  for (int i = 0, j = (value / 10) * 10; i < 10; i++, j++) {
    a[i] = ins[j];
  }
  if (len >= max_size) {
    // page fault happens
    pop(lst);
    append(lst, a);
  } else {
    // list is not full
    append(lst, a);
  }
  return 1;
}

#endif  // __LRU_H__
