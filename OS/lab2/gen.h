/*
 *  author: Jingbo Su
 *  created: Oct 19 2022
**/

#ifndef __GEN_H__
#define __GEN_H__

#include "ins.h"

void __generate__(int* step, int* flip, int* addr) {
  if (*step % 2 == 0) {
    // jump
    if (*flip) {
      // jump forward
      *addr = rand() % (*addr == 0 ? 0 : *addr - 1);
    } else {
      // jump backward
      *addr += rand() % (__TOTAL__ - *addr);
      if (*addr >= __TOTAL__ - 1) {
        *addr = __TOTAL__ - 2;
      }
    }
    *flip ^= 1;
  } else {
    // sequence
    *addr += 1;
  }
}

#endif  // __GEN_H__
