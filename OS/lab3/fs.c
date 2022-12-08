#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fs.h"

void fs_create() {
  sb = (struct superblock) {
    .size = sizeof(struct diskblock),
    .ninodes = 16,
    .nblocks = 128,
  };
  inodes = malloc(sizeof(struct inode) * sb.ninodes);
  dbs = malloc(sizeof(struct diskblock) * sb.nblocks);
  files = malloc(sizeof(struct file) * sb.ninodes);

  struct inode* ip = inodes;
  for (int i = 0; i < sb.ninodes; i++, ip++) {
    ip->size = 0;
    ip->inum = i;
    ip->first_block = INIT;
  }

  struct diskblock* dp = dbs;
  for (int i = 0; i < sb.nblocks; i++, dp++) {
    dp->next_block = INIT;
    strcpy(dp->data, "");
  }
}

void fs_sync() {
  FILE* fp = fopen("data", "w+");
  fwrite(&sb, sizeof(struct superblock), 1, fp);
  fwrite(inodes, sizeof(struct inode), sb.ninodes, fp);
  fwrite(dbs, sizeof(struct diskblock), sb.nblocks, fp);
  fwrite(files, sizeof(struct file), sb.ninodes, fp);
  fclose(fp);
}

int fs_alloc(int fd, int size) {
  // how many blocks we should have
  int total = (size + BLOCK_SIZE - 1) / BLOCK_SIZE - 1;
  int bid = inodes[fd].first_block;

  // extend the file if necessary...
  bid = grow(total, bid);
  return bid;
}

void fs_free(int fd) {
  int bid = inodes[fd].first_block;

  // contract the file if necessary...
  shrink(bid);
  dbs[bid].next_block = LAST;
  memset(files[fd].name, 0, sizeof(files[fd].name));
  files[fd].ip->size = 0;
  files[fd].ip->first_block = INIT;
  files[fd].ip = NULL;
}

// TODO: rewrite the write function!
void write_byte(int fnum, int pos, char* xs) {
  // calculate which block is
  int block = pos / BLOCK_SIZE;

  // find the block number
  int bnum = get_block_number(fnum, block);

  // calculate the offset
  int offset = pos % BLOCK_SIZE;

  // write the data
//  printf("[block] %d, [bnum] %d, [offset] %d\n", block, bnum, offset);
  int len = (int) strlen(xs);
  for (int i = 0, j = offset; i < len; i++, j++) {
    if (j >= BLOCK_SIZE) {
      j -= BLOCK_SIZE;
      bnum += 1;
    }
    dbs[bnum].data[j] = xs[i];
  }
//  dbs[bnum].data[offset] = *xs;
}
