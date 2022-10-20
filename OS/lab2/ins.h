/*
 *  author: Jingbo Su
 *  created: Oct 13 2022
**/

#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#define __TOTAL__ 320
#define __1K__ 10

int ins[__TOTAL__];

void __init__() {
  for (int i = 0; i < __TOTAL__; i++) {
    ins[i] = i;
  }
}

#endif  // __INSTRUCTION_H__
