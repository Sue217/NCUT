#include <stdio.h>

#include "fs.h"

void print() {
  printf("[Superblock Info]\n");
  printf("\t[inodes num] %d\n", sb.ninodes);
  printf("\t[blocks num] %d\n", sb.nblocks);
  printf("\t[blocks size] %d\n", sb.size);

  printf("[Inode Info]\n");
  struct inode* ip = inodes;
  for (int i = 0; i < sb.ninodes; i++, ip++) {
    printf("\t[size] %d, [first] %d, [name] %s\n", ip->size, ip->first_block, files[ip->inum].name);
  }

  printf("[Block Info]\n");
  struct diskblock* dp = dbs;
  for (int i = 0; i < sb.nblocks; i++, dp++) {
    printf("\t[cur num] %d, [next num] %d, [data] %s\n", i, dp->next_block, dp->data);
  }
}