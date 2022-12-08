#include <string.h>

#include "fs.h"

int grow(int total, int bid) {
  if (dbs[bid].data[0]) {
    int eb = find_empty_block();
    dbs[bid].next_block = eb;
    dbs[eb].next_block = LAST;
    bid = eb;
  }
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
  strcpy(dbs[bid].data, "");
  int nn = dbs[bid].next_block;
  if (nn >= 0) {
    shrink(nn);
  }
  dbs[bid].next_block = INIT; //! or LAST?
}