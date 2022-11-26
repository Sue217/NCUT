#include "fs.h"

int find_empty_inode() {
  struct inode* ip = inodes;
  for (int i = 0; i < sb.ninodes; i++, ip++) {
    if (ip->first == INIT) {
      return i;
    }
  }
  return INIT;
}

int find_empty_block() {
  struct diskblock* dp = dbs;
  for (int i = 0; i < sb.nblocks; i++, dp++) {
    if (dp->next == INIT) {
      return i;
    }
  }
  return INIT;
}