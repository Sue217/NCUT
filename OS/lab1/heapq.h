/*
 *  author: Jingbo Su
 *  created: Mon Oct 10 2022
**/

#ifndef __HEAPQ_H__
#define __HEAPQ_H__

#include "process.h"

process_t heapq[__NPROCESS__ << 2];
static int size = 0;

void push(process_t v, int t) {
  int x = size;
  size += 1;
  heapq[x] = v;
  process[heapq[x].pid].wait_time -= t;
  while (x && heapq[(x - 1) >> 1].priority > heapq[x].priority) {
    process_t temp = heapq[x];
    heapq[x] = heapq[(x - 1) >> 1];
    heapq[(x - 1) >> 1] = temp;
    x = (x - 1) >> 1;
  }
}

void pull(int x) {
  int midx = x;
  int left = (x << 1) + 1;
  int right = (x << 1) + 2;
  if (left < size && heapq[left].priority < heapq[midx].priority) {
    midx = left;
  }
  if (right < size && heapq[right].priority < heapq[midx].priority) {
    midx = left;
  }
  if (midx != x) {
    process_t temp = heapq[midx];
    heapq[midx] = heapq[x];
    heapq[x] = temp;
    pull(midx);
  }
}

process_t popq(int t) {
  process_t min_element = heapq[0];
  process[min_element.pid].wait_time += t;
  if (size > 0) {
    heapq[0] = heapq[size - 1];
    size -= 1;
  }
  pull(0);
  return min_element;
}

int update() {
  for (int i = 0; i < size; ++i) {
    heapq[i].priority -= 1;
  }
  return heapq[0].priority;
}

#endif // __HEAPQ_H__
