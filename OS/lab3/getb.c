#include "fs.h"

int get_block_number(int fnum, int block) {
  int _offset = block;
  int bnum = inodes[fnum].first;  // first block of the file whose number is `fnum`
  while (_offset--) {
    bnum = dbs[bnum].next;
  }
  return bnum;
}