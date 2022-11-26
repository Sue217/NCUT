#include <stdio.h>

#include "fs.h"

int grow(int total, int bid) {
  while (total--) {
    // check next block number
    int nn = dbs[bid].next;
    if (nn == LAST) {
      int eb = find_empty_block();
      dbs[bid].next = eb;
      dbs[eb].next = LAST;
    }
    bid = dbs[bid].next;
  }
  return bid;
}

int shrink(int bid) {
//  printf("bid = %d\n", bid);
  int nn = dbs[bid].next;
  if (nn >= 0) {
    shrink(nn);
  }
  dbs[bid].next = INIT; //! or LAST?
  return bid;
}