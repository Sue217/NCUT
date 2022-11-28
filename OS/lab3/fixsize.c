#include <stdio.h>

#include "fs.h"

int grow(int total, int bid) {
  while (total--) {
    // check next block number
    int nn = dbs[bid].next_block;
    if (nn == LAST) {
      int eb = find_empty_block();
      dbs[bid].next_block = eb;
      dbs[eb].next_block = LAST;
    }
    bid = dbs[bid].next_block;
  }
  return bid;
}

void shrink(int bid) {
//  printf("bid = %d\n", bid);
  int nn = dbs[bid].next_block;
  if (nn >= 0) {
    shrink(nn);
  }
  dbs[bid].next_block = INIT; //! or LAST?
}