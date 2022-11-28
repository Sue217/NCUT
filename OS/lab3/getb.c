#include "fs.h"

int get_block_number(int fnum, int block) {
  int _offset = block;
  int bnum = inodes[fnum].first_block;  // first block of the file whose number is `fnum`
  while (_offset--) {
    bnum = dbs[bnum].next_block;
  }
  return bnum;
}